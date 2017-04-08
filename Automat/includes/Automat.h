#ifndef Automat_H_
#define Automat_H_

#include "../includes/State.h"
//class State;

class Automat {
public:
    State* currentState;
    Start *start;
	Automat();
	virtual ~Automat();
    void handle(char* character);
    //char Array und int für Tokenizer
    int i;
};

#endif /* Automat_H_ */

