#include "../headers/Graph.hpp"
#include "../headers/Matrix.hpp"
#include "../headers/Utils.hpp"
#include <math.h>
#include <map>
#include <thread>
#include <algorithm>

using namespace std;

GraphAdjListVV::GraphAdjListVV(int vertices) {
    this->setSize(vertices);
}

int GraphAdjListVV::getNumVertices() const {
    return numVertices;
}

int GraphAdjListVV::getNumEdges() const {
    int count = 0;
    for (int i = 0; i < numVertices; ++i) {
        count += adjacencyList[i].size();
    }
    return count/2;
}

void GraphAdjListVV::setSize(int vertices) {
    numVertices = vertices;
    adjacencyList.resize(numVertices);
}

void GraphAdjListVV::addEdge(int vrtx1, int vrtx2) {
    adjacencyList[vrtx1].push_back(vrtx2);
    adjacencyList[vrtx2].push_back(vrtx1);
}

int GraphAdjListVV::degree(int vertex) const {
    return adjacencyList[vertex].size();
}

bool GraphAdjListVV::isBiggerOrder(int vrtx1, int vrtx2) const {
    int dv1 = degree(vrtx1);
    int dv2 = degree(vrtx2);
    return (dv1 > dv2) || (dv1 == dv2 && vrtx1 > vrtx2);
}

void GraphAdjListVV::printGraph() const {
    for (int i = 0; i < numVertices; ++i) {
        cout << "Vertex " << i << ": ";
        for (const int& neighbor : adjacencyList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}

bool GraphAdjListVV::hasEdge(int vrtx1, int vrtx2) const {
    for (const int& neighbor : adjacencyList[vrtx1]) {
        if (neighbor == vrtx2) {
            return true;
        }
    }
    return false;
}

vector<int>& GraphAdjListVV::getNeighbors(int v){
    return adjacencyList[v];
}

map<pair<int, int>, int>  GraphAdjListVV::count4CyclesEdgeLocalMap() const{
    vector<int> L(numVertices, 0);
    vector<int> Lbis(numVertices, 0);
    vector<int> M(2*getNumEdges(), 0);
    std::map<std::pair<int, int>, int> edgeCount;
    vector<int> T(numVertices, 0);
    //define T
    for(int v = 0; v < numVertices; v++){
        for(int vp = 0; vp < v; vp++){
            T[v]+=degree(vp);
        }
    }

    //the algo
    for(int v = 0 ; v < numVertices; v++){
        for(int i = 0; i < adjacencyList[v].size(); i++){
            int u = adjacencyList[v][i];
            if(isBiggerOrder(v,u)){
                for(int j = 0; j < adjacencyList[u].size(); j++){
                    int y = adjacencyList[u][j];
                    if(isBiggerOrder(v,y)){
                        L[y] = Lbis[y];
                        Lbis[y]++;
                    }
                }
            }
        }
        for(int i = 0; i < adjacencyList[v].size(); i++){
            int u = adjacencyList[v][i];
            if(isBiggerOrder(v,u)){
                for(int j = 0; j < adjacencyList[u].size(); j++){
                    int y = adjacencyList[u][j];
                    if(isBiggerOrder(v,y)){
                        M[T[v]+i] += L[y];
                        M[T[u]+j] += L[y];
                        Lbis[y] = 0;
                    }
                }
            }
        }
    }

    for(int v = 0 ; v < numVertices; v++){
        for(int i = 0; i < adjacencyList[v].size(); i++){
            int u = adjacencyList[v][i];
            if(isBiggerOrder(v,u)){
                int j = 0;
                for(int y : adjacencyList[u]){
                    if(y == v){
                        edgeCount[make_pair(v,u)] = M[T[v]+i] + M[T[u]+j];
                    }
                    j++;
                }
            }
        }
    }
    
    return edgeCount;
}

vector<vector<int>> GraphAdjListVV::count4CyclesEdgeLocalVector() const{
    vector<int> L(numVertices, 0);
    vector<int> Lbis(numVertices, 0);
    vector<int> M(2*getNumEdges(), 0);
    vector<vector<int>> edgeCount;
    vector<int> T(numVertices, 0);
    //define T
    for(int v = 0; v < numVertices; v++){
        for(int vp = 0; vp < v; vp++){
            T[v]+=degree(vp);
        }
    }

    //the algo
    for(int v = 0 ; v < numVertices; v++){
        for(int i = 0; i < adjacencyList[v].size(); i++){
            int u = adjacencyList[v][i];
            if(isBiggerOrder(v,u)){
                for(int j = 0; j < adjacencyList[u].size(); j++){
                    int y = adjacencyList[u][j];
                    if(isBiggerOrder(v,y)){
                        L[y] = Lbis[y];
                        Lbis[y]++;
                    }
                }
            }
        }
        for(int i = 0; i < adjacencyList[v].size(); i++){
            int u = adjacencyList[v][i];
            if(isBiggerOrder(v,u)){
                for(int j = 0; j < adjacencyList[u].size(); j++){
                    int y = adjacencyList[u][j];
                    if(isBiggerOrder(v,y)){
                        M[T[v]+i] += L[y];
                        M[T[u]+j] += L[y];
                        Lbis[y] = 0;
                    }
                }
            }
        }
    }

    for(int v = 0 ; v < numVertices; v++){
        for(int i = 0; i < adjacencyList[v].size(); i++){
            int u = adjacencyList[v][i];
            if(isBiggerOrder(v,u)){
                int j = 0;
                for(int y : adjacencyList[u]){
                    if(y == v){
                        edgeCount.push_back({v,u,M[T[v]+i] + M[T[u]+j]});
                    }
                    j++;
                }
            }
        }
    }
    
    return edgeCount;
}
