#include "AdjacencyList.h"
#include<iostream>
#include <vector>
#include<string>
#include <iomanip>

using namespace std;

// base constructor
AdjacencyList::Vertex::Vertex() {
    this->websiteLink = "";
    outDegree = 0.0;
    pageRank= 0.0;
    sum = 0.0;
}

// parametrized vertex constructor
AdjacencyList::Vertex::Vertex(string websiteLink) {
    outDegree = 0.0;
    sum = 0.0;
    vertexID = 0.0;
    this->websiteLink= websiteLink;
}

// adjacency list base constructor
AdjacencyList::AdjacencyList() {
    verticeCount = 0.0;
}

bool AdjacencyList::findFromVertex(string vertexToFind) {
    // if vertexToFind is not found, we return true
    if (adjacencyList.find(vertexToFind) == adjacencyList.end()){
        return true;
    }
    return false;
}

bool AdjacencyList::findToVertex(string vertexToFind) {
    // if vertexToFind is not found, we return true
    if (adjacencyList.find(vertexToFind) == adjacencyList.end()){
        return true;
    }
    return false;
}

void AdjacencyList::createFromVertex(string from, Vertex fromVertex) {
    //update from vertex values
    adjacencyList[from].first = fromVertex;
    adjacencyList[from].first.vertexID = verticeCount;
}

void AdjacencyList::createToVertex(string to, Vertex toVertex){
    //update to vertex values
    adjacencyList[to].first = toVertex;
    adjacencyList[to].first.vertexID = verticeCount;
}

void AdjacencyList::insertInList(string from, string to) {
    Vertex fromVertex = Vertex(from);
    Vertex toVertex = Vertex(to);

    // from node doesnt exist
    if (findFromVertex(from) == true) {
        // we know from does not exist, create from vertex
        createFromVertex(from, fromVertex);
        verticeCount += 1;
    }
    else if (findFromVertex(from) == false){
        fromVertex = fromVertex;
    }
    // to node doesnt exist
    if (findToVertex(to) == true) {
        // we know to does not exist, create to vertex
        createToVertex(to, toVertex);
        verticeCount += 1;
    }
    else if (findToVertex(to) == false) {
        toVertex = toVertex;
    }
    // puts fromVertex to point at toVertex
    adjacencyList[from].second.push_back(toVertex);

    // increment outDegree
    adjacencyList[from].first.outDegree += 1;
}

void AdjacencyList::pageRank(int powerIterations){
    vector<float> iteration;
    // standardizes to 1.0 / numVertices;
    for (auto iter = adjacencyList.begin(); iter != adjacencyList.end(); ++iter) {
        iteration.push_back(1.0 / verticeCount);
        iter->second.first.pageRank = 1.0 / verticeCount;
    }
    while (powerIterations > 1) {
    //for each Vertex calculate pagerank for each vertex that points to it
        for (auto iter = adjacencyList.begin(); iter != adjacencyList.end(); iter++) {
            for (int j = 0; j < iter->second.second.size(); j++) {
                float insert = (1.0 / iter->second.first.outDegree) * (iteration.at(iter->second.first.vertexID));
                adjacencyList.find(iter->second.second.at(j).websiteLink)->second.first.sum += insert;
            }
        }
        // updates iteration matrix to current power iteration
        for (auto iter = adjacencyList.begin(); iter != adjacencyList.end(); iter++) {
            iter->second.first.pageRank = iter->second.first.sum;
            iteration.at(iter->second.first.vertexID) = iter->second.first.pageRank;
            iter->second.first.sum = 0.0;
        }
        powerIterations--;
    }
}

void AdjacencyList::printInOrder(){
    //prints the web links and page rank in order (alphabetical, least -> highest rank)
    for (auto iter2 = adjacencyList.begin(); iter2 != adjacencyList.end(); iter2++) {
        cout << iter2->first << " " << fixed << setprecision(2) << iter2->second.first.pageRank << endl;
    }
}