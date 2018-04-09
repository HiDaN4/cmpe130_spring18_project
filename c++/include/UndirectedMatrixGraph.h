//
// Created by Mian Hashim Shah on 4/4/18.
//

#ifndef CMPE130PROJECT_UNDIRECTEDMATRIXGRAPH_H
#define CMPE130PROJECT_UNDIRECTEDMATRIXGRAPH_H

#include "Graph.h"
#include <vector>

//Undirected Matric Graph inherits from the parent Graph class
template <class T>
class UndirectedMatrixGraph : public Graph<T>
{
private:
    vector<vector <double>> adjMatrix;// vector of vectors to create a 2d matrix
    vector <Vertex <T>> vertexList; // vector list of our vertices
    int currentCountOfVertices;

public:

    UndirectedMatrixGraph(int numOfVertices) : Graph<T>(numOfVertices), currentCountOfVertices(0) // constructor of default size = 10int totalNumOfVertices = 10
    {
//        adjMatrix(numOfVertices), vertexList(numOfVertices)
        adjMatrix.resize(this->getNumberOfVertices(), vector<double>(this->getNumberOfVertices()));
    }

    //This function adds a vertices to our vertex List
    // @param: Vertex * addThisVertex

    //1. adds to list using stl vector function
    //2. notifies user
    //3. increments the number of verices
    void addVertex(Vertex<T> * addThisVertex)
    {
        vertexList.push_back(*addThisVertex);
        cout << __FUNCTION__ << ": Added vertex "   << endl;

        currentCountOfVertices++;

        //resize if we hit maximum graph adj matrix size
        if (currentCountOfVertices == this->getNumberOfVertices())
        {
            this->setNumberOfVertices(currentCountOfVertices + 1);
            cout << "ehods" << this->getNumberOfVertices()<< endl << endl;
            //resize entire graph
            for (int i = 0; i < this->getNumberOfVertices() - 1; i ++ )
            {
                    adjMatrix[i].resize(this->getNumberOfVertices());
            }

            adjMatrix.resize(this->getNumberOfVertices(), vector<double>(this->getNumberOfVertices()));

        }
    };

    //This function removes a vertices to our vertex List
    // @param: Vertex * deleteThisVertex

    //1. Checks for whether the vertex existss, if it does, erase from list using stl vector function
    //2. notifies user
    //3. increments the number of verices
    void removeVertex(Vertex<T> * deleteThisVertex)
    {
        int index = lookUpVertex(deleteThisVertex);

        if (index != -1 && currentCountOfVertices!=-1) // if index is valid
        {
            vertexList.erase(vertexList.begin()+index); // remove vertex at that index
            currentCountOfVertices--;

            cout << __FUNCTION__ << ": Removed vertex at index " << index << endl;
        }
    }

    //This function adds an edge between two given vertices
    // @param: Vertex * fromVertex, Vertex * toVertex

    //1. safe check if the passed vertices are valid
    //2. look up in our vertex list if these vertices exist. Return index of both vertices
    //3. check if edge already exists between them, if yes, then return
    //4. add edge between the vertices
//    void addEdge(Vertex<T> * fromVertex, Vertex<T> * toVertex)
//    {
//        if (fromVertex == nullptr && toVertex == nullptr)
//        {
//                cout << __FUNCTION__ << ": Error!" << endl;
//        }
//        else
//        {
//            //look up vertices if they exist
//            int fromIndex = lookUpVertex(fromVertex);
//            int toIndex = lookUpVertex(toVertex);
//
//            if (fromIndex != -1 && toIndex != -1)
//            {
//                //check to see if edge already exists between vertices
//                if (adjMatrix[fromIndex][toIndex] == 1)
//                {
//                    cout << __FUNCTION__ << ": Edge already exists.. Nothing to do here" << endl;
//                    return;
//                }
//
//                //if they exist, then add it
//                adjMatrix[fromIndex][toIndex] = adjMatrix[toIndex][fromIndex] = 1; //add edge between vertices
//            }
//        }
//    }
    //This function adds an edge between two given vertices and sets an associated cost to the edge
    // @param: Vertex * fromVertex, Vertex * toVertex

    //1. safe check if the passed vertices are valid
    //2. look up in our vertex list if these vertices exist. Return index of both vertices
    //3. check if edge already exists between them, if yes, then return
    //4. add edge between the vertices
    void addEdge(Vertex<T> * fromVertex, Vertex<T> * toVertex, double cost)
    {
        if (fromVertex == nullptr && toVertex == nullptr)
        {
                cout << __FUNCTION__ << ": Error!" << endl;
        }
        else
        {
            //look up vertices if they exist
            int fromIndex = lookUpVertex(fromVertex);
            int toIndex = lookUpVertex(toVertex);

            if (fromIndex != -1 && toIndex != -1)
            {
                //check to see if edge already exists between vertices
                if (adjMatrix[fromIndex][toIndex] != 0)
                {
                    cout << __FUNCTION__ << ": Edge already exists.. Nothing to do here" << endl;
                    return;
                }

                //if they exist, then add it
                adjMatrix[fromIndex][toIndex] = adjMatrix[toIndex][fromIndex] = cost; //add edge between vertices
            }
        }
    }
    //This function removes an edge between two given vertices
    // @param: Vertex * fromVertex, Vertex * toVertex

    //1. safe check if the passed vertices are valid
    //2. look up in our vertex list if these vertices exist. Return index of both vertices
    //3. check if edge already exists between them, if not, then nothing to delete. We exit then
    //4. remove edge between the vertices
    void removeEdge(Vertex<T> * fromVertex, Vertex<T> * toVertex)
    {
        if (fromVertex == nullptr && toVertex == nullptr)
        {

            cout << __FUNCTION__ << ": Error!" << endl;
        }
        else {
            //look up vertices if they exist
            int fromIndex = lookUpVertex(fromVertex);
            int toIndex = lookUpVertex(toVertex);

            if (fromIndex != -1 && toIndex != -1) {
                //check to see if edge doesnt exist between vertices
                if (adjMatrix[fromIndex][toIndex] == 0) {
                    cout << __FUNCTION__ << ": Edge does not exist.. Nothing to do here" << endl;
                    return;
                }

                //if they exist, then remove it
                adjMatrix[fromIndex][toIndex] = adjMatrix[toIndex][fromIndex] = 0; //add edge between vertices
            }
        }
    }


    //This function checks to see if a vertex exists or not
    // @param: Vertex * V

    //1. safe check if the passed vertices are valid
    //2. loops through vertex list
    //3. if V is equal to any of the indices, return index
    //4. outherwise return -1 to indicate "not found"
    int lookUpVertex(Vertex<T> * v)
    {
        if (v == nullptr) //error check
        {
            cout << __FUNCTION__ << ": Error!" << endl;
        }
        else
        {
            for (int i = 0; i < this->getNumberOfVertices(); i++)
            {
                if (vertexList[i] == *v)
                {
                    return i;
                }
            }
        }
        cout << "Vertex not found!" << endl;
        return -1;
    }

    //TODO: Change name to toString n modify
    //This function gives us an idea of what vetices have an edge between them. -> for testing purposes
    // @param: none
    void display()
    {
        for (int i = 0; i < this->getNumberOfVertices(); i++)
        {
            for (int j = 0; j < this->getNumberOfVertices(); j++)
            {
                if (adjMatrix[i][j] != 0)
                {
                    cout << vertexList[i].getValue();
                    cout << "-" << vertexList[j].getValue() << endl;
                }
            }
        }
    }
};

#endif //CMPE130PROJECT_UNDIRECTEDMATRIXGRAPH_H
