
#include "../includes/Regex.h"
#include "../includes/State.h"


State* Start::read(char* c ) {
    if (r.checkDigit(c)) {
        nextState = new State1(this);
        return nextState;
    }
    else if (r.checkLetter(c)) {
        switch (*c) {
            case 'i': return nextState = new State3(this);
            case 'I': return nextState = new State5(this);
            case 'w': return nextState = new State7(this);
            case 'W': return nextState = new State12(this);
            default: return nextState = new State2(this);
        }
    }
    else if (r.checkSign(c)) {
        switch(*c) {
            case '+': return nextState = new State17(this);
            case '-': return nextState = new State18(this);
            case ':': return nextState = new State19(this);
            case '*': return nextState = new State21(this);
            case '<': return nextState = new State22(this);
            case '>': return nextState = new State23(this);
            case '=': return nextState = new State24(this);
            case '!': return nextState = new State27(this);
            case '&': return nextState = new State28(this);
            case ';': return nextState = new State30(this);
            case '(': return nextState = new State31(this);
            case ')': return nextState = new State32(this);
            case '{': return nextState = new State33(this);
            case '}': return nextState = new State34(this);
            case '[': return nextState = new State35(this);
            case ']': return nextState = new State36(this);
            default:break;
        }
    }
    else if (*c == ' ' || *c == '\n') {
        return this;
    }
    return nextState = new ErrorState(this);
}

State* State1::read(char *c) {
    if (r.checkDigit(c)) {
        nextState = new State1(this);
    }
    else {
        nextState = new EndState(this);
    }
    return nextState;
}

State* State2::read(char *c) {
    if (r.checkLD(c)) {
        nextState = new State2(this);
    }
    else {
        nextState = new EndState(this);
    }
    return nextState;
}

State* State3::read(char* c) {
    r.setRegex(0);
    r.setExclude('f');
    if (*c == 'f') {
        return nextState = new State4(this);
    }
    else if (r.getResult(c)) {
        return nextState = new State2(this);
    }
    else {
        return nextState = new EndState(this);
    }
}

State* State4::read(char* c) {
    r.setRegex(0);
    r.setExclude('\0');
    if (r.getResult(c)) {
        return nextState = new State2(this);
    }
    else {
        return nextState = new EndState(this);
    }
}

State* State5::read(char* c) {
    r.setRegex(0);
    r.setExclude('F');
    if (*c == 'F') {
        return nextState = new State6(this);
    }
    else if (r.getResult(c)) {
        return nextState = new State2(this);
    }
    else {
        return nextState = new EndState(this);
    }
}

State* State6::read(char* c) {
    r.setRegex(0);
    r.setExclude('\0');
    if (r.getResult(c)) {
        return nextState = new State2(this);
    }
    else {
        return nextState = new EndState(this);
    }
}

State* State7::read(char* c) {
    r.setRegex(0);
    r.setExclude('h');
    if (*c == 'h') {
        return nextState = new State8(this);
    }
    else if (r.getResult(c)) {
        return nextState = new State2(this);
    }
    else {
        return nextState = new EndState(this);
    }
}

State* State8::read(char* c) {
    r.setRegex(0);
    r.setExclude('i');
    if (*c == 'i') {
        return nextState = new State9(this);
    }
    else if (r.getResult(c)) {
        return nextState = new State2(this);
    }
    else {
        return nextState = new EndState(this);
    }
}

State* State9::read(char* c) {
    r.setRegex(0);
    r.setExclude('l');
    if (*c == 'l') {
        return nextState = new State10(this);
    }
    else if (r.getResult(c)) {
        return nextState = new State2(this);
    }
    else {
        return nextState = new EndState(this);
    }
}

State* State10::read(char* c) {
    r.setRegex(3);
    r.setExclude('e');
    if (*c == 'e'){
        return nextState = new State11(this);
    }
    else if (r.getResult(c)) {
        return nextState = new State2(this);
    }
    else {
        return nextState = new EndState(this);
    }
}

