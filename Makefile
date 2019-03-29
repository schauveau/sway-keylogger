

all:
	chmod +x sway-keylogger
	$(CC) -o sway-keylogger-decoder sway-keylogger-decoder.c

html:
	markdown_py README.md > README.html


