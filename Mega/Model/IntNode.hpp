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
    IntNode * nextPointer;

public:
    void start();
    
    //constructors
    IntNode();
    IntNode(int value);
    /*
      Creates an intnode with specified value and refrence to the next node.
      */
    IntNode(int value, IntNode * nextNode);

    
    //methods
    int getNodeData();
    IntNode * getNextPointer();
    void setNodeData(int value);
    void setNextPointer(IntNode * nextNode);
    

    
    
};


#endif /* IntNode_hpp */
