//
// Created by Yener on 27.03.2017.
//


#ifndef COMPILER_STATE_H
#define COMPILER_STATE_H


#include "../includes/Regex.h"
//#include "../includes/Automat.h"

//class Automat;

class State {
public:
		//State(){};
		virtual State* read(char c) = 0;
		virtual ~State() {};
		//bool accepted;
    	//enum Type {Sign, Letter, If, While, Digit, None };
    	Regex r;// = Regex();
};
class Start : public State {
	State* read(char c );/* {
        if (r.checkDigit(c)) {
        	State1* state1 = new State1();
            m->setCurrentState(state1);
        }
        else if (r.checkLetter(c)) {
            switch (c) {
                case 'i': 	State3* state3 = new State3();
                			m->setCurrentState(state3);
                			break;
                case 'I': 	State5* state5 = new State5();
                			m->setCurrentState(state5);
                			break;
                case 'w': 	State7* state7 = new State7();
                			m->setCurrentState(state7);
                			break;
                case 'W':   State12* state12 = new State12();
                			m->setCurrentState(state12);
                			break;
            }
        }
        else if (r.checkSign(c)){
            switch(c) {
                case '+':   State17* state17 = new State17();
                			m->setCurrentState(state17);
                			break;
                case '-':   State18* state18 = new State18();
                			m->setCurrentState(state18);
                			break;
                case ':':   State19* state19 = new State19();
                			m->setCurrentState(state19);
                			break;
                case '*':   State21* state21 = new State21();
                			m->setCurrentState(state21);
                			break;
                case '<':   State22* state22 = new State22();
                			m->setCurrentState(state22);
                			break;
                case '>':   State23* state23 = new State23();
                			m->setCurrentState(state23);
                			break;
                case '=':   State24* state24 = new State24();
                			m->setCurrentState(state24);
                			break;
                case '!':   State27* state27 = new State27();
                			m->setCurrentState(state27);
                			break;
                case '&':   State28* state28 = new State28();
                			m->setCurrentState(state28);
                			break;
                case ';':   State30* state30 = new State30();
                			m->setCurrentState(state30);
                			break;
                case '(':   State31* state31 = new State31();
                			m->setCurrentState(state31);
                			break;
                case ')':   State32* state32 = new State32();
                			m->setCurrentState(state32);
                			break;
                case '{':   State33* state33 = new State33();
                			m->setCurrentState(state33);
                			break;
                case '}':   State34* state34 = new state34();
                			m->setCurrentState(state34);
                			break;
                case '[':   State35* state35 = new State35();
                			m->setCurrentState(state35);
                			break;
                case ']':   State36* state36 = new State36();
                			m->setCurrentState(state36);
                			break;
            }
        }
    }
    Type type = Type.None;
    //accepted = false;
*/

};

class State1 : public State {
    State* read(char c );// {
     /*   if (r.checkDigit(c)) {
        	State1* state1 = new State1();
            m->setCurrentState(state1);
        }
        else {
        	Error* error = new Error();
            m->setCurrentState(error);
        }
    }
    Type type = Type.Digit;
    accepted = 1;
*/ };

class State2 : public State {
    State* read(char c );/* {
        if(r.checkLD(c)) {
        	State2* state2 = new State2();
            m->setCurrentState(state2);
        }
        else {
        	Error* error = new Error();
            m->setCurrentState(error);
        }
    }
    Type type = Type.Letter;
    accepted = true;

*/
};

class State3 : public State {
    State* read(char c ); /*{
        r.setRegex(0);
        r.setExclude('f');
        //Wechsel State4
        if (c == 'f'){
        	State4* state4 = new State4();
            m->setCurrentState(state4);
        }
            //Wechsel zu State2
        else if (r.getResult(c)) {
        	State2* state2 = new State2();
            m->setCurrentState(state2);
        }
            //Wechsel Error
        else {
        	Error* error = new Error();
            m->setCurrentState(error);
        }
    }
    Type type = Type.Letter;
    accepted = true;
*/ };

