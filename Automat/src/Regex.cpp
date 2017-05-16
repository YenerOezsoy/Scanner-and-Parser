//
// Created by Yener on 27.03.2017.
//

#include "../includes/Regex.h"

Regex::Regex(void) {
    regex = 0;
}

Regex::~Regex(void) {
}

void Regex::setRegex(int regex) {
    this->regex=regex;
}

void Regex::setExclude(char exclude) {
    this->exclude = &exclude;
}

bool Regex::getResult(char* c) {
    if (checkExclude(c)) {

        switch (regex) {
            //Letter + Digit
            case 0:  return checkLD(c);
			//All
            case 1 : return checkAll(c);
        }
    }
    return false;
}

bool Regex::checkExclude(char* c) {
    if (exclude == c) {
        return false;
    }
    return true;
}

bool Regex::checkDigit(char* c) {
    switch (*c) {
        case '0': return true;
        case '1': return true;
        case '2': return true;
        case '3': return true;
        case '4': return true;
        case '5': return true;
        case '6': return true;
        case '7': return true;
        case '8': return true;
        case '9': return true;
        default: return false;
    }
}
bool Regex::checkLetter(char* c) {
    switch (*c) {
        case 'a': return true;
        case 'b': return true;
        case 'c': return true;
        case 'd': return true;
        case 'e': return true;
        case 'f': return true;
        case 'g': return true;
        case 'h': return true;
        case 'i': return true;
        case 'j': return true;
        case 'k': return true;
        case 'l': return true;
        case 'm': return true;
        case 'n': return true;
        case 'o': return true;
        case 'p': return true;
        case 'q': return true;
        case 'r': return true;
        case 's': return true;
        case 't': return true;
        case 'u': return true;
        case 'v': return true;
        case 'w': return true;
        case 'x': return true;
        case 'y': return true;
        case 'z': return true;
        case 'A': return true;
        case 'B': return true;
        case 'C': return true;
        case 'D': return true;
        case 'E': return true;
        case 'F': return true;
        case 'G': return true;
        case 'H': return true;
        case 'I': return true;
        case 'J': return true;
        case 'K': return true;
        case 'L': return true;
        case 'M': return true;
        case 'N': return true;
        case 'O': return true;
        case 'P': return true;
        case 'Q': return true;
        case 'R': return true;
        case 'S': return true;
        case 'T': return true;
        case 'U': return true;
        case 'V': return true;
        case 'W': return true;
        case 'X': return true;
        case 'Y': return true;
        case 'Z': return true;
        default: return false;
    }
}

bool Regex::checkSign(char* c) {
    switch (*c) {
        case '+': return true;
        case '-': return true;
        case ':': return true;
        case '*': return true;
        case '<': return true;
        case '>': return true;
        case '=': return true;
        case '!': return true;
        case '&': return true;
        case ';': return true;
        case '(': return true;
        case ')': return true;
        case '{': return true;
        case '}': return true;
        case '[': return true;
        case ']': return true;
        default: return false;
    }
}

bool Regex::checkLD(char* c) {
    return checkLetter(c) || checkDigit(c);
}

bool Regex::checkAll(char* c) {
    return checkDigit(c) || checkLetter(c) || checkSign(c);
}
