//
//implementation of the DirectedMatrixGraph.h
//
#include "DirectedMatrixGraph.h"

//constructor
template<class T>
DirectedMatrixGraph<T>::DirectedMatrixGraph() {

}

//addVertex function inherits from the UndirectedMtrixGraph
template<class T>
void DirectedMatrixGraph<T>::addVertex(const T &value) {
    UndirectedMatrixGraph<T>::addVertex(value); //call parent function
}

//removeVertex unction inherits from the UndirectedMtrixGraph
template<class T>
void DirectedMatrixGraph<T>::removeVertex(const T &value) {
    UndirectedMatrixGraph<T>::removeVertex(value);//call parent function
}

//addEdge modified for the directedMatrixGraph
template<class T>
void DirectedMatrixGraph<T>::addEdge(const T &fromValue, const T &toValue, double cost)
{
    //look up vertices if they exist
    int fromIndex = lookUpVertex(fromValue);
    int toIndex = lookUpVertex(toValue);

    if (fromIndex != -1 && toIndex != -1) //if they do exist, go through to this loop
    {
        //if they exist, then add it
        adjMatrix[fromIndex][toIndex] = cost; // add edge between vertices //since its directed, add the edge from one way
    }
}
//removeEdge modified for the directedMatrixGraph
template<class T>
void DirectedMatrixGraph<T>::removeEdge(const T &fromValue, const T &toValue)
{
    //look up vertices if they exist
    int fromIndex = lookUpVertex(fromValue);
    int toIndex = lookUpVertex(toValue);

    if (fromIndex != -1 && toIndex != -1)
    { //if they do exist, go through to this loop

        //check to see if edge doesnt exist between vertices
        if (adjMatrix[fromIndex][toIndex] == 0)
        {
            cout << __FUNCTION__ << ": Edge does not exist.. Nothing to do here" << endl;
            return;
        }

        //if they exist, then remove it
        adjMatrix[fromIndex][toIndex] = 0.00; //remove edge between vertices
    }
}

//lookUpVertex calling parent classes function
template<class T>
int DirectedMatrixGraph<T>::lookUpVertex(const T &value)
{
    return UndirectedMatrixGraph<T>::lookUpVertex(value);
}

//returns weight of between two vertices
template <class T>
double DirectedMatrixGraph<T>::getWeight(const T &fromValue, const T &toValue)
{
    return UndirectedMatrixGraph<T>::getWeight(fromValue, toValue);
}

//return neighbors of a specific currency
template <class T>
vector<Vertex<T>> DirectedMatrixGraph<T>::getNeighbors(const T &targetCoin)
{
    return UndirectedMatrixGraph<T>::getNeighbors(targetCoin);
}

//display function
template<class T>
string DirectedMatrixGraph<T>::toString()
{
    return UndirectedMatrixGraph<T>::toString();
}