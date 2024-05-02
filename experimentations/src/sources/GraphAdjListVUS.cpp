#include "../headers/Graph.hpp"
#include "../headers/Matrix.hpp"
#include "../headers/Utils.hpp"
#include <math.h>
#include <map>
#include <thread>
#include <algorithm>

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

int GraphAdjListVUS::getSumDegreesSquared() const {
    int sum = 0;
    for (int i = 0; i < numVertices; ++i) {
        sum += degree(i) * degree(i);
    }
    return sum;
}

vector<int> GraphAdjListVUS::getClusturingCoefficientDistribution(int nbSplits) const {
    vector<int> ccDistribution(nbSplits, 0);
    double splitSize = 1/((double)nbSplits);
    Utils utils;
    
    for(int i = 0; i < numVertices; i++){
        if(degree(i) > 1){
            int nbEdgesBtwNeighbors = 0;
            int degreeChoose2 = utils.comb(degree(i), 2);
            for(int u : adjacencyList[i]){
                for(int w : adjacencyList[i]){
                    if(hasEdge(u,w)){
                        nbEdgesBtwNeighbors++;
                    }
                }
            }
            nbEdgesBtwNeighbors /= 2;
            double ccv = (double)nbEdgesBtwNeighbors/(double) degreeChoose2;
            if(ccv == 1){
                ccDistribution[nbSplits-1]++;
            } else {
                ccDistribution[(int)(ccv/splitSize)]++;
            }
        }else{
            ccDistribution[0]++;
        }
    }

    return ccDistribution;
}

double GraphAdjListVUS::getAverageClusturingCoefficient() const {
    double sum = 0;
    Utils utils;
    for(int i = 0; i < numVertices; i++){
        double ccv;
        if(degree(i) > 1){
            int nbEdgesBtwNeighbors = 0;
            int degreeChoose2 = utils.comb(degree(i), 2);
            for(int u : adjacencyList[i]){
                for(int w : adjacencyList[i]){
                    if(hasEdge(u,w)){
                        nbEdgesBtwNeighbors++;
                    }
                }
            }
            nbEdgesBtwNeighbors /= 2;
            ccv = (double)nbEdgesBtwNeighbors/(double) degreeChoose2;
            sum += ccv;
        }
    }
    return sum/(numVertices);
}

double GraphAdjListVUS::getAverageDegeneracy() const{
    double sumDegeneracy = 0;
    for(int i = 0; i < numVertices; i++){
        for(int j : adjacencyList[i]){
            sumDegeneracy += min(degree(i), degree(j));
        }
    }
    return sumDegeneracy/getNumEdges();
}

double GraphAdjListVUS::getGraphDensity() const {
    return (double) getNumEdges() / ((double) numVertices * (numVertices - 1) / 2.0);
}

double GraphAdjListVUS::nbTwoPathsNodeIterator() const {
    double count = 0;
    for (int v = 0; v < numVertices; ++v) {
        for (const int& u : adjacencyList[v]) {
            //count++;
            for (const int& w : adjacencyList[v]) {
                count++;
                if (hasEdge(u, w)) {
                }
            }
        }
    }
    return count;
}

double GraphAdjListVUS::nbTwoPathsNodeIteratorPlusPlus() const {
    double count = 0;
    for (int v = 0; v < numVertices; ++v) {
        for (const int& u : adjacencyList[v]) {
            //count++;
            if(isBiggerOrder(u, v)){
                for (const int& w : adjacencyList[v]) {
                    count++;
                    if (isBiggerOrder(w,u) && hasEdge(u, w)) {
                    }
                }
            }
        }
    }
    return count;
}

