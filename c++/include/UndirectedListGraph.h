//
// Created by Mian Hashim Shah on 4/8/18.
//

#ifndef CMPE130PROJECT_UNDIRECTEDLISTGRAPH_H
#define CMPE130PROJECT_UNDIRECTEDLISTGRAPH_H
#include "Graph.h"
#include <forward_list>

template <class T>
class Node
{
    double cost;
    T value;
    Node * next;
public:
    Node(T val, double c)
    {
        cost = c;
        T value = val;
        next = nullptr;
    }
};

template <class T>
class UndirectedListGraph : public Graph<T>
{
private:
    forward_list<Node<T>> * adjList;
    int count;
public:
    explicit UndirectedListGraph(int numOfVertices) : Graph<T>(numOfVertices)
    {
        adjList = new forward_list<Node<T>>[numOfVertices];
        for (int i = 0; i < numOfVertices; i++)
        {
            adjList = new forward_list<Node<T>>[10];
        }
        count = 0;
    }
     void addVertex(Node<T> * Node)
    {
        adjList->emplace_front(Node);

    }
    void removeVertex(Vertex<T> * deleteThisVertex){}
    void addEdge(Vertex<T> * fromVertex, Vertex<T> * toVertex, double cost){}
    void removeEdge(Vertex<T> * fromVertex, Vertex<T> * toVertex){}
    int lookUpVertex(Vertex<T> * v) {return 0;}
    virtual string toString(){ return ""; }
};


#endif //CMPE130PROJECT_UNDIRECTEDLISTGRAPH_H
