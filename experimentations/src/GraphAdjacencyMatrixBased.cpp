#include "Graph.hpp"
#include "Matrix.hpp"

GraphAdjacencyMatrixBased::GraphAdjacencyMatrixBased(int vertices) {
    numVertices = vertices;
    // Initialize adjacency matrix with zeros
    adjacencyMatrix.resize(numVertices, std::vector<int>(numVertices, 0));
}

std::vector<std::vector<int>> GraphAdjacencyMatrixBased::getAdjacencyMatrix(){
    return adjacencyMatrix;
}

void GraphAdjacencyMatrixBased::addEdge(int vrtx1, int vrtx2) {
    // Assuming the graph is undirected
    adjacencyMatrix[vrtx1][vrtx2] = 1;
    adjacencyMatrix[vrtx2][vrtx1] = 1;
}

void GraphAdjacencyMatrixBased::printGraph() const {
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            std::cout << adjacencyMatrix[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool GraphAdjacencyMatrixBased::hasEdge(int vrtx1, int vrtx2) const {
    return adjacencyMatrix[vrtx1][vrtx2] == 1;
}

int GraphAdjacencyMatrixBased::countTrianglesNodeIterator() const {
    double count = 0;
    for (int v = 0; v < numVertices; ++v) {
        for (int u = 0; u < numVertices; ++u) {
            if (hasEdge(v, u)) {
                for (int w = 0; w < numVertices; ++w) {
                    if (hasEdge(v, w) && hasEdge(u, w)) {
                        count = count + 0.5;
                    }
                }
            }
        }
    }
    return count/3;
}

int GraphAdjacencyMatrixBased::countTrianglesMatrixSquaring() const {
    double count = 0;
    std::vector<std::vector<int>> A = adjacencyMatrix;
    std::vector<std::vector<int>> A2 = Matrix::multiplyNaive(A, A);

    for(int i = 0; i < numVertices; i++){
        for(int j = 0; j < numVertices; j++){
            if(A2[i][j] > 0){
                count += A2[i][j];
            }
        }
    }
    return count/3;
}

int GraphAdjacencyMatrixBased::countTrianglesMatrixCube() const {
    double count = 0;
    std::vector<std::vector<int>> A = adjacencyMatrix;
    std::vector<std::vector<int>> A2 = Matrix::multiplyNaive(A, A);
    std::vector<std::vector<int>> A3 = Matrix::multiplyNaive(A2, A);

    for(int i = 0; i < numVertices; i++){
        count += A3[i][i];
    }
    return count/6;
}
