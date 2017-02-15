//
//  Array.h
//  Mega
//
//  Created by Wrigley, Joseph on 2/15/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef Array_h
#define Array_h
#include <assert.h>
#include "Node.hpp"

template <class Type>
class Array
{
private:
    Node<Type>* front;
    int size;
    
public:
    //constructor
    Array<Type>();
    Array<Type>(int size);
    //methods
    int getSize();
    Type getFromIndex(int index);
    void setAtIndex(int index, Type value);
    
};
//constructor -- creates an array of what you want /size
template <class Type>
Array<Type> :: Array(int size)
{
    assert(size > 0);
    this->size = size;
    
    this->front = new Node<Type>();
    for(int index = 1; index < size; index++)
    {
        Node<Type> * currentNode = new Node<Type>();
        currentNode->setNodePointer(front);
        front = currentNode;
    }
}

//DO NOT USE
//IMPLEMENTED FOR COMPOLATION
template <class Type>
Array<Type> :: Array()
{
    
}

//methods / getters and setterz

template <class Type>
Type Array<Type> :: getFromIndex(int index)
{
    assert(index >=0 && index < size);
    Type value;
    
    Node<Type> * current = front;
    
    for(int position = 0; position < index; position++)
    {
        current = current->getNodePointer();
    }
    value = current->getNodeData();
    return value;
}

template <class Type>
void Array<Type> :: setAtIndex(int index, Type value)
{
    assert(index >= 0 && index < size);
    Node<Type> * current = front;
    for(int position = 0; position < index; position++)
    {
        current = current->getNodePointer();
    }
    
    current->setNodeData(value);
}


template <class Type>
int Array<Type> :: getSize()
{
    return size;
}


#endif /* Array_h */
