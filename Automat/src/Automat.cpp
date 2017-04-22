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


int Automat::handle(char* character) {
	    //Leerzeichen ignorieren wenn kein Kommentar
	    if (*character == ' ' && currentState-> type != 6) {
	        currentState = currentState->read(character);
	        return currentState->type;
	    }
	    //Leerzeichen in Kommentaren überspringen
	    else if (*character == ' ' && currentState-> type == 6) {
	        return currentState->type;
	    }
	    else {
	        currentState = currentState->read(character);
	        return currentState->type;
	    }
}
