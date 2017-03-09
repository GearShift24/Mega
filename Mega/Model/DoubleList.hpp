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
DoubleList<Type> :: ~DoubleList()
{
}


template <class Type>
DoubleList<Type> :: add(Type value)
{
    BiDirectionalNode<Type> * addedNode = new BiDirectionalNode<Type>(value);
    if(this->getSize() == 0)
    {
        this->setFront(addedNode);
        
    }
    else
    {
        this->getEnd()->setNextPointer(addedNode);
        addedNode->setPreviousPointer(this->getEnd());
    }
    
    this->setEnd(addedNode);
    this->setSize(this->getSize() + 1);
}

template <class Type>
Type DoubleList<Type> :: remove(int index)
{
    Type derp;
    return derp;
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
        Type DoubleList<Type> :: addAtIndexFast(int index, type value)
        {
        }
ßß#endif /* DoubleList_hpp */
