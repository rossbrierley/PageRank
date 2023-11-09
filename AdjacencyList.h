#ifndef PAGERANK_ADJACENCYLIST_H
#define PAGERANK_ADJACENCYLIST_H
#include <string>
#include <vector>
#include <map>
#pragma once
using namespace std;

class AdjacencyList {
    struct Vertex {
    public:
        Vertex(string websiteName);
        Vertex();
        float outDegree;
        float pageRank;
        float sum;
        int vertexID;
        string websiteLink;
    };
private:
    //Think about what member variables you need to initialize
    float verticeCount;
    map<string, pair<Vertex, vector<Vertex>>> adjacencyList;

public:
    //Think about what helper functions you will need in the algorithm
    AdjacencyList();
    void pageRank(int powerIteration);
    void insertInList(string from, string to);
    void createFromVertex(string from, Vertex fromVertex);
    void createToVertex(string to, Vertex toVertex);
    void printInOrder();

    bool findFromVertex(string vertexToFind);
    bool findToVertex(string vertexToFind);
};
#endif //PAGERANK_ADJACENCYLIST_H
