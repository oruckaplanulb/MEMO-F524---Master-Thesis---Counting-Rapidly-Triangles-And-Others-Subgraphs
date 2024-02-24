#include "GraphFiller.hpp"
#include <fstream>
#include <sstream>
#include <vector>

int GraphFiller::getVertexMax(const std::string& path) {
    int maxVertex = -1;

    std::ifstream file(path);
    std::string line;
    if (file.is_open()) {
        while (std::getline(file, line)) {
            if (line.empty() || line[0] == '#')
                continue;
            std::istringstream iss(line);
            int v1, v2;
            if (!(iss >> v1 >> v2)) {
                std::cerr << "Error reading edge from file." << std::endl;
                continue;
            }
            maxVertex = std::max(maxVertex,std::max(v1, v2));
        }
        file.close();
    } else {
        std::cerr << "Failed to open file: " << path << std::endl;
    }

    return maxVertex;
}


void GraphFiller::setGraphFromFile(const std::string& path, Graph* g) {
    std::cout << "Path: " << path << std::endl;

    int nbV = this->getVertexMax(path)+1;
    g->setSize(nbV);

    std::ifstream file(path);
    std::string line;
    if (file.is_open()) {
        while (std::getline(file, line)) {
            if (line.empty() || line[0] == '#')
                continue;

            std::istringstream iss(line);
            int v1, v2;
            if (!(iss >> v1 >> v2)) {
                std::cerr << "Error reading edge from file." << std::endl;
                continue;
            }
            if (!g->hasEdge(v1, v2) && v1 != v2) {
                g->addEdge(v1, v2); 
            }
        }
        file.close();
    } else {
        std::cerr << "Failed to open file: " << path << std::endl;
    }
}