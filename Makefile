CC = gcc

CFLAGS = -Wall -Wextra -Iinclude

TARGET = bin/client

SUBDIRS = src

MAN_DIR = /usr/local/share/man/man3

all:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir; \
	done

install: all
	install -d /usr/local/bin
	install -d $(MAN_DIR)
	install -m 755 $(TARGET) /usr/local/bin/client
	for file in man/man3/*.1; do \
		name=$$(basename $$file .1); \
		install -m 644 $$file $(MAN_DIR)/$$name.3; \
	done

clean:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done
	rm -f $(TARGET)
