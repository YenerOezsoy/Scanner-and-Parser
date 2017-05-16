
#include "../includes/Regex.h"
#include "../includes/State.h"


State* State::getState(int i) {
    switch (i) {
        default: break;
        case 0:  Start *start;
            start = new Start();
            return start;
        case 1:  State1 *state1;
            state1 = new State1();
            return state1;
        case 2:  State2 *state2;
            state2 = new State2();
            return state2;
        case 3:  State3 *state3;
            state3 = new State3();
            return state3;
        case 4:  State4 *state4;
            state4 = new State4();
            return state4;
        case 5:  State5 *state5;
            state5 = new State5();
            return state5;
        case 6:  State6 *state6;
            state6 = new State6();
            return state6;
        case 7:  State7 *state7;
            state7 = new State7();
            return state7;
        case 8:  State8 *state8;
            state8 = new State8();
            return state8;
        case 9:  State9 *state9;
            state9 = new State9();
            return state9;
        case 10: State10 *state10;
            state10 = new State10();
            return state10;
        case 11: State11 *state11;
            state11 = new State11();
            return state11;
        case 12: State12 *state12;
            state12 = new State12();
            return state12;
        case 13: State13 *state13;
            state13 = new State13();
            return state13;
        case 14: State14 *state14;
            state14 = new State14();
            return state14;
        case 15: State15 *state15;
            state15 = new State15();
            return state15;
        case 16: State16 *state16;
            state16 = new State16();
            return state16;
        case 17: State17 *state17;
            state17 = new State17();
            return state17;
        case 18: State18 *state18;
            state18 = new State18();
            return state18;
        case 19: State19 *state19;
            state19 = new State19();
            return state19;
        case 20: State20 *state20;
            state20 = new State20();
            return state20;
        case 21: State21 *state21;
            state21 = new State21();
            return state21;
        case 22: State22 *state22;
            state22 = new State22();
            return state22;
        case 23: State23 *state23;
            state23 = new State23();
            return state23;
        case 24: State24 *state24;
            state24 = new State24();
            return state24;
        case 25: State25 *state25;
            state25 = new State25();
            return state25;
        case 26: State26 *state26;
            state26 = new State26();
            return state26;
        case 27: State27 *state27;
            state27 = new State27();
            return state27;
        case 28: State28 *state28;
            state28 = new State28();
            return state28;
        case 29: State29 *state29;
            state29 = new State29();
            return state29;
        case 30: State30 *state30;
            state30 = new State30();
            return state30;
        case 31: State31 *state31;
            state31 = new State31();
            return state31;
        case 32: State32 *state32;
            state32 = new State32();
            return state32;
        case 33: State33 *state33;
            state33 = new State33();
            return state33;
        case 34: State34 *state34;
            state34 = new State34();
            return state34;
        case 35: State35 *state35;
            state35 = new State35();
            return state35;
        case 36: State36 *state36;
            state36 = new State36();
            return state36;
        case 37: State37 *state37;
            state37 = new State37();
            return state37;
        case 38: State38 *state38;
            state38 = new State38();
            return state38;
        case 39: State39 *state39;
            state39 = new State39();
            return state39;
        case -1: EndState *end;
            end = new EndState();
            return end;
        case -2: Error *error;
            error = new Error();
            return error;
    }
    return this;
}

State* Start::read(char* c) {
    if (r.checkDigit(c)) {
        return getState(1);
    }
    else if (r.checkLetter(c)) {
        switch (*c) {
            case 'i': return getState(3);
            case 'I': return getState(5);
            case 'w': return getState(7);
            case 'W': return getState(12);
            default: return getState(2);
        }
    }
    else if (r.checkSign(c)) {
        switch(*c) {
            case '+': return getState(17);
            case '-': return getState(18);
            case ':': return getState(19);
            case '*': return getState(21);
            case '<': return getState(22);
            case '>': return getState(23);
            case '=': return getState(24);
            case '!': return getState(27);
            case '&': return getState(28);
            case ';': return getState(30);
            case '(': return getState(31);
            case ')': return getState(32);
            case '{': return getState(33);
            case '}': return getState(34);
            case '[': return getState(35);
            case ']': return getState(36);
            default:break;
        }
    }
    else if (*c == ' ' || *c == '\n') {
        return this;
    }
    return getState(-2);
}

State* State1::read(char* c ) {
    if (r.checkDigit(c)) {
        return getState(1);
    }
    else {
        return getState(-1);
    }
}

State* State2::read(char* c ) {
    if(r.checkLD(c)) {
        return getState(2);
    }
    else {
        return getState(-1);
    }
}

State* State3::read(char* c) {
    r.setRegex(0);
    r.setExclude('f');
    if (*c == 'f') {
        return getState(4);
    }
    else if (r.getResult(c)) {
        return getState(2);
    }
    else {
        return getState(-1);
    }
}

State* State4::read(char* c) {
    r.setRegex(0);
    r.setExclude('\0');
    if (r.getResult(c)) {
        return getState(2);
    }
    else {
        return getState(-1);
    }
}

