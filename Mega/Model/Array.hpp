//
//  Array.h
//  Mega
//
//  Created by Wrigley, Joseph on 2/15/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef Array_hpp
#define Array_hpp

#include <iostream>
#include <assert.h>
#include "Node.hpp"


using namespace std;

template <class Type>
class Array
{
private:
    Node<Type> * front;
    int size;
    
public:
    //constructor
    Array<Type>();
    Array<Type>(int size);
    //destructor
    ~Array<Type>();
    //copy constructor
    Array<Type>(const Array<Type> & toBeCopied);
    // assignment operator overload
   // void operator = (const Array<Type> & toBeAssigned);
    //methods
    int getSize() const;
    Node<Type> * getFront() const;
    Type getFromIndex(int index);
    void setAtIndex(int index, Type value);
        int indexOf(Type itemToFind);
    
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
        currentNode->setNextPointer(front);
        front = currentNode;
    }
}

//DO NOT USE
//IMPLEMENTED FOR COMPOLATION
template <class Type>
Array<Type> :: Array()
{
    
}

//
//
//decstuctor
template <class Type>
Array<Type> :: ~Array()
{
    int count = size;
    Node<Type> * remove = front;
    while(front != nullptr)
    {
        //move to next node in array
        front = front->getNextPointer();
        cout << "moving the the next node. at: " << count << endl;
        //delete front pointer
        delete remove;
        cout << "Deleting the old front pointer" << endl;
        //move deleet to the new front
        remove = front;
        cout <<"moving to new front pointer" << endl;
        count--;
        cout << "the front is at: " <<front << " cout is: " << count << endl;
    }
}


//
//
//copy constructor
template <class Type>
Array<Type> :: Array(const Array<Type> & toBeCopied)
{
    this->size = toBeCopied.getSize();
    
    //build data strcture
    this->front = new Node<Type>();
    for(int index =1; index < size; index++)
    {
        Node<Type> * temp = new Node<Type>();
        temp->setNextPointer(front);
        front = temp;
    }
    //copy values into new array
    Node<Type> * copyTemp = toBeCopied.getFront();
    Node<Type> * updated = this->front;
    for(int index = 0; index < size; index++)
    {
        updated->setNodeData(copyTemp->getNodeData());
        updated = updated->getNextPointer();
        copyTemp = copyTemp->getNextPointer();
    }
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
        current = current->getNextPointer();
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
        current = current->getNextPointer();
    }
    
    current->setNodeData(value);
}


template <class Type>
int Array<Type> :: getSize() const
{
    return size;
}


template <class Type>
Node<Type>* Array<Type> :: getFront() const
{
    return front;
}


template <class Type>
int Array<Type> :: indexOf(Type findMe)
{
    int index = -1;
    
    Node<Type> * searchedPointer = this->getFront();
    
    for (int spot = 0; spot < this->getSize(); spot++)
    {
        if(findMe == searchedPointer->getNodeData())
        {
            return spot;
        }
        searchedPointer = searchedPointer->getNextPointer();
    }
    
    return index;
}


#endif /* Array_hpp */
