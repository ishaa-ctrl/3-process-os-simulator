CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: ui core logger launcher

ui:
	$(CC) $(CFLAGS) ui/ui.c -o ui/ui

core:
	$(CC) $(CFLAGS) core/core.c -o core/core

logger:
	$(CC) $(CFLAGS) logger/logger.c -o logger/logger

launcher:
	$(CC) $(CFLAGS) launcher.c -o launcher

clean:
	rm -f ui/ui core/core logger/logger launcher
