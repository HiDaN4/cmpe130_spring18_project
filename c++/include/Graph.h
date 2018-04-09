//
// Created by Mian Hashim Shah on 4/4/18.
//

#ifndef CMPE130PROJECT_GRAPH_H
#define CMPE130PROJECT_GRAPH_H

#include <iostream>
#include <string>
using namespace std;

//Vertex class which defines a vertex which holds an ID and a Value (which is a template)
template <class T>
class Vertex
{
private:
    int vertexID; // id of node
    T value;    // value the node contains
    static int vertexIDCounter;

public:
    //constructor for Vertex node
    explicit Vertex(T val)
    {
        vertexID = Vertex::vertexIDCounter++;
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
    bool operator<(const Vertex &b)
    {
        return this->value < b.value;
    }

    bool operator<=(const Vertex &b)
    {
        return this->value <= b.value;
    }

    bool operator>(const Vertex &b)
    {
        return this->value > b.value;
    }

    bool operator>=(const Vertex &b)
    {

        return this->value >= b.value;
    }

    bool operator==(const Vertex<T> &b)
    {
        return this->value == b.value;
    }
};

template <class T>
int Vertex<T>::vertexIDCounter = 0;

//Abstract graph class inherited by
//1. UndirectedMatrixGraph
//2. UndirectedListGraph
template <class T>
class Graph
{
protected:
    int totalNumberOfVertices; //number of vertices

private:
    virtual int lookUpVertex(const T &value) = 0;
public:

    //pure virtual functions which are supposed to be inherited by child Classes
    explicit Graph(int numOfVertices): totalNumberOfVertices(numOfVertices)
    {
    }

    //getter to return the number of nodes in graph
    int getNumberOfVertices()
    {
        return totalNumberOfVertices;
    }
    // setter to set the number of nodes in graph
    void setNumberOfVertices(int x)
    {
        totalNumberOfVertices = x;
    }

    //virtual functions which are inherited and implemented by child classes
    virtual void addVertex(const T& value) = 0;
    virtual void removeVertex(const T& value)=0;

    virtual void addEdge(const T& fromValue, const T& toValue, double cost) = 0;
    virtual void removeEdge(const T& fromValue, const T& toValue) = 0;


    //rough display function which displays the edges between vertices.
    virtual string toString() = 0;

};


#endif //CMPE130PROJECT_GRAPH_H
