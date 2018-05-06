//
// Created by Mian Hashim Shah on 4/8/18.
//

#ifndef CMPE130PROJECT_UNDIRECTEDLISTGRAPH_H
#define CMPE130PROJECT_UNDIRECTEDLISTGRAPH_H
#include "Graph.h"
#include <forward_list>
#include <vector>
#include <sstream>


template <class T>
class Node;

template <class T>
class ListGraphVertex
{
private:
    std::forward_list<Node<T> > listOfNodes;
    T value;
public:
    explicit ListGraphVertex(T val)
    {
        value = val;
    }

    T getValue() const { return value; }

    typename std::forward_list<Node<T> >::const_iterator getListIteratorBegin() const {
        return listOfNodes.begin();
    }

    typename std::forward_list<Node<T> >::const_iterator getListIteratorEnd() const {
        return listOfNodes.end();
    }

    void insertNode(const Node<T>& node) {
        listOfNodes.push_front(node);
    }

    void removeNode(const Node<T>& node) {
        listOfNodes.remove(node);
    }

    bool operator==(const ListGraphVertex& rhs) const {
        return this->value == rhs.value;
    }

    friend std::ostream& operator<<(std::ostream& ost, const ListGraphVertex& obj) {
        ost << "Vertex '" << obj.value << "'";
        return ost;
    }
};



template <class T>
class Node
{
    double cost;
    ListGraphVertex<T> * vertexPtr;
public:
    Node(ListGraphVertex<T> * ptr, double nodeCost)
    {
        cost = nodeCost;
        vertexPtr = ptr;
    }

    bool operator==(const Node& rhs)
    {
        return this->vertexPtr->getValue() == rhs.vertexPtr->getValue();
    }

    friend std::ostream& operator<<(std::ostream& ost, const Node& obj) {
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
    std::vector < ListGraphVertex<T> > adjList;
public:
    UndirectedListGraph() : Graph<T>(), count(0){};

    virtual void addVertex(const T& value);
    virtual void removeVertex(const T& value);

    virtual void addEdge(const T& fromValue, const T& toValue, double cost);
    virtual void removeEdge(const T& fromValue, const T& toValue);
    virtual double getWeight (const T& fromValue, const T& toValue);
    virtual std::string toString();    //rough display function which displays the edges between vertices.

    virtual int lookUpVertex(const T &value);

    // function to remove all vertices in the graph
    virtual void reset();

};

#include "UndirectedListGraph.cpp"

#endif //CMPE130PROJECT_UNDIRECTEDLISTGRAPH_H
