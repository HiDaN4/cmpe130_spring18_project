//
// Created by Mian Hashim Shah on 4/8/18.
//

#include "UndirectedListGraph.h"

template <class T>
void UndirectedListGraph<T>::addVertex(const T &value)
{
        Vertices<T> vertex(value); // create a vertex of passed value
        adjList.push_back(vertex); // push the vertex onto the vector
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
        Node<T> myNode(&adjList[toValueIndex], cost); //create a node pointing to vertex containing toValue

        adjList[fromValueIndex].getListOfNodes().emplace_front(myNode); // add it to the linked list
        adjList[toValueIndex].getListOfNodes().emplace_front(myNode); // add it to the linked list

    }
}

template <class T>
void UndirectedListGraph<T>::removeEdge(const T &fromValue, const T &toValue)
{
    int fromValueIndex = lookUpVertex(fromValue);
    int toValueIndex = lookUpVertex(toValue);

    if (fromValueIndex != -1 && toValueIndex != -1) // if both vertices are found
    {
        Node<T> myNode(&adjList[toValueIndex], 0);

       adjList[fromValueIndex].getListOfNodes().remove(myNode);
       adjList[toValueIndex].getListOfNodes().remove(myNode);

    }

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

    cout << __FUNCTION__ << ": Vertex not found";
    return -1;
}
template <class T>
string UndirectedListGraph<T>::toString()
{
    return std::string();
}