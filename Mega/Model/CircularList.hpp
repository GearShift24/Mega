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
class CircularList : DoublyLinkedList<Type>
{
private:
public: CircularList();
    ~CircularList();
    
}

template <class Type>
CircularList<Type> :: CircularList() : DoublyLinkedList<Type>()
{
    
}


template <class Type>
CircularList<Type> :: ~CircularList() : DoublyLinkedList<Type>()
{
    BiDirectionalNode<Type> * remove = this->getFront();
    while(this->getFront() != nullptr)
    {
        this->setFront(this->getFront()->getNextPointer());
        delete remove;
        remove = this->getFront();
    }
}



#endif /* CircularList_hpp */
