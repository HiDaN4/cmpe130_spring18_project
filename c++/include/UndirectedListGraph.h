//
// Created by Mian Hashim Shah on 4/8/18.
//

#ifndef CMPE130PROJECT_UNDIRECTEDLISTGRAPH_H
#define CMPE130PROJECT_UNDIRECTEDLISTGRAPH_H
#include "Graph.h"
#include <forward_list>


template <class T>
class Node;

template <class T>
class Vertices
{
private:
    forward_list<Node<T> > listOfNodes;
    T value;
public:
    explicit Vertices(T val)
    {
        value = val;
    }

    T getValue() { return value; }

    typename forward_list<Node<T> >::const_iterator getListIteratorBegin() const {
        return listOfNodes.begin();
    }

    typename forward_list<Node<T> >::const_iterator getListIteratorEnd() const {
        return listOfNodes.end();
    }

    void insertNode(const Node<T>& node) {
        listOfNodes.push_front(node);
    }

    void removeNode(const Node<T>& node) {
        listOfNodes.remove(node);
    }

    bool operator==(const Vertices& rhs) {
        return this->value == rhs.value;
    }

    friend ostream& operator<<(ostream& ost, const Vertices& obj) {
        ost << "Vertex '" << obj.value << "'";
        return ost;
    }
};



template <class T>
class Node
{
    double cost;
    Vertices<T> * vertexPtr;
public:
    Node(Vertices<T> * ptr, double nodeCost)
    {
        cost = nodeCost;
        vertexPtr = ptr;
    }

    bool operator==(const Node& rhs)
    {
        return this->vertexPtr->getValue() == rhs.vertexPtr->getValue();
    }

    friend ostream& operator<<(ostream& ost, const Node& obj) {
        ost << "Node with cost (" << obj.cost << ") to " << *(obj.vertexPtr);
        return ost;
    }
};

template <class T>
class UndirectedListGraph : public Graph<T>
{
private:

    int count;
    using Graph<T>::totalNumberOfVertices;

protected:
    vector < Vertices<T> > adjList;
public:
    UndirectedListGraph() : Graph<T>(), count(0){};


    virtual void addVertex(const T& value);
    virtual void removeVertex(const T& value);

    virtual void addEdge(const T& fromValue, const T& toValue, double cost);
    virtual void removeEdge(const T& fromValue, const T& toValue);

    virtual string toString();    //rough display function which displays the edges between vertices.
    virtual int lookUpVertex(const T &value);

};


#include "UndirectedListGraph.cpp"

#endif //CMPE130PROJECT_UNDIRECTEDLISTGRAPH_H
