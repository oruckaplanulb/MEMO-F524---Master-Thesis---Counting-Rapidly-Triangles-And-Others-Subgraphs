#include "../headers/Graph.hpp"
#include "../headers/Matrix.hpp"
#include <math.h>
#include <map>

using namespace std;

GraphAdjListVUS::GraphAdjListVUS(int vertices) {
    this->setSize(vertices);
}

int GraphAdjListVUS::getNumVertices() const {
    return numVertices;
}

int GraphAdjListVUS::getNumEdges() const {
    int count = 0;
    for (int i = 0; i < numVertices; ++i) {
        count += adjacencyList[i].size();
    }
    return count/2;
}

void GraphAdjListVUS::setSize(int vertices) {
    numVertices = vertices;
    adjacencyList.resize(numVertices);
}

void GraphAdjListVUS::addEdge(int vrtx1, int vrtx2) {
    adjacencyList[vrtx1].insert(vrtx2);
    adjacencyList[vrtx2].insert(vrtx1);
}

int GraphAdjListVUS::degree(int vertex) const {
    return adjacencyList[vertex].size();
}

bool GraphAdjListVUS::isBiggerOrder(int vrtx1, int vrtx2) const {
    int dv1 = degree(vrtx1);
    int dv2 = degree(vrtx2);
    return (dv1 > dv2) || (dv1 == dv2 && vrtx1 > vrtx2);
}

void GraphAdjListVUS::printGraph() const {
    for (int i = 0; i < numVertices; ++i) {
        cout << "Vertex " << i << ": ";
        for (const int& neighbor : adjacencyList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

bool GraphAdjListVUS::hasEdge(int vrtx1, int vrtx2) const {
    return (adjacencyList[vrtx1].find(vrtx2) != adjacencyList[vrtx1].end());
}

unordered_set<int>& GraphAdjListVUS::getNeighbors(int v){
    return adjacencyList[v];
}

int GraphAdjListVUS::countTrianglesNodeIterator() const {
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

int GraphAdjListVUS::countTrianglesNodeIteratorPlusPlus() const {
    int count = 0;
    for (int v = 0; v < numVertices; ++v) {
        for (const int& u : adjacencyList[v]) {
            if(isBiggerOrder(u, v)){
                for (const int& w : adjacencyList[v]) {
                    if (isBiggerOrder(w,u) && hasEdge(u, w)) {
                        count++;
                    }
                }
            }
        }
    }
    return count;
}

int GraphAdjListVUS::countTrianglesEdgeIterator() const {
    int count = 0;
    for (int v = 0; v < numVertices; ++v) {
        for (const int& u : adjacencyList[v]) {
            unordered_set<int> intersection;
            for (const int& w : adjacencyList[u]) {
                if (adjacencyList[v].count(w)) {
                    intersection.insert(w);
                }
            }
            count += intersection.size();
        }
    }
    return count/6;
}

int GraphAdjListVUS::AYZ_Algorithm() const{
    double beta = pow(getNumEdges(),2.0/4.0);

    vector<double> delta(numVertices, 0);
    vector<int> Vlow, Vhigh;

    for (int v = 0; v < numVertices; ++v) {
        if (degree(v) <= beta) {
            Vlow.push_back(v);
        } else {
            Vhigh.push_back(v);
        }
    }

    cout << "Vlow size: " << Vlow.size() << endl;
    cout << "Vhigh size: " << Vhigh.size() << endl;

    for (int v : Vlow) {
        for (const int& u : adjacencyList[v]) {
            for (const int& w : adjacencyList[v]) {
                if (hasEdge(u, w)) {
                    if (degree(u) <= beta && degree(w) <= beta) {
                        delta[v] += 1.0/3.0;
                        delta[u] += 1.0/3.0;
                        delta[w] += 1.0/3.0;
                    } else if (degree(u) > beta && degree(w) > beta) {
                        delta[v] += 1.0;
                        delta[u] += 1.0;
                        delta[w] += 1.0;
                    } else {
                        delta[v] += 1.0/2.0;
                        delta[u] += 1.0/2.0;
                        delta[w] += 1.0/2.0;
                    }
                }
            }
        }
    }
    
    vector<vector<int>> A(Vhigh.size(), vector<int>(Vhigh.size(), 0));

    for (int i = 0; i < Vhigh.size(); ++i) {
        int v = Vhigh[i];
        for (int j = 0; j < Vhigh.size(); ++j) {
            int u = Vhigh[j];
            if (hasEdge(v, u)) {
                A[i][j] = 1;
            }
        }
    }
    cout << "TEST" << endl;
    if(Vhigh.size() != 0){
        vector<vector<int>> M = Matrix::multiplyNaive(Matrix::multiplyNaive(A, A), A); // A^3

        for (int i = 0; i < Vhigh.size(); ++i) {
            int v = Vhigh[i];
            delta[v] += M[i][i] / 2.0;
        }
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

int GraphAdjListVUS::count4CyclesBasic() const{
    //zero-initialized array L of size n indexed by V
    int count = 0;
    vector<int> L(numVertices, 0);
    for(int v = 0 ; v < numVertices; v++){
        for(int u : adjacencyList[v]){
            if(isBiggerOrder(v,u)){
                for(int w : adjacencyList[u]){
                    if(isBiggerOrder(v,w)){
                        count = count + L[w];
                        L[w]++;
                    }
                }
            }
        }
        for(int u : adjacencyList[v]){
            if(isBiggerOrder(v,u)){
                for(int w : adjacencyList[u]){
                    if(isBiggerOrder(v,w)){
                        L[w] = 0;
                    }
                }
            }
        }
    }
    return count;
}