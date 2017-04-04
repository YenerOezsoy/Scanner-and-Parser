//
/*// Created by Yener on 27.03.2017.
 //

 #include "../includes/State.h"
 #include "../includes/Regex.h"

 class State {
 public: virtual State read(char c, AutomatOO* m=0);
 bool accepted;
 enum Type {Sign, Letter, If, While, Digit, None};
 Regex* r = new Regex();
 };

 class Start : public State {
 State Start::read(char c, AutomatOO *m) {
 if (r->checkDigit(c)) {
 // m->setState(State1);
 }
 else if (r->checkLetter(c)) {
 switch (c) {
 case 'i':   // m->setState(State3);
 break;
 case 'I':   // m->setSate(State5);
 break;
 case 'w':   // m->setSate(State7);
 break;
 case 'W':   // m->setState(State12);
 break;
 }
 }
 else if (r->checkSign(c)){
 switch(c) {
 case '+':   // m->setState(State17);
 break;
 case '-':   // m->setSate(State18);
 break;
 case ':':   // m->setSate(State19);
 break;
 case '*':   // m->setState(State21);
 break;
 case '<':   // m->setState(State22);
 break;
 case '>':   // m->setSate(State23);
 break;
 case '=':   // m->setSate(State24);
 break;
 case '!':   // m->setState(State27);
 break;
 case '&':   // m->setState(State28);
 break;
 case ';':   // m->setSate(State30);
 break;
 case '(':   // m->setSate(State31);
 break;
 case ')':   // m->setState(State32);
 break;
 case '{':   // m->setState(State33);
 break;
 case '}':   // m->setSate(State34);
 break;
 case '[':   // m->setSate(State35);
 break;
 case ']':   // m->setState(State36);
 break;
 }
 }
 }
 Type type = Type.None;
 accepted = false;
 };

 class State1 : public State {
 State Start::read(char c, AutomatOO *m) {
 if (r->checkDigit(c)) {
 // m->setState(State1);
 }
 else {
 // m->setState(Error);
 }
 }
 Type type = Type.Digit;
 accepted = true;
 };

 class State2 : public State {
 State Start::read(char c, AutomatOO *m) {
 if(r->checkLD(c)) {
 // m->setState(State2);
 }
 else {
 // m->setState(Error);
 }
 }
 Type type = Type.Letter;
 accepted = true;
 };

 class State3 : public State {
 State Start::read(char c, AutomatOO *m) {
 r->setRegex(0);

 r->setExclude('f');
 //Wechsel State4
 if (c == 'f'){
 // m->setState(State4);
 }
 //Wechsel zu State2
 else if (r->getResult(c)) {
 // m->setState(State2);
 }
 //Wechsel Error
 else {
 // m->setState(Error);
 }
 }
 Type type = Type.Letter;
 accepted = true;
 };

 class State4 : public State {
 State Start::read(char c, AutomatOO *m) {
 r->setRegex(0);
 r->setExclude('');
 if (r->getResult(c)) {
 // m->setState(State2);
 }
 else {
 // m->setState(Error);
 }
 }
 Type type = Type.If;
 accepted = true;
 };

 class State5 : public State {
 State Start::read(char c, AutomatOO *m) {
 r->setRegex(0);

 char carray[1] = {'F'};
 char* cpointer;
 r->setExclude(cpointer);
 r->setExclude('F');
 if (c == 'F'){
 // m->setState(State6);
 }
 else if (r->getResult(c)) {
 // m->setState(State2);
 }
 else {
 // m->setState(Error);
 }
 }
 Type type = Type.Identifier;
 accepted = true;
 };

 class State6 : public State {
 State Start::read(char c, AutomatOO *m) {
 r->setRegex(0);
 r->setExclude('');
 if (r->getResult(c)) {
 // m->setState(State2);
 }
 else {
 // m->setState(Error);
 }
 }
 accepted = true;
 Type type = Type.If;
 };

 class State7 : public State {
 State Start::read(char c, AutomatOO *m) {
 r->setRegex(0);
 r->setExclude('h');
 if (c == 'h'){
 // m->setState(State8);
 }
 else if (r->getResult(c)) {
 // m->setState(State2);
 }
 else {
 // m->setState(Error);
 }
 }
 accepted = true;
 Type type = Type.Identifier;
 };

 class State8 : public State {
 State Start::read(char c, AutomatOO *m) {
 r->setRegex(0);
 r->setExclude('i');
 if (c == 'i'){
 // m->setState(State9);
 }
 else if (r->getResult(c)) {
 // m->setState(State2);
 }
 else {
 // m->setState(Error);
 }
 }
 accepted = true;
 Type type = Type.Identifier;
 };

 class State9 : public State {
 State Start::read(char c, AutomatOO *m) {
 r->setRegex(0);
 r->setExclude('l');
 if (c == 'l'){
 // m->setState(State10);
 }
 else if (r->getResult(c)) {
 // m->setState(State2);
 }
 else {
 // m->setState(Error);
 }
 }
 accepted = true;
 Type type = Type.Identifier;
 };

 class State10 : public State {
 State Start::read(char c, AutomatOO *m) {
 r->setRegex(3);
 r->setExclude('e');
 if (c == 'e'){
 // m->setState(State11);
 }
 else if (r->getResult(c)) {
 // m->setState(State2);
 }
 else {
 // m->setState(Error);
 }
 }
 accepted = true;
 Type type = Type.Identifier;
 };

 class State11 : public State {
 State Start::read(char c, AutomatOO *m) {
 //nach while weiteres Zeichen(Letter oder Digit) -> Letter!
 r->setExclude('');
 r->setRegex(0);
 if (r->getResult(c)) {
 // m->setState(State2);
 }
 //Sign
 else {
 // m->setState(Error);
 }
 }
 accepted = true;
 Type type = Type.While;
 };

 class State12 : public State {
 State Start::read(char c, AutomatOO *m) {
 r->setRegex(0);
 r->setExclude('H');
 if (c == 'H'){
 // m->setState(State13);
 }
 else if (r->getResult(c)) {
 // m->setState(State2);
 }
 else {
 // m->setState(Error);
 }
 }
 accepted = true;
 Type type = Type.Identifier;
 };

 class State13 : public State {
 State Start::read(char c, AutomatOO *m) {
 r->setRegex(0);
 r->setExclude('I');
 if (c == 'I'){
 // m->setState(State14);
 }
 else if (r->getResult(c)) {
 // m->setState(State2);
 }
 else {
 // m->setState(Error);
 }
 }
 accepted = true;
 Type type = Type.Identifier;
 };

 class State14 : public State {
 State Start::read(char c, AutomatOO *m) {
 r->setRegex(0);
 r->setExclude('L');
 if (c == 'L'){
 // m->setState(State15);
 }
 else if (r->getResult(c)) {
 // m->setState(State2);
 }
 else {
 // m->setState(Error);
 }
 }
 accepted = true;
 Type type = Type.Identifier;
 };

 class State15 : public State {
 State Start::read(char c, AutomatOO *m) {
 r->setRegex(0);
 r->setExclude('E');
 if (c == 'E'){
 // m->setState(State16);
 }
 else if (r->getResult(c)) {
 // m->setState(State2);
 }
 else {
 // m->setState(Error);
 }
 }
 accepted = true;
 Type type = Type.Identifier;
 };

 class State16 : public State {
 State Start::read(char c, AutomatOO *m) {
 //nach WHILE weiteres Zeichen(Letter oder Digit) -> Letter!
 r->setExclude('');
 r->setRegex(0);
 if (r->getResult(c)) {
 // m->setState(State2);
 }
 //Sign
 else {
 // m->setState(Error);
 }
 }
 accepted = true;
 Type type = Type.While;
 };

 class State17 : public State {
 State Start::read(char c, AutomatOO *m) {
 r->setRegex(1);
 r->setExclude('');
 if (r->getResult(c)) {
 // m->setState(Error);
 }
 }
 accepted = true;
 Type type = Type.Sign;
 };

 class State18 : public State {
 State Start::read(char c, AutomatOO *m) {
 r->setRegex(1);
 r->setExclude('');
 if (r->getResult(c)) {
 // m->setState(Error);
 }
 }
 accepted = true;
 Type type = Type.Sign;
 };

 class State19 : public State {
 State Start::read(char c, AutomatOO *m) {
 r->setRegex(1);
 r->setExclude('');
 if (c == '=') {
 // m->setState(State20);
 }
 else {
 // m->setState(Error);
 }
 }
 accepted = true;
 Type type = Type.Sign;
 };

 class State20 : public State {
 State Start::read(char c, AutomatOO *m) {
 r->setRegex(1);
 r->setExclude('');
 if (r->getResult(c)) {
 // m->setState(Error);
 }
 }
 accepted = true;
 Type type = Type.Sign;
 };

 class State21 : public State {
 State Start::read(char c, AutomatOO *m) {
 r->setRegex(1);
 r->setExclude('');
 if (r->getResult(c)) {
 // m->setState(Error);
 }
 }
 accepted = true;
 Type type = Type.Sign;
 };

 class State22 : public State {
 State Start::read(char c, AutomatOO *m) {
 r->setRegex(1);
 r->setExclude('');
 if (r->getResult(c)) {
 // m->setState(Error);
 }
 }
 accepted = true;
 Type type = Type.Sign;
 };

 class State23 : public State {
 State Start::read(char c, AutomatOO *m) {
 r->setRegex(1);
 r->setExclude('');
 if (r->getResult(c)) {
 // m->setState(Error);
 }
 }
 accepted = true;
 Type type = Type.Sign;
 };

 class State24 : public State {
 State Start::read(char c, AutomatOO *m) {
 r->setRegex(1);
 r->setExclude('');
 if (c == ':') {
 // m->setState(State25);
 }
 else {
 // m->setState(Error);
 }
 }
 accepted = true;
 Type type = Type.Sign;
 };

 class State25 : public State {
 State Start::read(char c, AutomatOO *m) {
 r->setRegex(1);
 r->setExclude('');
 if (c == '=') {
 // m->setState(State26);
 }
 else {
 // m->setState(Error);
 }
 }
 accepted = false;
 Type type = Type.Sign;
 };

 class State26 : public State {
 State Start::read(char c, AutomatOO *m) {
 r->setRegex(1);
 r->setExclude('');
 if (r->getResult(c)) {
 // m->setState(Error);
 }
 }
 accepted = true;
 Type type = Type.Sign;
 };

 class State27 : public State {
 State Start::read(char c, AutomatOO *m) {
 r->setRegex(1);
 r->setExclude('');
 if (r->getResult(c)) {
 // m->setState(Error);
 }
 }
 accepted = true;
 Type type = Type.Sign;
 };

 class State28 : public State {
 State Start::read(char c, AutomatOO *m) {
 r->setRegex(1);
 r->setExclude('');
 if (c == '&') {
 // m->setState(State29);
 }
 else {
 // m->setState(Error);
 }
 }
 accepted = false;
 Type type = Type.Sign;
 };

 class State29 : public State {
 State Start::read(char c, AutomatOO *m) {
 r->setRegex(1);
 r->setExclude('');
 if (r->getResult(c)) {
 // m->setState(Error);
 }
 }
 accepted = true;
 Type type = Type.Sign;
 };

 class State30 : public State {
 State Start::read(char c, AutomatOO *m) {
 r->setRegex(1);
 r->setExclude('');
 if (r->getResult(c)) {
 // m->setState(Error);
 }
 }
 accepted = true;
 Type type = Type.Sign;
 };

 class State31 : public State {
 State Start::read(char c, AutomatOO *m) {
 r->setRegex(1);
 r->setExclude('');
 if (r->getResult(c)) {
 // m->setState(Error);
 }
 }
 accepted = true;
 Type type = Type.Sign;
 };

 class State32 : public State {
 State Start::read(char c, AutomatOO *m) {
 r->setRegex(1);
 r->setExclude('');
 if (r->getResult(c)) {
 // m->setState(Error);
 }
 }
 accepted = true;
 Type type = Type.Sign;
 };

 class Error : public State {
 State Start::read(char c, AutomatOO *m) {
 r->setRegex(1);
 r->setExclude('');
 if (r->getResult(c)) {
 // m->setState(Error);
 }
 }
 accepted = false;
 Type type = Type.None;
 };*/

