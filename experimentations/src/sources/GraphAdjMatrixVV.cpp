#include "../headers/Graph.hpp"
#include "../headers/Matrix.hpp"
#include <math.h>
#include <algorithm>

using namespace std;

GraphAdjMatrixVV::GraphAdjMatrixVV(int vertices) {
    this->setSize(vertices);
}

vector<vector<int>> GraphAdjMatrixVV::getAdjacencyMatrix(){
    return adjacencyMatrix;
}

int GraphAdjMatrixVV::getNumVertices() const {
    return numVertices;
}

int GraphAdjMatrixVV::getNumEdges() const {
    int count = 0;
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            count += adjacencyMatrix[i][j];
        }
    }
    return count/2;
}

void GraphAdjMatrixVV::setSize(int vertices) {
    numVertices = vertices;
    adjacencyMatrix.resize(numVertices, vector<int>(numVertices, 0));
}

void GraphAdjMatrixVV::addEdge(int vrtx1, int vrtx2) {
    adjacencyMatrix[vrtx1][vrtx2] = 1;
    adjacencyMatrix[vrtx2][vrtx1] = 1;
}

int GraphAdjMatrixVV::degree(int vertex) const {
    int degree = 0;
    for (int i = 0; i < numVertices; ++i) {
        if (adjacencyMatrix[vertex][i] == 1) {
            degree++;
        }
    }
    return degree;
}

bool GraphAdjMatrixVV::isBiggerOrder(int vrtx1, int vrtx2) const {
    int dv1 = degree(vrtx1);
    int dv2 = degree(vrtx2);
    return (dv1 > dv2) || (dv1 == dv2 && vrtx1 > vrtx2);
}

void GraphAdjMatrixVV::printGraph() const {
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

bool GraphAdjMatrixVV::hasEdge(int vrtx1, int vrtx2) const {
    return adjacencyMatrix[vrtx1][vrtx2] == 1;
}

int GraphAdjMatrixVV::countTrianglesNodeIterator() const {
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

int GraphAdjMatrixVV::countTrianglesNodeIteratorPlusPlus() const {
    int count = 0;
    for (int v = 0; v < numVertices; ++v) {
        for (int u = 0; u < numVertices; ++u) {
            if (hasEdge(v, u) && isBiggerOrder(u,v) ) {
                for (int w = 0; w < numVertices; ++w) {
                    if (hasEdge(v, w) && hasEdge(u, w) && isBiggerOrder(w,u)){
                        count++;
                    }
                }
            }
        }
    }
    return count;
}

int GraphAdjMatrixVV::countTrianglesMatrixSquaring(std::function<std::vector<std::vector<int>>(const std::vector<std::vector<int>>&, const std::vector<std::vector<int>>&, int)> multiplyFunc, int numThreads) const {
    double count = 0;
    vector<vector<int>> A = adjacencyMatrix;
    vector<vector<int>> A2 = multiplyFunc(A, A, numThreads);

    for(int i = 0; i < numVertices; i++){
        for(int j = 0; j < numVertices; j++){
            count += A[i][j]*A2[i][j];
        }
    }
    return count/6;
}

int GraphAdjMatrixVV::countTrianglesMatrixSquaring(std::function<std::vector<std::vector<int>>(const std::vector<std::vector<int>>&, const std::vector<std::vector<int>>&)> multiplyFunc) const {
    double count = 0;
    vector<vector<int>> A = adjacencyMatrix;
    vector<vector<int>> A2 = multiplyFunc(A, A);

    for(int i = 0; i < numVertices; i++){
        for(int j = 0; j < numVertices; j++){
            count += A[i][j]*A2[i][j];
        }
    }
    return count/6;
}

int GraphAdjMatrixVV::countTrianglesMatrixCube(std::function<std::vector<std::vector<int>>(const std::vector<std::vector<int>>&, const std::vector<std::vector<int>>&, int)> multiplyFunc, int numThreads) const {
    double count = 0;
    vector<vector<int>> A = adjacencyMatrix;
    vector<vector<int>> A2 = multiplyFunc(A, A, numThreads);
    vector<vector<int>> A3 = multiplyFunc(A2, A, numThreads);

    for(int i = 0; i < numVertices; i++){
        count += A3[i][i];
    }
    return count/6;
}

int GraphAdjMatrixVV::countTrianglesMatrixCube(std::function<std::vector<std::vector<int>>(const std::vector<std::vector<int>>&, const std::vector<std::vector<int>>&)> multiplyFunc) const {
    double count = 0;
    vector<vector<int>> A = adjacencyMatrix;
    vector<vector<int>> A2 = multiplyFunc(A, A);
    vector<vector<int>> A3 = multiplyFunc(A2, A);

    for(int i = 0; i < numVertices; i++){
        count += A3[i][i];
    }
    return count/6;
}
