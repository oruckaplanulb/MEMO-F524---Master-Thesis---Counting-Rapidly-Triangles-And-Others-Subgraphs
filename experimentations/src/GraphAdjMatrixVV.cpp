#include "Graph.hpp"
#include "Matrix.hpp"
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
    // Assuming the graph is undirected
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
    return count;
}

int GraphAdjMatrixVV::countTrianglesMatrixSquaring() const {
    double count = 0;
    vector<vector<int>> A = adjacencyMatrix;
    vector<vector<int>> A2 = Matrix::multiplyNaive(A, A);
    cout << "multiplication done" << endl;

    for(int i = 0; i < numVertices; i++){
        for(int j = 0; j < numVertices; j++){
            count += A[i][j]*A2[i][j];
        }
    }
    return count/6;
}

int GraphAdjMatrixVV::countTrianglesMatrixCube() const {
    double count = 0;
    vector<vector<int>> A = adjacencyMatrix;
    vector<vector<int>> A2 = Matrix::multiplyNaive(A, A);
    vector<vector<int>> A3 = Matrix::multiplyNaive(A2, A);

    for(int i = 0; i < numVertices; i++){
        count += A3[i][i];
    }
    return count/6;
}

int GraphAdjMatrixVV::AYZ_Algorithm() const{
    double beta = pow(getNumEdges(),2.0/4.0);

    vector<int> delta(numVertices, 0);

    vector<int> Vlow, Vhigh;

    for (int v = 0; v < numVertices; ++v) {
        if (degree(v) <= beta) {
            Vlow.push_back(v);
        } else {
            Vhigh.push_back(v);
        }
    }
    //print Vlow and Vhigh size
    cout << "Vlow size: " << Vlow.size() << endl;
    cout << "Vhigh size: " << Vhigh.size() << endl;

    for (int v : Vlow) {
        for (int u = 0; u < numVertices; ++u) {
            for (int w = 0; w < numVertices; ++w) {
                if (hasEdge(u,v) && hasEdge(w,v) && hasEdge(u, w)) {
                    if (degree(u) <= beta && degree(w) <= beta) {
                        delta[v] += 1;
                        delta[u] += 1;
                        delta[w] += 1;
                    } else if (degree(u) > beta && degree(w) > beta) {
                        delta[v] += 1;
                        delta[u] += 1;
                        delta[w] += 1;
                    } else {
                        delta[v] += 1;
                        delta[u] += 1;
                        delta[w] += 1;
                    }
                }
            }
        }
    }

    /*vector<vector<int>> A(numVertices, vector<int>(numVertices, 0));
    for (int v : Vhigh) {
        for (int u = 0; u < numVertices; ++u) {
            if (hasEdge(v, u)) {
                A[v][u] = 1;
            }
        }
    }*/
    vector<vector<int>> M = Matrix::multiplyNaive((adjacencyMatrix,adjacencyMatrix),adjacencyMatrix); // A^3

    for (int v : Vhigh) {
        delta[v] += M[v][v];
    }

    /*cout << "Delta values:" << endl;
    for (int v = 0; v < numVertices; ++v) {
        cout << "Vertex " << v << ": " << delta[v] << endl;
    }*/

    int count = 0;
    for (int v = 0; v < numVertices; ++v) {
        count += delta[v];
    }
    return count/6;
}
