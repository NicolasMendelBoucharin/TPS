CFLAGS = -Wall -Wextra -g
CPPFLAGS = -I ../include/

OBJDIR = ../obj
BINDIR = ../bin

all: AES

AES: AES.c cypher.o parser.o
	$(CC) $(CFLAGS) $(OBJDIR)/*.o -o $(BINDIR)/$@  $< $(CPPFLAGS)

parser.o: parser.c cypher.o
	$(CC) -c $(CFLAGS) -o  $(OBJDIR)/$@  $< $(CPPFLAGS)

cypher.o: cypher.c
	$(CC) -c $(CFLAGS) -o  $(OBJDIR)/$@  $< $(CPPFLAGS)



clean:
	rm -f  $(OBJDIR)/*  $(BINDIR)/*

.PHONY: all clean help