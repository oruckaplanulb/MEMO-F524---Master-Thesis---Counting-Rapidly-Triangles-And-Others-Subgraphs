#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <list> 
#include <unordered_set>
#include <map>
#include <functional>
#include <cmath>

class Graph {
public:
    virtual ~Graph() = default;

    virtual int getNumVertices() const = 0;
    virtual int getNumEdges() const = 0;
    virtual void setSize(int vertices) = 0;
    virtual void addEdge(int vrtx1, int vrtx2) = 0;
    virtual int degree(int vertex) const = 0;
    virtual bool isBiggerOrder(int vrtx1, int vrtx2) const = 0;
    virtual void printGraph() const = 0;
    virtual bool hasEdge(int vrtx1, int vrtx2) const = 0;

    //virtual int count4CyclesBasic() const = 0;
};

class GraphAdjMatrixVV : public Graph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjacencyMatrix;

public:
    GraphAdjMatrixVV(int vertices);
    GraphAdjMatrixVV() : numVertices(0), adjacencyMatrix(0, std::vector<int>(0, 0)) {}
    ~GraphAdjMatrixVV() override = default;

    int getNumVertices() const override;
    int getNumEdges() const override;
    void setSize(int vertices) override;
    void addEdge(int vrtx1, int vrtx2) override;
    int degree(int vertex) const override;
    bool isBiggerOrder(int vrtx1, int vrtx2) const override;
    void printGraph() const override;
    bool hasEdge(int vrtx1, int vrtx2) const override;
    std::vector<std::vector<int>> getAdjacencyMatrix() const;
    std::vector<int> getNeighbors(int v);

    std::vector<double> getNumberOfTrianglesPassThrough() const;

    int countTrianglesNodeIterator() const;
    int countTrianglesNodeIteratorPlusPlus() const;
    int countTrianglesNodeIteratorPlusPlusWithOrder() const;
    int countTrianglesMatrixSquaring(std::function<std::vector<std::vector<int>>(const std::vector<std::vector<int>>&, const std::vector<std::vector<int>>&, int)> multiplyFunc, int numThreads) const;
    int countTrianglesMatrixSquaringParallel(std::function<std::vector<std::vector<int>>(const std::vector<std::vector<int>>&, const std::vector<std::vector<int>>&, int)> multiplyFunc, int numThreadsMM, int numThreads) const;
    int countTrianglesMatrixCube(std::function<std::vector<std::vector<int>>(const std::vector<std::vector<int>>&, const std::vector<std::vector<int>>&, int)> multiplyFunc, int numThreads) const;
    int countTrianglesMatrixCubeParallel(std::function<std::vector<std::vector<int>>(const std::vector<std::vector<int>>&, const std::vector<std::vector<int>>&, int)> multiplyFunc, int numThreadsMM, int numThreads) const;

    int count4CyclesMatrixPow4(std::function<std::vector<std::vector<int>>(const std::vector<std::vector<int>>&, const std::vector<std::vector<int>>&, int)> multiplyFunc, int numThreads) const;
    long int count5CyclesMatrixPow5(std::function<std::vector<std::vector<int>>(const std::vector<std::vector<int>>&, const std::vector<std::vector<int>>&, int)> multiplyFunc, int numThreads) const;
    long int count6CyclesMatrixPow6(std::function<std::vector<std::vector<int>>(const std::vector<std::vector<int>>&, const std::vector<std::vector<int>>&, int)> multiplyFunc, int numThreads) const;
};

class GraphAdjListVUS : public Graph {
private:
    int numVertices;
    std::vector<std::unordered_set<int>> adjacencyList;

public:
    GraphAdjListVUS(int vertices);
    GraphAdjListVUS() : numVertices(0), adjacencyList(0) {}
    ~GraphAdjListVUS() override = default;

