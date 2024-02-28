#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <list> 
#include <unordered_set>
#include <functional>

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

    virtual int countTrianglesNodeIterator() const = 0;
    virtual int countTrianglesNodeIteratorPlusPlus() const = 0;
    virtual int AYZ_Algorithm() const = 0;

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

    std::vector<std::vector<int>> getAdjacencyMatrix();
    int getNumVertices() const override;
    int getNumEdges() const override;
    void setSize(int vertices) override;
    void addEdge(int vrtx1, int vrtx2) override;
    int degree(int vertex) const override;
    bool isBiggerOrder(int vrtx1, int vrtx2) const override;
    void printGraph() const override;
    bool hasEdge(int vrtx1, int vrtx2) const override;

    int countTrianglesNodeIterator() const override;
    int countTrianglesNodeIteratorPlusPlus() const override;
    int countTrianglesMatrixSquaring(std::function<std::vector<std::vector<int>>(const std::vector<std::vector<int>>&, const std::vector<std::vector<int>>&, int)> multiplyFunc, int numThreads) const;
    int countTrianglesMatrixSquaring(std::function<std::vector<std::vector<int>>(const std::vector<std::vector<int>>&, const std::vector<std::vector<int>>&)> multiplyFunc) const;
    int countTrianglesMatrixCube(std::function<std::vector<std::vector<int>>(const std::vector<std::vector<int>>&, const std::vector<std::vector<int>>&, int)> multiplyFunc, int numThreads) const;
    int countTrianglesMatrixCube(std::function<std::vector<std::vector<int>>(const std::vector<std::vector<int>>&, const std::vector<std::vector<int>>&)> multiplyFunc) const;
    int AYZ_Algorithm() const override;
};

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

    int countTrianglesNodeIterator() const override;
    int countTrianglesNodeIteratorPlusPlus() const override;
    int AYZ_Algorithm() const override;
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

    int countTrianglesNodeIterator() const override;
    int countTrianglesNodeIteratorPlusPlus() const override;
    int AYZ_Algorithm() const override;

    int count4CyclesBasic() const ;
};



#endif
