CC = gcc

CFLAGS = -Wall -Wextra -I../include

TARGET = ../bin/client_static

LIBRARY = ../lib/libmyutils.a

OBJDIR = ../obj

MAIN_OBJECT = $(OBJDIR)/main.o

LIB_OBJECTS = $(OBJDIR)/mystrfunctions.o \
              $(OBJDIR)/myfilefunctions.o

all: $(TARGET)

$(TARGET): $(MAIN_OBJECT) $(LIBRARY)
	$(CC) $(MAIN_OBJECT) -L../lib -lmyutils -o $(TARGET)

$(LIBRARY): $(LIB_OBJECTS)
	ar r $(LIBRARY) $(LIB_OBJECTS)
	ranlib $(LIBRARY)

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
