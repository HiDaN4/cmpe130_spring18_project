//
// Created by Mian Hashim Shah on 4/4/18.
//

#ifndef CMPE130PROJECT_GRAPH_H
#define CMPE130PROJECT_GRAPH_H

#include <iostream>
#include <string>
#include <ostream>
#include <list>
#include <vector>

class CurrencyPair;


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

    T getValue() const
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


    bool operator==(const T& objType)
    {
        return this->value == objType;
    }

    friend std::ostream&operator << (std::ostream& stream, const Vertex<T> obj) {
        stream << obj.value;
        return stream;
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
    unsigned int totalNumberOfVertices; //number of vertices

    /* Return the index of given value in the graph
     *
     * If the value is not in the graph, return -1
     * */
    virtual int lookUpVertex(const T& value) const = 0;

public:

    //pure virtual functions which are supposed to be inherited by child Classes
    explicit Graph(): totalNumberOfVertices(0)
    {
    }

    //getter to return the number of nodes in graph
    unsigned int getNumberOfVertices() const
    {
        return totalNumberOfVertices;
    }

    //virtual functions which are inherited and implemented by child classes
    virtual void addVertex(const T& value) = 0;
    virtual void removeVertex(const T& value)=0;

    virtual void addEdge(const T& fromValue, const T& toValue, double cost) = 0;
    virtual void removeEdge(const T& fromValue, const T& toValue) = 0;

    virtual double getWeight (const T& fromValue, const T& toValue) = 0;

    // function to remove all vertices in the graph
    virtual void reset() = 0;

    virtual bool isEmpty() const {
        return totalNumberOfVertices == 0;
    }

    //display function which displays the edges between vertices.
    virtual std::string toString() = 0;



    /*! computeShortestDistanceBetweenAllVertices - Calculate shortest paths between all vertices using Floyd-Warshall Algorithm
    *
    * @return 2D vector with shortest paths between all vertices
    */
    virtual std::vector< std::vector<double> > computeShortestDistanceBetweenAllVertices() const = 0;

    virtual std::list<CurrencyPair> computeShortestDistanceBetweenVertices(const T& from, const T& to) const = 0;

};


#endif //CMPE130PROJECT_GRAPH_H
