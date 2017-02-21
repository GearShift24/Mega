//
//  List.hpp
//  Mega
//
//  Created by Wrigley, Joseph on 2/21/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef List_hpp
#define List_hpp


#include <assert.h>
#include "Node.hpp"


template <class Type>
class Array
{
private:
    Node<Type> * front;
    int size;
    
public:
    //constructors
    List<Type>();
    List<Type>(const List<Type> & source);
    ~List<Type>();
    
    //methods
    void addAtIndex(int index, Type value);
    void add(Type value);
    Type remove(int index);
    Type setAtIndex(int index, Type data);
    Type getFromIndex(int index);
    bool contains(Type data);
    int getSize() const;
    Node<Type> * getFront() const;
};










#endif /* List_hpp */
