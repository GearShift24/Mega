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
#include "../Model/Meme.hpp"
#include <string>
#include "../Model/Graph.h"
using namespace std;


class DataStructureController
{
private:

//    Array<int> numberArray;

        Graph<string> JoJoGraph;
    
//    void testIntArray();
//    void testNodeTypes();
//    void testArrayTemplate();
//    void testListIntro();
//    void testAdvancedFeatures();
//    void testListTiming();
//    //meme testing
//    void testMemeQueue();
//    void testNumberStack();
//    //testing
//    void testBinarySearchTreeOperations();
//
    
    //test JoJos
    void testGraph();
    


public:
	DataStructureController();
	void start();

};

#endif /* DataStructureController_hpp */
