////
//// Created by Mian Hashim Shah on 4/4/18.
////

#include "UndirectedMatrixGraph.h"
#include <iomanip> // setprecision
#include <sstream> // stringstream

//constructor of undireceted graph using adjacency matrix
template<class T>
UndirectedMatrixGraph<T>::UndirectedMatrixGraph() : Graph<T>(), adjMatrix(), verticesMap() {}


//This function adds a vertices to our vertex List
// @param: Vertex * addThisVertex

//1. adds to list using stl vector function
//2. notifies user
//3. increments the number of vertices
template<class T>
void UndirectedMatrixGraph<T>::addVertex(const T& value)
{

    if (lookUpVertex(value) != -1)
        return;

    Vertex<T> vertex(value);
    vertexList.push_back(vertex);

    verticesMap.insert(
            std::make_pair(
                    (std::is_same<T, std::string>::value) ? (value) : std::string(value), (vertexList.size() - 1)
            )
    );

    cout << __FUNCTION__ << ": Added vertex "   << endl;

    unsigned int prevCount = totalNumberOfVertices;
    totalNumberOfVertices++;

    // resize the vectors (as we add a new vertex, columns increase)
    for (auto it = adjMatrix.begin(); it != adjMatrix.end(); ++it) {
        while (it->size() < totalNumberOfVertices)
            it->push_back(0);
    }

    // create a new vertex vector
    auto v = vector<double>();
    for (int i = 0; i < totalNumberOfVertices; ++i) // initialize the vector to 0 with size: numberOfVertices
        v.push_back(0);

    adjMatrix.push_back(v);

};

//This function removes a vertices to our vertex List
// @param: Vertex * deleteThisVertex

//1. Checks for whether the vertex existss, if it does, erase from list using stl vector function
//2. notifies user
//3. increments the number of vertices
template<class T>
void UndirectedMatrixGraph<T>::removeVertex(const T& value)
{
    int index = lookUpVertex(value);


    if (index != -1 && totalNumberOfVertices!=-1) // if index is valid
    {
        vertexList.erase(vertexList.begin() + index); // remove vertex at that index
        totalNumberOfVertices--;

        //resize the matrix accordingly
        adjMatrix.erase(adjMatrix.begin() + index);
        for (auto iterator = adjMatrix.begin(); iterator != adjMatrix.end(); ++iterator)
        {
            iterator->erase(iterator->begin() + index);
        }

        cout << __FUNCTION__ << ": Removed vertex at index " << index << endl;
    }
}

//This function adds an edge between two given vertices and sets an associated cost to the edge
// @param: Vertex * fromVertex, Vertex * toVertex

//1. safe check if the passed vertices are valid
//2. look up in our vertex list if these vertices exist. Return index of both vertices
//3. check if edge already exists between them, if yes, then return
//4. add edge between the vertices
template<class T>
void UndirectedMatrixGraph<T>::addEdge(const T& fromValue, const T& toValue, double cost)
{

    //look up vertices if they exist
    int fromIndex = lookUpVertex(fromValue);
    int toIndex = lookUpVertex(toValue);

    if (fromIndex != -1 && toIndex != -1)
    {
        //if they exist, then add it
        adjMatrix[fromIndex][toIndex] = adjMatrix[toIndex][fromIndex] = cost; // add edge between vertices

    }
}
//This function removes an edge between two given vertices
// @param: Vertex * fromVertex, Vertex * toVertex

//1. safe check if the passed vertices are valid
//2. look up in our vertex list if these vertices exist. Return index of both vertices
//3. check if edge already exists between them, if not, then nothing to delete. We exit then
//4. remove edge between the vertices
template<class T>
void UndirectedMatrixGraph<T>::removeEdge(const T& fromValue, const T& toValue)
{
    //look up vertices if they exist
    int fromIndex = lookUpVertex(fromValue);
    int toIndex = lookUpVertex(toValue);

    if (fromIndex != -1 && toIndex != -1) {
        //check to see if edge doesnt exist between vertices
        if (adjMatrix[fromIndex][toIndex] == 0) {
            cout << __FUNCTION__ << ": Edge does not exist.. Nothing to do here" << endl;
            return;
        }

        //if they exist, then remove it
        adjMatrix[fromIndex][toIndex] = adjMatrix[toIndex][fromIndex] = 0.00; //add edge between vertices
    }
}


