//
//  BiDirectionalNode.hpp
//  Mega
//
//  Created by Wrigley, Joseph on 2/27/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef BiDirectionalNode_hpp
#define BiDirectionalNode_hpp


template <class Type>
class BiDirectionalNode : public Node<Type>
{
private:
//    Type data; removed as the data member will be inherited from node
    BiDirectionalNode<Type> * nextPointer;
    BiDirectionalNode<Type> * previous;
public:
    BiDirectionalNode();
    BiDirectionalNode(Type data);
    BiDirectionalNode(Type data, BiDirectionalNode<Type> * previous, BiDirectionalNode<Type> * next);
    
    
//    Type getNodeData();
    BiDirectionalNode<Type> * getNextPointer();
    BiDirectionalNode<Type> * getPreviousPointer();
    
//    void setNodeData(Type data);
    void setNextPointer(BiDirectionalNode<Type> * next);
    void setPreviousPointer(BiDirectionalNode<Type> * previous);
};

template <class Type>
BiDirectionalNode<Type> :: BiDirectionalNode() : Node<Type>()
{
    this->nextPointer = nullptr;
    this->previous = nullptr;
}





template <class Type>
BiDirectionalNode<Type> :: BiDirectionalNode(Type data) : Node(data)
{
    this->nextPointer = nullptr;
    this->previous = nullptr;
}

Templace <class Type>
BiDirectionalNode<Type> ::    BiDirectionalNode(Type data, BiDirectionalNode<Type> * previous, BiDirectionalNode<Type> * next) : Node(data, next)
{
    this->nextPointer = next;
    this->previous = previous;
}





//getters/setters

template <class Type>
BiDirectionalNode<Type> * BiDirectionalNode<Type> :: getNextPointer()
{
    return this->nextPointer;
}

template <class Type>
BiDirectionalNode<Type> * BiDirectionalNode<Type> :: getPreviousPointer()
{
    return this->previous;
}





template <class Type>
void BiDirectionalNode<Type> * BiDirectionalNode<Type> :: setNextPointer(BiDirectionalNode<Type> * next)
{
    return this->nextPointer;
}

template <class Type>
void BiDirectionalNode<Type> * BiDirectionalNode<Type> :: setPreviousPointer(BiDirectionalNode<Type> * previous)
{
    return this->previous;
}



#endif /* BiDirectionalNode_hpp */
