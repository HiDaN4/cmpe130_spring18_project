//
// Created by Mian Hashim Shah on 4/8/18.
//

#include "UndirectedListGraph.h"

template <class T>
void UndirectedListGraph<T>::addVertex(const T &value)
{
    ListGraphVertex<T> vertex(value); // create a vertex of passed value

    //this for loop iterates through the vector and detects if there already exists a "vertex" of the same value. If it does, then return
    for (auto iterator = adjList.begin(); iterator != adjList.end(); ++iterator)
    {
        if (*iterator == vertex)
        {
            return;
        }
    }
    //else, push it to the vector
    adjList.push_back(vertex); // push the vertex onto the vector
    ++totalNumberOfVertices;
}


template <class T>
void UndirectedListGraph<T>::removeVertex(const T &value)
{
    int index = lookUpVertex(value); //check to see if vertex exists
    if (index != -1) // if we have found the vertex, we delete
    {
        adjList.erase(adjList.begin()+index); // remove entry
        totalNumberOfVertices--; //decrease number of vertices
    }
}


template <class T>
void UndirectedListGraph<T>::addEdge(const T &fromValue, const T &toValue, double cost)
{

    int fromValueIndex = lookUpVertex(fromValue);
    int toValueIndex = lookUpVertex(toValue);

    if (fromValueIndex != -1 && toValueIndex != -1) // if both vertices are found
    {
        adjList[fromValueIndex].insertNode( Node<T>(&adjList[toValueIndex], cost) );
        adjList[toValueIndex].insertNode( Node<T>(&adjList[fromValueIndex], cost) );
    }
}

template <class T>
void UndirectedListGraph<T>::removeEdge(const T &fromValue, const T &toValue)
{
    int fromValueIndex = lookUpVertex(fromValue);
    int toValueIndex = lookUpVertex(toValue);

    if (fromValueIndex != -1 && toValueIndex != -1) // if both vertices are found
    {
       adjList[fromValueIndex].removeNode( Node<T>(&adjList[toValueIndex], 0) );
       adjList[toValueIndex].removeNode(Node<T>(&adjList[fromValueIndex], 0));
    }

}

//TODO: Complete This function
template <class T>
double UndirectedListGraph<T>::getWeight(const T &fromValue, const T &toValue)
{
    return 0;
}

template <class T>
int UndirectedListGraph<T>::lookUpVertex(const T &value)
{
    for (int i = 0; i < totalNumberOfVertices; i ++) // loop through entire vector
    {
        if (adjList[i].getValue() == value) // looks into each index of vector and compares vertex value with given value
        {
            return i;
        }
    }

    cout << __FUNCTION__ << ": Vertex not found for " << value << "\n";
    return -1;
}


template <class T>
string UndirectedListGraph<T>::toString()
{
    stringstream buffer;
    unsigned int count = 1;
    for (auto row = adjList.begin(); row != adjList.end(); ++row) {
        buffer << "#" << to_string(count++) << " - ";
        buffer << *row << "\n";
        for (auto it = row->getListIteratorBegin(); it != row->getListIteratorEnd(); ++it) {
            buffer << string(6, ' ');
            buffer << "- ";
            buffer << *it;
            buffer << "\n";
        }
        buffer << "\n";
    }
    return buffer.str();
}



template <class T>
void UndirectedListGraph<T>::reset() {
    adjList.clear();
    count = 0;
    totalNumberOfVertices = 0;
}