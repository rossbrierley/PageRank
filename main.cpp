#include "AdjacencyList.h"
#include "PageRank.cpp"
#include "iostream"
using namespace std;
int main() {
    int numLines, powerIterations;
    string from, to;

    //create asjacency list object
    AdjacencyList adjacencyList;
    cin >> numLines;
    cin >> powerIterations;

    for (int i = 0; i < numLines; i++) {
        cin >> from;
        cin >> to;
        // insert from and to into adjacency list
        adjacencyList.insertInList(from, to);
    }
    // call page rank and rank the pages
    adjacencyList.pageRank(powerIterations);
    // print links and ranks in order
    adjacencyList.printInOrder();
}