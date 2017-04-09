#ifndef Automat_H_
#define Automat_H_

#include "../includes/State.h"
//class State;

class Automat {
public:
    State* currentState = 0;
    Start *start = 0;
	Automat();
	virtual ~Automat();
    void handle(char* character);
    //int für Tokenizer, Buchstaben zählen
    int i;
};

#endif /* Automat_H_ */