    int getNumVertices() const override;
    int getNumEdges() const override;
    void setSize(int vertices) override;
    void addEdge(int vrtx1, int vrtx2) override;
    int degree(int vertex) const override;
    bool isBiggerOrder(int vrtx1, int vrtx2) const override;
    void printGraph() const override;
    bool hasEdge(int vrtx1, int vrtx2) const override;
    std::unordered_set<int>& getNeighbors(int v);

    std::vector<double> getNumberOfTrianglesPassThrough() const;
    
    int getSumDegreesSquared() const;
    std::vector<int> getClusturingCoefficientDistribution(int nbSplits = 10) const;
    double getAverageClusturingCoefficient() const;
    double getAverageDegeneracy() const;
    double getGraphDensity() const;

    double nbTwoPathsNodeIterator() const;
    double nbTwoPathsNodeIteratorPlusPlus() const;
    int countTrianglesNodeIterator() const;
    int countTrianglesNodeIteratorPlusPlus() const;
    int countTrianglesChibaNishizeki() const;
    int countTrianglesForward() const;

    std::vector<std::vector<int>> findTrianglesNodeIteratorPlusPlus() const;
    std::vector<std::vector<int>> findTrianglesChibaNishizeki() const;
    std::vector<std::vector<int>> findTrianglesForward() const;
    int AYZ_Algorithm() const;

    int count4CyclesBasic() const;
    std::vector<std::vector<int>> find4Cycles() const;
    std::vector<int> count4CyclesVertexLocal() const;

    int count4CyclesGeneralization() const;
    long int count5CyclesGeneralization() const;
};

class GraphAdjListVV : public Graph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjacencyList;

public:
    GraphAdjListVV(int vertices);
    GraphAdjListVV() : numVertices(0), adjacencyList(0) {}
    ~GraphAdjListVV() override = default;

    int getNumVertices() const override;
    int getNumEdges() const override;
    void setSize(int vertices) override;
    void addEdge(int vrtx1, int vrtx2) override;
    int degree(int vertex) const override;
    bool isBiggerOrder(int vrtx1, int vrtx2) const override;
    void printGraph() const override;
    bool hasEdge(int vrtx1, int vrtx2) const override;
    std::vector<int>& getNeighbors(int v);

    std::map<std::pair<int, int>, int> count4CyclesEdgeLocal() const;
};



////////////////////////////////////////////////////////////////

//OLD CLASS
class GraphAdjListVL : public Graph {
private:
    int numVertices;
    std::vector<std::list<int>> adjacencyList;

public:
    GraphAdjListVL(int vertices);
    GraphAdjListVL() : numVertices(0), adjacencyList(0) {}
    ~GraphAdjListVL() override = default;

    int getNumVertices() const override;
    int getNumEdges() const override;
    void setSize(int vertices) override;
    void addEdge(int vrtx1, int vrtx2) override;
    int degree(int vertex) const override;
    bool isBiggerOrder(int vrtx1, int vrtx2) const override;
    void printGraph() const override;
    bool hasEdge(int vrtx1, int vrtx2) const override;
    std::list<int>& getNeighbors(int v);

    int countTrianglesNodeIterator() const;
    int countTrianglesNodeIteratorPlusPlus() const;
};

//USELESS CLASS
class GraphEdgListVP : public Graph {
private:
    int numVertices;
    std::vector<std::pair<int, int>> edgeList;

public:
    GraphEdgListVP(int vertices);
    GraphEdgListVP() : numVertices(0), edgeList(0) {}
    ~GraphEdgListVP() override = default;

    int getNumVertices() const override;
    int getNumEdges() const override;
    void setSize(int vertices) override;
    void addEdge(int vrtx1, int vrtx2) override;
    int degree(int vertex) const override;
    bool isBiggerOrder(int vrtx1, int vrtx2) const override;
    void printGraph() const override;
    bool hasEdge(int vrtx1, int vrtx2) const override;
    std::vector<int> getNeighbors(int v) const;

    int countTrianglesEdgeIterator() const;
    int countTrianglesForward() const;
};


#endif
