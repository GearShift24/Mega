//
//  Node.hpp
//  Mega
//
//  Created by Wrigley, Joseph on 2/13/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp


template <class Type>
class Node
{
private:
    Type nodeData;
    Node<Type>* nextPointer;
public:
    Node<Type>();
    Node<Type>(Type data);
    Node<Type>(Type data, Node<Type> * nextPointer);
    
    
    Type getNodeData();
    Node<Type> * getNextPointer();
    void setNodeData(Type value);
    void setNextPointer(Node<Type> * nextPointer);
};


/*
 Implementaion section of the templated Class!
 */

template <class Type>
Node<Type> :: Node()
{
    nextPointer = nullptr;
    //Excplicitly NOT initilizing node data b/c i do not know what type it is.
}

template <class Type>
Node<Type> :: Node(Type data)
{
    this->nodeData = data;
    this->nextPointer = nullptr;
}

template <class Type>
Node<Type> :: Node(Type value, Node<Type> * nextNode)
{
    this->NodeData = value;
    this->nextPointer = nextNode;
}


//getters / setters

template <class Type>
Type Node<Type> :: getNodeData()
{
    return nodeData;
}


template <class Type>
Node<Type> *Node<Type> :: getNextPointer()
{
    return nextPointer;
}

template <class Type>
void Node<Type> :: setNodeData(Type data)
{
    this->nodeData = data;
}

template <class Type>
void Node<Type> :: setNextPointer(Node<Type> * pointer)
{
    this->nextPointer = pointer;
}

#endif /* Node_hpp */




