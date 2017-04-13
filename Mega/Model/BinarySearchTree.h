//
//  BinarySearchTree.h
//  Mega
//
//  Created by Wrigley, Joseph on 4/11/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef BinarySearchTree_h
#define BinarySearchTree_h

#include "Tree.h"

template <class Type>
class BinarySearchTree : public Tree<Type>
{
private:
    BinarySearchTreeNode<Type> * root;
    
    int calculateSize(BinarySearchTreeNode<Type> * root);
    void inOrderTraversal(BinarySearchTreeNode<Type> * inStart);
    void preOrderTraversal(BinarySearchTreeNode<Type> * preStart);
    void postOrderTraversal(BinarySearchTreeNode<Type> * postStart);
    
    void removeNode(BinarySearchTreeNode<Tree> * & removeMe);
    
public:
    BinarySearchTree();
    ~BinarySearchTree();
    
    BinarySearchTreeNode<Type> * getRoot();
    void setRoot(BinarySearchTreeNode<Type> * root);
    
    void printToFile();
    
    void inOrderTraversal();
    void preOrderTraversal();
    void postOrderTraversal();
    
    bool contains(Type value);
    void insert(Type itemToInsert);
    void remove(Type value);
};

template <class Type>
BinarySearchTree<Type> :: BinarySearchTree() : Tree<Type>()
{
    this->root = nullptr;
}

template <class Type>
BinarySearchTree<Type> :: ~BinarySearchTree() : Tree<Type>()
{
   
}

template <class Type>
BinarySearchTreeNode<Type> * BinarySearchTree<Type> : getRoot()
{
    return this->root;
}

template <class Type>
void BinarySearchTree<Type> :: setRoot(BinarySearchTreeNode<Type> * root)
{
    this->root = root;
}

template <class Type>
void BinarySearchTree<Type> :: inOrderTraversal()
{
    
}
template <class Type>
void BinarySearchTree<Type> :: preOrderTraversal()
{
    
}
template <class Type>
void BinarySearchTree<Type> :: postOrderTraversal()
{
    
}

template <class Type>
int BinarySearchTree<Type> :: calculateSize(BinarySearchTreeNode<Type> * start)
{
    return -99;
}

template <class Type>
int BinarySearchTree<Type> :: inOrderTraversal(BinarySearchTreeNode<Type> * inStart)
{
    
}

template <class Type>
int BinarySearchTree<Type> :: preOrderTraversal(BinarySearchTreeNode<Type> * preStart)
{
    
}

template <class Type>
int BinarySearchTree<Type> :: postOrderTraversal(BinarySearchTreeNode<Type> * postStart)
{
    
}


template <class Type>
void BinarySearchTree<Type> : insert(Type itemToInsert)
{
    BinarySearchTreeNode<Tree> * insertMe = new BinarySearchTreeNode<Type>(itemToInsert);
    BinarySearchTreeNode<Tree> * previous = nullptr;
    BinarySearchTreeNode<Tree> * current = root;
    if(current == nullptr)
    {
        root = insertMe;
    }
    else
    {
            while(current != nullptr)
            {
                previous = current;
                if(itemToInsert < current->getNodeData())
                {
                    current = current->getLeftChild()
                }
                else if(itemToInsert > current->getNodeData())
                {
                    current = current->getRightChild();
                }
                else
                {
                    cerr << "item always exists bruh - exiting" << endl;
                    delete insertMe;
                    return;
                }
            }
        
        if(previous->getNodeData() > itemToInsert)
        {
            previous->setLeftChild(insertMe);
        }
        else
        {
            previous->setRightChild(insertMe);
        }
        insertMe->setRoot(previous);
    }
}

#endif /* BinarySearchTree_h */
