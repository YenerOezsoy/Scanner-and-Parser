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
	int handle(char* character);
};

#endif /* Automat_H_ */

