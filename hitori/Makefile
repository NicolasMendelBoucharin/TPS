all:
	@(cd ./src; make all; mv hitori ..)

report :

	@(cd src; make report)
clean:
	@(rm hitori; cd src; make clean)
	
test:
	@./hitori
help:
	@echo "Targets:"
	@echo "clean : remove all temporary files + binary file gererated by the compilation"
	@echo "help : display the targets of the Makefile with a short description"
	@echo "test : run a list of commands to test the software"
	@echo "report : compile a report"
	#faire attention à bien prendre les commandes possibles juste pour le make à la racine
.PHONY: all clean help

