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
}
#endif /* DoubleList_hpp */
