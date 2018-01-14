#
#	baut das komplette Scanner Projekt
#
OBJDIR = objs

AUTOMATDIR = Automat

BUFFERDIR = Buffer

SYMBOLTABELLEDIR = Symboltabelle

SCANNERDIR = Scanner

PARSERDIR = Parser


all:	automatOBJs bufferOBJs symboltabelleOBJs scanner parser  
	@echo "target all"

	
# rm 	remove
# -f	force, ohne nachfragen
clean:
	rm -f $(AUTOMATDIR)/$(OBJDIR)/*.o
	rm -f $(BUFFERDIR)/$(OBJDIR)/*.o
	rm -f $(SYMBOLTABELLEDIR)/$(OBJDIR)/*.o
	rm -f $(SCANNERDIR)/$(OBJDIR)/*.o
	rm -f $(SCANNERDIR)/debug/*
	rm -f $(PARSERDIR)/$(OBJDIR)/*.o
	rm -f $(PARSERDIR)/debug/*
	

automatOBJs:
	$(MAKE) -C $(AUTOMATDIR) AutomatOBJTarget
	

bufferOBJs:
	$(MAKE) -C $(BUFFERDIR) BufferOBJTarget

	
symboltabelleOBJs:
	$(MAKE) -C $(SYMBOLTABELLEDIR) SymboltabelleOBJTarget
	

scanner: 
	$(MAKE) -C $(SCANNERDIR) makeTestScanner

parser:
	$(MAKE) -C $(PARSERDIR) makeTestParser
	