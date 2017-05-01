//
//  HashTable.h
//  Mega
//
//  Created by Wrigley, Joseph on 5/1/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef HashTable_h
#define HashTable_h



#include <cmath>
#include <assert.h>

using namespace std;
template<class Type>
class HashTable
{
private:
    long capacity;
    long size;
    double efficiencyPercentage;
    HashNode<Type> * * hashTableStorage;
    bool isPrime(long sampleNumber);
    void resize();
    long nextPrime(long current);
    long findPosition(Type data);
    long handleCollision(Type data, long currentPosition);
    
    
public:
    HashTable();
    ~HashTable();
    void add(Type data);
    bool remove(Type data);
    void displayContents();
};

template <class Type>
HashTable<Type> :: HashTable()
{
    this->capacity = 101;
    this->efficiencyPercentage = .667;
    this->size = 0;
    this->hashTableStorage = HashNode<Type> * [capacity];
}

template <class Type>
HashTable<Type> :: ~HashTable()
{
    delete [] hashTableStorage;
}

template <class Type>
intt HashTable<Type> :: getNextPrime()
{
    int nextPrime = (this->capacity * 2) + 1;
    while(!isPrime(nextPrime))
    {
        nextPrime++;
    }
    return nextPrime;
}


template <class Type>
bool HashTable<Type> :: isPrime(long canidateNumber)
{
    if(canidateNumber < = 1)
    {
        return false;
    }
    else if(canidateNumber == 2 || canidateNumber == 3)
    {
        return true;
        
    }
    else if(canidateNumber % 2 == 0)
    {
        return false;
    }
    else
    {
        for(int next = 3; next <= sqrt(canidateNumber) +1; next += 2)
        {
            if(canidateNumber % next == 0)
            {
                return false;
            }
            
        }
        return true;
    }
}


#endif /* HashTable_h */
