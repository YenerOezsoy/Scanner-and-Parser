/*
 * Buffer.h
 *
 *  Created on: Mar 22, 2017
 *      Author: kaok1012
 */

#ifndef BUFFER_H_
#define BUFFER_H_

class Buffer {
	const char* INPUT = "Buffer//debug//input";

public:
	Buffer();
	virtual ~Buffer();
	void read();
};

#endif /* BUFFER_H_ */
