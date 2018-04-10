//
// Created by Mian Hashim Shah on 4/4/18.
//

#ifndef CMPE130PROJECT_UNDIRECTEDMATRIXGRAPH_H
#define CMPE130PROJECT_UNDIRECTEDMATRIXGRAPH_H

#include "Graph.h"
#include <vector>

//Undirected Matric Graph inherits from the parent Graph class
template <class T>
class UndirectedMatrixGraph : public Graph<T>
{
private:
    vector<vector<double> > adjMatrix;// vector of vectors to create a 2d matrix
    vector<Vertex<T> > vertexList; // vector list of our vertices

    using Graph<T>::totalNumberOfVertices;

public:
    UndirectedMatrixGraph();
    //This function adds a vertices to our vertex List
    // @param: Vertex * addThisVertex

    //1. adds to list using stl vector function
    //2. notifies user
    //3. increments the number of verices
    virtual void addVertex(const T& value);

    //This function removes a vertices to our vertex List
    // @param: Vertex * deleteThisVertex

    //1. Checks for whether the vertex existss, if it does, erase from list using stl vector function
    //2. notifies user
    //3. increments the number of verices
    virtual void removeVertex(const T& value);

    //This function adds an edge between two given vertices and sets an associated cost to the edge
    // @param: Vertex * fromVertex, Vertex * toVertex

    //1. safe check if the passed vertices are valid
    //2. look up in our vertex list if these vertices exist. Return index of both vertices
    //3. check if edge already exists between them, if yes, then return
    //4. add edge between the vertices
    virtual void addEdge(const T& fromValue, const T& toValue, double cost);



    //This function removes an edge between two given vertices
    // @param: Vertex * fromVertex, Vertex * toVertex

    //1. safe check if the passed vertices are valid
    //2. look up in our vertex list if these vertices exist. Return index of both vertices
    //3. check if edge already exists between them, if not, then nothing to delete. We exit then
    //4. remove edge between the vertices
    virtual void removeEdge(const T& fromValue, const T& toValue);

    //This function checks to see if a vertex exists or not
    // @param: Vertex * V

    //1. safe check if the passed vertices are valid
    //2. loops through vertex list
    //3. if V is equal to any of the indices, return index
    //4. otherwise return -1 to indicate "not found"
    virtual int lookUpVertex(const T& value);

    //This function gives us an idea of what vetices have an edge between them. -> for testing purposes
    // @param: none
    virtual string toString();
};

//#include "UndirectedMatrixGraph.cpp"
#endif //CMPE130PROJECT_UNDIRECTEDMATRIXGRAPH_H
