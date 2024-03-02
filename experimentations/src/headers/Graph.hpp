#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <list> 
#include <unordered_set>
#include <functional>

template<typename T>
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
    virtual T getNeighbors(int v) const = 0;

    //virtual int count4CyclesBasic() const = 0;
};

class GraphAdjMatrixVV : public Graph<std::vector<int>> {
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
    std::vector<int> getNeighbors(int v) const  override;

    //OLD
    int countTrianglesNodeIterator() const;
    int countTrianglesNodeIteratorPlusPlus() const;
    int countTrianglesMatrixSquaring(std::function<std::vector<std::vector<int>>(const std::vector<std::vector<int>>&, const std::vector<std::vector<int>>&, int)> multiplyFunc, int numThreads) const;
    int countTrianglesMatrixSquaring(std::function<std::vector<std::vector<int>>(const std::vector<std::vector<int>>&, const std::vector<std::vector<int>>&)> multiplyFunc) const;
    int countTrianglesMatrixCube(std::function<std::vector<std::vector<int>>(const std::vector<std::vector<int>>&, const std::vector<std::vector<int>>&, int)> multiplyFunc, int numThreads) const;
    int countTrianglesMatrixCube(std::function<std::vector<std::vector<int>>(const std::vector<std::vector<int>>&, const std::vector<std::vector<int>>&)> multiplyFunc) const;
};

class GraphAdjListVL : public Graph<std::list<int>> {
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
    std::list<int> getNeighbors(int v) const  override;

    //OLD
    int countTrianglesNodeIterator() const;
    int countTrianglesNodeIteratorPlusPlus() const;
};

class GraphAdjListVUS : public Graph<std::unordered_set<int>> {
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
    std::unordered_set<int> getNeighbors(int v) const override;

    //OLD
    int countTrianglesNodeIterator() const;
    int countTrianglesNodeIteratorPlusPlus() const;
    int countTrianglesEdgeIterator() const;
    int AYZ_Algorithm() const;
    int count4CyclesBasic() const ;
};



#endif
