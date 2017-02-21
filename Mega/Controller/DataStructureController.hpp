/*
 * DataStructureController.hpp
 *
 *  Created on: Feb 12, 2017
 *      Author: joey
 */

#ifndef DataStructureController_hpp
#define DataStructureController_hpp

#include "../Model/Array.hpp"
#include "../Model/Node.hpp"
#include <string>
using namespace std;


class DataStructureController
{
private:
    
    Node<int> numberNode;
    Node<string> wordNode;
    Array<int> numberArray;
    
    void testIntArray();
    void testNodeTypes();
    void testArrayTemplate();
    void testAdvancedFeatures();

public:
	DataStructureController();
	void start();

};

#endif /* DataStructureController_hpp */
