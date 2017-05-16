/*
 * Token.h
 *
 *  Created on: 12.04.2017
 *      Author: yenerozsoy
 */

#ifndef TOKEN_H_
#define TOKEN_H_

class Token {

    int type;
    int row;
    int column;
    char* key;

public: Token(int type, int row, int column, char* key) {
        this->type = type;
        this->row = row;
        this->column = column;
        this->key = key;
    }

    int getType() {
        return type;
    }

    int getRow() {
        return row;
    }

    int getColumn() {
        return column;
    }

    char* getKey() {
        return key;
    }
};

#endif /* TOKEN_H_ */
