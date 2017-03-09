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

    testListTiming();
    
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

void DataStructureController :: testListTiming()
{
    DoubleList<int> timingList;
    for(int index = 0; index < 10000; index++)
    {
        timingList.add(rand());
    }
    
    long slowTme [1000];
    long fastTime [1000];
    double averageSlow = 0.00, averageFast = 0.00;
    Timer doubleTimer;
    
    for(int index = 0; index < 1000; index++)
    {
        int randomIndex = rand() % 10000;
        doubleTimer.startTime();
        timingList.getFromIndex(randomIndex);
        doubleTimer.stopTimer();
        slowTime[index] = doubleTimer.getExecutionTimeInMicroseconds();
        doubleTimer.resetTimer();
        
        doubleTimer.startTime();
        timingList.getFromIndexFast(randomIndex);
        doubleTimer.stopTimer();
        fastTime[index] = doubleTimer.getExecutionTimeInMicroseconds();
        
        averageSlow += slowTime[index];
        averageFast += fastTime[index];
    }
    
    averageSlow = averageSlow/1000.00;
    averageFast = averageFast/1000.00;
    
    cout << "The average speed for the getFromIndex method was: " << averageSlow << " microseconds." << endl;
    
      cout << "The average speed for the getFromIndexFast method was: " << averageFast << " microseconds." << endl;
    
    cout << "A time savings?? of: " << averageSlow - averageFast << " microseconds." << endl;
}
