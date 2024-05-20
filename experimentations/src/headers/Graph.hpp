#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <list> 
#include <unordered_set>
#include <map>
#include <functional>
#include <cmath>
#include <chrono>

/**
 * @brief
*/
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
};

/**
 * @brief
*/
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

    /**
     * @brief
    */
    int countTrianglesNodeIterator() const;
    /**
     * @brief
    */
    int countTrianglesNodeIteratorPlusPlus() const;
    /**
     * @brief
    */
    int countTrianglesNodeIteratorPlusPlusWithOrder() const;
    /**
     * @brief
    */
    int countTrianglesMatrixSquaring(std::function<std::vector<std::vector<int>>(const std::vector<std::vector<int>>&, const std::vector<std::vector<int>>&, int)> multiplyFunc, int numThreads) const;
    /**
     * @brief
    */
    int countTrianglesMatrixSquaringParallel(std::function<std::vector<std::vector<int>>(const std::vector<std::vector<int>>&, const std::vector<std::vector<int>>&, int)> multiplyFunc, int numThreadsMM, int numThreads) const;
    /**
     * @brief
    */
    int countTrianglesMatrixCube(std::function<std::vector<std::vector<int>>(const std::vector<std::vector<int>>&, const std::vector<std::vector<int>>&, int)> multiplyFunc, int numThreads) const;
    /**
     * @brief
    */
    int countTrianglesMatrixCubeParallel(std::function<std::vector<std::vector<int>>(const std::vector<std::vector<int>>&, const std::vector<std::vector<int>>&, int)> multiplyFunc, int numThreadsMM, int numThreads) const;

    /**
     * @brief
    */
    long long int count4CyclesMatrixPow4(std::function<std::vector<std::vector<int>>(const std::vector<std::vector<int>>&, const std::vector<std::vector<int>>&, int)> multiplyFunc, int numThreads) const;
    /**
     * @brief
    */
    long long int count5CyclesMatrixPow5(std::function<std::vector<std::vector<int>>(const std::vector<std::vector<int>>&, const std::vector<std::vector<int>>&, int)> multiplyFunc, int numThreads) const;
    /**
     * @brief
    */
    long long int count5CyclesMatrixPow5NodeIterator(std::function<std::vector<std::vector<int>>(const std::vector<std::vector<int>>&, const std::vector<std::vector<int>>&, int)> multiplyFunc, int numThreads) const;
    /*DOES NOT WORK*/
    long long int count6CyclesMatrixPow6(std::function<std::vector<std::vector<int>>(const std::vector<std::vector<int>>&, const std::vector<std::vector<int>>&, int)> multiplyFunc, int numThreads) const;
};

/**
 * @brief
*/
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

    /**
     * @brief
    */
    std::vector<double> getNumberOfTrianglesPassThrough() const;
    
    int getSumDegreesSquared() const;
    std::vector<int> getClusturingCoefficientDistribution(int nbSplits = 10) const;
    double getAverageClusturingCoefficient() const;
    double getAverageDegeneracy() const;
    double getGraphDensity() const;

    /**
     * @brief
    */
    double nbTwoPathsNodeIterator() const;
    /**
     * @brief
    */
    double nbTwoPathsNodeIteratorPlusPlus() const;
    /**
     * @brief
    */
    int countTrianglesNodeIterator() const;
    /**
     * @brief
    */
    int countTrianglesNodeIteratorParallel(int numThreads) const;
    /**
     * @brief
    */
    int countTrianglesNodeIteratorPlusPlus() const;
    /**
     * @brief
    */
    int countTrianglesNodeIteratorPlusPlusParallel(int numThreads) const;
    /**
     * @brief
    */
    int countTrianglesChibaNishizeki() const;
    /**
     * @brief
    */
    int countTrianglesForward() const;

    /**
     * @brief
    */
    std::vector<std::vector<int>> findTrianglesNodeIteratorPlusPlus() const;
    /**
     * @brief
    */
    std::vector<std::vector<int>> findTrianglesChibaNishizeki() const;
    /**
     * @brief
    */
    std::vector<std::vector<int>> findTrianglesForward() const;
    /*DOES NOT WORK*/
    int AYZ_Algorithm() const;

    /**
     * @brief
    */
    long long int count4CyclesBasic() const;
    /**
     * @brief
    */
    std::vector<std::vector<int>> find4Cycles() const;
    /**
     * @brief
    */
    std::vector<long long int> count4CyclesVertexLocal() const;

    /**
     * @brief
    */
    long long int count4CyclesGeneralization() const;
    /**
     * @brief
    */
    long long int count5CyclesGeneralization() const;
};

/**
 * @brief
*/
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

    /**
     * @brief
    */
    int countTrianglesNodeIteratorPlusPlus() const;

    /**
     * @brief
    */
    long long int count4CyclesBasic() const;
    /**
     * @brief
    */
    std::vector<std::vector<int>> find4Cycles() const;
    /**
     * @brief
    */
    std::vector<long long int> count4CyclesVertexLocal() const;
    /**
     * @brief
    */
    std::map<std::pair<int, int>, int> count4CyclesEdgeLocalMap() const;
    /**
     * @brief
    */
    std::vector<std::vector<int>> count4CyclesEdgeLocalVector() const;
    /**
     * @brief
    */
    std::chrono::duration<double> count4CyclesEdgeLocalTtime() const;
};

////////////////////////////////////////////////////////////////
//OLD CLASS - Testing purposes
////////////////////////////////////////////////////////////////
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

////////////////////////////////////////////////////////////////
//OLD CLASS - Testing purposes
////////////////////////////////////////////////////////////////
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
