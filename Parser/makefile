# Definition der Variablen

# enthaelt die Header Files
HEADERDIR = includes

# enthaelt die Source Files
SRCDIR = src

# enthaelt die Obj Files zum Testen
OBJDIR = objs

# enthaelt das ausfuehrbare File zum Testen
BINDIRTEST = debug


AUTOMATDIR = ../Automat

BUFFERDIR = ../Buffer

SCANNERDIR = ../Scanner

SYMBOLTABELLEDIR = ../Symboltabelle


## hier alle Object Files eintragen, ausser das File mit der Mainmethode
## darauf achten, dass letzte Zeile ohne "\" eingetragen wird

OBJS = $(OBJDIR)/Parser.o \
	   $(OBJDIR)/ParseTree.o \
	   $(OBJDIR)/ParseTreeNode.o


## Variante mit wenig Makefile-Kenntnissen
# 
## linken der Object-files 
#makeTestScanner: $(OBJDIR)/Scanner.o $(OBJDIR)/TestScanner.o
#	g++ -g $(OBJDIR)/Scanner.o $(OBJDIR)/TestScanner.o   $(PROJECTOBJDIR)/Automat/*.o $(PROJECTOBJDIR)/Buffer/*.o $(PROJECTOBJDIR)/Symboltable/*.o -o $(BINDIRTEST)/ScannerTest
##	
##	
##	
### compilieren der source-files
#$(OBJDIR)/Scanner.o :  $(SRCDIR)/Scanner.cpp $(HEADERDIR)/Scanner.h
#	@echo "g++ $*.cpp"
#	g++ -g  -c -Wall  -o $(OBJDIR)/Scanner.o  $(SRCDIR)/Scanner.cpp
#	cp $(OBJDIR)/Scanner.o $(PROJECTOBJDIR)/Scanner
##
#$(OBJDIR)/TestScanner.o :  $(SRCDIR)/TestScanner.cpp 
#	@echo "g++ $*.cpp"
#	g++ -g  -c -Wall  -o $(OBJDIR)/TestScanner.o  $(SRCDIR)/TestScanner.cpp
#
	
	
# Variante mit guten Makefile-Kenntnissen
makeTestParser: ParseTreeTarget ParseTreeNodeTarget ParserTarget ParserTest

ParseTreeTarget :  src/ParseTree.cpp includes/ParseTree.h 
	g++ -g  -c -Wall src/ParseTree.cpp -o objs/ParseTree.o  

ParseTreeNodeTarget :  src/ParseTreeNode.cpp includes/ParseTreeNode.h 
	g++ -g  -c -Wall src/ParseTreeNode.cpp -o objs/ParseTreeNode.o  

ParserTarget :  src/Parser.cpp includes/Parser.h 
	g++ -g  -c -Wall src/Parser.cpp -o objs/Parser.o  
# 
# $@ name des object files
# $< erste abhaengigkeit


ParserTest: $(SRCDIR)/TestParser.cpp $(HEADERDIR)/Parser.h
	g++ -g -std=gnu++11 -c -Wall src/TestParser.cpp -o $(BINDIRTEST)/TestParser.o  
	g++ -g $(BINDIRTEST)/TestParser.o $(OBJDIR)/*.o $(AUTOMATDIR)/$(OBJDIR)/*.o $(BUFFERDIR)/$(OBJDIR)/*.o $(SCANNERDIR)/$(OBJDIR)/*.o $(SYMBOLTABELLEDIR)/$(OBJDIR)/*.o -o $(BINDIRTEST)/ParserTest

# loeschen aller files im verzeichnis $(OBJDIR) und $(BINDIRTEST) und neu erstellen

cleanParser:
	rm -rf $(OBJDIR)/*.o
	rm -rf $(BINDIRTEST)/*
	$(MAKE) makeTestParser
