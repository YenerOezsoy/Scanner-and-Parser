/*
 * Buffer.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: kaok1012
 */

#include "../includes/Buffer.h"
#include <iostream>
#include <fstream>

using namespace std;

Buffer::Buffer() {
	// TODO Auto-generated constructor stub

}

Buffer::~Buffer() {
	// TODO Auto-generated destructor stub
}

void Buffer::read() {
    fstream file;

    file.open(INPUT, ios::out);

    file << "Test Text geht in die Datei" << endl;
    file << "Welcome to Bufferland" << endl;

    file.close();
    cout << "close" << endl;
}
