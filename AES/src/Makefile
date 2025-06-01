CFLAGS = -Wall -Wextra -g
CPPFLAGS = -I ../include/

OBJDIR = ../obj
BINDIR = ../bin

all: AES

AES: AES.c cipher.o parser.o
	$(CC) $(CFLAGS) $(OBJDIR)/*.o -o $(BINDIR)/$@  $< $(CPPFLAGS)

parser.o: parser.c cipher.o
	$(CC) -c $(CFLAGS) -o  $(OBJDIR)/$@  $< $(CPPFLAGS)

cipher.o: cipher.c
	$(CC) -c $(CFLAGS) -o  $(OBJDIR)/$@  $< $(CPPFLAGS)



clean:
	rm -f  $(OBJDIR)/*  $(BINDIR)/* ciphered.txt deciphered.txt

.PHONY: all clean help