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
	location1 = location2 = inputSize2 = 0;
	file.open("Buffer//input",
			ios::in); //durch das "in" wird Datei gelesen, durch out wird in Datei geschrieben
	if (!file.is_open()) throw NotAbleToOpenFileException();
	file.read(buffer1, BUFFER_SIZE);
	inputSize1 = file.gcount();
	currentBuffer = 1; //Zaehler in welchem Buffer wir uns befinden
}

Buffer::~Buffer() {
    file.close();
}


char Buffer::getChar(){
	//Scanner fraegt char von Buffer an. Liefert char-weise.

	/*
	if(location2 >= inputSize2 && location1 >= inputSize1){
		if(currentBuffer == 2){
			file.read(buffer1, BUFFER_SIZE);
			inputSize1 = file.gcount();
			if (inputSize1 == 0) return '\0'; //wenn nichts mehr eingelesen wird
			location1 = location2 = 0;
			currentBuffer = 1;
		}
	}
	if (location1 >= inputSize1){ 	//zweiter Buffer (wird befüllt sobald B1 voll ist)
			if (location2 == 0 && checkNew()){
				file.read(buffer2, BUFFER_SIZE);
				inputSize2 = file.gcount();
				if (inputSize2 == 0) return '\0';
			}
			currentBuffer = 2;
			return buffer2[location2++];
	}

	return buffer1[location1++]; //holt Wert aus Array an erster Stelle raus und Zeiger zeigt danach eins rechts weiter
	*/

	if (location1 == BUFFER_SIZE && currentBuffer == 1) {
		file.read(buffer2, BUFFER_SIZE);
		inputSize2 = file.gcount();
		currentBuffer = 2;
		read = true;
		if (inputSize2 == 0) return '\0';
	}
	else if (location2 == BUFFER_SIZE && currentBuffer == 2) {
		file.read(buffer1, BUFFER_SIZE);
		inputSize1 = file.gcount();
		currentBuffer = 1;
		read = true;
		if (inputSize1 == 0) return '\0';
	}
	if (location1 > 0 && read) {
		location2 = 0;
		read = false;
	}
	else if (location2 > 0 && read) {
		location1 = 0;
		read = false;
	}

	if (currentBuffer == 1) return buffer1[location1++];
	else if (currentBuffer == 2) return buffer2[location2++];
}



//geht char-weise wieder zurueck, location wird verringert
void Buffer::ungetChar(){
	/*
	if(currentBuffer == 1){
		location1--;
		if(location1 == 0){
			currentBuffer = 2;
		}
	}
	else if(currentBuffer == 2){
		oldLocation= location2;
		location2--;
		if(location2 == 0){
			currentBuffer = 1;
		}
	}*/
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
