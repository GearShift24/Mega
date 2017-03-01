//
//  Stack.hpp
//  Mega
//
//  Created by Wrigley, Joseph on 3/1/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef Stack_hpp
#define Stack_hpp


template <class Type>
class Stack : DoublyLinkedList<Type>
{
private:
public:
    Stack();
    void add(Type value);
};


template <class Type>
void Stack<Type> :: add(Type valuetoAdd) : DoublyLinkedList :: add (valueToAdd)
{
    
}

#endif /* Stack_hpp */
