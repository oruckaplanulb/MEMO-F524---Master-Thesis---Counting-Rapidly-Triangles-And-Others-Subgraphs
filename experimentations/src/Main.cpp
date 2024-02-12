#include "Graph.hpp"
#include "Matrix.hpp"
#include "GraphFiller.hpp"

int main() {
    // Create a graph with 5 vertices using the matrix-based implementation

    GraphFiller* graphFiller = new GraphFiller();
    std::cout << "FILLER INIT"<< std::endl;

    GraphAdjacencyMatrixBased* graph3 = graphFiller->setGraphFromFile("graphs/facebook_combined1.txt", new GraphAdjacencyMatrixBased());
    std::cout << "BUILD DONE"<< std::endl;

    // Print the graph
    std::cout << "Graph:" << std::endl;
    graph3->printGraph();

    std::cout << "PRINT DONE"<< std::endl;

    // Count the number of triangles using the node iterator
    std::cout << "Number of triangles: " << graph3->countTrianglesNodeIterator() << std::endl;
    std::cout << "FCT1 DONE"<< std::endl;
    std::cout << "Number of triangles: " << graph3->countTrianglesMatrixSquaring() << std::endl;
    std::cout << "FCT2 DONE"<< std::endl;
    std::cout << "Number of triangles: " << graph3->countTrianglesMatrixCube() << std::endl;
    std::cout << "FCT3 DONE"<< std::endl;
    std::cout << "Number of triangles: " << graph3->countTrianglesNodeIterator() << std::endl;
    std::cout << "FCT4 DONE"<< std::endl;

    delete graph3;
    delete graphFiller;


    return 0;
}

