//
// Created by Mian Hashim Shah on 4/4/18.
//

#ifndef CMPE130PROJECT_UNDIRECTEDMATRIXGRAPH_H
#define CMPE130PROJECT_UNDIRECTEDMATRIXGRAPH_H

#include "Graph.h"
#include <vector>
#include <list>
#include <unordered_map>

class CurrencyPair;

//Undirected Matric Graph inherits from the parent Graph class
template <class T>
class UndirectedMatrixGraph : public Graph<T>
{
// vector of vectors to create a 2d matrix
    // vector list of our vertices

    using Graph<T>::totalNumberOfVertices;

protected:
    std::vector<Vertex<T> > vertexList;
    std::unordered_map<std::string, unsigned int> verticesMap;
    std::vector< std::vector<double> > adjMatrix;


public:
    // Default Constructor
    UndirectedMatrixGraph();



    //This function adds a vertices to our vertex List
    // @param: Vertex * addThisVertex

    //1. adds to list using stl vector function
    //2. notifies user
    //3. increments the number of verices
    virtual void addVertex(const T& value);

    //This function removes a vertices to our vertex List
    // @param: Vertex * deleteThisVertex

    //1. Checks for whether the vertex exists, if it does, erase from list using stl vector function
    //2. notifies user
    //3. increments the number of verices
    virtual void removeVertex(const T& value);

    //This function adds an edge between two given vertices and sets an associated cost to the edge
    // @param: Vertex * fromVertex, Vertex * toVertex

    //1. safe check if the passed vertices are valid
    //2. look up in our vertex list if these vertices exist. Return index of both vertices
    //3. check if edge already exists between them, if yes, then return
    //4. add edge between the vertices. Since Undirected, edges from both ends are added
    virtual void addEdge(const T& fromValue, const T& toValue, double cost);

    //This function removes an edge between two given vertices
    // @param: Vertex * fromVertex, Vertex * toVertex

    //1. safe check if the passed vertices are valid
    //2. look up in our vertex list if these vertices exist. Return index of both vertices
    //3. check if edge already exists between them, if not, then nothing to delete. We exit then
    //4. remove edge between the vertices. Since Undirected, edges from both ends are removed
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


    // function to remove all vertices in the graph
    virtual void reset();

    /*! computeShortestDistanceBetweenAllVertices - Calculate shortest paths between all vertices using Floyd-Warshall Algorithm
     *
     * @return 2D vector with shortest paths between all vertices
    */
    virtual std::vector< std::vector<double> > computeShortestDistanceBetweenAllVertices() const;

    virtual std::list<CurrencyPair> computeShortestDistanceBetweenVertices(const T& from, const T& to) const;

};


#include "UndirectedMatrixGraph.cpp"

#endif //CMPE130PROJECT_UNDIRECTEDMATRIXGRAPH_H
