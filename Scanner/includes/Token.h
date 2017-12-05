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
    int value;
    bool isANumber;

public: Token(int type, int row, int column, char* key) {
        this->type = type;
        this->row = row;
        this->column = column;
        this->key = key;
        isANumber = false;
}

	Token(int type, int row, int column, long key) {
        this->type = type;
        this->row = row;
        this->column = column;
        this->value = key;
        isANumber = true;
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
};

#endif /* TOKEN_H_ */
