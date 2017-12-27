//
// Created by Yener on 27.03.2017.
//
#include "Regex.h"

#ifndef COMPILER_STATE_H
#define COMPILER_STATE_H

enum Type {
	Sign,
	Letter,
	If,
	While,
	Digit,
	SignPlus,
	SignMinus,
	SignDoppelpunkt,
	SignStern,
	SignKleiner,
	SignGroesser,
	SignGleich,
	SignDoppelpunktGleich,
	SignGleichDoppelpunktGleich,
	SignAusrufezeichen,
	SignUndUnd,
	SignSemikolon,
	SignRundeKlammerAuf,
	SignRundeKlammerZu,
	SignGeschweifteKlammerAuf,
	SignGeschweifteKlammerZu,
	SignEckigeKlammerAuf,
	SignEckigeKlammerZu,
	intType,
	writeType,
	readType,
	elseType,
	Comment,
	StartType,
	End,
	ErrorType,
	FinalType
};

class State {
public:
    virtual State* read(char* c) = 0;
    virtual ~State() {};
    bool accepted;
    Type type;
    Regex r;
    State* previousState;
    State* nextState;
};


class Start : public State {
public:
    Start() {
        accepted = false;
        type = Type::StartType;
    };
    State* read(char* c);

};

class State1 : public State {
public:
    State1(State* State) {
        previousState = State;
        accepted = true;
        type = Type::Digit;
    };
    State* read(char* c);

};

class State2 : public State {
public: State2(State* State) {
        previousState = State;
        accepted = true;
        type = Type::Letter;
    };
    State* read(char* c );
};

class State3 : public State {
public: State3(State* State) {
        previousState = State;
        accepted = true;
        type = Type::Letter;
    };
    State* read(char* c );
};

class State4 : public State {
public: State4 (State* State) {
        previousState = State;
        accepted = true;
        type = Type::If;
    };
    State* read(char* c ); };

class State5 : public State {
public: State5(State* State) {
        previousState = State;
        accepted = true;
        type = Type::Letter;
    };
    State* read(char* c );
};

class State6 : public State {
public:     State6(State* State) {
        previousState = State;
        accepted = true;
        type = Type::If;
    };
    State* read(char* c ); };

class State7 : public State {
public: State7(State* State) {
        previousState = State;
        accepted = true;
        type = Type::Letter;
    };
    State* read(char* c );
};

class State8 : public State {
public: State8(State* State) {
        previousState = State;
        accepted = true;
        type = Type::Letter;
    };
    State* read(char* c ); };

class State9 : public State {
public: State9(State* State) {
        previousState = State;
        accepted = true;
        type = Type::Letter;
    };
    State* read(char* c );  };

class State10 : public State {
public: State10(State* State) {
        previousState = State;
        accepted = true;
        type = Type::Letter;
    };
    State* read(char* c );  };

class State11 : public State {
public: State11(State* State) {
        previousState = State;
        accepted = true;
        type = Type::While;
    };
    State* read(char* c );};

class State12 : public State {
public: State12(State* State) {
        previousState = State;
        accepted = true;
        type = Type::Letter;
    };
    State* read(char* c );
};

class State13 : public State {
public: State13(State* State) {
        previousState = State;
        accepted = true;
        type = Type::Letter;
    };
    State* read(char* c );  };

class State14 : public State {
public: State14(State* State) {
        previousState = State;
        accepted = true;
        type = Type::Letter;
    };
    State* read(char* c ); };

class State15 : public State {
public: State15(State* State) {
        previousState = State;
        accepted = true;
        type = Type::Letter;
    };
    State* read(char* c );  };

class State16 : public State {
public: State16(State* State) {
        previousState = State;
        accepted = true;
        type = Type::While;
    };
    State* read(char* c ); };

class State17 : public State {
public: State17(State* State) {
        previousState = State;
        accepted = true;
        type = Type::SignPlus;
    };
    State* read(char* c );
};

class State18 : public State {
public: State18(State* State) {
        previousState = State;
        accepted = true;
        type = Type::SignMinus;
    };
    State* read(char* c );
};

class State19 : public State {
public: State19(State* State) {
        previousState = State;
        accepted = false;
        type = Type::SignDoppelpunkt;
    };
    State* read(char* c );
};

class State20 : public State {
public: State20(State* State) {
        previousState = State;
        accepted = true;
        type = Type::SignDoppelpunktGleich;
    };
    State* read(char* c ) ; };

class State21 : public State {
public: State21(State* State) {
        previousState = State;
        accepted = true;
        type = Type::SignStern;
    };
    State* read(char* c );
};

class State22 : public State {
public: State22(State* State) {
        previousState = State;
        accepted = true;
        type = Type::SignKleiner;
    };
    State* read(char* c );
};

class State23 : public State {
public: State23(State* State) {
        previousState = State;
        accepted = true;
        type = Type::SignGroesser;
    };
    State* read(char* c );
};

class State24 : public State {
public: State24(State* State) {
        previousState = State;
        accepted = true;
        type = Type::SignGleich;
    };
    State* read(char* c );
};

class State25 : public State {
public: State25(State* State) {
        previousState = State;
        accepted = false;
        type = Type::Sign;
    };
    State* read(char* c );
};