vector<double> GraphAdjListVUS::getNumberOfTrianglesPassThrough() const {
    vector<double> delta(numVertices, 0);
    for (int v = 0; v < numVertices; ++v) {
        for (const int& u : adjacencyList[v]) {
            for (const int& w : adjacencyList[u]) {
                if (hasEdge(v, w)) {  //All this to avoid the division by 3 to not correctly roundup
                    if(delta[v] > (0.5 + (int) delta[v])){
                        delta[v] = (int) delta[v] + 1;
                    } else {
                        delta[v] += 1.0/3;
                    }
                    if(delta[u] > (0.5 + (int) delta[u])){
                        delta[u] = (int) delta[u] + 1;
                    } else {
                        delta[u] += 1.0/3;
                    }
                    if(delta[w] > (0.5 + (int) delta[w])){
                        delta[w] = (int) delta[w] + 1;
                    } else {
                        delta[w] += 1.0/3;
                    }
                }
            }
        }
    }
    return delta;
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

int GraphAdjListVUS::countTrianglesChibaNishizeki() const {
    int count = 0;
    vector<int> vSortedByOrder(numVertices);
    for (int i = 0; i < numVertices; ++i) {
        vSortedByOrder[i] = i;
    }
    sort(vSortedByOrder.begin(), vSortedByOrder.end(), [this](int v1,int v2) {
        return isBiggerOrder(v1, v2);
    });
    vector<unordered_set<int>> graphCopy = adjacencyList;
    vector<bool> marked(numVertices, false); 
    for(int i = 0; i < numVertices-2; i++){
        for (int adj : graphCopy[vSortedByOrder[i]]){
            marked[adj] = true;
        }
        for (int u : graphCopy[vSortedByOrder[i]]){
            if(!marked[u]){
                continue;
            }
            for(int w : graphCopy[u]){
                if(marked[w]){
                    count++;
                }
                marked[u] = false;
            }
        }
        //remove v from the graph
        for(int adj : graphCopy[vSortedByOrder[i]]){
            graphCopy[adj].erase(vSortedByOrder[i]);
        }
    }
    return count;
}

int GraphAdjListVUS::countTrianglesForward() const {
    int count = 0;
    vector<unordered_set<int>> A(numVertices);
    
    vector<int> vSortedByOrder(numVertices);
    for (int i = 0; i < numVertices; ++i) {
        vSortedByOrder[i] = i;
    }
    sort(vSortedByOrder.begin(), vSortedByOrder.end(), [this](int v1, int v2) {
        return !isBiggerOrder(v1, v2);
    });

    for(int vi : vSortedByOrder){
        for(int vl : adjacencyList[vi]){
            if(isBiggerOrder(vl,vi)){
                for(int v : A[vi]){
                    if(A[vl].find(v) != A[vl].end()){
                        count++;
                    }
                }
                A[vl].insert(vi);
            }
        }
    }
    return count;
}

vector<vector<int>> GraphAdjListVUS::findTrianglesNodeIteratorPlusPlus() const {
    vector<vector<int>> triangles;
    for (int v = 0; v < numVertices; ++v) {
        for (const int& u : adjacencyList[v]) {
            if(isBiggerOrder(u, v)){
                for (const int& w : adjacencyList[v]) {
                    if (isBiggerOrder(w,u) && hasEdge(u, w)) {
                        vector<int> triangle = {v, u, w};
                        triangles.push_back(triangle);
                    }
                }
            }
        }
    }
    return triangles;
}

vector<vector<int>> GraphAdjListVUS::findTrianglesChibaNishizeki() const {
    vector<vector<int>> triangles;
    vector<int> vSortedByOrder(numVertices);
    for (int i = 0; i < numVertices; ++i) {
        vSortedByOrder[i] = i;
    }
    sort(vSortedByOrder.begin(), vSortedByOrder.end(), [this](int v1,int v2) {
        return isBiggerOrder(v1, v2);
    });
    vector<unordered_set<int>> graphCopy = adjacencyList;
    vector<bool> marked(numVertices, false); 
    for(int i = 0; i < numVertices-2; i++){
        for (int adj : graphCopy[vSortedByOrder[i]]){
            marked[adj] = true;
        }
        for (int u : graphCopy[vSortedByOrder[i]]){
            if(!marked[u]){
                continue;
            }
            for(int w : graphCopy[u]){
                if(marked[w]){
                    vector<int> triangle = {vSortedByOrder[i], u, w};
                    triangles.push_back(triangle);
                }
                marked[u] = false;
            }
        }
        //remove v from the graph
        for(int adj : graphCopy[vSortedByOrder[i]]){
            graphCopy[adj].erase(vSortedByOrder[i]);
        }
    }
    return triangles;
}

vector<vector<int>> GraphAdjListVUS::findTrianglesForward() const {
    vector<vector<int>> triangles;
    vector<unordered_set<int>> A(numVertices);
    
    vector<int> vSortedByOrder(numVertices);
    for (int i = 0; i < numVertices; ++i) {
        vSortedByOrder[i] = i;
    }
    sort(vSortedByOrder.begin(), vSortedByOrder.end(), [this](int v1, int v2) {
        return !isBiggerOrder(v1, v2);
    });

    for(int vi : vSortedByOrder){
        for(int vl : adjacencyList[vi]){
            if(isBiggerOrder(vl,vi)){
                for(int v : A[vi]){
                    if(A[vl].find(v) != A[vl].end()){
                        vector<int> triangle = {v, vi, vl};
                        triangles.push_back(triangle);
                    }
                }
                A[vl].insert(vi);
            }
        }
    }
    return triangles;
}

int GraphAdjListVUS::AYZ_Algorithm() const{
    double beta = pow(getNumEdges(),(3.0-1)/(3.0+1));

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
                        if(delta[v] > (0.5 + (int) delta[v])){
                            delta[v] = (int) delta[v] + 1;
                        } else {
                            delta[v] += 1.0/3;
                        }
                        if(delta[u] > (0.5 + (int) delta[u])){
                            delta[u] = (int) delta[u] + 1;
                        } else {
                            delta[u] += 1.0/3;
                        }
                        if(delta[w] > (0.5 + (int) delta[w])){
                            delta[w] = (int) delta[w] + 1;
                        } else {
                            delta[w] += 1.0/3;
                        }
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
    

    if(Vhigh.size() > 0){
        //create a vector of vector of size edge count
        vector<vector<int>> A(Vhigh.size(), vector<int>(Vhigh.size(), 0));
        for(int v = 0 ; v < Vhigh.size(); v++){
            for(int u = 0 ; u < Vhigh.size(); u++){
                if(hasEdge(Vhigh[v], Vhigh[u])){
                    A[v][u] = 1;
                    A[u][v] = 1;
                }
            }
        }
        vector<vector<int>> M = Matrix::multiplyBlasSSYMM(A, A, 8);

        cout << "M size: " << M.size() << endl;

        for(int vi = 0 ; vi < Vhigh.size(); vi++){
            delta[Vhigh[vi]] += (((int)M[vi][vi])/2.0);
        }
    }


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

vector<vector<int>> GraphAdjListVUS::find4Cycles() const {
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

vector<int> GraphAdjListVUS::count4CyclesVertexLocal() const{
    vector<int> L(numVertices, 0);
    vector<int> Lbis(numVertices, 0);
    vector<int> count(numVertices, 0);

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

int GraphAdjListVUS::count4CyclesGeneralization() const {
    double countTrace = 0;
    double countH2 = 0;
    double countH1 = 0;

    //nb path of len 4
    for(int v = 0; v < numVertices; v++){
        for(int u : adjacencyList[v]){
            for(int w : adjacencyList[u]){
                for(int x : adjacencyList[w]){
                    if(hasEdge(v,x)){
                        countTrace++;
                    }
                }
            }
        }
        int di = degree(v);
        //di choose 2
        countH2 += (di*(di-1))/2;
    }
    countH1 = getNumEdges();

    return (countTrace - (4*countH2) - (2*countH1))/8;
}

long int GraphAdjListVUS::count5CyclesGeneralization() const {
    unsigned long int countTrace = 0;
    unsigned long int countH5 = 0;
    unsigned long int countC3 = 0;
    const vector<double> passThroughTriangles = getNumberOfTrianglesPassThrough();

    for(int v = 0; v < numVertices; v++){
        for(int u : adjacencyList[v]){
            for(int w : adjacencyList[u]){
                for(int x : adjacencyList[w]){
                    for(int y : adjacencyList[x]){
                        if(hasEdge(v,y)){
                            countTrace++;
                        }
                    }
                }
            }
        }
        countH5 += (passThroughTriangles[v])*(degree(v)-2);
        countC3 += passThroughTriangles[v];
    }
    countH5 = countH5/2;
    countC3 = countC3/6;

    //cout << "countH5: " << 10*countH5 << endl;
    //cout << "countC3: " << 30*countC3 << endl;
    //cout << "countTrace: " << countTrace << endl;

    return (countTrace - (10*countH5) - (30*countC3))/10;
}