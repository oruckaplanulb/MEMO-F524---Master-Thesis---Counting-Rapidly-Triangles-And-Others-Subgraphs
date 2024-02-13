#include "Graph.hpp"
#include "Matrix.hpp"
#include "GraphFiller.hpp"

int main() {
    // Create a graph with 5 vertices using the matrix-based implementation

    GraphFiller* graphFiller = new GraphFiller();
    std::cout << "FILLER INIT"<< std::endl;

    GraphAdjacencyMatrixBased* graph1 = new GraphAdjacencyMatrixBased();
    GraphAdjacencyListBased* graph2 = new GraphAdjacencyListBased();
    graphFiller->setGraphFromFile("../graphs/facebook_combined1.txt", graph1);
    graphFiller->setGraphFromFile("../graphs/facebook_combined1.txt", graph2);

    // Count the number of triangles using the node iterator
    std::cout << "Number of triangles: " << graph1->countTrianglesNodeIterator() << std::endl;
    std::cout << "FCT1 DONE"<< std::endl;
    std::cout << "Number of triangles: " << graph2->countTrianglesNodeIterator() << std::endl;
    std::cout << "FCT2 DONE"<< std::endl;

    delete graph1;
    delete graphFiller;


    return 0;
}

