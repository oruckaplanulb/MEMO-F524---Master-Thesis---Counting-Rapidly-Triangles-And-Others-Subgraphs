#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <list>  // Add this include for std::list

class Graph {
public:
    virtual ~Graph() = default;

    virtual void addEdge(int vrtx1, int vrtx2) = 0;
    virtual void printGraph() const = 0;
    virtual bool hasEdge(int vrtx1, int vrtx2) const = 0;
    virtual int countTrianglesNodeIterator() const = 0;
};

class GraphAdjacencyMatrixBased : public Graph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjacencyMatrix;

public:
    GraphAdjacencyMatrixBased(int vertices);
    ~GraphAdjacencyMatrixBased() override = default;

    void addEdge(int vrtx1, int vrtx2) override;
    void printGraph() const override;
    bool hasEdge(int vrtx1, int vrtx2) const override;
    int countTrianglesNodeIterator() const override;
};

class GraphAdjacencyListBased : public Graph {
private:
    int numVertices;
    std::vector<std::list<int>> adjacencyList;

public:
    GraphAdjacencyListBased(int vertices);
    ~GraphAdjacencyListBased() override = default;

    void addEdge(int vrtx1, int vrtx2) override;
    void printGraph() const override;
    bool hasEdge(int vrtx1, int vrtx2) const override;
    int countTrianglesNodeIterator() const override;
};

#endif // GRAPH_H
