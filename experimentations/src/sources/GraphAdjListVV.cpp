#include "../headers/Graph.hpp"
#include "../headers/Matrix.hpp"
#include "../headers/Utils.hpp"
#include <math.h>
#include <map>
#include <thread>
#include <algorithm>
#include <chrono>

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

int GraphAdjListVV::countTrianglesNodeIteratorPlusPlus() const {
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

long long int GraphAdjListVV::count4CyclesBasic() const{
    long long int count = 0;
    vector<int> L(numVertices, 0);

    /*cout << "HELLO" << endl;
    std::this_thread::sleep_for(std::chrono::seconds(40));
    cout << "HELLOFINISHED" << endl;*/

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

vector<vector<int>> GraphAdjListVV::find4Cycles() const {
    vector<vector<int>> cycles;
    vector<vector<int>> L(numVertices);

    for (int v = 0; v < numVertices; ++v) {
        for (int u : adjacencyList[v]) {
            if (isBiggerOrder(v, u)) {
                for (int y : adjacencyList[u]) {
                    if (isBiggerOrder(v, y)) {
                        for (int x : L[y]) {
                            std::vector<int> cycle = {v, u, y, x};
                            cycles.push_back(cycle);
                        }
                        L[y].push_back(u);
                    }
                }
            }
        }
        for (int u : adjacencyList[v]) {
            if (isBiggerOrder(v, u)) {
                for (int y : adjacencyList[u]) {
                    L[y].clear();
                }
            }
        }
    }

    return cycles;
}

vector<long long int> GraphAdjListVV::count4CyclesVertexLocal() const{
    vector<int> L(numVertices, 0);
    vector<int> Lbis(numVertices, 0);
    vector<long long int> count(numVertices, 0);

    /*cout << "HELLO" << endl;
    std::this_thread::sleep_for(std::chrono::seconds(40));
    cout << "HELLOFINISHED" << endl;*/

    for(int v = 0 ; v < numVertices; v++){
        for(int u : adjacencyList[v]){
            if(isBiggerOrder(v,u)){
                for(int y : adjacencyList[u]){
                    if(isBiggerOrder(v,y)){
                        count[v] += Lbis[y];
                        count[y] += Lbis[y];
                        L[y] = Lbis[y];
                        Lbis[y]++;
                    }
                }
            }
        }
        for(int u : adjacencyList[v]){
            if(isBiggerOrder(v,u)){
                for(int y : adjacencyList[u]){
                    if(isBiggerOrder(v,y)){
                        count[u] += L[y];
                        Lbis[y] = 0;
                    }
                }
            }
        }
    }
    
    return count;
}


map<pair<int, int>, int>  GraphAdjListVV::count4CyclesEdgeLocalMap() const{
    vector<int> L(numVertices, 0);
    vector<int> Lbis(numVertices, 0);
    vector<int> M(2*getNumEdges(), 0);
    std::map<std::pair<int, int>, int> edgeCount;
    vector<int> T(numVertices, 0);
    //define T
    /*for(int v = 0; v < numVertices; v++){
        for(int vp = 0; vp < v; vp++){
            T[v]+=degree(vp);
        }
    }*/
    int degreeSum = 0;
    for(int v = 0; v < numVertices; v++){
        T[v] = degreeSum;
        degreeSum += degree(v);
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

    /*cout << "HELLO" << endl;
    std::this_thread::sleep_for(std::chrono::seconds(40));
    cout << "HELLOFINISHED" << endl;*/

    //define T
    /*for(int v = 0; v < numVertices; v++){
        for(int vp = 0; vp < v; vp++){
            T[v]+=degree(vp);
        }
    }*/
    int degreeSum = 0;
    for(int v = 0; v < numVertices; v++){
        T[v] = degreeSum;
        degreeSum += degree(v);
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

chrono::duration<double> GraphAdjListVV::count4CyclesEdgeLocalTtime() const{
    vector<int> L(numVertices, 0);
    vector<int> Lbis(numVertices, 0);
    vector<int> M(2*getNumEdges(), 0);
    vector<vector<int>> edgeCount;
    vector<int> T(numVertices, 0);

    
    auto start = chrono::high_resolution_clock::now();

    int degreeSum = 0;
    for(int v = 0; v < numVertices; v++){
        T[v] = degreeSum;
        degreeSum += degree(v);
    }   
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_seconds = end-start;

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
    
    return elapsed_seconds;
}