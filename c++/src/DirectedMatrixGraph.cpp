//
// Created by Mian Hashim Shah on 4/25/18.
//
#include "DirectedMatrixGraph.h"

template<class T>
DirectedMatrixGraph<T>::DirectedMatrixGraph() {

}

template<class T>
void DirectedMatrixGraph<T>::addVertex(const T &value) {
    UndirectedMatrixGraph<T>::addVertex(value);
}

template<class T>
void DirectedMatrixGraph<T>::removeVertex(const T &value) {
    UndirectedMatrixGraph<T>::removeVertex(value);
}

template<class T>
void DirectedMatrixGraph<T>::addEdge(const T &fromValue, const T &toValue, double cost)
{
    //look up vertices if they exist
    int fromIndex = lookUpVertex(fromValue);
    int toIndex = lookUpVertex(toValue);

    if (fromIndex != -1 && toIndex != -1)
    {
        //if they exist, then add it
        adjMatrix[fromIndex][toIndex] = cost; // add edge between vertices
    }
}

template<class T>
void DirectedMatrixGraph<T>::removeEdge(const T &fromValue, const T &toValue)
{
    //look up vertices if they exist
    int fromIndex = lookUpVertex(fromValue);
    int toIndex = lookUpVertex(toValue);

    if (fromIndex != -1 && toIndex != -1) {
        //check to see if edge doesnt exist between vertices
        if (adjMatrix[fromIndex][toIndex] == 0) {
            std::cout << __FUNCTION__ << ": Edge does not exist.. Nothing to do here" << "\n";
            return;
        }

        //if they exist, then remove it
        adjMatrix[fromIndex][toIndex] = 0.00; //add edge between vertices
    }
}

template<class T>
int DirectedMatrixGraph<T>::lookUpVertex(const T &value) const
{
    return UndirectedMatrixGraph<T>::lookUpVertex(value);
}

template<class T>
double DirectedMatrixGraph<T>::getWeight(const T &fromValue, const T &toValue)
{
    return UndirectedMatrixGraph<T>::getWeight(fromValue, toValue);
}

template<class T>
std::vector< Vertex<T> > DirectedMatrixGraph<T>::getNeighbors(const T &targetCoin)
{
    return UndirectedMatrixGraph<T>::getNeighbors(targetCoin);
}

template<class T>
std::string DirectedMatrixGraph<T>::toString()
{
    return UndirectedMatrixGraph<T>::toString();
}


template<class T>
std::list<CurrencyPair> DirectedMatrixGraph<T>::getShortestPairsBetween(const T &from, const T &to) const {
    return UndirectedMatrixGraph<T>::getShortestPairsBetween(from, to);
}