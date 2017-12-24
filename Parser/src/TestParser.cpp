/*
 *  TestParser.cpp
 *
 *  Created on: Dec 24, 2017
 *      Author: kaok1012
 */

#include "../includes/Parser.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
    std::cout << "Parser" << std::endl;

    Symboltabelle* symtab = new Symboltabelle(1024);
    Parser* parser = new Parser(symtab, argv[1], argv[2]);

    parser->parse();

    std::cout << "Done" << std::endl;

    return 0;
}
