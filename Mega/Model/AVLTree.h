//
//  AVLTree.h
//  Mega
//
//  Created by Wrigley, Joseph on 4/19/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef AVLTree_h
#define AVLTree_h

template <class Type>
class AVLTree : public BinarySearchTree<Type>
{
private:
    
    BinarySearchTreeNode<Type> * leftRotation(BinarySearchTreeNode<Type> * parent);
    BinarySearchTreeNode<Type> * rightRotation(BinarySearchTreeNode<Type> * parent);
    BinarySearchTreeNode<Type> * leftRightRotation(BinarySearchTreeNode<Type> * parent);
    BinarySearchTreeNode<Type> * rightLeftRotation(BinarySearchTreeNode<Type> * parent);
    
    BinarySearchTreeNode<Type> * balanceSubTree*BinarySearchTreeNode<Type> * parent);
    
    BinarySearchTreeNode<Type> * insertNode(BinarySearchTreeNode<Type> * parent);
    BinarySearchTreeNode<Type> * removeNode(BinarySearchTreeNode<Type> * parent);
    
    int heightDifference(BinarySearchTreeNode<Type> * parent);

public:
    AVLTree();
    ~AVLTree();
    
    void insert(Type itemToInsert);
    void remove(Type value);
};


#endif /* AVLTree_h */