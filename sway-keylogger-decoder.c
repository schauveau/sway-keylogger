// gcc sway-keylogger-decoder.c -o sway-keylogger-decoder.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <linux/input.h>

#define CASE(x) case x: return #x

const char * type_name(int type)
{
  switch(type) {    
    CASE(EV_SYN);
    CASE(EV_KEY);
    CASE(EV_REL);
    CASE(EV_ABS);
    CASE(EV_MSC);
    CASE(EV_SW);
    CASE(EV_LED);
    CASE(EV_SND);
    CASE(EV_REP);
    CASE(EV_FF);
    CASE(EV_PWR);
    CASE(EV_FF_STATUS);
  default:
    return "?????" ;
  }
}

const char * code_name(int type, int code)
{
  switch(type) {    

  case EV_SYN:
    switch(code) {
      CASE(SYN_REPORT);
      CASE(SYN_CONFIG);
      CASE(SYN_MT_REPORT);
      CASE(SYN_DROPPED);
      CASE(SYN_MAX);
      CASE(SYN_CNT);
    default:  return "?";      
    }
    break ;
    
  case EV_KEY:
    // Reminder: Lines that are commented out are duplicate. See linux/input.h
    switch(code) {
      CASE(KEY_RESERVED);
      CASE(KEY_ESC);
      CASE(KEY_1);
      CASE(KEY_2);
      CASE(KEY_3);
      CASE(KEY_4);
      CASE(KEY_5);
      CASE(KEY_6);
      CASE(KEY_7);
      CASE(KEY_8);
      CASE(KEY_9);
      CASE(KEY_0);
      CASE(KEY_MINUS);
      CASE(KEY_EQUAL);
      CASE(KEY_BACKSPACE);
      CASE(KEY_TAB);
      CASE(KEY_Q);
      CASE(KEY_W);
      CASE(KEY_E);
      CASE(KEY_R);
      CASE(KEY_T);
      CASE(KEY_Y);
      CASE(KEY_U);
      CASE(KEY_I);
      CASE(KEY_O);
      CASE(KEY_P);
      CASE(KEY_LEFTBRACE);
      CASE(KEY_RIGHTBRACE);
      CASE(KEY_ENTER);
      CASE(KEY_LEFTCTRL);
      CASE(KEY_A);
      CASE(KEY_S);
      CASE(KEY_D);
      CASE(KEY_F);
      CASE(KEY_G);
      CASE(KEY_H);
      CASE(KEY_J);
      CASE(KEY_K);
      CASE(KEY_L);
      CASE(KEY_SEMICOLON);
      CASE(KEY_APOSTROPHE);
      CASE(KEY_GRAVE);
      CASE(KEY_LEFTSHIFT);
      CASE(KEY_BACKSLASH);
      CASE(KEY_Z);
      CASE(KEY_X);
      CASE(KEY_C);
      CASE(KEY_V);
      CASE(KEY_B);
      CASE(KEY_N);
      CASE(KEY_M);
      CASE(KEY_COMMA);
      CASE(KEY_DOT);
      CASE(KEY_SLASH);
      CASE(KEY_RIGHTSHIFT);
      CASE(KEY_KPASTERISK);
      CASE(KEY_LEFTALT);
      CASE(KEY_SPACE);
      CASE(KEY_CAPSLOCK);
      CASE(KEY_F1);
      CASE(KEY_F2);
      CASE(KEY_F3);
      CASE(KEY_F4);
      CASE(KEY_F5);
      CASE(KEY_F6);
      CASE(KEY_F7);
      CASE(KEY_F8);
      CASE(KEY_F9);
      CASE(KEY_F10);
      CASE(KEY_NUMLOCK);
      CASE(KEY_SCROLLLOCK);
      CASE(KEY_KP7);
      CASE(KEY_KP8);
      CASE(KEY_KP9);
      CASE(KEY_KPMINUS);
      CASE(KEY_KP4);
      CASE(KEY_KP5);
      CASE(KEY_KP6);
      CASE(KEY_KPPLUS);
      CASE(KEY_KP1);
      CASE(KEY_KP2);
      CASE(KEY_KP3);
      CASE(KEY_KP0);
      CASE(KEY_KPDOT);
      CASE(KEY_ZENKAKUHANKAKU);
      CASE(KEY_102ND);
      CASE(KEY_F11);
      CASE(KEY_F12);
      CASE(KEY_RO);
      CASE(KEY_KATAKANA);
      CASE(KEY_HIRAGANA);
      CASE(KEY_HENKAN);
      CASE(KEY_KATAKANAHIRAGANA);
      CASE(KEY_MUHENKAN);
      CASE(KEY_KPJPCOMMA);
      CASE(KEY_KPENTER);
      CASE(KEY_RIGHTCTRL);
      CASE(KEY_KPSLASH);
      CASE(KEY_SYSRQ);
      CASE(KEY_RIGHTALT);
      CASE(KEY_LINEFEED);
      CASE(KEY_HOME);
      CASE(KEY_UP);
      CASE(KEY_PAGEUP);
      CASE(KEY_LEFT);
      CASE(KEY_RIGHT);
      CASE(KEY_END);
      CASE(KEY_DOWN);
      CASE(KEY_PAGEDOWN);
      CASE(KEY_INSERT);
      CASE(KEY_DELETE);
      CASE(KEY_MACRO);
      CASE(KEY_MUTE);
      CASE(KEY_VOLUMEDOWN);
      CASE(KEY_VOLUMEUP);
      CASE(KEY_POWER);
      CASE(KEY_KPEQUAL);
      CASE(KEY_KPPLUSMINUS);
      CASE(KEY_PAUSE);
      CASE(KEY_SCALE);
      CASE(KEY_KPCOMMA);
      CASE(KEY_HANGEUL);
      //CASE(KEY_HANGUEL);
      CASE(KEY_HANJA);
      CASE(KEY_YEN);
      CASE(KEY_LEFTMETA);
      CASE(KEY_RIGHTMETA);
      CASE(KEY_COMPOSE);
      CASE(KEY_STOP);
      CASE(KEY_AGAIN);
      CASE(KEY_PROPS);
      CASE(KEY_UNDO);
      CASE(KEY_FRONT);
      CASE(KEY_COPY);
      CASE(KEY_OPEN);
      CASE(KEY_PASTE);
      CASE(KEY_FIND);
      CASE(KEY_CUT);
      CASE(KEY_HELP);
      CASE(KEY_MENU);
      CASE(KEY_CALC);
      CASE(KEY_SETUP);
      CASE(KEY_SLEEP);
      CASE(KEY_WAKEUP);
      CASE(KEY_FILE);
      CASE(KEY_SENDFILE);
      CASE(KEY_DELETEFILE);
      CASE(KEY_XFER);
      CASE(KEY_PROG1);
      CASE(KEY_PROG2);
      CASE(KEY_WWW);
      CASE(KEY_MSDOS);
      CASE(KEY_COFFEE);
      //CASE(KEY_SCREENLOCK);
      CASE(KEY_ROTATE_DISPLAY);
      //CASE(KEY_DIRECTION);
      CASE(KEY_CYCLEWINDOWS);
      CASE(KEY_MAIL);
      CASE(KEY_BOOKMARKS);
      CASE(KEY_COMPUTER);
      CASE(KEY_BACK);
      CASE(KEY_FORWARD);
      CASE(KEY_CLOSECD);
      CASE(KEY_EJECTCD);
      CASE(KEY_EJECTCLOSECD);
      CASE(KEY_NEXTSONG);
      CASE(KEY_PLAYPAUSE);
      CASE(KEY_PREVIOUSSONG);
      CASE(KEY_STOPCD);
      CASE(KEY_RECORD);
      CASE(KEY_REWIND);
      CASE(KEY_PHONE);
      CASE(KEY_ISO);
      CASE(KEY_CONFIG);
      CASE(KEY_HOMEPAGE);
      CASE(KEY_REFRESH);
      CASE(KEY_EXIT);
      CASE(KEY_MOVE);
      CASE(KEY_EDIT);
      CASE(KEY_SCROLLUP);
      CASE(KEY_SCROLLDOWN);
      CASE(KEY_KPLEFTPAREN);
      CASE(KEY_KPRIGHTPAREN);
      CASE(KEY_NEW);
      CASE(KEY_REDO);
      CASE(KEY_F13);
      CASE(KEY_F14);
      CASE(KEY_F15);
      CASE(KEY_F16);
      CASE(KEY_F17);
      CASE(KEY_F18);
      CASE(KEY_F19);
      CASE(KEY_F20);
      CASE(KEY_F21);
      CASE(KEY_F22);
      CASE(KEY_F23);
      CASE(KEY_F24);
      CASE(KEY_PLAYCD);
      CASE(KEY_PAUSECD);
      CASE(KEY_PROG3);
      CASE(KEY_PROG4);
      CASE(KEY_DASHBOARD);
      CASE(KEY_SUSPEND);
      CASE(KEY_CLOSE);
      CASE(KEY_PLAY);
      CASE(KEY_FASTFORWARD);
      CASE(KEY_BASSBOOST);
      CASE(KEY_PRINT);
      CASE(KEY_HP);
      CASE(KEY_CAMERA);
      CASE(KEY_SOUND);
      CASE(KEY_QUESTION);
      CASE(KEY_EMAIL);
      CASE(KEY_CHAT);
      CASE(KEY_SEARCH);
      CASE(KEY_CONNECT);
      CASE(KEY_FINANCE);
      CASE(KEY_SPORT);
      CASE(KEY_SHOP);
      CASE(KEY_ALTERASE);
      CASE(KEY_CANCEL);
      CASE(KEY_BRIGHTNESSDOWN);
      CASE(KEY_BRIGHTNESSUP);
      CASE(KEY_MEDIA);
      CASE(KEY_SWITCHVIDEOMODE);
      CASE(KEY_KBDILLUMTOGGLE);
      CASE(KEY_KBDILLUMDOWN);
      CASE(KEY_KBDILLUMUP);
      CASE(KEY_SEND);
      CASE(KEY_REPLY);
      CASE(KEY_FORWARDMAIL);
      CASE(KEY_SAVE);
      CASE(KEY_DOCUMENTS);
      CASE(KEY_BATTERY);
      CASE(KEY_BLUETOOTH);
      CASE(KEY_WLAN);
      CASE(KEY_UWB);
      CASE(KEY_UNKNOWN);
      CASE(KEY_VIDEO_NEXT);
      CASE(KEY_VIDEO_PREV);
      CASE(KEY_BRIGHTNESS_CYCLE);
      CASE(KEY_BRIGHTNESS_AUTO);      
      //CASE(KEY_BRIGHTNESS_ZERO);
      CASE(KEY_DISPLAY_OFF);
      CASE(KEY_WWAN);
      //CASE(KEY_WIMAX);
      CASE(KEY_RFKILL);
      CASE(KEY_MICMUTE);
      
      //CASE(BTN_MISC);
      CASE(BTN_0);
      CASE(BTN_1);
      CASE(BTN_2);
      CASE(BTN_3);
      CASE(BTN_4);
      CASE(BTN_5);
      CASE(BTN_6);
      CASE(BTN_7);
      CASE(BTN_8);
      CASE(BTN_9);

      //CASE(BTN_MOUSE);
      CASE(BTN_LEFT);
      CASE(BTN_RIGHT);
      CASE(BTN_MIDDLE);
      CASE(BTN_SIDE);
      CASE(BTN_EXTRA);
      CASE(BTN_FORWARD);
      CASE(BTN_BACK);
      CASE(BTN_TASK);

      CASE(BTN_JOYSTICK);
      //CASE(BTN_TRIGGER);
      CASE(BTN_THUMB);
      CASE(BTN_THUMB2);
      CASE(BTN_TOP);
      CASE(BTN_TOP2);
      CASE(BTN_PINKIE);
      CASE(BTN_BASE);
      CASE(BTN_BASE2);
      CASE(BTN_BASE3);
      CASE(BTN_BASE4);
      CASE(BTN_BASE5);
      CASE(BTN_BASE6);
      CASE(BTN_DEAD);

      //CASE(BTN_GAMEPAD);
      CASE(BTN_SOUTH);
      //CASE(BTN_A);
      CASE(BTN_EAST);
      //CASE(BTN_B);
      CASE(BTN_C);
      CASE(BTN_NORTH);
      //CASE(BTN_X);
      CASE(BTN_WEST);
      //CASE(BTN_Y);
      CASE(BTN_Z);
      CASE(BTN_TL);
      CASE(BTN_TR);
      CASE(BTN_TL2);
      CASE(BTN_TR2);
      CASE(BTN_SELECT);
      CASE(BTN_START);
      CASE(BTN_MODE);
      CASE(BTN_THUMBL);
      CASE(BTN_THUMBR);

      //CASE(BTN_DIGI);
      CASE(BTN_TOOL_PEN);
      CASE(BTN_TOOL_RUBBER);
      CASE(BTN_TOOL_BRUSH);
      CASE(BTN_TOOL_PENCIL);
      CASE(BTN_TOOL_AIRBRUSH);
      CASE(BTN_TOOL_FINGER);
      CASE(BTN_TOOL_MOUSE);
      CASE(BTN_TOOL_LENS);
      CASE(BTN_TOOL_QUINTTAP);
      CASE(BTN_STYLUS3);
      CASE(BTN_TOUCH);
      CASE(BTN_STYLUS);
      CASE(BTN_STYLUS2);
      CASE(BTN_TOOL_DOUBLETAP);
      CASE(BTN_TOOL_TRIPLETAP);
      CASE(BTN_TOOL_QUADTAP);

      // CASE(BTN_WHEEL);
      CASE(BTN_GEAR_DOWN);
      CASE(BTN_GEAR_UP);

      CASE(KEY_OK);
      CASE(KEY_SELECT);
      CASE(KEY_GOTO);
      CASE(KEY_CLEAR);
      CASE(KEY_POWER2);
      CASE(KEY_OPTION);
      CASE(KEY_INFO);
      CASE(KEY_TIME);
      CASE(KEY_VENDOR);
      CASE(KEY_ARCHIVE);
      CASE(KEY_PROGRAM);
      CASE(KEY_CHANNEL);
      CASE(KEY_FAVORITES);
      CASE(KEY_EPG);
      CASE(KEY_PVR);
      CASE(KEY_MHP);
      CASE(KEY_LANGUAGE);
      CASE(KEY_TITLE);
      CASE(KEY_SUBTITLE);
      CASE(KEY_ANGLE);
      CASE(KEY_ZOOM);
      CASE(KEY_MODE);
      CASE(KEY_KEYBOARD);
      CASE(KEY_SCREEN);
      CASE(KEY_PC);
      CASE(KEY_TV);
      CASE(KEY_TV2);
      CASE(KEY_VCR);
      CASE(KEY_VCR2);
      CASE(KEY_SAT);
      CASE(KEY_SAT2);
      CASE(KEY_CD);
      CASE(KEY_TAPE);
      CASE(KEY_RADIO);
      CASE(KEY_TUNER);
      CASE(KEY_PLAYER);
      CASE(KEY_TEXT);
      CASE(KEY_DVD);
      CASE(KEY_AUX);
      CASE(KEY_MP3);
      CASE(KEY_AUDIO);
      CASE(KEY_VIDEO);
      CASE(KEY_DIRECTORY);
      CASE(KEY_LIST);
      CASE(KEY_MEMO);
      CASE(KEY_CALENDAR);
      CASE(KEY_RED);
      CASE(KEY_GREEN);
      CASE(KEY_YELLOW);
      CASE(KEY_BLUE);
      CASE(KEY_CHANNELUP);
      CASE(KEY_CHANNELDOWN);
      CASE(KEY_FIRST);
      CASE(KEY_LAST);
      CASE(KEY_AB);
      CASE(KEY_NEXT);
      CASE(KEY_RESTART);
      CASE(KEY_SLOW);
      CASE(KEY_SHUFFLE);
      CASE(KEY_BREAK);
      CASE(KEY_PREVIOUS);
      CASE(KEY_DIGITS);
      CASE(KEY_TEEN);
      CASE(KEY_TWEN);
      CASE(KEY_VIDEOPHONE);
      CASE(KEY_GAMES);
      CASE(KEY_ZOOMIN);
      CASE(KEY_ZOOMOUT);
      CASE(KEY_ZOOMRESET);
      CASE(KEY_WORDPROCESSOR);
      CASE(KEY_EDITOR);
      CASE(KEY_SPREADSHEET);
      CASE(KEY_GRAPHICSEDITOR);
      CASE(KEY_PRESENTATION);
      CASE(KEY_DATABASE);
      CASE(KEY_NEWS);
      CASE(KEY_VOICEMAIL);
      CASE(KEY_ADDRESSBOOK);
      CASE(KEY_MESSENGER);
      CASE(KEY_DISPLAYTOGGLE);
      //CASE(KEY_BRIGHTNESS_TOGGLE);
      CASE(KEY_SPELLCHECK);
      CASE(KEY_LOGOFF);

      CASE(KEY_DOLLAR);
      CASE(KEY_EURO);

      CASE(KEY_FRAMEBACK);
      CASE(KEY_FRAMEFORWARD);
      CASE(KEY_CONTEXT_MENU);
      CASE(KEY_MEDIA_REPEAT);
      CASE(KEY_10CHANNELSUP);
      CASE(KEY_10CHANNELSDOWN);
      CASE(KEY_IMAGES);

      CASE(KEY_DEL_EOL);
      CASE(KEY_DEL_EOS);
      CASE(KEY_INS_LINE);
      CASE(KEY_DEL_LINE);

      CASE(KEY_FN);
      CASE(KEY_FN_ESC);
      CASE(KEY_FN_F1);
      CASE(KEY_FN_F2);
      CASE(KEY_FN_F3);
      CASE(KEY_FN_F4);
      CASE(KEY_FN_F5);
      CASE(KEY_FN_F6);
      CASE(KEY_FN_F7);
      CASE(KEY_FN_F8);
      CASE(KEY_FN_F9);
      CASE(KEY_FN_F10);
      CASE(KEY_FN_F11);
      CASE(KEY_FN_F12);
      CASE(KEY_FN_1);
      CASE(KEY_FN_2);
      CASE(KEY_FN_D);
      CASE(KEY_FN_E);
      CASE(KEY_FN_F);
      CASE(KEY_FN_S);
      CASE(KEY_FN_B);

      CASE(KEY_BRL_DOT1);
      CASE(KEY_BRL_DOT2);
      CASE(KEY_BRL_DOT3);
      CASE(KEY_BRL_DOT4);
      CASE(KEY_BRL_DOT5);
      CASE(KEY_BRL_DOT6);
      CASE(KEY_BRL_DOT7);
      CASE(KEY_BRL_DOT8);
      CASE(KEY_BRL_DOT9);
      CASE(KEY_BRL_DOT10);

      CASE(KEY_NUMERIC_0);
      CASE(KEY_NUMERIC_1);
      CASE(KEY_NUMERIC_2);
      CASE(KEY_NUMERIC_3);
      CASE(KEY_NUMERIC_4);
      CASE(KEY_NUMERIC_5);
      CASE(KEY_NUMERIC_6);
      CASE(KEY_NUMERIC_7);
      CASE(KEY_NUMERIC_8);
      CASE(KEY_NUMERIC_9);
      CASE(KEY_NUMERIC_STAR);
      CASE(KEY_NUMERIC_POUND);
      CASE(KEY_NUMERIC_A);
      CASE(KEY_NUMERIC_B);
      CASE(KEY_NUMERIC_C);
      CASE(KEY_NUMERIC_D);

      CASE(KEY_CAMERA_FOCUS);
      CASE(KEY_WPS_BUTTON);

      CASE(KEY_TOUCHPAD_TOGGLE);
      CASE(KEY_TOUCHPAD_ON);
      CASE(KEY_TOUCHPAD_OFF);

      CASE(KEY_CAMERA_ZOOMIN);
      CASE(KEY_CAMERA_ZOOMOUT);
      CASE(KEY_CAMERA_UP);
      CASE(KEY_CAMERA_DOWN);
      CASE(KEY_CAMERA_LEFT);
      CASE(KEY_CAMERA_RIGHT);

      CASE(KEY_ATTENDANT_ON);
      CASE(KEY_ATTENDANT_OFF);
      CASE(KEY_ATTENDANT_TOGGLE);
      CASE(KEY_LIGHTS_TOGGLE);

      CASE(BTN_DPAD_UP);
      CASE(BTN_DPAD_DOWN);
      CASE(BTN_DPAD_LEFT);
      CASE(BTN_DPAD_RIGHT);

      CASE(KEY_ALS_TOGGLE);
      CASE(KEY_ROTATE_LOCK_TOGGLE);

      CASE(KEY_BUTTONCONFIG);
      CASE(KEY_TASKMANAGER);
      CASE(KEY_JOURNAL);
      CASE(KEY_CONTROLPANEL);
      CASE(KEY_APPSELECT);
      CASE(KEY_SCREENSAVER);
      CASE(KEY_VOICECOMMAND);
      CASE(KEY_ASSISTANT);

      CASE(KEY_BRIGHTNESS_MIN);
      CASE(KEY_BRIGHTNESS_MAX);

      CASE(KEY_KBDINPUTASSIST_PREV);
      CASE(KEY_KBDINPUTASSIST_NEXT);
      CASE(KEY_KBDINPUTASSIST_PREVGROUP);
      CASE(KEY_KBDINPUTASSIST_NEXTGROUP);
      CASE(KEY_KBDINPUTASSIST_ACCEPT);
      CASE(KEY_KBDINPUTASSIST_CANCEL);

      CASE(KEY_RIGHT_UP);
      CASE(KEY_RIGHT_DOWN);
      CASE(KEY_LEFT_UP);
      CASE(KEY_LEFT_DOWN);

      CASE(KEY_ROOT_MENU);
      CASE(KEY_MEDIA_TOP_MENU);
      CASE(KEY_NUMERIC_11);
      CASE(KEY_NUMERIC_12);
      CASE(KEY_AUDIO_DESC);
      CASE(KEY_3D_MODE);
      CASE(KEY_NEXT_FAVORITE);
      CASE(KEY_STOP_RECORD);
      CASE(KEY_PAUSE_RECORD);
      CASE(KEY_VOD);
      CASE(KEY_UNMUTE);
      CASE(KEY_FASTREVERSE);
      CASE(KEY_SLOWREVERSE);
      CASE(KEY_DATA);
      CASE(KEY_ONSCREEN_KEYBOARD);
      // CASE(BTN_TRIGGER_HAPPY);
      CASE(BTN_TRIGGER_HAPPY1);
      CASE(BTN_TRIGGER_HAPPY2);
      CASE(BTN_TRIGGER_HAPPY3);
      CASE(BTN_TRIGGER_HAPPY4);
      CASE(BTN_TRIGGER_HAPPY5);
      CASE(BTN_TRIGGER_HAPPY6);
      CASE(BTN_TRIGGER_HAPPY7);
      CASE(BTN_TRIGGER_HAPPY8);
      CASE(BTN_TRIGGER_HAPPY9);
      CASE(BTN_TRIGGER_HAPPY10);
      CASE(BTN_TRIGGER_HAPPY11);
      CASE(BTN_TRIGGER_HAPPY12);
      CASE(BTN_TRIGGER_HAPPY13);
      CASE(BTN_TRIGGER_HAPPY14);
      CASE(BTN_TRIGGER_HAPPY15);
      CASE(BTN_TRIGGER_HAPPY16);
      CASE(BTN_TRIGGER_HAPPY17);
      CASE(BTN_TRIGGER_HAPPY18);
      CASE(BTN_TRIGGER_HAPPY19);
      CASE(BTN_TRIGGER_HAPPY20);
      CASE(BTN_TRIGGER_HAPPY21);
      CASE(BTN_TRIGGER_HAPPY22);
      CASE(BTN_TRIGGER_HAPPY23);
      CASE(BTN_TRIGGER_HAPPY24);
      CASE(BTN_TRIGGER_HAPPY25);
      CASE(BTN_TRIGGER_HAPPY26);
      CASE(BTN_TRIGGER_HAPPY27);
      CASE(BTN_TRIGGER_HAPPY28);
      CASE(BTN_TRIGGER_HAPPY29);
      CASE(BTN_TRIGGER_HAPPY30);
      CASE(BTN_TRIGGER_HAPPY31);
      CASE(BTN_TRIGGER_HAPPY32);
      CASE(BTN_TRIGGER_HAPPY33);
      CASE(BTN_TRIGGER_HAPPY34);
      CASE(BTN_TRIGGER_HAPPY35);
      CASE(BTN_TRIGGER_HAPPY36);
      CASE(BTN_TRIGGER_HAPPY37);
      CASE(BTN_TRIGGER_HAPPY38);
      CASE(BTN_TRIGGER_HAPPY39);
      CASE(BTN_TRIGGER_HAPPY40);

    default: return "?"; 
    }
    break ;
    
  case EV_REL:
    switch(code) {
      CASE(REL_X);
      CASE(REL_Y);
      CASE(REL_Z);
      CASE(REL_RX);
      CASE(REL_RY);
      CASE(REL_RZ);
      CASE(REL_HWHEEL);
      CASE(REL_DIAL);
      CASE(REL_WHEEL);
      CASE(REL_MISC);
    default: return "?";
    }
    break ;
    
  case EV_ABS:
    switch(code) {
      CASE(ABS_X);
      CASE(ABS_Y);
      CASE(ABS_Z);
      CASE(ABS_RX);
      CASE(ABS_RY);
      CASE(ABS_RZ);
      CASE(ABS_THROTTLE);
      CASE(ABS_RUDDER);
      CASE(ABS_WHEEL);
      CASE(ABS_GAS);
      CASE(ABS_BRAKE);
      CASE(ABS_HAT0X);
      CASE(ABS_HAT0Y);
      CASE(ABS_HAT1X);
      CASE(ABS_HAT1Y);
      CASE(ABS_HAT2X);
      CASE(ABS_HAT2Y);
      CASE(ABS_HAT3X);
      CASE(ABS_HAT3Y);
      CASE(ABS_PRESSURE);
      CASE(ABS_DISTANCE);
      CASE(ABS_TILT_X);
      CASE(ABS_TILT_Y);
      CASE(ABS_TOOL_WIDTH);
      CASE(ABS_VOLUME);
      CASE(ABS_MISC);
      CASE(ABS_RESERVED);
      CASE(ABS_MT_SLOT);
      CASE(ABS_MT_TOUCH_MAJOR);
      CASE(ABS_MT_TOUCH_MINOR);
      CASE(ABS_MT_WIDTH_MAJOR);
      CASE(ABS_MT_WIDTH_MINOR);
      CASE(ABS_MT_ORIENTATION);
      CASE(ABS_MT_POSITION_X);
      CASE(ABS_MT_POSITION_Y);
      CASE(ABS_MT_TOOL_TYPE);
      CASE(ABS_MT_BLOB_ID);
      CASE(ABS_MT_TRACKING_ID);
      CASE(ABS_MT_PRESSURE);
      CASE(ABS_MT_DISTANCE);
      CASE(ABS_MT_TOOL_X);
      CASE(ABS_MT_TOOL_Y);
      CASE(ABS_MAX);
      CASE(ABS_CNT);
    default: return "?";
    }
    break ;
    
  case EV_MSC:
    switch(code) {
      CASE(MSC_SERIAL);
      CASE(MSC_PULSELED);
      CASE(MSC_GESTURE);
      CASE(MSC_RAW);
      CASE(MSC_SCAN);
      CASE(MSC_TIMESTAMP);
      CASE(MSC_MAX);
      CASE(MSC_CNT);
    default: return "?";
    }
    break ;
    
  case EV_SW:
    switch(code) {
      CASE(SW_LID);
      CASE(SW_TABLET_MODE);
      CASE(SW_HEADPHONE_INSERT);
      CASE(SW_RFKILL_ALL);
      //      CASE(SW_RADIO);
      CASE(SW_MICROPHONE_INSERT);
      CASE(SW_DOCK);
      CASE(SW_LINEOUT_INSERT);
      CASE(SW_JACK_PHYSICAL_INSERT);
      CASE(SW_VIDEOOUT_INSERT);
      CASE(SW_CAMERA_LENS_COVER);
      CASE(SW_KEYPAD_SLIDE);
      CASE(SW_FRONT_PROXIMITY);
      CASE(SW_ROTATE_LOCK);
      CASE(SW_LINEIN_INSERT);
      CASE(SW_MUTE_DEVICE);
      CASE(SW_PEN_INSERTED);
    default: return "?";
    }
    break ;
    
  case EV_LED:
    switch(code) {
      CASE(LED_NUML);
      CASE(LED_CAPSL);
      CASE(LED_SCROLLL);
      CASE(LED_COMPOSE);
      CASE(LED_KANA);
      CASE(LED_SLEEP);
      CASE(LED_SUSPEND);
      CASE(LED_MUTE);
      CASE(LED_MISC);
      CASE(LED_MAIL);
      CASE(LED_CHARGING);
    default: return "?";
    }
    break ;
    
  case EV_SND:
    switch(code) {
      CASE(SND_CLICK);
      CASE(SND_BELL);
      CASE(SND_TONE);
    default: return "?";
    }
    break ;
    
  case EV_REP:
    switch(code) {
      CASE(REP_DELAY);
      CASE(REP_PERIOD);
    default: return "?";
    }
    break ;
    
  case EV_FF:
    switch(code) {
    default: return "?";
    }
    break ;
    
  case EV_PWR:
    switch(code) {
    default: return "?";
    }
    break ;
    
  case EV_FF_STATUS:
    switch(code) {
    default: return "?";
    }
    break ;
    
    
  default:
    return "?" ;
  }
}

