CC = gcc

CFLAGS = -Wall -Wextra -I../include

TARGET = ../bin/client

OBJDIR = ../obj

OBJECTS = $(OBJDIR)/main.o \
          $(OBJDIR)/mystrfunctions.o \
          $(OBJDIR)/myfilefunctions.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

$(OBJDIR)/main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o $(OBJDIR)/main.o

$(OBJDIR)/mystrfunctions.o: mystrfunctions.c
	$(CC) $(CFLAGS) -c mystrfunctions.c -o $(OBJDIR)/mystrfunctions.o

$(OBJDIR)/myfilefunctions.o: myfilefunctions.c
	$(CC) $(CFLAGS) -c myfilefunctions.c -o $(OBJDIR)/myfilefunctions.o

clean:
	rm -f $(OBJECTS)
