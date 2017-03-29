//
// Created by Yener on 27.03.2017.
//


#ifndef COMPILER_STATE_H
#define COMPILER_STATE_H

#include "../includes/State.h"
#include "../includes/Regex.h"

class State {
public: virtual void read(char c, AutomatOO* m=0);
    bool accepted;
    enum Type {Sign, Letter, If, While, Digit, None};
    Regex* r = new Regex();
};

class Start : public State {
    void Start::read(char c, AutomatOO *m) {
        if (r->checkDigit(c)) {
            m->setState(State1);
        }
        else if (r->checkLetter(c)) {
            switch (c) {
                case 'i':   m->setState(State3);
                    break;
                case 'I':   m->setSate(State5);
                    break;
                case 'w':   m->setSate(State7);
                    break;
                case 'W':   m->setState(State12);
                    break;
            }
        }
        else if (r->checkSign(c)){
            switch(c) {
                case '+':   m->setState(State17);
                    break;
                case '-':   m->setSate(State18);
                    break;
                case ':':   m->setSate(State19);
                    break;
                case '*':   m->setState(State21);
                    break;
                case '<':   m->setState(State22);
                    break;
                case '>':   m->setSate(State23);
                    break;
                case '=':   m->setSate(State24);
                    break;
                case '!':   m->setState(State27);
                    break;
                case '&':   m->setState(State28);
                    break;
                case ';':   m->setSate(State30);
                    break;
                case '(':   m->setSate(State31);
                    break;
                case ')':   m->setState(State32);
                    break;
                case '{':   m->setState(State33);
                    break;
                case '}':   m->setSate(State34);
                    break;
                case '[':   m->setSate(State35);
                    break;
                case ']':   m->setState(State36);
                    break;
            }
        }
    }
    Type type = Type.None;
    accepted = false;
};

class State1 : public State {
    void Start::read(char c, AutomatOO *m) {
        if (r->checkDigit(c)) {
            m->setState(State1);
        }
        else {
            m->setState(Error);
        }
    }
    Type type = Type.Digit;
    accepted = true;
};

class State2 : public State {
    void Start::read(char c, AutomatOO *m) {
        if(r->checkLD(c)) {
            m->setState(State2);
        }
        else {
            m->setState(Error);
        }
    }
    Type type = Type.Letter;
    accepted = true;
};

class State3 : public State {
    void Start::read(char c, AutomatOO *m) {
        r->setRegex(0);
        /*
        char carray[1] = {'f'};
        char* cpointer;
        r->setExclude(cpointer);*/
        r->setExclude('f');
        //Wechsel State4
        if (c == 'f'){
            m->setState(State4);
        }
            //Wechsel zu State2
        else if (r->getResult(c)) {
            m->setState(State2);
        }
            //Wechsel Error
        else {
            m->setState(Error);
        }
    }
    Type type = Type.Letter;
    accepted = true;
};

class State4 : public State {
    void Start::read(char c, AutomatOO *m) {
        r->setRegex(0);
        r->setExclude('');
        if (r->getResult(c)) {
            m->setState(State2);
        }
        else {
            m->setState(Error);
        }
    }
    Type type = Type.If;
    accepted = true;
};

class State5 : public State {
    void Start::read(char c, AutomatOO *m) {
        r->setRegex(0);
        /*
        char carray[1] = {'F'};
        char* cpointer;
        r->setExclude(cpointer);*/
        r->setExclude('F');
        if (c == 'F'){
            m->setState(State6);
        }
        else if (r->getResult(c)) {
            m->setState(State2);
        }
        else {
            m->setState(Error);
        }
    }
    Type type = Type.Identifier;
    accepted = true;
};

class State6 : public State {
    void Start::read(char c, AutomatOO *m) {
        r->setRegex(0);
        r->setExclude('');
        if (r->getResult(c)) {
            m->setState(State2);
        }
        else {
            m->setState(Error);
        }
    }
    accepted = true;
    Type type = Type.If;
};

