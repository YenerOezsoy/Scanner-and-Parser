//
// Created by Yener on 27.03.2017.
//


#ifndef COMPILER_STATE_H
#define COMPILER_STATE_H


#include "Regex.h"

class State {
public:
    virtual State* read(char* c) = 0;
    virtual ~State() {};
    bool accepted;
    enum Type {Sign, Letter, If, While, Digit, SignPlus, SignMinus, SignDoppelpunkt , SignStern, SignKleiner, SignGroesser, SignGleich, SignDoppelpunktGleich, SignGleichDoppelpunktGleich, SignAusrufezeichen, SignUndUnd, SignSemikolon, SignRundeKlammerAuf, SignRundeKlammerZu, SignGeschweifteKlammerAuf, SignGeschweifteKlammerZu, SignEckigeKlammerAuf, SignEckigeKlammerZu, Comment, StartType,  End, ErrorType};
    Type type;
    Regex r;
    State* previousState;
    State* nextState;
};


class Start : public State {
public:
    Start() {
        accepted = false;
        type = StartType;
    };
    State* read(char* c);

};


class State1 : public State {
public:
    State1(State* state) {
        previousState = state;
        accepted = true;
        type = Digit;
    };
    State* read(char* c);

};


class State2 : public State {
public: State2(State* state) {
        previousState = state;
        accepted = true;
        type = Letter;
    };
    State* read(char* c );
};

class State3 : public State {
public: State3(State* state) {
        previousState = state;
        accepted = true;
        type = Letter;
    };
    State* read(char* c );
};

class State4 : public State {
public: State4 (State* state) {
        previousState = state;
        accepted = true;
        type = If;
    };
    State* read(char* c ); };

class State5 : public State {
public: State5(State* state) {
        previousState = state;
        accepted = true;
        type = Letter;
    };
    State* read(char* c );
};

class State6 : public State {
public:     State6(State* state) {
        previousState = state;
        accepted = true;
        type = If;
    };
    State* read(char* c ); };

class State7 : public State {
public: State7(State* state) {
        previousState = state;
        accepted = true;
        type = Letter;
    };
    State* read(char* c );
};

class State8 : public State {
public: State8(State* state) {
        previousState = state;
        accepted = true;
        type = Letter;
    };
    State* read(char* c ); };

class State9 : public State {
public: State9(State* state) {
        previousState = state;
        accepted = true;
        type = Letter;
    };
    State* read(char* c );  };

class State10 : public State {
public: State10(State* state) {
        previousState = state;
        accepted = true;
        type = Letter;
    };
    State* read(char* c );  };

class State11 : public State {
public: State11(State* state) {
        previousState = state;
        accepted = true;
        type = While;
    };
    State* read(char* c );};

class State12 : public State {
public: State12(State* state) {
        previousState = state;
        accepted = true;
        type = Letter;
    };
    State* read(char* c );
};

class State13 : public State {
public: State13(State* state) {
        previousState = state;
        accepted = true;
        type = Letter;
    };
    State* read(char* c );  };

class State14 : public State {
public: State14(State* state) {
        previousState = state;
        accepted = true;
        type = Letter;
    };
    State* read(char* c ); };

class State15 : public State {
public: State15(State* state) {
        previousState = state;
        accepted = true;
        type = Letter;
    };
    State* read(char* c );  };

class State16 : public State {
public: State16(State* state) {
        previousState = state;
        accepted = true;
        type = While;
    };
    State* read(char* c ); };

class State17 : public State {
public: State17(State* state) {
        previousState = state;
        accepted = true;
        type = SignPlus;
    };
    State* read(char* c );
};

class State18 : public State {
public: State18(State* state) {
        previousState = state;
        accepted = true;
        type = SignMinus;
    };
    State* read(char* c );
};

class State19 : public State {
public: State19(State* state) {
        previousState = state;
        accepted = false;
        type = SignDoppelpunkt;
    };
    State* read(char* c );
};

class State20 : public State {
public: State20(State* state) {
        previousState = state;
        accepted = true;
        type = SignDoppelpunktGleich;
    };
    State* read(char* c ) ; };

class State21 : public State {
public: State21(State* state) {
        previousState = state;
        accepted = true;
        type = SignStern;
    };
    State* read(char* c );
};

class State22 : public State {
public: State22(State* state) {
        previousState = state;
        accepted = true;
        type = SignKleiner;
    };
    State* read(char* c );
};

class State23 : public State {
public: State23(State* state) {
        previousState = state;
        accepted = true;
        type = SignGroesser;
    };
    State* read(char* c );
};

class State24 : public State {
public: State24(State* state) {
        previousState = state;
        accepted = true;
        type = SignGleich;
    };
    State* read(char* c );
};

class State25 : public State {
public: State25(State* state) {
        previousState = state;
        accepted = false;
        type = Sign;
    };
    State* read(char* c );
};

class State26 : public State {
public: State26(State* state) {
        previousState = state;
        accepted = true;
        type = SignGleichDoppelpunktGleich;
    };
    State* read(char* c ) ;
};

class State27 : public State {
public: State27(State* state) {
        previousState = state;
        accepted = true;
        type = SignAusrufezeichen;
    };
    State* read(char* c );
};

class State28 : public State {
public: State28(State* state) {
        previousState = state;
        accepted = false;
        type = Sign;
    };
    State* read(char* c );
};

class State29 : public State {
public: State29(State* state) {
        previousState = state;
        accepted = true;
        type = SignUndUnd;
    };
    State* read(char* c ) ;
};

class State30 : public State {
public: State30(State* state) {
        previousState = state;
        accepted = true;
        type = SignSemikolon;
    };
    State* read(char* c );
};

class State31 : public State {
public: State31(State* state) {
        previousState = state;
        accepted = true;
        type = SignRundeKlammerAuf;
    };
    State* read(char* c );
};

class State32 : public State {
public: State32(State* state) {
        previousState = state;
        accepted = true;
        type = SignRundeKlammerZu;
    };
    State* read(char* c );
};

class State33 : public State {
public: State33(State* state) {
        previousState = state;
        accepted = true;
        type = SignGeschweifteKlammerAuf;
    };
    State* read(char* c );
};

class State34 : public State {
public: State34(State* state) {
        previousState = state;
        accepted = true;
        type = SignGeschweifteKlammerZu;
    };
    State* read(char* c );
};

class State35 : public State {
public: State35(State* state) {
        previousState = state;
        accepted = true;
        type = SignEckigeKlammerAuf;
    };
    State* read(char* c );
};

class State36 : public State {
public: State36(State* state) {
        previousState = state;
        accepted = true;
        type = SignEckigeKlammerZu;
    };
    State* read(char* c );
};

class State37 : public State {
public: State37(State* state) {
        previousState = state;
        accepted = false;
        type = Comment;
    };
    State* read(char* c );
};

class State38 : public State {
public: State38(State* state) {
        previousState = state;
        accepted = false;
        type = Comment;
    };
    State* read(char* c );
};

class State39 : public State {
public: State39(State* state) {
        previousState = state;
        accepted = false;
        type = Comment;
    };
    State* read(char* c );
};

class ErrorState : public State {
public: ErrorState(State* state) {
        previousState = state;
        accepted = false;
        type = ErrorType;
    };
    State* read(char* c );
};


class EndState : public State {
public: EndState(State* state) {
        previousState = state;
        accepted = false;
        type = End;
    };
    State* read(char* c);
};

#endif //COMPILER_STATE_H
