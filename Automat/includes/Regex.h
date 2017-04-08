// Created by Yener on 27.03.2017.
//

#ifndef COMPILER_REGEX_H
#define COMPILER_REGEX_H



class Regex{

public:
    Regex();
    ~Regex();
    void setRegex(int regex);
    void setExclude(char c);
    bool getResult(char c);
    bool checkDigit(char c);
    bool checkLetter(char c);
    bool checkSign(char c);
    bool checkLD(char c);
    bool checkAll(char c);
private:
    int regex;
    char exclude;
    bool checkExclude(char c);
};

#endif //COMPILER_REGEX_H
