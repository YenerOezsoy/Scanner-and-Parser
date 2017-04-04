/*
 * Created by Yener on 27.03.2017.
 */

#include "../../Automat/includes/Automat.h"
#include "../includes/State.h"
#include <iostream>


Automat::Automat() {

    /*state1 =  State1();
    state2 =  State2();
    state3 =  State3();
    state4 =  State4();
    state5 =  State5();
    state6 =  State6();
    state7 =  State7();
    state8 =  State8();
    state9 =  State9();
    state10 =  State10();
    state11 =  State11();
    state12 =  State12();
    state13 =  State13();
    state14 =  State14();
    state15 =  State15();
    state16 =  State16();
    state17 =  State17();
    state18 =  State18();
    state19 =  State19();
    state20 =  State20();
    state21 =  State21();
    state22 =  State22();
    state23 =  State23();
    state24 =  State24();
    state25 =  State25();
    state26 = State26();
    state27 =  State27();
    state28 =  State28();
    state29 =  State29();
    state30 =  State30();
    state31 =  State31();
    state32 =  State32();
    error =  Error();*/
    *currentState = start;
}

Automat::~Automat() {
	// TODO Auto-generated destructor stub
}


void Automat::handle() {
    char test[] = {'i','f', '\0'};
    int i = 0;
    std::cout << "test2" << std::endl;
    while (test[i] != '\0') {
        currentState = currentState->read(test[i]);
    }


}

void Automat::setCurrentState(State* s) {
   *currentState = *s;
}
