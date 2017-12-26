/*
 *  Checktype.h
 *
 *  Created on: Dec 26, 2017
 *      Author: kaok1012
 */

#ifndef CHECKTYPE_H_
#define CHECKTYPE_H_

enum CheckType {
	NOTYPE,
	ERRORTYPE,

	ARRAYTYPE,
	INTARRAYTYPE,
	INTTYPE,

	OPPLUS,
	OPMINUS,
	OPMULT,
	OPDIV,
	OPLESS,
	OPGREATER,
	OPEQUAL,
	OPUNEQUAL,
	OPAND
};


#endif /* CHECKTYPE_H_ */
