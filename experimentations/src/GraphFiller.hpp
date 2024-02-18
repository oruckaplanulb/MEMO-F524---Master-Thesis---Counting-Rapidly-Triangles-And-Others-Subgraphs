#ifndef GRAPHFILLER_HPP
#define GRAPHFILLER_HPP

#include "Graph.hpp"

class GraphFiller {
public:
    GraphFiller() = default;

    void setGraphFromFile(const std::string& path, Graph* g);
private:
    int getVertexMax(const std::string& path);

    bool startFromZero(const std::string& path);
};

#endif