/*
 * Created by Yener on 27.03.2017.
 */

#include "../../Automat/includes/Automat.h"
#include "../includes/State.h"


Automat::Automat() {
	// TODO Auto-generated constructor stub
    start = new Start();
    state1 = new State1();
    state2 = new State2();
    state3 = new State3();
    state4 = new State4();
    state5 = new State5();
    state6 = new State6();
    state7 = new State7();
    state8 = new State8();
    state9 = new State9();
    state10 = new State10();
    state11 = new State11();
    state12 = new State12();
    state13 = new State13();
    state14 = new State14();
    state15 = new State15();
    state16 = new State16();
    state17 = new State17();
    state18 = new State18();
    state19 = new State19();
    state20 = new State20();
    state21 = new State21();
    state22 = new State22();
    state23 = new State23();
    state24 = new State24();
    state25 = new State25();
    state26 = new State26();
    state27 = new State27();
    state28 = new State28();
    state29 = new State29();
    state30 = new State30();
    state31 = new State31();
    state32 = new State32();
    error = new Error();
    currentState = start;
}

Automat::~Automat() {
	// TODO Auto-generated destructor stub
}


void Automat::handle() {
    char test[] = {'i','f', '\0'};
    int i = 0;
    while (test[i] != '\0') {
        currentState.read(test[i]);
    }
}

void Automat::setCurrentState(State s) {
    this->currentState = s;
}