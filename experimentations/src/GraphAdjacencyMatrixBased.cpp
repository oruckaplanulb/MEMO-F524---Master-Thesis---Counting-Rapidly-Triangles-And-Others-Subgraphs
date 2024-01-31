#include "Graph.hpp"

GraphAdjacencyMatrixBased::GraphAdjacencyMatrixBased(int vertices) {
    numVertices = vertices;
    // Initialize adjacency matrix with zeros
    adjacencyMatrix.resize(numVertices, std::vector<int>(numVertices, 0));
}

void GraphAdjacencyMatrixBased::addEdge(int start, int end) {
    // Assuming the graph is undirected
    adjacencyMatrix[start][end] = 1;
    adjacencyMatrix[end][start] = 1;
}

void GraphAdjacencyMatrixBased::printGraph() const {
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            std::cout << adjacencyMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool GraphAdjacencyMatrixBased::hasEdge(int start, int end) const {
    return adjacencyMatrix[start][end] == 1;
}