void process_data(int fd, char *data, int n)
{
  if ( n % sizeof(struct input_event) != 0 ) {
    fprintf(stderr, "Ignoring suspicious block\n");
    return ;
  }

  for ( int i=0; i<n ; i+=sizeof(struct input_event) ) {
    struct input_event *event = (struct input_event *)(data+i) ;

      
    printf("fd=%-3d time=%lld.%06ld" ,
           fd,
           event->input_event_sec,
           event->input_event_usec) ;

    if (event->type==EV_SYN && event->code==SYN_REPORT) {
      printf(" -------------- SYN_REPORT ------------\n") ;
    } else {
      printf(" type %u (%s), code %u (%s), value %d\n",
             event->type, type_name(event->type),
             event->code, code_name(event->type, event->code),
             event->value
             );
    }
  }
}

int main(void)
{
  int n;
  int offset;
  int byte[16];
  char buffer[100] ; 

  char *data ;
  int data_alloc = 16*100 ;
  int data_size ;

  int read_fd ;
  int read_size ;

  // TODO: realloc when too small? 
  data = malloc(data_alloc) ;

  read_size = 0 ;
  data_size = 0 ;

  while ( fgets(buffer, sizeof(buffer), stdin)) {
    if ( buffer[0] == '#' ) {
      fputs(buffer,stdout) ;
      continue ;
    }

    if ( strncmp(buffer,"read(",5)==0 ) {

      data_size = 0 ;
      read_size = 0 ;

      // A line of the form
      //     read(FD,...) = N
      // where FD is the file descriptor number and N is the
      // number of bytes obtained by the 'read'
      //
      
      sscanf(buffer+5,"%d",&read_fd) ;

      char * s = strchr(buffer,'=');
      if (s) {
        sscanf(s,"= %d",&read_size) ;
        if ( read_size > data_alloc ) {
          // Todo: realloc? 
          fprintf(stderr,"Ignoring large block\n"); 
          read_size = 0 ;
        }
      }
      continue ;
    }

    if ( read_size == 0 ) {
      // Probably 
      continue ;
    }

    if (buffer[0]==' ' && buffer[1]=='|') {
      // This is a data line of the form 
      //    | 00060  a5 1c 00 00 00 00 00 00  ab 49 00 00 00 00 00 00  .........I...... |
      // so composed of an offset, up to 16 hex bytes and an ascii dump
      //

      char * current = data + data_size ;
      
      n = sscanf(buffer+2,
                 " %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x %x",
                 &offset,
                 &data[data_size+0],
                 &data[data_size+1],
                 &data[data_size+2],
                 &data[data_size+3],
                 &data[data_size+4],
                 &data[data_size+5],
                 &data[data_size+6],
                 &data[data_size+7],
                 &data[data_size+8],
                 &data[data_size+9],
                 &data[data_size+10],
                 &data[data_size+11],
                 &data[data_size+12],
                 &data[data_size+13],
                 &data[data_size+14],
                 &data[data_size+15]
                 ) ;

      if ( n<1 || n>17 ) {
        // Strange... malformed input>?
        // Ignore that line
        continue ;
      }
      
      if ( offset != data_size ) {
        fprintf(stderr,"ERROR: Unexpected offset in block (%d vs %d). Ignoring that block!\n", offset, data_size);
        // Ignore the whole data block.
        read_size = 0 ;
        continue ;
      }

      data_size += n-1 ;

      if ( data_size > read_size ) {
        fprintf(stderr,"ERROR: Too much data. Ignoring that block!\n");
        read_size = 0 ;
        continue ;
      }
      
      if ( data_size == read_size ) {
        process_data( read_fd, data, data_size ) ;
        read_size = 0 ;
      }
      
    }

    
  }
  return 0;
}