class State7 : public State {
    void Start::read(char c, AutomatOO *m) {
        r->setRegex(0);
        r->setExclude('h');
        if (c == 'h'){
            m->setState(State8);
        }
        else if (r->getResult(c)) {
            m->setState(State2);
        }
        else {
            m->setState(Error);
        }
    }
    accepted = true;
    Type type = Type.Identifier;
};

class State8 : public State {
    void Start::read(char c, AutomatOO *m) {
        r->setRegex(0);
        r->setExclude('i');
        if (c == 'i'){
            m->setState(State9);
        }
        else if (r->getResult(c)) {
            m->setState(State2);
        }
        else {
            m->setState(Error);
        }
    }
    accepted = true;
    Type type = Type.Identifier;
};

class State9 : public State {
    void Start::read(char c, AutomatOO *m) {
        r->setRegex(0);
        r->setExclude('l');
        if (c == 'l'){
            m->setState(State10);
        }
        else if (r->getResult(c)) {
            m->setState(State2);
        }
        else {
            m->setState(Error);
        }
    }
    accepted = true;
    Type type = Type.Identifier;
};

class State10 : public State {
    void Start::read(char c, AutomatOO *m) {
        r->setRegex(3);
        r->setExclude('e');
        if (c == 'e'){
            m->setState(State11);
        }
        else if (r->getResult(c)) {
            m->setState(State2);
        }
        else {
            m->setState(Error);
        }
    }
    accepted = true;
    Type type = Type.Identifier;
};

class State11 : public State {
    void Start::read(char c, AutomatOO *m) {
        //nach while weiteres Zeichen(Letter oder Digit) -> Letter!
        r->setExclude('');
        r->setRegex(0);
        if (r->getResult(c)) {
            m->setState(State2);
        }
            //Sign
        else {
            m->setState(Error);
        }
    }
    accepted = true;
    Type type = Type.While;
};

class State12 : public State {
    void Start::read(char c, AutomatOO *m) {
        r->setRegex(0);
        r->setExclude('H');
        if (c == 'H'){
            m->setState(State13);
        }
        else if (r->getResult(c)) {
            m->setState(State2);
        }
        else {
            m->setState(Error);
        }
    }
    accepted = true;
    Type type = Type.Identifier;
};

class State13 : public State {
    void Start::read(char c, AutomatOO *m) {
        r->setRegex(0);
        r->setExclude('I');
        if (c == 'I'){
            m->setState(State14);
        }
        else if (r->getResult(c)) {
            m->setState(State2);
        }
        else {
            m->setState(Error);
        }
    }
    accepted = true;
    Type type = Type.Identifier;
};

class State14 : public State {
    void Start::read(char c, AutomatOO *m) {
        r->setRegex(0);
        r->setExclude('L');
        if (c == 'L'){
            m->setState(State15);
        }
        else if (r->getResult(c)) {
            m->setState(State2);
        }
        else {
            m->setState(Error);
        }
    }
    accepted = true;
    Type type = Type.Identifier;
};

class State15 : public State {
    void Start::read(char c, AutomatOO *m) {
        r->setRegex(0);
        r->setExclude('E');
        if (c == 'E'){
            m->setState(State16);
        }
        else if (r->getResult(c)) {
            m->setState(State2);
        }
        else {
            m->setState(Error);
        }
    }
    accepted = true;
    Type type = Type.Identifier;
};

class State16 : public State {
    void Start::read(char c, AutomatOO *m) {
        //nach WHILE weiteres Zeichen(Letter oder Digit) -> Letter!
        r->setExclude('');
        r->setRegex(0);
        if (r->getResult(c)) {
            m->setState(State2);
        }
            //Sign
        else {
            m->setState(Error);
        }
    }
    accepted = true;
    Type type = Type.While;
};

class State17 : public State {
    void Start::read(char c, AutomatOO *m) {
        r->setRegex(1);
        r->setExclude('');
        if (r->getResult(c)) {
            m->setState(Error);
        }
    }
    accepted = true;
    Type type = Type.Sign;
};

class State18 : public State {
    void Start::read(char c, AutomatOO *m) {
        r->setRegex(1);
        r->setExclude('');
        if (r->getResult(c)) {
            m->setState(Error);
        }
    }
    accepted = true;
    Type type = Type.Sign;
};

