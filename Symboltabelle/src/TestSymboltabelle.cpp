/*
 * TestSymboltabelle.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: kaok1012
 */

#include "../includes/Symboltabelle.h"
#include <iostream>

int main(int argc, char **argv) {

	std::cout << "SymTab main test so plsss" << std::endl;
	Symboltabelle* symboltabelle = new Symboltabelle(10);

	symboltabelle->initSymbols();
	symboltabelle->ausgabe();
}