class State4 : public State {
    State* read(char c ); /*{
        r.setRegex(0);
        r.setExclude('');
        if (r.getResult(c)) {
        	State2* state2 = new State2();
            m->setCurrentState(state2);
        }
        else {
        	Error* error = new Error();
            m->setCurrentState(error);
        }
    }
    Type type = Type.If;
    accepted = true;
*/ };

class State5 : public State {
    State* read(char c ); /*{
        r.setRegex(0);

        char carray[1] = {'F'};
        char* cpointer;
        r.setExclude(cpointer);
        r.setExclude('F');
        if (c == 'F'){
        	State6* state6 = new State6();
            m->setCurrentState(state6);
        }
        else if (r.getResult(c)) {
        	State2* state2 = new State2();
            m->setCurrentState(state2);
        }
        else {
        	Error* error = new Error();
            m->setCurrentState(error);
        }
    }
    Type type = Type.Identifier;
    accepted = true;*/
 };

class State6 : public State {
    State* read(char c ); /*{
        r.setRegex(0);
        r.setExclude('');
        if (r.getResult(c)) {
        	State2* state2 = new State2();
            m->setCurrentState(state2);
        }
        else {
        	Error* error = new Error();
            m->setCurrentState(error);
        }
    }
    accepted = true;
    Type type = Type.If;
*/ };

class State7 : public State {
    State* read(char c ); /*{
        r.setRegex(0);
        r.setExclude('h');
        if (c == 'h'){
        	State8 state8 = new State8();
            m->setCurrentState(state8);
        }
        else if (r.getResult(c)) {
        	State2* state2 = new State2();
            m->setCurrentState(state2);
        }
        else {
        	Error* error = new Error();
            m->setCurrentState(error);
        }
    }
    accepted = true;
    Type type = Type.Identifier;
*/ };

class State8 : public State {
    State* read(char c ); /*{
        r.setRegex(0);
        r.setExclude('i');
        if (c == 'i'){
        	State9* state9 = new State9();
            m->setCurrentState(state9);
        }
        else if (r.getResult(c)) {
        	State2* state2 = new State2();
            m->setCurrentState(state2);
        }
        else {
        	Error* error = new Error();
            m->setCurrentState(error);
        }
    }
    accepted = true;
    Type type = Type.Identifier;
*/ };

class State9 : public State {
    State* read(char c ); /*{
        r.setRegex(0);
        r.setExclude('l');
        if (c == 'l'){
        	State10* state10 = new State10();
            m->setCurrentState(state10);
        }
        else if (r.getResult(c)) {
        	State2* state2 = new State2();
            m->setCurrentState(state2);
        }
        else {
        	Error* error = new Error();
            m->setCurrentState(error);
        }
    }
    accepted = true;
    Type type = Type.Identifier;
*/ };

class State10 : public State {
    State* read(char c ); /*{
        r.setRegex(3);
        r.setExclude('e');
        if (c == 'e'){
        	State11* state11 = new State11();
            m->setCurrentState(state11);
        }
        else if (r.getResult(c)) {
        	State2* state2 = new State2();
            m->setCurrentState(state2);
        }
        else {
        	Error* error = new Error();
            m->setCurrentState(error);
        }
    }
    accepted = true;
    Type type = Type.Identifier;
*/ };

class State11 : public State {
    State* read(char c );/* {
        //nach while weiteres Zeichen(Letter oder Digit) -> Letter!
        r.setExclude('');
        r.setRegex(0);
        if (r.getResult(c)) {
        	State2* state2 = new State2();
            m->setCurrentState(state2);
        }
            //Sign
        else {
        	Error* error = new Error();
            m->setCurrentState(error);
        }
    }
    accepted = true;
    Type type = Type.While;
*/ };

class State12 : public State {
    State* read(char c );/* {
        r.setRegex(0);
        r.setExclude('H');
        if (c == 'H'){
        	State13* state13 = new State13();
            m->setCurrentState(state13);
        }
        else if (r.getResult(c)) {
        	State2 state2 = new State2();
            m->setCurrentState(state2);
        }
        else {
        	Error* error = new Error();
            m->setCurrentState(error);
        }
    }
    accepted = true;
    Type type = Type.Identifier;
*/ };

