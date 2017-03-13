//
//  Stack.hpp
//  Mega
//
//  Created by Wrigley, Joseph on 3/1/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp
#include "DoublyLinkedList.hpp"

template <class Type>
class Stack : public  DoublyLinkedList<Type>
{
private:
public:
    Stack();
    ~Stack();
    void add(Type value);
    Type remove(int index);
    Type pop();
    Type peek();
    void push(Type data);
};

/*
 empty since the base class constructor is null
 */
template <class Type>
Stack<Type> :: Stack() : DoublyLinkedList<Type>()
{
    
}

/*
 just goes through the list and removes your crap
 */
template <class Type>
Stack<Type> :: ~Stack()
{
    BiDirectionalNode<Type> * remove = this->getFront();
    while(this->getFront() != nullptr)
    {
        this->setFront(this->getFront()->getNextPointer());
        delete remove;
        remove = this->getFront();
    }
}
/*
 the add method only adds to the end on a stack. Never at an index.
 Implemented only to avoid abstract status in class
 */

template <class Type>
void Stack<Type> :: add(Type valueToAdd)
{
    push(valueToAdd);
}



/*
 1. create a new node
 2.if the stack is empty sets fron to the new node
 3.Else sets the end's next to point to the new node
 4.move end to the new node
 5.increase the size by 1
 */
template <class Type>
void Stack<Type> :: push(Type addedThing)
{
    BiDirectionalNode<Type> * addToStack = new BiDirectionalNode<Type>(addedThing);
    
    if(this->getSize() == 0 || this->getFront() == nullptr || this->getEnd() == nullptr)
    {
        this->setFront(addToStack);
    }
    else
    {
        this->getEnd()->setNextPointer(addToStack);
        addToStack->setPreviousPointer(this->getEnd());
    }
    
        this->setEnd(addToStack);
    this->setSize(this->getSize() + 1);
}
                                       
                                    
/*
 used to avoid abstract status
 Asserts that the size is correct and calls pop method
 */
template <class Type>
Type Stack<Type> :: remove(int index)
    {
        assert(index == this->getSize() - 1 && this->getSize() > 0);
               return pop();
    }
        
        /*
         assert that stack is greater than 0
         */
template <class Type>
               Type Stack<Type> :: peek()
               {
                   assert(this->getSize() > 0);
                   return this->getEnd()->getNodeData();
               }
        
               
            /*
            1.assert size > 0
            2.get data from end node
            3.move end to ends previous
            4.deleted old end node
            5.decrease size
            6.reutrn data from old end.
            */
template <class Type>
Type Stack<Type> :: pop()
    {
        assert(this->getSize() > 0);
        Type removed = this->getEnd()->getNodeData();
        
        BiDirectionalNode<Type> * update = this->getEnd();
        update = update->getPreviousPointer();
        
        if(update != nullptr)
        {
            update->setNextPointer(nullptr);
        }
        
        delete this->getEnd();
        this->setEnd(update);
        this->setSize(this->getSize() - 1);
        return removed;
    }
       
        
        
#endif /* Stack_hpp */
