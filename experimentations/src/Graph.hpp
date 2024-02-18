#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <list> 

class Graph {
public:
    virtual ~Graph() = default;

    virtual int getNumVertices() const = 0;
    virtual int getNumEdges() const = 0;
    virtual void setSize(int vertices) = 0;
    virtual void addEdge(int vrtx1, int vrtx2) = 0;
    virtual int degree(int vertex) const = 0;
    virtual void printGraph() const = 0;
    virtual bool hasEdge(int vrtx1, int vrtx2) const = 0;
    virtual int countTrianglesNodeIterator() const = 0;
    virtual int countTrianglesNodeIteratorPlusPlus() const = 0;
    virtual int AYZ_Algorithm() const = 0;
};

class GraphAdjacencyMatrixBased : public Graph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjacencyMatrix;

public:
    GraphAdjacencyMatrixBased(int vertices);
    GraphAdjacencyMatrixBased() : numVertices(0), adjacencyMatrix(0, std::vector<int>(0, 0)) {}
    ~GraphAdjacencyMatrixBased() override = default;

    std::vector<std::vector<int>> getAdjacencyMatrix();
    int getNumVertices() const override;
    int getNumEdges() const override;
    void setSize(int vertices) override;
    void addEdge(int vrtx1, int vrtx2) override;
    int degree(int vertex) const override;
    void printGraph() const override;
    bool hasEdge(int vrtx1, int vrtx2) const override;
    int countTrianglesNodeIterator() const override;
    int countTrianglesNodeIteratorPlusPlus() const override;
    int countTrianglesMatrixSquaring() const;
    int countTrianglesMatrixCube() const;
    int AYZ_Algorithm() const override;
};

class GraphAdjacencyListBased : public Graph {
private:
    int numVertices;
    std::vector<std::list<int>> adjacencyList;

public:
    GraphAdjacencyListBased(int vertices);
    GraphAdjacencyListBased() : numVertices(0), adjacencyList(0) {}
    ~GraphAdjacencyListBased() override = default;

    int getNumVertices() const override;
    int getNumEdges() const override;
    void setSize(int vertices) override;
    void addEdge(int vrtx1, int vrtx2) override;
    int degree(int vertex) const override;
    void printGraph() const override;
    bool hasEdge(int vrtx1, int vrtx2) const override;
    int countTrianglesNodeIterator() const override;
    int countTrianglesNodeIteratorPlusPlus() const override;
    int AYZ_Algorithm() const override;
};

#endif
