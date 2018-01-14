/*
 * Token.h
 *
 *  Created on: 12.04.2017
 *      Author: yenerozsoy
 */
#include "../../Symboltabelle/includes/Information.h"

#ifndef TOKEN_H_
#define TOKEN_H_

class Token {

	Key realKey;
    int type;
    int row;
    int column;
    char* key;
    int value;
    bool isANumber;

public:
    Token(int type, int row, int column, char* key, Key realKey) {
        this->type = type;
        this->row = row;
        this->column = column;
        this->key = key;
        isANumber = false;
        this->realKey = realKey;
        this->value = 0;
    }

	Token(int type, int row, int column, long key, Key realKey) {
        this->type = type;
        this->row = row;
        this->column = column;
        this->value = key;
        isANumber = true;
        this->realKey = realKey;
	}

	int getValue() {
		return value;
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

    char* getKey(int** ptr) {
    	if (!isANumber) {
    		*ptr = &value;
    		return nullptr;
    	}
        return key;
    }

    Key getRealKey() {
    	return realKey;
    }

    bool isThisANumber() {
    	return isANumber;
    }
};

#endif /* TOKEN_H_ */
