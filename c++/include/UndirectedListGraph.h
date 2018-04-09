//
// Created by Mian Hashim Shah on 4/8/18.
//

#ifndef CMPE130PROJECT_UNDIRECTEDLISTGRAPH_H
#define CMPE130PROJECT_UNDIRECTEDLISTGRAPH_H
#include "Graph.h"
#include <forward_list>

template <class T>
class Vertices;

template <class T>
class Node
{
    double cost;
    Vertices<T> * vertexPtr;
public:
    Node(Vertices<T> * ptr, double nodeCost)
    {
        cost = nodeCost;
        vertexPtr = ptr;
    }
};

template <class T>
class Vertices
{
private:
    forward_list<Node<T> > listOfNodes;
    T value;
public:
    Vertices(T val)
    {
        value = val;
    }
};

template <class T>
class UndirectedListGraph : public Graph<T>
{
private:
    vector < Vertices<T> > adjList;
    int count;

public:
    explicit UndirectedListGraph(int numOfVertices) : Graph<T>(numOfVertices), count(0) {}

    virtual void addVertex(const T& value);
    virtual void removeVertex(const T& value);

    virtual void addEdge(const T& fromValue, const T& toValue, double cost);
    virtual void removeEdge(const T& fromValue, const T& toValue);

    virtual string toString();    //rough display function which displays the edges between vertices.
    virtual int lookUpVertex(const T &value);

};

#include "UndirectedListGraph.cpp"
#endif //CMPE130PROJECT_UNDIRECTEDLISTGRAPH_H
