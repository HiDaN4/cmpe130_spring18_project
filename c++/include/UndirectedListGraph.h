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

    bool operator==(const Node& rhs)
    {
        return this->vertexPtr->getValue() == rhs.vertexPtr->getValue();
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
    T getValue(){return value;}
    forward_list<Node<T> > getListOfNodes(){return listOfNodes;}

    bool operator==(const Vertices& rhs) {
        return this->value == rhs.value;
    }
};

template <class T>
class UndirectedListGraph : public Graph<T>
{
private:
    vector < Vertices<T> > adjList;
    int count;
    using Graph<T>::totalNumberOfVertices;

public:
    UndirectedListGraph() : Graph<T>(), count(0) { }

    virtual void addVertex(const T& value);
    virtual void removeVertex(const T& value);

    virtual void addEdge(const T& fromValue, const T& toValue, double cost);
    virtual void removeEdge(const T& fromValue, const T& toValue);

    virtual string toString();    //rough display function which displays the edges between vertices.
    virtual int lookUpVertex(const T &value);

};

#include "UndirectedListGraph.cpp"
#endif //CMPE130PROJECT_UNDIRECTEDLISTGRAPH_H
