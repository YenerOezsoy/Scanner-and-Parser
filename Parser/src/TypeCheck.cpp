/*
 *  TypeCheck.cpp
 *
 *  Created on: Dec 26, 2017
 *      Author: kaok1012
 */
#include "../includes/Parser.h"

void Parser::typeError(char* msg) {
	++typeErrorCount;
//	cout << msg << endl;
}

void Parser::store(Key key, CheckType type){
	symtab->lookup(key)->setCheckType(type);
}

CheckType Parser::getType(Key key) {
	return symtab->lookup(key)->getCheckType();
}

void Parser::typeCheck(ParseTreeNode* node) {
	if (node->getType() == PROG) {
		typeCheck(node->getChild(0));
		typeCheck(node->getChild(1));
		node->setCheckType(NOTYPE);
	}
	else if (node->getType() == DECLS || node->getType() == STATEMENTS) {
		if (node->isLeaf()) {
			node->setCheckType(NOTYPE);
		}
		else {
			ParseTreeNode* child = node->getChild();

			while (child != nullptr) {
				typeCheck(child);
				child = child->getNext();
			}
			node->setCheckType(NOTYPE);
		}
	}
	else if (node->getType() == DECL) {
		typeCheck(node->getChild(1));

		if (node->getChild(2) != nullptr) {
			if (getType(node->getChild(2)->getToken()->getRealKey()) != NOTYPE) {
				typeError("identifier already defined");
				node->setCheckType(ERRORTYPE);
			}
			else if (node->getChild(1)->getCheckType() == ERRORTYPE) {
				node->setCheckType(ERRORTYPE);
			}
			else {
				node->setCheckType(NOTYPE);

				if (node->getChild(1)->getCheckType() == ARRAYTYPE) {
					store(node->getChild(2)->getToken()->getRealKey(), INTARRAYTYPE);
				} else {
					store(node->getChild(2)->getToken()->getRealKey(), INTTYPE);
				}
			}
		}
		else {
			typeError("no identifier name");
		}
	}
	else if (node->getType() == ARRAY) {
		if (!node->isLeaf()) {
			if (node->getChild(1)->getToken()->getValue() > 0) {
				node->setCheckType(ARRAYTYPE);
			} else {
				typeError("no valid number");
				node->setCheckType(ERRORTYPE);
			}
		}
		else {
			node->setCheckType(NOTYPE);
		}
	}
	else if (node->getType() == STATEMENT) {
		Type stmtType = node->getChild()->getToken()->getType();

		// ASSIGN
		if (stmtType == Letter) {
			typeCheck(node->getChild(3));
			typeCheck(node->getChild(1));
			if (getType(node->getChild(0)->getToken()->getRealKey()) == NOTYPE) {
				typeError("identifier not defined");
				node->setCheckType(ERRORTYPE);
			}
			else if (node->getChild(3)->getCheckType() == INTTYPE
								&& ((getType(node->getChild(0)->getToken()->getRealKey()) == INTTYPE
										&& node->getChild(1)->getCheckType() == NOTYPE)
										|| (getType(node->getChild(0)->getToken()->getRealKey()) == INTARRAYTYPE
												&& node->getChild(1)->getCheckType() == ARRAYTYPE))
					) {
				node->setCheckType(NOTYPE);
			}
			else {
				typeError("incompatible types");
			}
		}

		// WRITE
		else if (stmtType == writeType) {
			typeCheck(node->getChild(2));
			node->setCheckType(NOTYPE);
		}

		//READ
		else if (stmtType == readType) {
			typeCheck(node->getChild(3));

			if (getType(node->getChild(2)->getToken()->getRealKey()) == NOTYPE) {
				typeError("identifier not defined");
				node->setCheckType(ERRORTYPE);
			}
			else if ( ((getType(node->getChild(2)->getToken()->getRealKey()) == INTTYPE)
					&& node->getChild(3)->getCheckType() == NOTYPE)
					||((getType(node->getChild(2)->getToken()->getRealKey()) == INTARRAYTYPE)
							&& node->getChild(3)->getCheckType() == ARRAYTYPE)
					) {
				node->setCheckType(NOTYPE);
			}
			else {
				typeError("incompatible types");
			}
		}

		//{STATEMENTS}
		else if (stmtType == SignGeschweifteKlammerAuf) {
			typeCheck(node->getChild(1));
			node->setCheckType(NOTYPE);
		}

		//IF
		else if (stmtType == If) {
			typeCheck(node->getChild(2));
			typeCheck(node->getChild(4));
			typeCheck(node->getChild(6));
			if (node->getChild(2)->getCheckType() == ERRORTYPE) {
				node->setCheckType(ERRORTYPE);
			}
			else {
				node->setCheckType(NOTYPE);
			}
		}
		else if (stmtType == While) {
			typeCheck(node->getChild(2));
			typeCheck(node->getChild(4));

			if(node->getChild(2)->getCheckType() == ERRORTYPE) {
				node->setCheckType(ERRORTYPE);
			}
			else {
				node->setCheckType(NOTYPE);
			}
		}
	}
	else if (node->getType() == INDEX) {
		if (!node->isLeaf()) {
			typeCheck(node->getChild(1));
			if (node->getChild(1)->getCheckType() == ERRORTYPE) {
				node->setCheckType(ERRORTYPE);
			} else {
				node->setCheckType(ARRAYTYPE);
			}
		}
		else {
			node->setCheckType(NOTYPE);
		}
	}
	else if(node->getType() == EXP) {
		typeCheck(node->getChild(0));
		typeCheck(node->getChild(1));

		if (node->getChild(1)->getCheckType() == NOTYPE) {
			node->setCheckType(node->getChild(0)->getCheckType());
		}
		else if (node->getChild(0)->getCheckType() != node->getChild(1)->getCheckType()) {
			node->setCheckType(ERRORTYPE);
		}
		else {
			node->setCheckType(node->getChild(0)->getCheckType());
		}
	}

//	else if (node->getType() == EXP2) {
//			Type exp2Type = node->getChild()->getToken()->getType();
//			if (exp2Type == T_SIGN_BRACKET_ROUND_L) {
//				typeCheck(node->getChild(1));
//				node->setCheckType(node->getChild(1)->getCheckType());
//			}
//			else if (exp2Type == T_IDENTIFIER) {
//				typeCheck(node->getChild(1));
//				CheckType identifierType = getType(
//						node->getChild(0)->getToken()->getKey());
//				if (identifierType == NOTYPE) {
//					typeError("identifier not defined");
//					node->setCheckType(ERRORTYPE);
//				}
//				else if (identifierType == INTTYPE && node->getChild(1)->getCheckType() == NOTYPE) {
//					node->setCheckType(identifierType);
//				}
//				else if (identifierType == INTARRAYTYPE && node->getChild(1)->getCheckType() == ARRAYTYPE){
//					node->setCheckType(INTTYPE);
//				}
//				else{
//					typeError("no primitive type");
//				}
//
//			}
//			else if(exp2Type == T_INTEGER){
//				node->setCheckType(INTTYPE);
//			}
//			else if(exp2Type == T_SIGN_MINUS){
//				typeCheck(node->getChild(1));
//				node->setCheckType(node->getChild(1)->getCheckType());
//			}
//			else if(exp2Type == T_SIGN_EXCLAMATION){
//				typeCheck(node->getChild(1));
//				if(node->getChild(1)->getCheckType() != INTTYPE){
//					node->setCheckType(ERRORTYPE);
//				}
//				else{
//					node->setCheckType(INTTYPE);
//				}
//			}
//
//		}
}
