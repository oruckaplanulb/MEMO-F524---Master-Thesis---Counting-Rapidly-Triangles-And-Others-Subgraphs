#ifndef GRAPHFILLER_HPP
#define GRAPHFILLER_HPP

#include "Graph.hpp"

class GraphFiller {
public:
    GraphFiller() = default;

    Graph* setGraphFromFile(const std::string& path, Graph* g);
private:
    int getNumberOfV(const std::string& path);

    bool startFromZero(const std::string& path);
};

#endif