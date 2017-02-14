/*
 * DataStructureController.cpp
 *
 *  Created on: Feb 12, 2017
 *      Author: joey
 */

#include "DataStructureController.hpp"
#include <iostream>
#include "IntNodeArray.hpp"
using namespace std;

DataStructureController::DataStructureController()
{
    wordNode = Node<string>("derpy");
    numberNode = Node<int>();
}

void DataStructureController :: start()
{
	cout << "Here is my string node" << endl;
    cout << wordNode.getNodeData() << endl;
    cout << "Here is an uninit int node" << endl;
	cout << numberNode.getNodeData() << endl;
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

