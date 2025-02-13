INCLUDEDIR=../include

CFLAGS=-std=c11 -Wall -Wextra -g
LDFLAGS=-lm
CPPFLAGS=-I$(INCLUDEDIR)




report: 
	pdflatex ../report/report.tex 
	
all: ./hitori
	
hitori: hitori.o grid.o grid_io.o DFS.o heuristics.o generate.o
	$(CC) $(CFLAGS) -o ./hitori hitori.o grid.o grid_io.o DFS.o heuristics.o generate.o

hitori.o: hitori.c $(INCLUDEDIR)/hitori.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $^

grid.o : grid.c $(INCLUDEDIR)/grid.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $^

grid_io.o : grid_io.c $(INCLUDEDIR)/grid_io.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $^

DFS.o : DFS.c $(INCLUDEDIR)/DFS.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $^

HEURISTICS.o : heuristics.c $(INCLUDEDIR)/heuristics.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $^

GENERATE.o : generate.c $(INCLUDEDIR)/generate.h
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $^
	
clean:
	@rm -f *.o ../include/*.gch ./hitori ../report/*.aux ../report/*.log ../report/*.out ../report/*.toc
	
test:
	
help:
	@echo "Targets:"
	@echo "hitori : generate the hitori binary file from the sources files"
	@echo "clean : remove all temporary files + binary file gererated by the compilation"
	@echo "help : display the targets of the Makefile with a short description"
	@echo "test : run a list of commands to test the software"

.PHONY: all clean help

