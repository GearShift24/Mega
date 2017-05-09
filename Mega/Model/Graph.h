//
//  Graph.h
//  Mega
//
//  Created by Wrigley, Joseph on 5/9/17.
//  Copyright © 2017 CTEC. All rights reserved.
//

#ifndef Graph_h
#define Graph_h

#include <set>
#include <queue>
#include <assert.h>

using namespace std;
template <class Type>
class Graph
{
private:
    static const int MAXIMUM = 20;
    bool adjacencyMatrix [MAXMIMUM][MAXIMUM];
    Type graphData[MAXIMUM];
    int vertexCount;
    void depthFirstTraversal(Graph<Type> graph, int vertex, bool markedVerticies[]);
    
public:
    Graph();
    ~Graph();
    
    void addVertex(const Type& value);
    void addEdge(int source, int target);
    void removeEdge(int source, int target);
    Type& operator [] (int vertex);
    Type operator [] (int vertex) const;
    int size() const;
    bool areConnected(int source, int target) const;
    std::set<int> neighbors(int vertex) const;
    void depthFirstTraversal(Graph<Type> graph, int vertex);
    void breadthFirstTraversal(Graph<Type> graph, int vertex);
    
};

template <class Type>
const int Graph<Type> :: MAXIMUM;

template <class Type>
Graph<Type> :: Graph()
{
    this->vertexCount = 0;
}

template <class Type>
Graph<Type> :: ~Graph()
{
    delete [] this->adjacentMatrix;
    delete [] this->graphData;
}

template <class Type>
int Graph<Type> :: size() const
{
    return vertexCount;
}

template <class Type>
void Graph<Type> :: addVertex(const Type& value)
{
    assert(size() < MAXIMUM);
    int netVertexNumber = vertexCount;
    
    for(int otherVertexNumber = 0; otherVertexNumber < vertexCount; otherVertexNumber++)
    {
        adjacencyMatrix[otherVertexNumber][newVertexNumber] = false;
        [adjacencyMatrix[newVertexNumber] [otherVertexNumber] = false;
    }
         graphData[newVertexNumber = value;
}


#endif /* Graph_h */
