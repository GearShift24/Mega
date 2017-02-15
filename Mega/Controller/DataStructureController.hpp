/*
 * DataStructureController.hpp
 *
 *  Created on: Feb 12, 2017
 *      Author: joey
 */

#ifndef DataStructureController_hpp
#define DataStructureController_hpp

#include "../Model/Array.h"
#include "../Model/Node.hpp"
#include <string>
using namespace std;


class DataStructureController
{
private:
	void testIntArray();
    
    Node<int> numberNode;
    Node<string> wordNode;
    void textIntArray();
    void testNodeTypes();

public:
	DataStructureController();
	void start();

};

#endif /* DataStructureController_hpp */
