/*
 * Created by Yener on 27.03.2017.
 */

#include "../includes/Automat.h"
#include <iostream>


Automat::Automat() {
    start = new Start();
    currentState = start;
}

Automat::~Automat() {
    // TODO Auto-generated destructor stub
}


void Automat::handle(char* character) {
	i = 0;
	    while (character[i] != '\0') {

	        //Leerzeichen trennen Lexeme, currentState wieder auf Start
	        if (character[i] == ' ' & currentState->type != 6) {
	            i++;
	            currentState = start;
	            std::cout << "____________ Trennzeichen" << std::endl;
	        }

	        // Leerzeichen bei Kommentaren ignorieren, currentState nicht zurücksetzen
	        else if (character[i] == ' ') {
	            i++;
	            std::cout << "____________ Kommentar" << std::endl;
	        }


	        currentState = currentState->read(character[i]);
	        std::cout << "State accepted: " << currentState->accepted << " Type: " << currentState->type << " Buchstabe: " << character[i]<< std::endl;

	        //Fehlerzustand erkennen und auf Start zurücksetzen
	        if (currentState->read(character[i + 1])->type == 5 && character[i + 1] != ' ') {
	            currentState = start;
	            std::cout << "____________ Fehler" << std::endl;
	        }

	        i++;
	    }
}
