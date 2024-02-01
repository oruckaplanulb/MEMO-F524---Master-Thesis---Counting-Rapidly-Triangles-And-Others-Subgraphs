#include "Graph.hpp"

GraphAdjacencyListBased::GraphAdjacencyListBased(int vertices) {
    numVertices = vertices;
    adjacencyList.resize(numVertices);
}

void GraphAdjacencyListBased::addEdge(int vrtx1, int vrtx2) {
    adjacencyList[vrtx1].push_back(vrtx2);
    adjacencyList[vrtx2].push_back(vrtx1);
}

void GraphAdjacencyListBased::printGraph() const {
    for (int i = 0; i < numVertices; ++i) {
        std::cout << "Vertex " << i << ": ";
        for (const int& neighbor : adjacencyList[i]) {
            std::cout << neighbor << " ";
        }
        std::cout << std::endl;
    }
}

bool GraphAdjacencyListBased::hasEdge(int vrtx1, int vrtx2) const {
    for (const int& neighbor : adjacencyList[vrtx1]) {
        if (neighbor == vrtx2) {
            return true;
        }
    }
    return false;
}

int GraphAdjacencyListBased::countTrianglesNodeIterator() const {
    double count = 0;
    for (int v = 0; v < numVertices; ++v) {
        for (const int& u : adjacencyList[v]) {
            for (const int& w : adjacencyList[v]) {
                if (hasEdge(u, w)) {
                    count = count + 0.5;
                }
            }
        }
    }
    return count/3;
}
