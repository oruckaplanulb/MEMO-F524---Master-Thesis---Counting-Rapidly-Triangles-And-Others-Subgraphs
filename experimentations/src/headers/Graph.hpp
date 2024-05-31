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
 * @brief This class is an abstract class that represents a graph.
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
 * @brief This class represents a graph using an adjacency matrix of vectors.
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
     * @brief Use the NodeIterator algorithm to count the number of triangles in the graph.
    */
    int countTrianglesNodeIterator() const;
    /**
     * @brief Use the NodeIterator++ algorithm to count the number of triangles in the graph.
    */
    int countTrianglesNodeIteratorPlusPlus() const;
    /**
     * @brief Use the NodeIterator++ algorithm to count the number of triangles in the graph with pre-computing the total order of each vertex.
    */
    int countTrianglesNodeIteratorPlusPlusWithOrder() const;
    /**
     * @brief Use the MatrixSquaring algorithm to count the number of triangles in the graph, only the multiplication function is passed as a parameter can be changed and parallelized.
    */
    int countTrianglesMatrixSquaring(std::function<std::vector<std::vector<int>>(const std::vector<std::vector<int>>&, const std::vector<std::vector<int>>&, int)> multiplyFunc, int numThreads) const;
    /**
     * @brief Use the MatrixSquaring algorithm to count the number of triangles in the graph, here the multiplication function is passed as a parameter and the number of threads for the multiplication function and also for the main function.
    */
    int countTrianglesMatrixSquaringParallel(std::function<std::vector<std::vector<int>>(const std::vector<std::vector<int>>&, const std::vector<std::vector<int>>&, int)> multiplyFunc, int numThreadsMM, int numThreads) const;
    /**
     * @brief Use the MatrixCube algorithm to count the number of triangles in the graph, only the multiplication function is passed as a parameter can be changed and parallelized.
    */
    int countTrianglesMatrixCube(std::function<std::vector<std::vector<int>>(const std::vector<std::vector<int>>&, const std::vector<std::vector<int>>&, int)> multiplyFunc, int numThreads) const;
    /**
     * @brief Use the MatrixCube algorithm to count the number of triangles in the graph, here the multiplication function is passed as a parameter and the number of threads for the multiplication function and also for the main function.
    */
    int countTrianglesMatrixCubeParallel(std::function<std::vector<std::vector<int>>(const std::vector<std::vector<int>>&, const std::vector<std::vector<int>>&, int)> multiplyFunc, int numThreadsMM, int numThreads) const;

    /**
     * @brief Use the Matrix Pow 4 with the generalisation to count the number of 4-cycles in the graph.
    */
    long long int count4CyclesMatrixPow4(std::function<std::vector<std::vector<int>>(const std::vector<std::vector<int>>&, const std::vector<std::vector<int>>&, int)> multiplyFunc, int numThreads) const;
    /**
     * @brief Use the Matrix Pow 5 with the generalisation to count the number of 5-cycles in the graph.
    */
    long long int count5CyclesMatrixPow5(std::function<std::vector<std::vector<int>>(const std::vector<std::vector<int>>&, const std::vector<std::vector<int>>&, int)> multiplyFunc, int numThreads) const;
    /**
     * @brief Use the Matrix Pow 5 with the generalisation to count the number of 5-cycles in the graph, to count the triangles homomorphism, it use a variant of NodeIterator instead of A3.
    */
    long long int count5CyclesMatrixPow5NodeIterator(std::function<std::vector<std::vector<int>>(const std::vector<std::vector<int>>&, const std::vector<std::vector<int>>&, int)> multiplyFunc, int numThreads) const;
    /*DOES NOT WORK*/
    long long int count6CyclesMatrixPow6(std::function<std::vector<std::vector<int>>(const std::vector<std::vector<int>>&, const std::vector<std::vector<int>>&, int)> multiplyFunc, int numThreads) const;
};

