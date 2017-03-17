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
    testMemeQueue();
      testNumberStack();
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

    testMemeQueue();
    testNumberStack();
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
    
    long slowTime [1000];
    long fastTime [1000];
    double averageSlow = 0.00, averageFast = 0.00;
    Timer doubleTimer;
    
    for(int index = 0; index < 1000; index++)
    {
        int randomIndex = rand() % 10000;
        doubleTimer.startTimer();
        timingList.getFromIndex(randomIndex);
        doubleTimer.stopTimer();
        slowTime[index] = doubleTimer.getExecutionTimeInMicroseconds();
        doubleTimer.resetTimer();
        
        doubleTimer.startTimer();
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
















//test meme section

void DataStructureController :: testMemeQueue()
{
    Meme datMeme("dat boi");
    Meme cenaMeme("Johnnnn cena!");
    Meme sithMeme("Lord Sideous shooting star whooooo.");
    
    
    datMeme.setHipsterQuotient(200.00);
        cenaMeme.setHipsterQuotient(100000.00);
        sithMeme.setHipsterQuotient(2070.00);
    
    sithMeme.setMainstream(true);
    
    cenaMeme.setDankness(10000);
     sithMeme.setDankness(68);
    
    Queue<Meme> memeQueue;
    memeQueue.add(datMeme);
    memeQueue.enqueue(cenaMeme);
    memeQueue.enqueue(sithMeme);
    
        memeQueue.remove(0);
    
    cout << "- Since you are probably a normie you will love this new mainstream meme! It is called" << sithMeme.getTitle() << " and as you can see the fact that it is mainstream is " << sithMeme.isMainstream() << "." << endl;
    
    
    cout << "-Did you know that john cena has a dankness of: " << cenaMeme.getDankness() << "." << endl;
    
    
    Meme temp = memeQueue.dequeue();
    cout<< "-The top meme you tried to kill was: " << temp.getTitle() << " but heroes never die, well i mean it did die but here ist the info of its hipsterness " << temp.getHispterQuotient() << "." <<endl;
    
    cout<< "-If you were wondering there are " << memeQueue.getSize() << " amount of memes in this queue, ayy!" << endl;
    
    cout << "-The Dankness of the first meme in the line of the queue is: " << memeQueue.peek().getDankness() << " which is pretty cool if you ask me." << endl;
    
}


void DataStructureController :: testNumberStack()
{
    int num1;
    int num2;
    int num3;
    
    
   
    Stack<int> numberStack;
    
    numberStack.push(num2);
    numberStack.add(num1);
    numberStack.push(num3);
    
    cout << " " << endl;
     cout << " " << endl;
     cout << " " << endl;
  
    cout << "-The top number right now is " << numberStack.peek()<< endl;
      numberStack.push(num2);
    
    int temp = numberStack.pop();
    cout << "-You killed the " << temp << endl;
    numberStack.push(num1);
    
    
   numberStack.remove(numberStack.getSize()-1);
    cout << "-The final size of the stack is " << numberStack.getSize() << " and the top thing is " << numberStack.peek()<<endl;
}
