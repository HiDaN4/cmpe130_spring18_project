//
// Created by Mian Hashim Shah on 4/4/18.
//

#ifndef CMPE130PROJECT_GRAPH_H
#define CMPE130PROJECT_GRAPH_H

#include <iostream>
using namespace std;

//Vertex class which defines a vertex which holds an ID and a Value (which is a template)
template <class T>
class Vertex
{
private:
    int vertexID; //id of node
    T value;    // value the node contains

public:
    //constructor for Vertex node
    Vertex(int ID, T val)
    {
        vertexID = ID;
        value = val;
    }

    //getters
    int getID()
    {
        return vertexID;
    }

    T getValue()
    {
        return value;
    }

    //operator overloads
    bool operator<(Vertex &b)
    {
        if (this->value< b.value&& this->getID() < b.getID())
        {
                return true;
        }
        return false;
    }

    bool operator<=(Vertex &b)
    {
        if (this->value <= b.value&& this->getID() <= b.getID())
        {
            return true;
        }
        return false;
    }

    bool operator>( Vertex &b)
    {
        if (this->value > b.value&& this->getID() > b.getID())
        {
            return true;
        }
        return false;
    }

    bool operator>=(Vertex &b)
    {

        if (this->value >= b.value&& this->getID() >= b.getID())
        {
            return true;
        }
        return false;
    }

    bool operator==(Vertex<T> &b)
    {
         if (this->value == b.value && this->getID() == b.getID())
        {
            return true;
        }
        return false;
    }
};

//Abstract graph class inherited by
//1. UndirectedMatrixGraph
//2. UndirectedListGraph
template <class T>
class Graph
{
public:
     int totalNumberOfVertices; //number of vertices
public:

    //TODO:Fix this constructor and its base constructor
    //pure virtual functions which are supposed to be inherited by child Classes
    Graph(int numOfVertices): totalNumberOfVertices(numOfVertices)
    {
        //totalNumberOfVertices = numOfVertices;//getNumberOfVertices();
    }

    //getter to return the number of nodes in graph
    int getNumberOfVertices()
    {
        return totalNumberOfVertices;
    }
    //settter to set the number of nodes in graph
    void setNumberOfVertices(int x)
    {
        totalNumberOfVertices = x;
    }

    //virtual functions which are inherited and implemented by child classes
    virtual void addVertex(T* value) = 0;
    virtual void removeVertex(Vertex<T> * deleteThisVertex)=0;
    virtual int lookUpVertex(Vertex<T> * v) = 0;

    //virtual void addEdge(Vertex<T> * fromVertex, Vertex<T> * toVertex) = 0;
    virtual void addEdge(Vertex<T> * fromVertex, Vertex<T> * toVertex, double cost) = 0;
    virtual void removeEdge(Vertex<T> * fromVertex, Vertex<T> * toVertex) = 0;


    //rough display function which displays the edges between vertices.
    virtual void display() = 0;

};


#endif //CMPE130PROJECT_GRAPH_H
