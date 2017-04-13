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
        insertMe->setRootPointer(previous);
    }
}

template <class Type>
bool BinarySearchTree<Type> :: contains(Type itemToFind)
{
    BinarySearchTreeNode<Type> * current = root;
    if(current == nullptr)
    {
        return false;
    }
    else
    {
        while(current != nullptr)
        {
            if(itemToFind == current->getNodeData())
            {
                return true;
            }
        else if(itemToFind < current->getNodeData())
        {
            current = current->getLeftChild();
        }
        else
        {
            current = current->getRightChild();
        }
    }
        return false;
    }
}

template <class Type>
void BinarySearchTree<Type> :: remove(Type getRidOfMe)
{
    if(root == nullptr)
    {
        cout << "empty tree so removal is not possible" << endl;
    }
    else
    {
        BinarySearchTreeNode<Type> * current = root;
        BinarySearchTreeNode<Type> * previous = nullptr;
        bool hadBeenFound = false;
        
        while(current != nullptr && !hadBeenFound)
        {
            if(current->getNodeData() == getRidOfMe)
            {
                hasBeenFound = true;
            }
            else
            {
                previous = current;
                if(getRidOfMe < current->getNodeData())
                {
                    current = current->getLeftChild();
                }
                else
                {
                    current = current->getRightChild();
                }
            }
        }
        
        if(current == nullptr)
        {
            cerr << "item not found, removal fail" << endl;
        }
        else if(hasBeenFound)
        {
            if(current == root)
            {
                removeNode(root);
            }
            else if(getRidOfMe < previous->getNodeData())
            {
                removeNode(previous->getLeftChild());
            }
            else
            {
                removeNode(previous->getRightChild());
            }
        }
    }
}

template <class Type>
void BinarySearchTree<Type> :: removeNode(BinarySearchTreeNode<Type> * & removeMe)
{
    BinarySerachTreeNode<Type> * current;
    BinarySerachTreeNode<Type> * previous;
    BinarySerachTreeNode<Type> * temp;
    
    previous = removeMe->getRoot();
    
    //leaf- has no kiddo
    if(removeMe->getRightChild() == nullptr && removeMe->getLeftChild() == nullptr)
    {
        temp = removeMe;
        removeMe = nullptr;
        
        if(previous != nullptr && removeMe->getNodeData() < previous->getNodeData())
        {
            previous->setLeftChild(removeMe);
        }
        else if(previous != nullptr && removeMe->getNodeData() > previous->getNodeData())
        {
            previous->setRightChild(removeMe);
        }
        
        delete temp;
    }
    //has only left child
    else if(removeMe->getRightChild == nullptr)
    {
        temp = removeMe;
        removeMe = removeMe->getLeftChild();
    
    if(previous != nullptr && temp->getNodeData() < previous->getNodeData())
    {
        previous->setLeftChild(removeMe);
        
    }
    else if(previous != nullptr && temp->getNodedata() > previous->getNodedata())
    {
        previous->setRightChild(removeMe);
   
    }
    removeMe->setRootPointer(previous);
    delete temp;
    }
//has only right
else if(removeMe->getLeftChild() == nullptr)
{
    temp = removeMe;
    removeMe = removeMe->getRightChild();
    
    if(previous != nullptr && removeMe->getNodeData() < previous->getNodeData())
    {
        previous->setLeftChild(removeMe);
    }
    else if(previous != nullptr && removeMe->getNodedata() > previous->getNodeData())
    {
        previous->setRightChild(removeMe);
    }
    removeMe->setRootPointer(previous);
    delete temp;
}
    //has both kids
    else
    {
        current = removeMe->getLeftChild();
        previous = nullptr;
        
        while(current->getRightChild != nullptr)
        {
            previous = current;
            current = current->getRightChild();
        }
        
        removeMe->setNodeData(current->getNodeData());
        
        if(previous == nullptr)
        {
            removeMe->setLeftChild(current->getLeftChild());
            current->getLeftChild()->setRootPointer(removeMe);
        }
        else
        {
            previous->setRightChild(current->getLeftChild());
            current->getLeftChild()->setRootPointer(previous);
        }
        
    }

//has both children

#endif /* BinarySearchTree_h */
