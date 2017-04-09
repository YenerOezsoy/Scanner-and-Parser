/*
 * TestAutomat.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: kaok1012
 */
//#include "../includes/TestAutomat.h‚"
#include "../../Automat/includes/Automat.h"
#include <iostream>

int main (int argc, char* argv[]){

	std::cout << "Hello, World!" << std::endl;

	char t[80] = ":*Dies ist ein*: Test iF if WHILE 1a a1 11 :*habt ihr weitere test?";
	char* test =  t;

	Automat *automat;

	std::cout << "TEST" << std::endl;

	automat = new Automat();

	automat->handle(test);

	return 0;
}
