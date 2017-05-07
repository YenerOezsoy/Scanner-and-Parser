/*
 * TestScanner.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: kaok1012
 */

#include "../includes/Scanner.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
	std::cout << "Output File created" << std::endl;

	Scanner *scanner = new Scanner(argv[1], argv[2]);
    Token *token;

    /*int i = 0;
    while (i < 500) {
        scanner->nextToken();
        i++;
        std::cout << "=====================" << std::endl;
    }*/

    while ((token = scanner->nextToken()) != nullptr) {
//        std::cout << " Wort: " << token->getKey() << '\n';
//        std::cout << " Row: " << token->getRow();
//        std::cout << " Column: " << token->getColumn();
//        std::cout << " Type: " << token->getType() << std::endl;
//        std::cout << "====================="  << std::endl;
    }

    return 0;
}