//#include "../includes/Automat.h"
#include "../includes/Regex.h"
#include "../includes/State.h"

/*class State {
	~State();
	Regex r = Regex();
};
*/
/*class Start : public State {*/


State* Start::read(char c ) {
	if (r.checkDigit(c)) {
         	State1* state1 = new State1();
         	return state1;
         	// m->setCurrentState(state1);
	}
	else if (r.checkLetter(c)) {
		switch (c) {
			case 'i': 	State3* state3;// = new State3();
	                	// m->setCurrentState(state3);
						return state3;
	                 	break;
	        case 'I': 	State5* state5;// = new State5();
	           			// m->setCurrentState(state5);
               			return state5;
	        				break;
	        case 'w': 	State7* state7;// = new State7();
	           			// m->setCurrentState(state7);
	        				return state7;
	        				break;
	        case 'W':   State12* state12;// = new State12();
	           			// m->setCurrentState(state12);
	        return state12;
	        				break;
	             }
	         }
	else if (r.checkSign(c)) {
		switch(c) {
			case '+':   State17* state17;// = new State17();
	           			// m->setCurrentState(state17);
			return state17;
						break;
            case '-':   State18* state18;// = new State18();
	           			// m->setCurrentState(state18);
            return state18;
            				break;
            case ':':   State19* state19;// = new State19();
              			// m->setCurrentState(state19);
            return state19;
            				break;
            case '*':   State21* state21;// = new State21();
               			// m->setCurrentState(state21);
            return state21;
            				break;
            case '<':   State22* state22;// = new State22();
               			// m->setCurrentState(state22);
            return state22;
            				break;
            case '>':   State23* state23;// = new State23();
               			// m->setCurrentState(state23);
            return state23;
            				break;
            case '=':   State24* state24;// = new State24();
              			// m->setCurrentState(state24);
            return state24;
            break;
            case '!':   State27* state27;// = new State27();
              			// m->setCurrentState(state27);
            return state27;
            	break;
            case '&':   State28* state28;// = new State28();
               			// m->setCurrentState(state28);
            return state28;
            break;
            case ';':   State30* state30;// = new State30();
               			// m->setCurrentState(state30);
            return state30;
            break;
            case '(':   State31* state31;// = new State31();
              			// m->setCurrentState(state31);
            return state31;
            break;
            case ')':   State32* state32;// = new State32();
               			// m->setCurrentState(state32);
            return state32;
            break;
            case '{':   State33* state33;// = new State33();
              			// m->setCurrentState(state33);
            return state33;
            break;
            case '}':   State34* state34;// = new state34();
               			// m->setCurrentState(state34);
            return state34;
            break;
            case '[':   State35* state35;// = new State35();
               			// m->setCurrentState(state35);
            return state35;
            break;
            case ']':   State36* state36;// = new State36();
               			// m->setCurrentState(state36);
            return state36;
            break;
		}
	}

}

State* State1::read(char c ) {
	if (r.checkDigit(c)) {
		State1* state1;// = new State1();
		// m->setCurrentState(state1);
		return state1;
	}
	else {
		Error* error;// = new Error();
		// m->setCurrentState(error);
		return error;
	}
}

State* State2::read(char c ) {
	if(r.checkLD(c)) {
         	//State2* state2;// = new State2();
         	// m->setCurrentState(state2);
         	return this;
	}
	else {
		Error* error;// = new Error();
		// m->setCurrentState(error);
		return error;
	}
}
