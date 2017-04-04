/*
 * Automat.h
 *
 *  Created on: Mar 22, 2017
 *      Author: kaok1012
 */



#ifndef Automat_H_
#define Automat_H_

//#include "../includes/State.h"
class State;

class Automat {
public:
    State* currentState;
    //Start start;
    /*State1 state1;
    State2 state2;
    State3 state3;
    State4 state4;
    State5 state5;
    State6 state6;
    State7 state7;
    State8 state8;
    State9 state9;
    State10 state10;
    State11 state11;
    State12 state12;
    State13 state13;
    State14 state14;
    State15 state15;
    State16 state16;
    State17 state17;
    State18 state18;
    State19 state19;
    State20 state20;
    State21 state21;
    State22 state22;
    State23 state23;
    State24 state24;
    State25 state25;
    State26 state26;
    State27 state27;
    State28 state28;
    State29 state29;
    State30 state30;
    State31 state31;
    State32 state32;
    Error error;*/
	Automat();
	virtual ~Automat();
    void handle();
    void setCurrentState(State* s);
};

#endif /* Automat_H_ */
