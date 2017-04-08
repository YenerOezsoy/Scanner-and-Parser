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


void Automat::handle() {
    char test[] = {'W', 'H', 'I', 'L', 'e', '\0'};
    int i = 0;
    while (test[i] != '\0') {
        currentState = currentState->read(test[i]);
        std::cout << "State accepted: " << currentState->accepted << " Type: " << currentState->type <<std::endl;
        i++;
    }


}