//This function checks to see if a vertex exists or not
// @param: Vertex * V

//1. safe check if the passed vertices are valid
//2. loops through vertex list
//3. if V is equal to any of the indices, return index
//4. outherwise return -1 to indicate "not found"
template<class T>
int UndirectedMatrixGraph<T>::lookUpVertex(const T& value)
{
    auto iterator = verticesMap.find(value);

    if (iterator == verticesMap.end()) {
        return -1;
    }

    return iterator->second;

//    for (int i = 0; i < this->getNumberOfVertices(); i++)
//    {
//        if (vertexList[i].getValue() == value)
//        {
//            return i;
//        }
//    }
//    cout << "Vertex not found!" << endl;
//    return -1;
}

//This function returns the weight between two vertices.
//@param: const T &fromValue, const T &toValue
//returns double in the form of the weight
template <class T>
double UndirectedMatrixGraph<T>::getWeight(const T &fromValue, const T &toValue)
{
    int fromIndex = lookUpVertex(fromValue);
    int toIndex = lookUpVertex(toValue);

    if (fromIndex != -1 && toIndex != -1) //if both vertices exist
    {
        return adjMatrix[fromIndex][toIndex]; //return weight
    }
    return -1; //if vertices arent available, return -1
}

//This function returns the neighbors of a specified vertex
//@param: const T& targetCoin
//returns list of neighbors to the targetCoin
template<class T>
vector<Vertex<T>> UndirectedMatrixGraph<T>::getNeighbors(const T &targetCoin)
{
    vector<Vertex<T>> listOfNeighbors;//create a list

    int index = lookUpVertex(targetCoin); //gets index of vertex
    if (index != -1) //if vertex exists
    {
        for (int i = 0; i < this->getNumberOfVertices(); i++)//loop through the rows of matrix
        {
            if (adjMatrix[index][i] != 0.00) //if a valid edge exists to the passed vertex
            {
                listOfNeighbors.push_back(vertexList[i]);//push the neighbors to the list
            }
        }
    }
    return std::move(listOfNeighbors);//return list of neighbors
}


template<class T>
string UndirectedMatrixGraph<T>::toString()
{
    static const int baseSymbolLength = 3;
    static const int spacing = 4;

    string spaces = string(spacing, ' ');
    string headerSpaces = string(spacing + 1, ' ');
    string str(spacing + 3, ' ');

    // row with headers
    for (auto it = vertexList.begin(); it != vertexList.end(); ++it) {
        str += (*it).getValue() + headerSpaces;
    }

    // remove the last whitespaces
    if (str.length() > 0)
        str = str.substr(0, str.length() - spacing);

    str += "\n";

    stringstream buffer;
    int i = 0; // counter of vertex list
    string line; // hold data for each line

    for (auto it = adjMatrix.begin(); it != adjMatrix.end(); ++it) {
        line += vertexList.at(i++).getValue(); // get the symbol
        line += string(spacing - (line.length() - baseSymbolLength), ' '); // calculate the spacing based on the symbol length
        for (auto column = it->begin(); column != it->end(); ++column) {
            buffer.str(string());
            buffer << fixed << setprecision(2) << *column << spaces; // get value of double with precision of 2
            line += buffer.str();
        }
        str += line + "\n\n";
        line = "";
    }

    return str;
}


template<class T>
void UndirectedMatrixGraph<T>::reset() {
    vertexList.clear();
    adjMatrix.clear();
    totalNumberOfVertices = 0;
}

