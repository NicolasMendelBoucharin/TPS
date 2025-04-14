INCLUDEDIR=../include

CFLAGS=-std=c11 -Wall -Wextra -g
LDFLAGS=-lm
CPPFLAGS=-I$(INCLUDEDIR)




report: 
	pdflatex ../report/report.tex 
	
all: ./AES
	
AES: AES.o grid.o grid_io.o DFS.o heuristics.o generate.o
	$(CC) $(CFLAGS) -o ./AES AES.o grid.o grid_io.o DFS.o heuristics.o generate.o

AES.o: AES.c $(INCLUDEDIR)/AES.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $^


	
clean:
	@rm -f *.o ../include/*.gch ./AES ../report/*.aux ../report/*.log ../report/*.out ../report/*.toc
	
test:
	
help:
	@echo "à remplir"

.PHONY: all clean help