class State19 : public State {
    void Start::read(char c, AutomatOO *m) {
        r->setRegex(1);
        r->setExclude('');
        if (c == '=') {
            m->setState(State20);
        }
        else {
            m->setState(Error);
        }
    }
    accepted = true;
    Type type = Type.Sign;
};

class State20 : public State {
    void Start::read(char c, AutomatOO *m) {
        r->setRegex(1);
        r->setExclude('');
        if (r->getResult(c)) {
            m->setState(Error);
        }
    }
    accepted = true;
    Type type = Type.Sign;
};

class State21 : public State {
    void Start::read(char c, AutomatOO *m) {
        r->setRegex(1);
        r->setExclude('');
        if (r->getResult(c)) {
            m->setState(Error);
        }
    }
    accepted = true;
    Type type = Type.Sign;
};

class State22 : public State {
    void Start::read(char c, AutomatOO *m) {
        r->setRegex(1);
        r->setExclude('');
        if (r->getResult(c)) {
            m->setState(Error);
        }
    }
    accepted = true;
    Type type = Type.Sign;
};

class State23 : public State {
    void Start::read(char c, AutomatOO *m) {
        r->setRegex(1);
        r->setExclude('');
        if (r->getResult(c)) {
            m->setState(Error);
        }
    }
    accepted = true;
    Type type = Type.Sign;
};

class State24 : public State {
    void Start::read(char c, AutomatOO *m) {
        r->setRegex(1);
        r->setExclude('');
        if (c == ':') {
            m->setState(State25);
        }
        else {
            m->setState(Error);
        }
    }
    accepted = true;
    Type type = Type.Sign;
};

class State25 : public State {
    void Start::read(char c, AutomatOO *m) {
        r->setRegex(1);
        r->setExclude('');
        if (c == '=') {
            m->setState(State26);
        }
        else {
            m->setState(Error);
        }
    }
    accepted = false;
    Type type = Type.Sign;
};

class State26 : public State {
    void Start::read(char c, AutomatOO *m) {
        r->setRegex(1);
        r->setExclude('');
        if (r->getResult(c)) {
            m->setState(Error);
        }
    }
    accepted = true;
    Type type = Type.Sign;
};

class State27 : public State {
    void Start::read(char c, AutomatOO *m) {
        r->setRegex(1);
        r->setExclude('');
        if (r->getResult(c)) {
            m->setState(Error);
        }
    }
    accepted = true;
    Type type = Type.Sign;
};

class State28 : public State {
    void Start::read(char c, AutomatOO *m) {
        r->setRegex(1);
        r->setExclude('');
        if (c == '&') {
            m->setState(State29);
        }
        else {
            m->setState(Error);
        }
    }
    accepted = false;
    Type type = Type.Sign;
};

class State29 : public State {
    void Start::read(char c, AutomatOO *m) {
        r->setRegex(1);
        r->setExclude('');
        if (r->getResult(c)) {
            m->setState(Error);
        }
    }
    accepted = true;
    Type type = Type.Sign;
};

class State30 : public State {
    void Start::read(char c, AutomatOO *m) {
        r->setRegex(1);
        r->setExclude('');
        if (r->getResult(c)) {
            m->setState(Error);
        }
    }
    accepted = true;
    Type type = Type.Sign;
};

class State31 : public State {
    void Start::read(char c, AutomatOO *m) {
        r->setRegex(1);
        r->setExclude('');
        if (r->getResult(c)) {
            m->setState(Error);
        }
    }
    accepted = true;
    Type type = Type.Sign;
};

class State32 : public State {
    void Start::read(char c, AutomatOO *m) {
        r->setRegex(1);
        r->setExclude('');
        if (r->getResult(c)) {
            m->setState(Error);
        }
    }
    accepted = true;
    Type type = Type.Sign;
};

class Error : public State {
    void Start::read(char c, AutomatOO *m) {
        r->setRegex(1);
        r->setExclude('');
        if (r->getResult(c)) {
            m->setState(Error);
        }
    }
    accepted = false;
    Type type = Type.None;
};


#endif //COMPILER_STATE_H
