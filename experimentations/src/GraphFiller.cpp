#include "GraphFiller.hpp"
#include <fstream>
#include <sstream>
#include <vector>

/*bool GraphFiller::startFromZero(const std::string& path){
    std::ifstream file(path);
    std::string line;

    bool isAZero = false;
    bool isAOne = false;
        
    if (file.is_open()) {
        while (std::getline(file, line)) {
            // Process the tokens as needed

            
        }
        file.close();
    } else {
        std::cout << "Failed to open file: " << path << std::endl;
        return false;
    }
}*/

int GraphFiller::getNumberOfV(const std::string& path) {
    int maxVertex = -1; // Initialize maxVertex to -1

    std::ifstream file(path);
    std::string line;
    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            int v1, v2;
            if (!(iss >> v1 >> v2)) {
                std::cerr << "Error reading edge from file." << std::endl;
                continue; // Skip this line if unable to read two integers
            }
            maxVertex = std::max(maxVertex,std::max(v1, v2)); // Update maxVertex if needed
        }
        file.close();
    } else {
        std::cerr << "Failed to open file: " << path << std::endl;
    }

    return maxVertex + 1; // Add 1 to get the number of vertices
}

Graph* GraphFiller::setGraphFromFile(const std::string& path, Graph* g) {
    int nbV = this->getNumberOfV(path);

    if (typeid(*g) == typeid(GraphAdjacencyListBased)) {
        std::cout << "Graph is of type GraphAdjacencyListBased" << std::endl;
        g = new GraphAdjacencyListBased(nbV);
    } else if (typeid(*g) == typeid(GraphAdjacencyMatrixBased)) {
        std::cout << "Graph is of type GraphAdjacencyMatrixBased" << std::endl;
        g = new GraphAdjacencyMatrixBased(nbV);
    } else {
        std::cout << "Graph is of unknown type" << std::endl;
        return nullptr;
    }

    std::ifstream file(path);
    std::string line;
    if (file.is_open()) {
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            int v1, v2;
            if (!(iss >> v1 >> v2)) {
                std::cerr << "Error reading edge from file." << std::endl;
                continue;
            }
            g->addEdge(v1, v2);
        }
        file.close();
    } else {
        std::cerr << "Failed to open file: " << path << std::endl;
    }

    return g;
}