#
#		Targets zum Bauen des Tests
#

# Linken der Object-files, abhaengig von AutomatTarget und TestAutomatTarget
# flag:
# -g --> debug Informationen erzeugen
# -o --> name des output-files

makeTestAutomat: AutomatTarget TestAutomatTarget  
	g++ -g objs/Automat.o debug/TestAutomat.o -o debug/AutomatTest
	

# compilieren des Files Automat.cpp zu Automat.o, 
# das Objekt-File ist abhängig von src/Automat.cpp und src/Automat.h
# flag:
# -c --> nur compilieren
# -g --> debug Informationen erzeugen
# -Wall --> alle meldungen erzeugen (Warning all)

AutomatTarget :  src/Automat.cpp includes/Automat.h 
	g++ -g  -c -Wall src/Automat.cpp -o objs/Automat.o  

StateTarget :  src/State.cpp includes/State.h includes/Regex.h
	g++ -g  -c -Wall src/State.cpp -o objs/State.o

RegexTarget :  src/Regex.cpp includes/Regex.h
	g++ -g  -c -Wall src/Regex.cpp -o objs/Regex.o
	
# TestAutomat.o ist abhängig von src/TestAutomat.cpp und src/Automat.h
TestAutomatTarget :  src/TestAutomat.cpp includes/Automat.h
	g++ -g  -c -Wall src/TestAutomat.cpp  -o debug/TestAutomat.o  



# loeschen aller files im verzeichnis obj und debug, dann neu erzeugen

cleanAutomat:
	rm -f objs/*.o
	rm -f debug/*
	$(MAKE) makeTestAutomat
	
	
# dieses Target wird vom makefile des Gesamtprojekts verwendet
# objs fuer Gesamtprojekt loeschen und dann neu erzeugen
AutomatOBJTarget:
	$(MAKE) AutomatTarget
	$(MAKE) StateTarget
	$(MAKE) RegexTarget

