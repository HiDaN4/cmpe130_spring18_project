//
// Created by Mian Hashim Shah on 4/25/18.
//

#include "DirectedListGraph.h"

template <class T>
DirectedListGraph<T>::DirectedListGraph(){}

template <class T>
void DirectedListGraph<T>::addVertex(const T &value)
{
    UndirectedListGraph<T>::addVertex(value);
}

template <class T>
void DirectedListGraph<T>::removeVertex(const T &value)
{
    UndirectedListGraph<T>::removeVertex(value);
}

template <class T>
void DirectedListGraph<T>::addEdge(const T &fromValue, const T &toValue, double cost)
{
    int fromValueIndex = lookUpVertex(fromValue);
    int toValueIndex = lookUpVertex(toValue);

    if (fromValueIndex != -1 && toValueIndex != -1) // if both vertices are found
    {
        adjList[fromValueIndex].insertNode( Node<T>(&adjList[toValueIndex], cost) );//only oneway insertion since directed graph
    }
}

template <class T>
void DirectedListGraph<T>::removeEdge(const T &fromValue, const T &toValue)
{
    int fromValueIndex = lookUpVertex(fromValue);
    int toValueIndex = lookUpVertex(toValue);

    if (fromValueIndex != -1 && toValueIndex != -1) // if both vertices are found
    {
        adjList[fromValueIndex].removeNode( Node<T>(&adjList[toValueIndex], 0) );//only oneway removal since directed graph
    }
}

template <class T>
std::string DirectedListGraph<T>::toString() {
    return UndirectedListGraph<T>::toString();
}

template <class T>
int DirectedListGraph<T>::lookUpVertex(const T &value) const
{
    return UndirectedListGraph<T>::lookUpVertex(value);
}

