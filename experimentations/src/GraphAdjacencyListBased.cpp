#include "Graph.hpp"
#include "Matrix.hpp"
#include <math.h>

using namespace std;

GraphAdjacencyListBased::GraphAdjacencyListBased(int vertices) {
    this->setSize(vertices);
}

int GraphAdjacencyListBased::getNumVertices() const {
    return numVertices;
}

int GraphAdjacencyListBased::getNumEdges() const {
    int count = 0;
    for (int i = 0; i < numVertices; ++i) {
        count += adjacencyList[i].size();
    }
    return count/2;
}

void GraphAdjacencyListBased::setSize(int vertices) {
    numVertices = vertices;
    adjacencyList.resize(numVertices);
}

void GraphAdjacencyListBased::addEdge(int vrtx1, int vrtx2) {
    adjacencyList[vrtx1].push_back(vrtx2);
    adjacencyList[vrtx2].push_back(vrtx1);
}

int GraphAdjacencyListBased::degree(int vertex) const {
    return adjacencyList[vertex].size();
}

void GraphAdjacencyListBased::printGraph() const {
    for (int i = 0; i < numVertices; ++i) {
        cout << "Vertex " << i << ": ";
        for (const int& neighbor : adjacencyList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
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

int GraphAdjacencyListBased::countTrianglesNodeIteratorPlusPlus() const {
    int count = 0;
    for (int v = 0; v < numVertices; ++v) {
        for (const int& u : adjacencyList[v]) {
            if (degree(v) <= degree(u)) {
                for (const int& w : adjacencyList[u]) {
                    if (degree(v) <= degree(w) && hasEdge(w, v)) {
                        count += 1;
                    }
                }
            }
        }
    }
    return count;
}

int GraphAdjacencyListBased::AYZ_Algorithm() const{
    double beta = pow(getNumEdges(),2.0/4.0);

    vector<int> delta(numVertices, 0);

    vector<int> Vlow, Vhigh;

    cout << "TEST1"<< endl;

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

    cout << "TEST2"<< endl;

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

    cout << "TEST3"<< endl;

    vector<vector<int>> A(numVertices, vector<int>(numVertices, 0));
    for (int v : Vhigh) {
        for (int u = 0; u < numVertices; ++u) {
            if (hasEdge(v, u)) {
                A[v][u] = 1;
            }
        }
    }
    vector<vector<int>> M = Matrix::multiplyNaive(Matrix::multiplyNaive(A, A), A); // A^3

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