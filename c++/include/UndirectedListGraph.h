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
    vector < forward_list<Node<T> > > adjList;
    int count;
public:
    explicit UndirectedListGraph(int numOfVertices) : Graph<T>(numOfVertices)
    {
        count = 0;
    }

     void addVertex(T * value, double c)
    {
        Node<T> * node = new Node<T>(value, c);//create a new node


        if (value != nullptr)//check
        {


        }


    }
    void removeVertex(Vertex<T> * deleteThisVertex){}
    void addEdge(Vertex<T> * fromVertex, Vertex<T> * toVertex, double cost){}
    void removeEdge(Vertex<T> * fromVertex, Vertex<T> * toVertex){}
    int lookUpVertex(Vertex<T> * v) {return 0;}
    virtual string toString(){ return ""; }
};


#endif //CMPE130PROJECT_UNDIRECTEDLISTGRAPH_H
