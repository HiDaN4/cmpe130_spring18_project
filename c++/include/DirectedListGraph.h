//
// Created by Mian Hashim Shah on 4/25/18.
//

#ifndef CMPE130PROJECT_DIRECTEDLISTGRAPH_H
#define CMPE130PROJECT_DIRECTEDLISTGRAPH_H

#include "UndirectedListGraph.h"
template <class T>
class DirectedListGraph : public UndirectedListGraph<T>
{
private:
    using UndirectedListGraph<T>::adjList;
public:
    DirectedListGraph();
    virtual void addVertex(const T& value);
    virtual void removeVertex(const T& value);

    virtual void addEdge(const T& fromValue, const T& toValue, double cost);
    virtual void removeEdge(const T& fromValue, const T& toValue);

    virtual string toString();    //rough display function which displays the edges between vertices.
    virtual int lookUpVertex(const T &value);

};
#include "DirectedListGraph.cpp"

#endif //CMPE130PROJECT_DIRECTEDLISTGRAPH_H
