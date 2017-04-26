/*
 * Buffer.cpp
 *
 *  Created on: Mar 22, 2017
 *      Author: kaok1012
 */

#include "../includes/Buffer.h"
#include <iostream>
#include <fstream> //wird schon im header file bestimmt, ist nun quasi doppelt

using namespace std;

Buffer::Buffer(){
	location1 = location2 = inputSize2 = diff = 0;
	file.open("/Users/yenerozsoy/Coding/CLion/Buffer/input.txt",
			ios::in); //durch das "in" wird Datei gelesen, durch out wird in Datei geschrieben
	if (!file.is_open()) throw NotAbleToOpenFileException();
	file.read(buffer1, BUFFER_SIZE);
	inputSize1 = file.gcount();
	currentBuffer = 1; //Zaehler in welchem Buffer wir uns befinden
    std::cout << "File size: " << file.tellg() << std::endl;
}

Buffer::~Buffer() {
    file.close();
}


char Buffer::getChar(){
	//Scanner fraegt char von Buffer an. Liefert char-weise.

    fillBuffer();

    deleteBuffer();

   // totalCount++;

	if (currentBuffer == 1) {
        if ( checkEndOfFile(buffer1, location1, inputSize1)) return '\0';
        return buffer1[location1++];

    }

	else {
        if ( checkEndOfFile(buffer2, location2, inputSize2)) return '\0';
        return buffer2[location2++];
    }
}



//geht char-weise wieder zurueck, location wird verringert
void Buffer::ungetChar(){
   // totalCount--;

    if(currentBuffer == 1){
		if(location1 == 0){
			currentBuffer = 2;
		}
		else {
			location1--;
		}
	}
	else if(currentBuffer == 2){
		if(location2 == 0){
			currentBuffer = 1;
		}
		else {
			location2--;
		}
	}
}

void Buffer::fillBuffer() {
    if (location1 == BUFFER_SIZE && currentBuffer == 1) {
        file.read(buffer2, BUFFER_SIZE);
        inputSize2 = file.gcount();
        //std::cout << inputSize2 << std::endl;
        currentBuffer = 2;
        read = true;
    }
    else if (location2 == BUFFER_SIZE && currentBuffer == 2) {
        file.read(buffer1, BUFFER_SIZE);
        inputSize1 = file.gcount();
       // std::cout << inputSize2 << std::endl;

        currentBuffer = 1;
        read = true;
    }
}

void Buffer::deleteBuffer() {
    if (location1 > 0 && read && currentBuffer == 1) {
        location2 = 0;
        //buffer2[0] = '\0';
        read = false;
    }
    else if (location2 > 0 && read && currentBuffer == 2) {
        location1 = 0;
        //buffer1[0] = '\0';
        read = false;
    }
}

bool Buffer::checkEndOfFile(char* buffer, int location, int size) {

    //std::cout << "Size: " << size << " Fileg: " << file.tellg() << std::endl;
    if (file.tellg() == -1 ) {
        if (size - diff == 0) return true;
        diff++;
    }
    return false;
}
