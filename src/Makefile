CC = gcc

CFLAGS = -Wall -Wextra -fPIC -I../include

LDFLAGS = -L../lib

TARGET = ../bin/client_dynamic

LIBRARY = ../lib/libmyutils.so

OBJDIR = ../obj

MAIN_OBJECT = $(OBJDIR)/main.o

LIB_OBJECTS = $(OBJDIR)/mystrfunctions.o \
              $(OBJDIR)/myfilefunctions.o

all: $(TARGET)

$(TARGET): $(MAIN_OBJECT) $(LIBRARY)
	$(CC) $(MAIN_OBJECT) $(LDFLAGS) -lmyutils -Wl,-rpath,'$$ORIGIN/../lib' -o $(TARGET)

$(LIBRARY): $(LIB_OBJECTS)
	$(CC) -shared -o $(LIBRARY) $(LIB_OBJECTS)

$(MAIN_OBJECT): main.c ../include/mystrfunctions.h ../include/myfilefunctions.h
	$(CC) $(CFLAGS) -c main.c -o $(MAIN_OBJECT)

$(OBJDIR)/mystrfunctions.o: mystrfunctions.c ../include/mystrfunctions.h
	$(CC) $(CFLAGS) -c mystrfunctions.c -o $(OBJDIR)/mystrfunctions.o

$(OBJDIR)/myfilefunctions.o: myfilefunctions.c ../include/myfilefunctions.h
	$(CC) $(CFLAGS) -c myfilefunctions.c -o $(OBJDIR)/myfilefunctions.o

clean:
	rm -f $(MAIN_OBJECT) $(LIB_OBJECTS)
	rm -f $(LIBRARY)
	rm -f $(TARGET)
