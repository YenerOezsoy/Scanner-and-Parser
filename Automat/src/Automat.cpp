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
        if (character[i] == ' ' & currentState->type != 6) {
            i++;
            currentState = start;
            std::cout << "____________" << std::endl;
        }
        else if (character[i] == ' '){
            i++;
            std::cout << "____________" << std::endl;
        }
        currentState = currentState->read(character[i]);
        std::cout << "State accepted: " << currentState->accepted << " Type: " << currentState->type << " Buchstabe: " << character[i]<< std::endl;
        i++;
    }
}
