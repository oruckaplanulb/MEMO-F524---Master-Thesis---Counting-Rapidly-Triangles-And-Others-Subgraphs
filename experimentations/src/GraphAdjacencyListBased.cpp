#include "Graph.hpp"

GraphAdjacencyListBased::GraphAdjacencyListBased(int vertices) {
    numVertices = vertices;
    adjacencyList.resize(numVertices);
}

void GraphAdjacencyListBased::addEdge(int start, int end) {
    adjacencyList[start].push_back(end);
    adjacencyList[end].push_back(start);
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

bool GraphAdjacencyListBased::hasEdge(int start, int end) const {
    for (const int& neighbor : adjacencyList[start]) {
        if (neighbor == end) {
            return true;
        }
    }
    return false;
}
