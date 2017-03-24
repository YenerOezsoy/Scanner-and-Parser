/*
 * TestBuffer.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: kaok1012
 */

#include "../includes/Buffer.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char **argv) {
	cout << "Buffer" << endl;
	Buffer*  buffer;

	buffer = new Buffer();

	buffer->read();
}
