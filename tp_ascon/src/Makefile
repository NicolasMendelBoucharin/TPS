CFLAGS = -Wall -Wextra -g
CPPFLAGS = -I ../include/

OBJDIR = ../obj
BINDIR = ../bin

all: ascon

ascon: ascon.c permutation.o processing.o
	$(CC) $(CFLAGS) $(OBJDIR)/*.o -o $(BINDIR)/$@  $< $(CPPFLAGS)

permutation.o: permutation.c processing.o
	$(CC) -c $(CFLAGS) -o  $(OBJDIR)/$@  $< $(CPPFLAGS)

processing.o: processing.c
	$(CC) -c $(CFLAGS) -o  $(OBJDIR)/$@  $< $(CPPFLAGS)

clean:
	rm -f  $(OBJDIR)/*  $(BINDIR)/*

.PHONY: all clean help