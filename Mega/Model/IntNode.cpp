//
//  IntNode.cpp
//  Mega
//
//  Created by Wrigley, Joseph on 2/6/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#include "IntNode.hpp"

IntNode :: IntNode()
{
	this -> nodePointer = nullptr;
	this->nodeData = -9999;
}

IntNode :: IntNode(int value)
{
	this->nodePointer = nullptr;
	this->nodeData = value;
}
IntNode :: IntNode(int value, IntNode * nodePointer)
{
	this->nodePointer = nodePointer;
	this->nodeData = value;
}


//getters / setters

void IntNode :: setNodeData(int newValue)
{
	this->nodeData = newValue;
}

void IntNode :: setNodePointer(IntNode * nodePointer)
{
	this->nodePointer = nodePointer;
}

int IntNode :: getNodeData()
{
	return nodeData;
}

IntNode * IntNode :: getNodePointer()
{
	return this->nodePointer;
}

