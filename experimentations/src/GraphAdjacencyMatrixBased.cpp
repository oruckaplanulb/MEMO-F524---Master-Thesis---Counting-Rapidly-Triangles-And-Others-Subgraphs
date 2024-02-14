#include "Graph.hpp"
#include "Matrix.hpp"

using namespace std;

GraphAdjacencyMatrixBased::GraphAdjacencyMatrixBased(int vertices) {
    this->setSize(vertices);
}

vector<vector<int>> GraphAdjacencyMatrixBased::getAdjacencyMatrix(){
    return adjacencyMatrix;
}

void GraphAdjacencyMatrixBased::setSize(int vertices) {
    numVertices = vertices;
    adjacencyMatrix.resize(numVertices, vector<int>(numVertices, 0));
}

void GraphAdjacencyMatrixBased::addEdge(int vrtx1, int vrtx2) {
    // Assuming the graph is undirected
    adjacencyMatrix[vrtx1][vrtx2] = 1;
    adjacencyMatrix[vrtx2][vrtx1] = 1;
}

int GraphAdjacencyMatrixBased::degree(int vertex) const {
    int degree = 0;
    for (int i = 0; i < numVertices; ++i) {
        if (adjacencyMatrix[vertex][i] == 1) {
            degree++;
        }
    }
    return degree;
}

void GraphAdjacencyMatrixBased::printGraph() const {
    for (int i = 0; i < numVertices; ++i) {
        for (int j = 0; j < numVertices; ++j) {
            cout << adjacencyMatrix[i][j] << " ";
        }
        cout << endl;
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

int GraphAdjacencyMatrixBased::countTrianglesNodeIteratorPlusPlus() const {
    double count = 0;
    for (int v = 0; v < numVertices; ++v) {
        for (int u = 0; u < numVertices; ++u) {
            if (hasEdge(v, u) && degree(v) <= degree(u)) {
                for (int w = 0; w < numVertices; ++w) {
                    if (hasEdge(v, w) && hasEdge(u, w) && degree(u) <= degree(w)) {
                        count += 1.0;
                    }
                }
            }
        }
    }
    return count;
}

int GraphAdjacencyMatrixBased::countTrianglesMatrixSquaring() const {
    double count = 0;
    vector<vector<int>> A = adjacencyMatrix;
    vector<vector<int>> A2 = Matrix::multiplyNaive(A, A);
    cout << "multiplication done" << endl;

    for(int i = 0; i < numVertices; i++){
        //print current i value
        cout << "i: " << i << endl;
        for(int j = 0; j < numVertices; j++){
            count += A[i][j]*A2[i][j];
        }
    }
    return count/6;
}

int GraphAdjacencyMatrixBased::countTrianglesMatrixCube() const {
    double count = 0;
    vector<vector<int>> A = adjacencyMatrix;
    vector<vector<int>> A2 = Matrix::multiplyNaive(A, A);
    vector<vector<int>> A3 = Matrix::multiplyNaive(A2, A);

    for(int i = 0; i < numVertices; i++){
        count += A3[i][i];
    }
    return count/6;
}
