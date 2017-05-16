#ifndef Automat_H_
#define Automat_H_

#include "../includes/State.h"

class Automat {
public:
	State* currentState;
	Start *start;
	Automat();
	virtual ~Automat();
	int handle(char* character);
	int reset();
	bool getAcceptance();
};

#endif /* Automat_H_ */