class State26 : public State {
public: State26(State* State) {
        previousState = State;
        accepted = true;
        type = Type::SignGleichDoppelpunktGleich;
    };
    State* read(char* c ) ;
};

class State27 : public State {
public: State27(State* State) {
        previousState = State;
        accepted = true;
        type = Type::SignAusrufezeichen;
    };
    State* read(char* c );
};

class State28 : public State {
public: State28(State* State) {
        previousState = State;
        accepted = false;
        type = Type::Sign;
    };
    State* read(char* c );
};

class State29 : public State {
public: State29(State* State) {
        previousState = State;
        accepted = true;
        type = Type::SignUndUnd;
    };
    State* read(char* c ) ;
};

class State30 : public State {
public: State30(State* State) {
        previousState = State;
        accepted = true;
        type = Type::SignSemikolon;
    };
    State* read(char* c );
};

class State31 : public State {
public: State31(State* State) {
        previousState = State;
        accepted = true;
        type = Type::SignRundeKlammerAuf;
    };
    State* read(char* c );
};

class State32 : public State {
public: State32(State* State) {
        previousState = State;
        accepted = true;
        type = Type::SignRundeKlammerZu;
    };
    State* read(char* c );
};

class State33 : public State {
public: State33(State* State) {
        previousState = State;
        accepted = true;
        type = Type::SignGeschweifteKlammerAuf;
    };
    State* read(char* c );
};

class State34 : public State {
public: State34(State* State) {
        previousState = State;
        accepted = true;
        type = Type::SignGeschweifteKlammerZu;
    };
    State* read(char* c );
};

class State35 : public State {
public: State35(State* State) {
        previousState = State;
        accepted = true;
        type = Type::SignEckigeKlammerAuf;
    };
    State* read(char* c );
};

class State36 : public State {
public: State36(State* State) {
        previousState = State;
        accepted = true;
        type = Type::SignEckigeKlammerZu;
    };
    State* read(char* c );
};


class State37 : public State {
public: State37(State* State) {
        previousState = State;
        accepted = false;
        type = Type::Comment;
    };
    State* read(char* c );
};

class State38 : public State {
public: State38(State* State) {
        previousState = State;
        accepted = false;
        type = Type::Comment;
    };
    State* read(char* c );
};

class State39 : public State {
public: State39(State* State) {
        previousState = State;
        accepted = false;
        type = Type::Comment;
    };
    State* read(char* c );
};

class State40 : public State {
public: State40(State* State) {
        previousState = State;
        accepted = true;
        type = Type::Letter;
    };
    State* read(char* c );
};

class State41 : public State {
public: State41(State* State) {
        previousState = State;
        accepted = true;
        type = Type::intType;
    };
    State* read(char* c );
};

class State42 : public State {
public: State42(State* State) {
        previousState = State;
        accepted = true;
        type = Type::Letter;
    };
    State* read(char* c );
};

class State43 : public State {
public: State43(State* State) {
        previousState = State;
        accepted = true;
        type = Type::Letter;
    };
    State* read(char* c );
};

class State44 : public State {
public: State44(State* State) {
        previousState = State;
        accepted = true;
        type = Type::Letter;
    };
    State* read(char* c );
};

class State45 : public State {
public: State45(State* State) {
        previousState = State;
        accepted = true;
        type = Type::writeType;
    };
    State* read(char* c );
};

class State46 : public State {
public: State46(State* State) {
        previousState = State;
        accepted = true;
        type = Type::Letter;
    };
    State* read(char* c );
};

class State47 : public State {
public: State47(State* State) {
        previousState = State;
        accepted = true;
        type = Type::Letter;
    };
    State* read(char* c );
};

class State48 : public State {
public: State48(State* State) {
        previousState = State;
        accepted = true;
        type = Type::Letter;
    };
    State* read(char* c );
};

class State49 : public State {
public: State49(State* State) {
        previousState = State;
        accepted = true;
        type = Type::readType;
    };
    State* read(char* c );
};

class State50 : public State {
public: State50(State* State) {
        previousState = State;
        accepted = true;
        type = Type::Letter;
    };
    State* read(char* c );
};

class State51 : public State {
public: State51(State* State) {
        previousState = State;
        accepted = true;
        type = Type::Letter;
    };
    State* read(char* c );
};

class State52 : public State {
public: State52(State* State) {
        previousState = State;
        accepted = true;
        type = Type::Letter;
    };
    State* read(char* c );
};

class State53 : public State {
public: State53(State* State) {
        previousState = State;
        accepted = true;
        type = Type::elseType;
    };
    State* read(char* c );
};


class ErrorState : public State {
public: ErrorState(State* State) {
        previousState = State;
        accepted = false;
        type = Type::ErrorType;
    };
    State* read(char* c );
};

class EndState : public State {
public: EndState(State* State) {
        previousState = State;
        accepted = false;
        type = Type::End;
    };
    State* read(char* c);
};

class FinalState : public State {
public: FinalState(State* State) {
        previousState = State;
        accepted = false;
        type = Type::FinalType;
    };
    State* read(char* c);
};
#endif //COMPILER_STATE_H
