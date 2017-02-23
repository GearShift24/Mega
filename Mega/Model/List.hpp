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
    Node<Type> * end;
    int size;
    
public:
    //constructors
    List<Type>();
    List<Type>(const List<Type> & source);
    ~List<Type>();
    
    //methods
    
    int getSize() const;
    Node<Type> * getFront() const;
    Node<Type> * getEnd() const;
    
    
    void addAtIndex(int index, Type value);
    void add(Type value);
    Type remove(int index);
    Type setAtIndex(int index, Type data);
    Type getFromIndex(int index);
    bool contains(Type data);
    
    


   };


//constructors implemented
template <class Type>
List<Type> :: List()
{
    this->size = 0;
    this->front = nullptr;
    this->end = nullptr;
}
//
//template <class Type>
//List<Type> :: List(const List<Type> & source)
//{
//    
//}
//
//template <class Type>
//List<Type> :: ~List()
//{
//    
//}





//methods implemented
template <class Type>
void List<Type> :: addFront(Type value)
{
    if(size ==0)
       {
           //gives you the way to get to the front here, then you add l8r g8r
           Node<Type> * first = new Node(value);
           this->front = first;
           this->end = first;
       }
    else
    {
        Node<Type> * newFirst = new Node<Type>();
        newFirst->setNodeData(value);
        newFirst->setNodePointer(front);
        //or
//        Node<Type> * newFirst = new Node<Type>(value, front);
        front = newFirst;
        
        
    }
    
    size++;
}



#endif /* List_hpp */