State* State5::read(char* c) {
    r.setRegex(0);
    r.setExclude('F');
    if (*c == 'F') {
        return getState(6);
    }
    else if (r.getResult(c)) {
        return getState(2);
    }
    else {
        return getState(-1);
    }
}

State* State6::read(char* c) {
    r.setRegex(0);
    r.setExclude('\0');
    if (r.getResult(c)) {
        return getState(2);
    }
    else {
        return getState(-1);
    }
}

State* State7::read(char* c) {
    r.setRegex(0);
    r.setExclude('h');
    if (*c == 'h') {
        return getState(8);
    }
    else if (r.getResult(c)) {
        return getState(2);
    }
    else {
        return getState(-1);
    }
}

State* State8::read(char* c) {
    r.setRegex(0);
    r.setExclude('i');
    if (*c == 'i') {
        return getState(9);
    }
    else if (r.getResult(c)) {
        return getState(2);
    }
    else {
        return getState(-1);
    }
}

State* State9::read(char* c) {
    r.setRegex(0);
    r.setExclude('l');
    if (*c == 'l') {
        return getState(10);
    }
    else if (r.getResult(c)) {
        return getState(2);
    }
    else {
        return getState(-1);
    }
}

State* State10::read(char* c) {
    r.setRegex(3);
    r.setExclude('e');
    if (*c == 'e'){
        return getState(11);
    }
    else if (r.getResult(c)) {
        return getState(2);
    }
    else {
        return getState(-1);
    }
}

State* State11::read(char* c) {
    r.setExclude('\0');
    r.setRegex(0);
    if (r.getResult(c)) {
        return getState(2);
    }
    else {
        return getState(-1);
    }
}

State* State12::read(char* c) {
    r.setRegex(0);
    r.setExclude('H');
    if (*c == 'H') {
        return getState(13);
    }
    else if (r.getResult(c)) {
        return getState(2);
    }
    else {
        return getState(-1);
    }
}

State* State13::read(char* c) {
    r.setRegex(0);
    r.setExclude('I');
    if (*c == 'I') {
        return getState(14);
    }
    else if (r.getResult(c)) {
        return getState(2);
    }
    else {
        return getState(-1);
    }
}

State* State14::read(char* c) {
    r.setRegex(0);
    r.setExclude('L');
    if (*c == 'L') {
        return getState(15);
    }
    else if (r.getResult(c)) {
        return getState(2);
    }
    else {
        return getState(-1);
    }
}

State* State15::read(char* c) {
    r.setRegex(0);
    r.setExclude('E');
    if (*c == 'E') {
        return getState(16);
    }
    else if (r.getResult(c)) {
        return getState(2);
    }
    else {
        return getState(-1);
    }
}

State* State16::read(char* c) {
    r.setExclude('\0');
    r.setRegex(0);
    if (r.getResult(c)) {
        return getState(2);
    }
    else {
        return getState(-1);
    }
}

State* State17::read(char* c) {
    return getState(-1);
}

State* State18::read(char* c) {
    return getState(-1);
}

State* State19::read(char* c) {
    r.setRegex(1);
    r.setExclude('\0');
    if (*c == '=') {
        return getState(20);
    }
    else if (*c == '*') {
        return getState(37);
    }
    else {
        return getState(-1);
    }
}

State* State20::read(char* c) {
    return getState(-1);
}

State* State21::read(char* c) {
    return getState(-1);
}

State* State22::read(char* c) {
    return getState(-1);
}

State* State23::read(char* c) {
    return getState(-1);
}

State* State24::read(char* c) {
    if (*c == ':') {
        return getState(25);
    }
    else {
        return getState(-1);
    }
}

State* State25::read(char* c) {
    if (*c == '=') {
        return getState(26);
    }
    else {
        return getState(-1);
    }
}

State* State26::read(char* c) {
    return getState(-1);
}

State* State27::read(char* c) {
    return getState(-1);
}

State* State28::read(char* c) {
    r.setRegex(1);
    r.setExclude('\0');
    if (*c == '&') {
        return getState(29);
    }
    else {
        return getState(-1);
    }
}

State* State29::read(char* c) {
    return getState(-1);
}

State* State30::read(char* c) {
    return getState(-1);
}

State* State31::read(char* c) {
    return getState(-1);
}

State* State32::read(char* c) {
    return getState(-1);
}

State* State33::read(char* c) {
    return getState(-1);
}

State* State34::read(char* c) {
    return getState(-1);
}

State* State35::read(char* c) {
    return getState(-1);
}

State* State36::read(char* c) {
    return getState(-1);
}

State* State37::read(char* c) {
    if (*c == '*') {
        return getState(38);
    }
    else {
        return this;
    }
}

State* State38::read(char* c) {
    if (*c == ':') {
        return getState(39);
    }
    else {
        return getState(37);
    }
}

State* State39::read(char* c) {
    return getState(0)->read(c);
}

State* EndState::read(char* c) {
    return getState(0);
}

State* Error::read(char* c) {
    return getState(-2);
}

