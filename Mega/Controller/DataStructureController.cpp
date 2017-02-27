/*
 * DataStructureController.cpp
 *
 *  Created on: Feb 12, 2017
 *      Author: joey
 */

#include "DataStructureController.hpp"
#include <iostream>
#include "../Model/Timer.hpp"
#include "IntNodeArray.hpp"
#include "List.hpp"
#include "Array.hpp"

using namespace std;

DataStructureController :: DataStructureController()
{
    wordNode = Node<string>("derpy");
    numberNode = Node<int>();
    this->numberArray = Array<int>(1);
}


void DataStructureController :: testArrayTemplate()
{
    cout << "Array Template" << endl;
    
    Timer arrayTimer;
    arrayTimer.startTimer();
    arrayTimer.stopTimer();
    arrayTimer.displayTimerInformation();
    arrayTimer.resetTimer();
    arrayTimer.startTimer();
    numberArray = Array<int>(9);
    arrayTimer.stopTimer();
    arrayTimer.displayTimerInformation();
    
}






void DataStructureController :: start()
{
    cout << "going to test the Array Template" << endl;
    testAdvancedFeatures();
    cout << "finished template testing" << endl;
    
}



void DataStructureController :: testAdvancedFeatures()
{
    int showDestructor = 0;
    
    if(showDestructor < 1)
    {
        Array<string> words = Array<string>(5);
        cout << "There should be messages destructor next" <<endl;
    }
    Array<string> words  = Array<string>(4);
    words.setAtIndex(0, "at zero");
    words.setAtIndex(3, "in the last spot");
    Array<string> copiedWords = Array<string>(words);
    
    cout << "these shoould match:" << endl;
    cout << words.getFromIndex(0) << " should be the same as " << copiedWords.getFromIndex(0) << endl;
    
    copiedWords.setAtIndex(3, "changed the contents of the copied Array");
}







void DataStructureController :: testIntArray()
{
	cout << "testing the array" << endl;

	IntNodeArray temp = IntNodeArray(3);

	for (int index = 0; index < 3; index++)
	{
		cout << temp.getFromIndex(index) << "  is at spot " << index << endl;
	}

	cout << "Testing IntNodeArray input" << endl;

	for(int index = 0; index < 3; index++)
	{
		temp.setAtIndex(index,index);

	}

	cout << "Verifying input via output." << endl;

	for(int index = 0; index < temp.getSize(); index++)
	{
		cout << temp.getFromIndex(index) << " is at spot  " << index << endl;
	}
}





void DataStructureController:: testListIntro()
{
    List<int> sample;
    sample.addFront(2);
    sample.addEnd(3);
    sample.addFront(1);
    cout<< "size shud b 1,2,3" << endl;
    
  
    
    
}
