#include "Graph.hpp"
#include "Matrix.hpp"
#include "GraphFiller.hpp"
#include <chrono>

int main() {
    GraphFiller* graphFiller = new GraphFiller();

    GraphAdjacencyMatrixBased* graph1 = new GraphAdjacencyMatrixBased();
    GraphAdjacencyListBased* graph2 = new GraphAdjacencyListBased();
    graphFiller->setGraphFromFile("../graphs/Gnutella/p2p-Gnutella05.txt", graph2);

    //print nb vertices and edges
    std::cout << "Number of vertices graph1: " << graph2->getNumVertices() << std::endl;
    std::cout << "Number of edges graph1: " << graph2->getNumEdges() << std::endl;

    int trianglescpt1 = 0;
    int trianglescpt2 = 0;
    int trianglescpt3 = 0;
    int trianglescpt4 = 0;

    //get time now
    auto start = std::chrono::high_resolution_clock::now();
    trianglescpt1 = graph2->countTrianglesNodeIterator();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "Number of triangles Node Iterator: " << trianglescpt1 << std::endl;
    std::cout << "Elapsed time Node Iterator: " << elapsed_seconds.count()*1000 << "ms\n";

    start = std::chrono::high_resolution_clock::now();
    trianglescpt2 = graph2->AYZ_Algorithm();
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Number of triangles AYZ Algorithm: " << trianglescpt2 << std::endl;
    std::cout << "Elapsed time AYZ Algorithm: " << elapsed_seconds.count()*1000 << "ms\n";


    delete graph1;
    delete graph2;
    delete graphFiller;


    return 0;
}

