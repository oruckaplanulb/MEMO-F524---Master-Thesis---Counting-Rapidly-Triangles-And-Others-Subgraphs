#include "../headers/Graph.hpp"
#include <numeric>
#include <algorithm>

using namespace std;

GraphEdgListVP::GraphEdgListVP(int vertices) {
    this->setSize(vertices);
}

int GraphEdgListVP::getNumVertices() const {
    return numVertices;
}

int GraphEdgListVP::getNumEdges() const {
    return edgeList.size();
}

void GraphEdgListVP::setSize(int vertices) {
    numVertices = vertices;
    edgeList.resize(0);
}

void GraphEdgListVP::addEdge(int vrtx1, int vrtx2) {
    edgeList.push_back(make_pair(vrtx1, vrtx2));
}

int GraphEdgListVP::degree(int vertex) const {
    int degree = 0;
    for (const pair<int, int>& edge : edgeList) {
        if (edge.first == vertex || edge.second == vertex) {
            degree++;
        }
    }
    return degree;
}

bool GraphEdgListVP::isBiggerOrder(int vrtx1, int vrtx2) const {
    int dv1 = degree(vrtx1);
    int dv2 = degree(vrtx2);
    return (dv1 > dv2) || (dv1 == dv2 && vrtx1 > vrtx2);
}

void GraphEdgListVP::printGraph() const {
    for (const pair<int, int>& edge : edgeList) {
        cout << edge.first << " " << edge.second << endl;
    }
}

bool GraphEdgListVP::hasEdge(int vrtx1, int vrtx2) const {
    for (const pair<int, int>& edge : edgeList) {
        if ((edge.first == vrtx1 && edge.second == vrtx2) || (edge.first == vrtx2 && edge.second == vrtx1)) {
            return true;
        }
    }
    return false;
}

vector<int> GraphEdgListVP::getNeighbors(int v) const{
    vector<int> neighbors;
    for (const pair<int, int>& edge : edgeList) {
        if (edge.first == v) {
            neighbors.push_back(edge.second);
        } else if (edge.second == v) {
            neighbors.push_back(edge.first);
        }
    }
    return neighbors;
}

int GraphEdgListVP::countTrianglesEdgeIterator() const {
    return 0;
}

int GraphEdgListVP::countTrianglesForward() const {
    int triangleCount = 0;
    vector<unordered_set<int>> A(numVertices);

    // Sort vertices by non-increasing degree
    vector<int> vertices;
    for (int i = 0; i < numVertices; ++i) {
        vertices.push_back(i);
    }
    sort(vertices.begin(), vertices.end(), [this](int v1, int v2) {
        return degree(v1) > degree(v2);
    });

    // Forward algorithm
    for (int vi : vertices) {
        for (int vl : getNeighbors(vi)) {
            if (vi < vl) {
                for (int v : A[vi]) {
                    if (A[vl].count(v) > 0) {
                        ++triangleCount;
                    }
                }
            }
        }
        for (int vl : getNeighbors(vi)) {
            if (vi < vl) {
                A[vl].insert(vi);
            }
        }
    }

    return triangleCount;
}