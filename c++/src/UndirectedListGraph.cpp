//
// Created by Mian Hashim Shah on 4/8/18.
//

#include "UndirectedListGraph.h"

template <class T>
void UndirectedListGraph<T>::addVertex(const T &value)
{
    Vertices<T> vertex(value);
//    adjList.push_back(vertex);
    //adjList.push_back();

}

template <class T>
int UndirectedListGraph<T>::lookUpVertex(const T &value) {
    return -1;
}

template <class T>
void UndirectedListGraph<T>::removeVertex(const T &value) {

}

template <class T>
void UndirectedListGraph<T>::addEdge(const T &fromValue, const T &toValue, double cost) {

}

template <class T>
void UndirectedListGraph<T>::removeEdge(const T &fromValue, const T &toValue) {

}

template <class T>
string UndirectedListGraph<T>::toString() {
    return std::string();
}