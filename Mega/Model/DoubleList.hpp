//
//  DoubleList.hpp
//  Mega
//
//  Created by Wrigley, Joseph on 3/3/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef DoubleList_hpp
#define DoubleList_hpp
#include "DoublyLinkedList.hpp"

template <class Type>
class DoubleList : DoublyLinkedList<Type>
{
private:
public: DoubleList();
    ~DoubleList();
    
    void add(Type data);
    Type remove(int index);
    void AddAtIndexFast(int index, Type value);
    void addAtIndex(int index, Type value);
    Type getFromIndex(int index);
    Type getFromIndexFast(int index);
}


template <class Type>
DoubleList<Type> :: DoubleList() : DoublyLinkedList<Type>()
{
    
}

template <class Type>
DoubleList<Type> :: ~DoubleList() : DoublyLinkedList<Type>()
{
    BiDirectionalNode<Type> * remove = this->getFront();
    while(this->getFront() != nullptr)
    {
        this->setFront(this->getFront()->getNextPointer());
        delete remove;
        remove = this->getFront();
    }
    
    
    
    template <class>
    Type DoubleList<Type> :: getFromIndex(int index)
    {
        assert(index >= 0 && index < this->getSize());
        Type vvalueAtIndex;
        
        BiDirectionalNode<Type> * reference = this->getFront();
        for(int position = 0; position < index; position++)
        {
            refrence = refrence->getNextPointer();
        }
        valueAtIndex = reference->getNodeData();
        
        return valueAtIndex;
    }
    
    
    
    template <class>
    Type DoubleList<Type> :: getFromIndexFast(int index)
    {
        assert(index >= 0 && index < this->getSize());
        Type valueAtIndex;
        BiDirectionalNode<Type> * reference;
        if(index < this->getSize() / 2)
        {
            reference = this->getFront();
            for(int position = 0; position < index; position++)
            {
                reference = reference->getNextPointer();
            }
        }
            else
            {
                reference = this->getEnd();
                for(int position = this->getSize() -1; position > index; position--)
                {
                    reference = refrence->getPreviousPointer();
                }
                valueAtIndex = reference->getNodeData();
                return valueAtIndex;
    }
    
        
        template <class>
        Type DoubleList<Type> :: addAtIndex(int index, type value)
        {
        }
    
    
        template <class>
        Type DoubleList<Type> :: addatIndexFast(int index, type value)
        {
        }

#endif /* DoubleList_hpp */
