//
//  CircularList.hpp
//  Mega
//
//  Created by Wrigley, Joseph on 3/3/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef CircularList_hpp
#define CircularList_hpp
#include "DoublyLinkedList.hpp"

template <class Type>
class CircularList : public  DoublyLinkedList<Type>
{
private:
    BiDirectionalNode<Type> * findNode(int index);
public: CircularList();
    ~CircularList();
    void add(Type data);
    Type remove(int index);
    Type getFromIndex(int index);
    Type setAtIndex(int index, Type data);
    
};

template <class Type>
CircularList<Type> :: CircularList() : DoublyLinkedList<Type>()
{
    
}


template <class Type>
CircularList<Type> :: ~CircularList()
{
    BiDirectionalNode<Type> * remove = this->getFront();
    while(this->getFront() != nullptr)
    {
        this->setFront(this->getFront()->getNextPointer());
        delete remove;
        remove = this->getFront();
    }
}


//the add method in a linked list adds to a point, and then changes the node connects from the previous one and the last one. boi.

template <class Type>
void CircularList<Type> :: add(Type data)
{
    BiDirectionalNode<Type> * addMe = new BiDirectionalNode<Type>(data);
    
    if(this->getSize() == 0)
    {
        this->setFront(addMe);
        this->setEnd(addMe);
        addMe->setPreviousPointer(this->getFront());
        this->getFront()->setNextPointer(this->getEnd());
    }
    else
    {
        this->getEnd()->setNextPointer(addMe);
        addMe->setPreviousPointer(this->getEnd());
        addMe->setNextPointer(this->getFront());
        this->getFront()->setPreviousPointer(addMe);
        this->setEnd(addMe);
    }
    this->setSize(this->getSize() + 1);
}

template <class Type>
Type CircularList<Type> :: remove(int index)
{
    assert(index >= 0 && index < this->getSize());
    
    Type removedValue;
    
    BiDirectionalNode<Type> * removed = findNode(index);
 
    
    removedValue = removed->getNodeData();
    
    BiDirectionalNode<Type> * oldPrevious = removed->getPreviousPointer();
    BiDirectionalNode<Type> * oldNext = removed->getNextPointer();
    
    if(this->getSize() > 1)
    {
        oldPrevious->setNextPointer(oldNext);
        oldNext->setPreviousPointer(oldPrevious);
        //adjust front/end if needed
        if(index == 0)
        {
            this->setFront(this->getFront()->getNextPointer());
        }
        else if(index == this->getSize() -1)
        {
            this->setEnd(this->getEnd()->getPreviousPointer());
        }
        
    }
    else
    {
        this->setFront(nullptr);
        this->setEnd(nullptr);
    }
    
   
    
    delete removed;
    this->setSize(this->getSize() - 1);
    return removedValue;
    
}

/*
 A helper method to cut the speed needed to get to a specific node in the list.
 Precondition: The @param index is within the range: size < index <= 0
 will only be called after passing the assert call.
 Returns the node at the specifid index.
 */
template <class Type>
BiDirectionalNode<Type> * CircularList<Type> :: findNode(int index)
{
    BiDirectionalNode<Type> * nodeToFind;
    if(index<this->getSize()/2)
    {
        nodeToFind=this->getFront();
        for(int spot = 0; spot < index; spot++)
        {
            nodeToFind = nodeToFind->getNextPointer();
        }
    }
    
    else
    {
        nodeToFind = this->getEnd();
        for(int spot = this->getSize() - 1; spot > index; spot--)
        {
            nodeToFind = nodeToFind->getPreviousPointer();
        }
    }
    return nodeToFind;
}

template <class Type>
Type CircularList<Type> :: getFromIndex(int index)
{
    assert(index >=0 && index < this->getSize());
    Type retrieved;
    
    BiDirectionalNode<Type> * current = findNode(index);
    
    retrieved = current->getNodeData();
    
    return retrieved;
}

template <class Type>
Type CircularList<Type> :: setAtIndex(int index, Type data)
{
    assert(index >= 0 && index < this->getSize());
    
    Type replaced;
    
    BiDirectionalNode<Type> * current = findNode(index);
    
    replaced = current->getNodeData();
    current->setNodeData(data);
    
    return replaced;
}

#endif /* CircularList_hpp */
