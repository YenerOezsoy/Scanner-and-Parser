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
    virtual State* read(char c) = 0;
    virtual ~State() {};
    bool accepted;
    enum Type {Sign, Letter, If, While, Digit, None, Comment};
    Type type;
    Regex r;// = Regex();
    State* getState(int i);
};

class Start : public State {
public: Start() {
        accepted = false;
        type = None;
    };
    State* read(char c );
};

class State1 : public State {
public: State1() {
        accepted = true;
        type = Digit;
    };
    State* read(char c );

};

class State2 : public State {
public: State2() {
        accepted = true;
        type = Letter;
    };
    State* read(char c );
};

class State3 : public State {
public: State3() {
        accepted = true;
        type = Letter;
    };
    State* read(char c );
};

class State4 : public State {
    public: State4 () {
        accepted = true;
        type = If;
    };
    State* read(char c ); };

class State5 : public State {
public: State5() {
        accepted = true;
        type = Letter;
    };
    State* read(char c );
};

class State6 : public State {
public:     State6() {
        accepted = true;
        type = If;
    };
    State* read(char c ); };

class State7 : public State {
public: State7() {
        accepted = true;
        type = Letter;
    };
    State* read(char c );
};

class State8 : public State {
    public: State8() {
        accepted = true;
        type = Letter;
    };
    State* read(char c ); };

class State9 : public State {
    public: State9() {
        accepted = true;
        type = Letter;
    };
    State* read(char c );  };

class State10 : public State {
    public: State10() {
        accepted = true;
        type = Letter;
    };
    State* read(char c );  };

class State11 : public State {
    public: State11() {
        accepted = true;
        type = While;
    };
    State* read(char c );};

class State12 : public State {
public: State12() {
        accepted = true;
        type = Letter;
    };
    State* read(char c );
};

class State13 : public State {
    public: State13() {
        accepted = true;
        type = Letter;
    };
    State* read(char c );  };

class State14 : public State {
    public: State14() {
        accepted = true;
        type = Letter;
    };
    State* read(char c ); };

class State15 : public State {
    public: State15() {
        accepted = true;
        type = Letter;
    };
    State* read(char c );  };

class State16 : public State {
    public: State16() {
        accepted = true;
        type = While;
    };
    State* read(char c ); };

class State17 : public State {
public: State17() {
        accepted = true;
        type = Sign;
    };
    State* read(char c );
};

class State18 : public State {
public: State18() {
        accepted = true;
        type = Sign;
    };
    State* read(char c );
};

class State19 : public State {
public: State19() {
        accepted = true;
        type = Sign;
    };
    State* read(char c );
};

class State20 : public State {
    public: State20() {
        accepted = true;
        type = Sign;
    };
    State* read(char c ) ; };

class State21 : public State {
public: State21() {
        accepted = true;
        type = Sign;
    };
    State* read(char c );
};

class State22 : public State {
public: State22() {
        accepted = true;
        type = Sign;
    };
    State* read(char c );
};

class State23 : public State {
public: State23() {
        accepted = true;
        type = Sign;
    };
    State* read(char c );
};

class State24 : public State {
public: State24() {
        accepted = true;
        type = Sign;
    };
    State* read(char c );
};

class State25 : public State {
    public: State25() {
        accepted = false;
        type = Sign;
    };
    State* read(char c );
};

class State26 : public State {
    public: State26() {
        accepted = true;
        type = Sign;
    };
    State* read(char c ) ;
};

class State27 : public State {
public: State27() {
        accepted = true;
        type = Sign;
    };
    State* read(char c );
};

class State28 : public State {
public: State28() {
        accepted = false;
        type = Sign;
    };
    State* read(char c );
};

class State29 : public State {
    public: State29() {
        accepted = true;
        type = Sign;
    };
    State* read(char c ) ;
};

class State30 : public State {
public: State30() {
        accepted = true;
        type = Sign;
    };
    State* read(char c );
};

class State31 : public State {
public: State31() {
        accepted = true;
        type = Sign;
    };
    State* read(char c );
};

class State32 : public State {
public: State32() {
        accepted = true;
        type = Sign;
    };
    State* read(char c );
};

class State33 : public State {
public: State33() {
        accepted = true;
        type = Sign;
    };
    State* read(char c );
};

class State34 : public State {
public: State34() {
        accepted = true;
        type = Sign;
    };
    State* read(char c );
};

class State35 : public State {
public: State35() {
        accepted = true;
        type = Sign;
    };
    State* read(char c );
};

class State36 : public State {
public: State36() {
        accepted = true;
        type = Sign;
    };
    State* read(char c );
};

class State37 : public State {
public: State37() {
        accepted = false;
        type = None;
    };
    State* read(char c );
};

class State38 : public State {
public: State38() {
        accepted = false;
        type = Comment;
    };
    State* read(char c );
};

class State39 : public State {
public: State39() {
        accepted = false;
        type = Comment;
    };
    State* read(char c );
};

class State40 : public State {
public: State40() {
        accepted = false;
        type = Comment;
    };
    State* read(char c );
};

class State41 : public State {
public: State41() {
        accepted = false;
        type = Comment;
    };
    State* read(char c);
};

class Error : public State {
public: Error() {
        accepted = false;
        type = None;
    };
    State* read(char c );
};

#endif //COMPILER_STATE_H
