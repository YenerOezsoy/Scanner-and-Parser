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

	std::cout << "test" << std::endl;

	Automat* automat;

	automat = new Automat();

	automat->handle();

	return 0;

}