State* State11::read(char* c) {
    r.setExclude('\0');
    r.setRegex(0);
    if (r.getResult(c)) {
        return nextState = new State2(this);
    }
    else {
        return nextState = new EndState(this);
    }
}

State* State12::read(char* c) {
    r.setRegex(0);
    r.setExclude('H');
    if (*c == 'H') {
        return nextState = new State13(this);
    }
    else if (r.getResult(c)) {
        return nextState = new State2(this);
    }
    else {
        return nextState = new EndState(this);
    }
}

State* State13::read(char* c) {
    r.setRegex(0);
    r.setExclude('I');
    if (*c == 'I') {
        return nextState = new State14(this);
    }
    else if (r.getResult(c)) {
        return nextState = new State2(this);
    }
    else {
        return nextState = new EndState(this);
    }
}

State* State14::read(char* c) {
    r.setRegex(0);
    r.setExclude('L');
    if (*c == 'L') {
        return nextState = new State15(this);
    }
    else if (r.getResult(c)) {
        return nextState = new State2(this);
    }
    else {
        return nextState = new EndState(this);
    }
}

State* State15::read(char* c) {
    r.setRegex(0);
    r.setExclude('E');
    if (*c == 'E') {
        return nextState = new State16(this);
    }
    else if (r.getResult(c)) {
        return nextState = new State2(this);
    }
    else {
        return nextState = new EndState(this);
    }
}

State* State16::read(char* c) {
    r.setExclude('\0');
    r.setRegex(0);
    if (r.getResult(c)) {
        return nextState = new State2(this);
    }
    else {
        return nextState = new EndState(this);
    }
}

State* State17::read(char* c) {
    return nextState = new EndState(this);
}

State* State18::read(char* c) {
    return nextState = new EndState(this);
}

State* State19::read(char* c) {
    r.setRegex(1);
    r.setExclude('\0');
    if (*c == '=') {
        return nextState = new State20(this);
    }
    else if (*c == '*') {
        return nextState = new State37(this);
    }
    else {
        return nextState = new EndState(this);
    }
}

State* State20::read(char* c) {
    return nextState = new EndState(this);
}

State* State21::read(char* c) {
    return nextState = new EndState(this);
}

State* State22::read(char* c) {
    return nextState = new EndState(this);
}

State* State23::read(char* c) {
    return nextState = new EndState(this);
}

State* State24::read(char* c) {
    if (*c == ':') {
        return nextState = new State25(this);
    }
    else {
        return nextState = new EndState(this);
    }
}

State* State25::read(char* c) {
    if (*c == '=') {
        return nextState = new State26(this);
    }
    else {
        return nextState = new EndState(this);
    }
}

State* State26::read(char* c) {
    return nextState = new EndState(this);
}

State* State27::read(char* c) {
    return nextState = new EndState(this);
}

State* State28::read(char* c) {
    r.setRegex(1);
    r.setExclude('\0');
    if (*c == '&') {
        return nextState = new State29(this);
    }
    else {
        return nextState = new EndState(this);
    }
}

State* State29::read(char* c) {
    return nextState = new EndState(this);
}

State* State30::read(char* c) {
    return nextState = new EndState(this);
}

State* State31::read(char* c) {
    return nextState = new EndState(this);
}

State* State32::read(char* c) {
    return nextState = new EndState(this);
}

State* State33::read(char* c) {
    return nextState = new EndState(this);
}

State* State34::read(char* c) {
    return nextState = new EndState(this);
}

State* State35::read(char* c) {
    return nextState = new EndState(this);
}

State* State36::read(char* c) {
    return nextState = new EndState(this);
}

State* State37::read(char* c) {
    if (*c == '*') {
        return nextState = new State38(this);
    }
    else {
        return this;
    }
}

State* State38::read(char* c) {
    if (*c == ':') {
        return nextState = new Start();
    }
    else {
        return nextState = new State37(this);
    }
}

State* ErrorState::read(char *c) {

    return this;
}


State* EndState::read(char* c) {
    nextState = new Start();
    return nextState;
}
