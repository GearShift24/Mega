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
class Stack : DoublyLinkedList<Type>
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
 the add method only adds to the end on a stack. Never at an index.
 
 */
template <class Type>
void Stack<Type> :: add(Type valuetoAdd)
{
    push(valueToAdd);
}

/*
 Adds supplied object to the stack to the end.
 Set new object to point to end
 Increase the size by 1.
 adjusts the end pointer to reflect the new end of the stack.
*/
templace <class Type>
void Stack<Type> :: push(Type addedThing)
{
    BiDirectionalNode<Type> * addToStack = new BiDirectionalNode(addedThing);
    
    if(this->size == 0 || this->front == nullptr || this->end == nullptr)
    {
        this->front = addToStack;
    }
    else()
    {
        this->end->setNextPointer(addToStack);
        addToStack ->setPreviousPointer(this->end);
    }
    
    this->end = addToStack;
    this->size++;

}

#endif /* Stack_hpp */