class State13 : public State {
    State* read(char c ); /*{
        r.setRegex(0);
        r.setExclude('I');
        if (c == 'I'){
        	State14* state14 = new State14();
            m->setCurrentState(state14);
        }
        else if (r.getResult(c)) {
        	State2 state2 = new State2();
            m->setCurrentState(state2);
        }
        else {
        	Error* error = new Error();
            m->setCurrentState(error);
        }
    }
    accepted = true;
    Type type = Type.Identifier;
*/ };

class State14 : public State {
    State* read(char c ); /*{
        r.setRegex(0);
        r.setExclude('L');
        if (c == 'L'){
        	State15* state15 = new State15();
            m->setCurrentState(state15);
        }
        else if (r.getResult(c)) {
        	State2* state2 = new State2();
            m->setCurrentState(state2);
        }
        else {
        	Error* error = new Error();
            m->setCurrentState(error);
        }
    }
    accepted = true;
    Type type = Type.Identifier;
*/ };

class State15 : public State {
    State* read(char c ); /*{
        r.setRegex(0);
        r.setExclude('E');
        if (c == 'E'){
        	State16* state16 = new State16();
            m->setCurrentState(state16);
        }
        else if (r.getResult(c)) {
        	State2* state2 = new State2();
            m->setCurrentState(state2);
        }
        else {
        	Error* error = new Error();
            m->setCurrentState(error);
        }
    }
    accepted = true;
    Type type = Type.Identifier;
*/ };

class State16 : public State {
    State* read(char c ); /*{
        //nach WHILE weiteres Zeichen(Letter oder Digit) -> Letter!
        r.setExclude('');
        r.setRegex(0);
        if (r.getResult(c)) {
        	State2* state2 = new State2();
            m->setCurrentState(state2);
        }
            //Sign
        else {
        	Error* error = new Error();
            m->setCurrentState(error);
        }
    }
    accepted = true;
    Type type = Type.While;
*/ };

class State17 : public State {
    State* read(char c ); /*{
        r.setRegex(1);
        r.setExclude('');
        if (r.getResult(c)) {
        	Error* error = new Error();
            m->setCurrentState(error);
        }
    }
    accepted = true;
    Type type = Type.Sign;
*/ };

class State18 : public State {
    State* read(char c ); /*{
        r.setRegex(1);
        r.setExclude('');
        if (r.getResult(c)) {
        	Error* error = new Error();
            m->setCurrentState(error);
        }
    }
    accepted = true;
    Type type = Type.Sign;
*/ };

class State19 : public State {
    State* read(char c );/* {
        r.setRegex(1);
        r.setExclude('');
        if (c == '=') {
        	State20* state20 = new State20();
            m->setCurrentState(state20);
        }
        else {
        	Error* error = new Error();
            m->setCurrentState(error);
        }
    }
    accepted = true;
    Type type = Type.Sign;
*/ };

class State20 : public State {
    State* read(char c ) ;/*{
        r.setRegex(1);
        r.setExclude('');
        if (r.getResult(c)) {
        	Error* error = new Error();
            m->setCurrentState(error);
        }
    }
    accepted = true;
    Type type = Type.Sign;
*/ };

class State21 : public State {
    State* read(char c ) ;/*{
        r.setRegex(1);
        r.setExclude('');
        if (r.getResult(c)) {
        	Error* error = new Error();
            m->setCurrentState(error);
        }
    }
    accepted = true;
    Type type = Type.Sign;
*/ };

class State22 : public State {
    State* read(char c ) ;/*{
        r.setRegex(1);
        r.setExclude('');
        if (r.getResult(c)) {
        	Error* error = new Error();
            m->setCurrentState(error);
        }
    }
    accepted = true;
    Type type = Type.Sign;
*/ };

class State23 : public State {
   State* read(char c ) ; /*{
        r.setRegex(1);
        r.setExclude('');
        if (r.getResult(c)) {
        	Error* error = new Error();
            m->setCurrentState(error);
        }
    }
    accepted = true;
    Type type = Type.Sign;
*/ };

class State24 : public State {
    State* read(char c ) ;/*{
        r.setRegex(1);
        r.setExclude('');
        if (c == ':') {
        	State25* state25 = new State25();
            m->setCurrentState(state25);
        }
        else {
        	Error* error = new Error();
            m->setCurrentState(error);
        }
    }
    accepted = true;
    Type type = Type.Sign;
*/ };

