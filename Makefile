CC = gcc

CFLAGS = -Wall -Wextra -Iinclude

TARGET = bin/client

SUBDIRS = src

all:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir; \
	done

clean:
	for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done
	rm -f $(TARGET)
