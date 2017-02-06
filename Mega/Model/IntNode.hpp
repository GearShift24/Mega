//
//  IntNode.hpp
//  Mega
//
//  Created by Wrigley, Joseph on 2/6/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef IntNode_hpp
#define IntNode_hpp
#include <String>

using namespace std;

class IntNode
{
private:
    int nodeData;
    IntNode * nodePointer;

public:
    void start();
    
    //constructors
    IntNode();
    IntNode(int value);
    IntNode(int value, IntNode * nextNode);
    /*
     Creates an intnode with specified value and refrence to the next node.
     */
    
    //methods
    int getNodeData();
    IntNode * getNodePointer();
    void setNodeData(int value);
    void setNodePointer(IntNode * nextNode);
    

    
    
};


#endif /* IntNode_hpp */