/**
 * @brief This class represents a graph using an adjacency list of unordered sets.
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
     * @brief Use the NodeIterator algorithm to count the number of triangles adjacent to each vertex in the graph, used in 5-cycle counting.
    */
    std::vector<double> getNumberOfTrianglesPassThrough() const;
    
    int getSumDegreesSquared() const;
    std::vector<int> getClusturingCoefficientDistribution(int nbSplits = 10) const;
    double getAverageClusturingCoefficient() const;
    double getAverageDegeneracy() const;
    double getGraphDensity() const;

    /**
     * @brief Count the number of two-paths checked by the NodeIterator algorithm.
    */
    double nbTwoPathsNodeIterator() const;
    /**
     * @brief Count the number of two-paths checked by the NodeIterator++ algorithm.
    */
    double nbTwoPathsNodeIteratorPlusPlus() const;
    /**
     * @brief Use the NodeIterator algorithm to count the number of triangles in the graph.
    */
    int countTrianglesNodeIterator() const;
    /**
     * @brief Use the NodeIterator algorithm to count the number of triangles in the graph, parallelized.
    */
    int countTrianglesNodeIteratorParallel(int numThreads) const;
    /**
     * @brief Use the NodeIterator++ algorithm to count the number of triangles in the graph.
    */
    int countTrianglesNodeIteratorPlusPlus() const;
    /**
     * @brief Use the NodeIterator++ algorithm to count the number of triangles in the graph, parallelized.
    */
    int countTrianglesNodeIteratorPlusPlusParallel(int numThreads) const;
    /**
     * @brief Use the Chiba-Nishizeki algorithm to count the number of triangles in the graph.
    */
    int countTrianglesChibaNishizeki() const;
    /**
     * @brief Use the Forward algorithm to count the number of triangles in the graph.
    */
    int countTrianglesForward() const;

    /**
     * @brief Use the NodeIterator++ algorithm to list the triangles in the graph.
    */
    std::vector<std::vector<int>> findTrianglesNodeIteratorPlusPlus() const;
    /**
     * @brief Use the Chiba-Nishizeki algorithm to list the triangles in the graph.
    */
    std::vector<std::vector<int>> findTrianglesChibaNishizeki() const;
    /**
     * @brief Use the Forward algorithm to list the triangles in the graph.
    */
    std::vector<std::vector<int>> findTrianglesForward() const;
    /*DOES NOT WORK*/
    int AYZ_Algorithm() const;

    /**
     * @brief Use the classical 4-cycle counting algorithm to count the number of 4-cycles in the graph.
    */
    long long int count4CyclesBasic() const;
    /**
     * @brief Use the listing algorithm to list the 4-cycles in the graph.
    */
    std::vector<std::vector<int>> find4Cycles() const;
    /**
     * @brief Use the vertex-local counting algorithm to count the number of 4-cycles adjacent to each vertex in the graph.
    */
    std::vector<long long int> count4CyclesVertexLocal() const;

    /**
     * @brief UNUSED in the thesis
    */
    long long int count4CyclesGeneralization() const;
    /**
     * @brief UNUSED in the thesis
    */
    long long int count5CyclesGeneralization() const;
};

/**
 * @brief This class represents a graph using an adjacency list of vectors.
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
     * @brief UNUSED in the thesis but allwed me to test if NodeIterator++ is faster with an adjacency list of vectors or unordered sets.
    */
    int countTrianglesNodeIteratorPlusPlus() const;

    /**
     * @brief Use the classical 4-cycle counting algorithm to count the number of 4-cycles in the graph.
    */
    long long int count4CyclesBasic() const;
    /**
     * @brief Use the listing algorithm to list the 4-cycles in the graph.
    */
    std::vector<std::vector<int>> find4Cycles() const;
    /**
     * @brief Use the vertex-local counting algorithm to count the number of 4-cycles adjacent to each vertex in the graph.
    */
    std::vector<long long int> count4CyclesVertexLocal() const;
    /**
     * @brief Use the edge-local counting algorithm to count the number of 4-cycles adjacent to each edge in the graph, the result is stored in a map. (UNUSED in the thesis)
    */
    std::map<std::pair<int, int>, int> count4CyclesEdgeLocalMap() const;
    /**
     * @brief Use the edge-local counting algorithm to count the number of 4-cycles adjacent to each edge in the graph, the result is stored in a vector.
    */
    std::vector<std::vector<int>> count4CyclesEdgeLocalVector() const;
    /**
     * @brief Use the edge-local counting algorithm to count the number of 4-cycles adjacent to each edge in the graph, return the time taken initialize the vector T.
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
