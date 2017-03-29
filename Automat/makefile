# Definition der Variablen

# enthaelt die Header Files
HEADERDIR = includes

# enthaelt die Source Files
SRCDIR = src

# enthaelt die Obj Files fuer das Gesamtprojekt
OBJDIR = objs

# enthaelt die Objectfiles und das ausfuehrbare File zum Testen des Teilprojekts
BINDIRTEST = debug

#
#		Targets zum Bauen des Tests
#

# Linken der Object-files, abhaengig von AutomatTarget und TestAutomatTarget
# flag:
# -g --> debug Informationen erzeugen
# -o --> name des output-files

makeTestAutomat: AutomatTarget TestAutomatTarget  
	g++ -g $(OBJDIR)/Automat.o $(BINDIRTEST)/TestAutomat.o -o $(BINDIRTEST)/AutomatTest
	

# compilieren des Files Automat.cpp zu Automat.o, 
# das Objekt-File ist abhängig von src/Automat.cpp und src/Automat.h
# flag:
# -c --> nur compilieren
# -g --> debug Informationen erzeugen
# -Wall --> alle meldungen erzeugen (Warning all)

AutomatTarget :  $(SRCDIR)/Automat.cpp $(HEADERDIR)/Automat.h 
	g++ -g  -c -Wall $(SRCDIR)/Automat.cpp -o $(OBJDIR)/Automat.o  


# TestAutomat.o ist abhängig von src/TestAutomat.cpp und src/Automat.h
TestAutomatTarget :  $(SRCDIR)/TestAutomat.cpp $(HEADERDIR)/Automat.h
	g++ -g  -c -Wall $(SRCDIR)/TestAutomat.cpp  -o $(BINDIRTEST)/TestAutomat.o  



# loeschen aller files im verzeichnis obj und debug, dann neu erzeugen

cleanAutomat:
	rm -f $(OBJDIR)/*.o
	rm -f $(BINDIRTEST)/*
	$(MAKE) makeTestAutomat
	
	
# dieses Target wird vom makefile des Gesamtprojekts verwendet
# objs fuer Gesamtprojekt loeschen und dann neu erzeugen
AutomatOBJTarget:
	$(MAKE) makeTestAutomat
