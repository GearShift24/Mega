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
class List
{
private:
    Node<Type> * front;
    Node<Type> * end;
    int size;
    
public:
    //constructors
    List<Type>();
    List<Type>(const List<Type> & source);
//    ~List<Type>();
    
    //methods
    
    int getSize() const;
    Node<Type> * getFront() const;
    Node<Type> * getEnd() const;
    
    void addFront(Type value);
    void addEnd(Type value);
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
           Node<Type> * first = new Node<Type>(value);
           this->front = first;
           this->end = first;
       }
    else
    {
        Node<Type> * newFirst = new Node<Type>();
        newFirst->setNodeData(value);
        newFirst->setNextPointer(front);
        //or
//        Node<Type> * newFirst = new Node<Type>(value, front);
        front = newFirst;
    }
    
    size++;
}




template <class Type>
void List<Type> :: addEnd(Type data)
{
    
    Node<Type> * added = new Node<Type>(data);
    if(size == 0)
    {
        this->front = added;
        this->end = added;
    }
    
    else
    {
        end->setNextPointer(added);
        this->end = added;
    }
    
    size++;
}

template <class Type>
void List<Type> :: addAtIndex(int index, Type value)
{
    assert(index >= 0 && index <= size);
    if(index == 0)
    {
        addFront(value);
    
    }
    else if(index == size)
    {
        addEnd(value);

    }
    else
    {
        Node<Type> * insertedNode = new Node<Type>(value);
        Node<Type> * current = front;
        Node<Type> * previous = nullptr;
        
        for(int position = 0; position < index; position++)
        {
            previous = current;
            current = current->getNextPointer();
        }
        
        previous->setNextPointer(insertedNode);
        insertedNode->setNextPointer(current);
        
        size++;
    }
        
                  
    
}

template <class Type>
Type List<Type> :: getFromIndex(int index)
{
    assert(index >=0 && index < size);
    Type value;
    
    Node<Type> * current = front;
    
    for(int position = 0; position < index; position++)
    {
        current = current->getNextPointer();
    }
    value = current->getNodeData();
    return value;
}


template <class Type>
Type List<Type> :: setAtIndex(int index, Type value)
{
    assert(index >= 0 && index < size);
    Node<Type> * current = front;
    for(int position = 0; position < index; position++)
    {
        current = current->getNextPointer();
    }
    
    current->setNodeData(value);
}


template <class Type>
Type List<Type> :: remove(int index)
{
    assert(index >= 0 && index < size);
    Type removed;
    
    Node<Type> * current = front;
    Node<Type> * previous = nullptr;
    Node<Type> * toBeRemoved = nullptr;
    
    
    
    if(index == 0)
    {
        toBeRemoved = front;
        front = front->getNextPointer();
    }
    else if(index == size - 1)
    {
        for(int spot = 0; spot < index; spot++)
        {
            previous = current;
            current = current->getNextPointer();
        }
        
        toBeRemoved = current;
        current->setNextPointer(nullptr);
        this->end = previous;
        
        
    }
    
    else
    {
        for(int spot = 0; spot < index; spot++)
        {
            previous = current;
            current = current->getNextPointer();
        }
        
        toBeRemoved = current;
        current = toBeRemoved->getNextPointer();
        previous->setNextPointer(current);
    }
    
    removed = toBeRemoved->getNodeData();
    
    delete toBeRemoved;
    
    
    size--;
    return removed;
}



template <class Type>
bool List<Type> :: contains(Type findMe)
{
    bool isInList = false;
    Node<Type> * current = front;
    
    for (int index = 0; index < size; index++)
    {
        if(current->getNodeData == findMe)
        {
            isInList = true;
            return isInList;
        }
        current = current->getNodePointer();
    }
    return isInList;
}


#endif /* List_hpp */
