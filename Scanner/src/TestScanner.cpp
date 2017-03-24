/*
 * TestScanner.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: kaok1012
 */

#include "../includes/Scanner.h"
#include "../../Buffer/includes/Buffer.h"
#include <iostream>

using namespace std;

int main(int argc, char **argv) {
	cout << "Scanner" << endl;
	Scanner* scanner;

	scanner = new Scanner();

	Buffer* buffer = new Buffer();

	buffer->read();
}


