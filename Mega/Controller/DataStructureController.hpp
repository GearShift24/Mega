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
#include "../Model/Timer.hpp"
#include "../Model/IntNodeArray.hpp"
#include "../Model/List.hpp"
#include "../Model/DoubleList.hpp"
#include "../Model/Stack.hpp"
#include "../Model/Queue.hpp"
#include "../Model/CircularList.hpp"
#include <string>
using namespace std;


class DataStructureController
{
private:

    Array<int> numberArray;
    
    void testIntArray();
    void testNodeTypes();
    void testArrayTemplate();
    void testAdvancedFeatures();
    void testListTiming();
    
    void testListIntro();

public:
	DataStructureController();
	void start();

};

#endif /* DataStructureController_hpp */