class State25 : public State {
    State* read(char c );/* {
        r.setRegex(1);
        r.setExclude('');
        if (c == '=') {
        	State26* state26 = new State26();
            m->setCurrentState(state26);
        }
        else {
        	Error* error = new Error();
            m->setCurrentState(error);
        }
    }
    accepted = false;
    Type type = Type.Sign;
*/ };

class State26 : public State {
    State* read(char c ) ;/*{
        r.setRegex(1);
        r.setExclude('');
        if (r.getResult(c)) {
        	Error* error = new Error();
            m->setCurrentState(error);
        }
    }
    accepted = true;
    Type type = Type.Sign;
*/ };

class State27 : public State {
    State* read(char c ) ;/*{
        r.setRegex(1);
        r.setExclude('');
        if (r.getResult(c)) {
        	Error* error = new Error();
            m->setCurrentState(error);
        }
    }
    accepted = true;
    Type type = Type.Sign;
*/ };

class State28 : public State {
    State* read(char c ) ;/*{
        r.setRegex(1);
        r.setExclude('');
        if (c == '&') {
        	State29* state29 = new State29();
            m->setCurrentState(state29);
        }
        else {
        	Error* error = new Error();
            m->setCurrentState(error);
        }
    }
    accepted = false;
    Type type = Type.Sign;
*/ };

class State29 : public State {
    State* read(char c ) ;/*{
        r.setRegex(1);
        r.setExclude('');
        if (r.getResult(c)) {
        	Error* error = new Error();
            m->setCurrentState(error);
        }
    }
    accepted = true;
    Type type = Type.Sign;
*/ };

class State30 : public State {
    State* read(char c ) ;/*{
        r.setRegex(1);
        r.setExclude('');
        if (r.getResult(c)) {
        	Error* error = new Error();
            m->setCurrentState(error);
        }
    }
    accepted = true;
    Type type = Type.Sign;
*/ };

class State31 : public State {
    State* read(char c ) ;/*{
        r.setRegex(1);
        r.setExclude('');
        if (r.getResult(c)) {
        	Error* error = new Error();
            m->setCurrentState(error);
        }
    }
    accepted = true;
    Type type = Type.Sign;
*/ };

class State32 : public State {
    State* read(char c ) ;/*{
        r.setRegex(1);
        r.setExclude('');
        if (r.getResult(c)) {
        	Error* error = new Error();
            m->setCurrentState(error);
        }
    }
    accepted = true;
    Type type = Type.Sign;
*/ };

class State33 : public State {
    State* read(char c ) ;/*{
        r.setRegex(1);
        r.setExclude('');
        if (r.getResult(c)) {
        	Error* error = new Error();
            m->setCurrentState(error);
        }
    }
    accepted = true;
    Type type = Type.Sign;
*/ };

class State34 : public State {
    State* read(char c );/* {
        r.setRegex(1);
        r.setExclude('');
        if (r.getResult(c)) {
        	Error* error = new Error();
            m->setCurrentState(error);
        }
    }
    accepted = true;
    Type type = Type.Sign;
*/ };

class State35 : public State {
    State* read(char c ) ;/*{
        r.setRegex(1);
        r.setExclude('');
        if (r.getResult(c)) {
        	Error* error = new Error();
            m->setCurrentState(error);
        }
    }
    accepted = true;
    Type type = Type.Sign;
*/ };

class State36 : public State {
    State* read(char c ) ;/*{
        r.setRegex(1);
        r.setExclude('');
        if (r.getResult(c)) {
        	Error* error = new Error();
            m->setCurrentState(error);
        }
    }
    accepted = true;
    Type type = Type.Sign;
*/ };

class Error : public State {
    State* read(char c ) ;/*{
        r.setRegex(1);
        r.setExclude('');
        if (r.getResult(c)) {
        	Error* error = new Error();
            m->setCurrentState(error);
        }
    }
    accepted = false;
    Type type = Type.None;
*/ };


#endif //COMPILER_STATE_H
