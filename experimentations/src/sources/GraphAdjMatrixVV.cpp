#include "../headers/Graph.hpp"
#include "../headers/Matrix.hpp"
#include <math.h>
#include <algorithm>
#include <thread>

using namespace std;

GraphAdjMatrixVV::GraphAdjMatrixVV(int vertices) {
    this->setSize(vertices);
}

vector<vector<int>> GraphAdjMatrixVV::getAdjacencyMatrix() const{
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

vector<int> GraphAdjMatrixVV::getNeighbors(int v) {
    std::vector<int> neighborsVector;
    for (int i = 0; i < numVertices; ++i) {
        if (adjacencyMatrix[v][i] == 1) {
            neighborsVector.push_back(i);
        }
    }
    return neighborsVector;
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

int GraphAdjMatrixVV::countTrianglesNodeIteratorPlusPlusWithOrder() const {

    vector<int> vSortedByOrder(numVertices);
    for (int i = 0; i < numVertices; ++i) {
        vSortedByOrder[i] = i;
    }
    sort(vSortedByOrder.begin(), vSortedByOrder.end(), [this](int v1,int v2) {
        return isBiggerOrder(v1, v2);
    });
    vector<int> vPositionInSorted(numVertices);
    for (int i = 0; i < numVertices; ++i) {
        vPositionInSorted[vSortedByOrder[i]] = i;
    }

    int count = 0;
    for (int v = 0; v < numVertices; ++v) {
        for (int u = 0; u < numVertices; ++u) {
            if (hasEdge(v, u) && vPositionInSorted[u] > vPositionInSorted[v]) {
                for (int w = 0; w < numVertices; ++w) {
                    if (hasEdge(v, w) && hasEdge(u, w) && vPositionInSorted[w] > vPositionInSorted[u]){
                        count++;
                    }
                }
            }
        }
    }
    return count;
}

int GraphAdjMatrixVV::countTrianglesMatrixSquaring(function<vector<vector<int>>(const vector<vector<int>>&, const vector<vector<int>>&, int)> multiplyFunc, int numThreads) const {
    double count = 0;
    const vector<vector<int>>& A = adjacencyMatrix;
    const vector<vector<int>>& A2 = multiplyFunc(A, A, numThreads);

    for(int i = 0; i < numVertices; i++){
        for(int j = 0; j < numVertices; j++){
            count += A[i][j]*A2[i][j];
        }
    }
    return count/6;
}

int GraphAdjMatrixVV::countTrianglesMatrixSquaringParallel(function<vector<vector<int>>(const vector<vector<int>>&, const vector<vector<int>>&, int)> multiplyFunc, int numThreadsMM, int numThreads) const {
    double count = 0;
    const vector<vector<int>>& A = adjacencyMatrix;
    const vector<vector<int>>& A2 = multiplyFunc(A, A, numThreadsMM);

    int chunkSize = numVertices / numThreads;
    vector<thread> threads;
    for (int t = 0; t < numThreads; ++t) {
        int start = t * chunkSize;
        int end = (t == numThreads - 1) ? numVertices : (t + 1) * chunkSize;
        threads.push_back(thread([&, start, end] {
            int localCount = 0;
            for (int i = start; i < end; ++i) {
                for (int j = 0; j < numVertices; ++j) {
                    localCount += A[i][j] * A2[i][j];
                }
            }
            count += localCount;
        }));
    }

    // Join all threads
    for (auto& thread : threads) {
        thread.join();
    }

    return count / 6;
}

int GraphAdjMatrixVV::countTrianglesMatrixCube(function<vector<vector<int>>(const vector<vector<int>>&, const vector<vector<int>>&, int)> multiplyFunc, int numThreads) const {
    double count = 0;
    const vector<vector<int>>& A = adjacencyMatrix;
    const vector<vector<int>>& A2 = multiplyFunc(A, A, numThreads);
    const vector<vector<int>>& A3 = multiplyFunc(A2, A, numThreads);

    for(int i = 0; i < numVertices; i++){
        count += A3[i][i];
    }
    return count/6;
}

int GraphAdjMatrixVV::countTrianglesMatrixCubeParallel(function<vector<vector<int>>(const vector<vector<int>>&, const vector<vector<int>>&, int)> multiplyFunc, int numThreadsMM, int numThreads) const {
    double count = 0;
    const vector<vector<int>>& A = adjacencyMatrix;
    const vector<vector<int>>& A2 = multiplyFunc(A, A, numThreadsMM);
    const vector<vector<int>>& A3 = multiplyFunc(A2, A, numThreadsMM);

    int chunkSize = numVertices/numThreads;
    vector<thread> threads;
    for (int i = 0; i< numThreads; ++i){
        int start = i*chunkSize;
        int end = (i == numThreads - 1) ? numVertices : start + chunkSize;
        threads.push_back(thread([start, end, &A3, &count] {
            int localCount = 0;
            for(int j = start; j < end; j++){
                localCount += A3[j][j];
            }
            count += localCount;
        }));
    }

    for (auto& t : threads) {
        t.join();
    }

    return count/6;
}
