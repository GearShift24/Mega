/*
 * IntNodeArray.h
 *
 *  Created on: Feb 12, 2017
 *      Author: joey
 */

#ifndef IntArray_hpp
#define IntArray_hpp

#include "IntNode.hpp"

class IntNodeArray
{
private:
	IntNode * front;
	int size;
public:

	IntNodeArray(int size);
	void setAtIndex(int index, int value);
	int getFromIndex(int index);
	int getSize();

};

#endif /* IntArray_hpp */
