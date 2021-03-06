//
// Created by Mian Hashim Shah on 4/25/18.
//

#ifndef CMPE130PROJECT_DIRECTEDMATRIXGRAPH_H
#define CMPE130PROJECT_DIRECTEDMATRIXGRAPH_H

#include "UndirectedMatrixGraph.h"
#include <vector>

//src/DirectedMatrixGraph.cpp
template <class T>
class DirectedMatrixGraph: public UndirectedMatrixGraph<T>
{
private:
    using UndirectedMatrixGraph<T>::verticesMap;
    using UndirectedMatrixGraph<T>::adjMatrix;// vector of vectors to create a 2d matrix
    using UndirectedMatrixGraph<T>::vertexList; // vector list of our vertices

    using Graph<T>::totalNumberOfVertices;
public:
    DirectedMatrixGraph();
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
    //4. add edge between the vertices. Since this is Directed, only one edge is added
    virtual void addEdge(const T& fromValue, const T& toValue, double cost);

    //This function removes an edge between two given vertices
    // @param: Vertex * fromVertex, Vertex * toVertex

    //1. safe check if the passed vertices are valid
    //2. look up in our vertex list if these vertices exist. Return index of both vertices
    //3. check if edge already exists between them, if not, then nothing to delete. We exit then
    //4. remove edge between the vertices. Since this is Directed, only one edge is removed
    virtual void removeEdge(const T& fromValue, const T& toValue);

    //This function checks to see if a vertex exists or not
    // @param: Vertex * V

    //1. safe check if the passed vertices are valid
    //2. loops through vertex list
    //3. if V is equal to any of the indices, return index
    //4. otherwise return -1 to indicate "not found"
    virtual int lookUpVertex(const T& value) const;

    //This function returns the weight between two vertices
    // @param: const T& fromValue, const T& toValue

    //1. safe check if the passed vertices are valid, and gets the indices of the vertex
    //2. returns the weight or index of the adjgraph at the two vertex indices
    //3. otherwise return -1 if function fails
    virtual double getWeight(const T& fromValue, const T& toValue);

    //This function returns the neighbors of a specified vertex
    // @param: const T& targetCoin

    /*
     * This function returns the neighbors of a specified vertex
     * @param: const T& targetCoin
     *
     * 1. Creates a vector of vertices
     * 2. gets index of the targetCoin
     * 3. if valid, loop through the rows of adj matrix (for the index of targetCoin) and
     *    push the vertex (at that index) (which has an edge to our targetCoin) to the list
     * 4. return the list of neighbors
     */
    virtual std::vector< Vertex<T> > getNeighbors(const T& targetCoin);

    //This function gives us an idea of what vetices have an edge between them. -> for testing purposes
    // @param: none
    virtual std::string toString();


    virtual std::list<CurrencyPair> getShortestPairsBetween(const T& from, const T& to) const;

};

#include "DirectedMatrixGraph.cpp"

#endif //CMPE130PROJECT_DIRECTEDMATRIXGRAPH_H
