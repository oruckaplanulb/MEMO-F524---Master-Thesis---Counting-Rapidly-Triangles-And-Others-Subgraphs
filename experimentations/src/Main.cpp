#include "Graph.hpp"
#include "Matrix.hpp"
#include "GraphFiller.hpp"
#include <chrono>

int main() {
    GraphFiller* graphFiller = new GraphFiller();

    GraphAdjacencyMatrixBased* graph1 = new GraphAdjacencyMatrixBased();
    GraphAdjacencyListBased* graph2 = new GraphAdjacencyListBased();
    graphFiller->setGraphFromFile("../graphs/facebook_combined1.txt", graph1);
    graphFiller->setGraphFromFile("../graphs/facebook_combined1.txt", graph2);
    //graphFiller->setGraphFromFile("../graphs/small_test.txt", graph1);
    //graphFiller->setGraphFromFile("../graphs/small_test.txt", graph2);

    int trianglesNIG1 = 0;
    int trianglesNIG2 = 0;
    int trianglesNIPPG1 = 0;
    int trianglesNIPPG2 = 0;


    //get time now
    auto start = std::chrono::high_resolution_clock::now();
    trianglesNIG1 = graph1->countTrianglesNodeIterator();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds = end-start;
    std::cout << "Number of triangles Node Iterator: " << trianglesNIG1 << std::endl;
    std::cout << "Elapsed time Node Iterator: " << elapsed_seconds.count()*1000 << "ms\n";

    /*start = std::chrono::high_resolution_clock::now();
    trianglesNIPPG1 = graph1->countTrianglesNodeIteratorPlusPlus();
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Number of triangles Node Iterator Plus Plus: " << trianglesNIPPG1 << std::endl;
    std::cout << "Elapsed time Node Iterator Plus Plus: " << elapsed_seconds.count()*1000 << "ms\n";*/

    start = std::chrono::high_resolution_clock::now();
    trianglesNIG2 = graph2->countTrianglesNodeIterator();
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Number of triangles Node Iterator: " << trianglesNIG2 << std::endl;
    std::cout << "Elapsed time Node Iterator: " << elapsed_seconds.count()*1000 << "ms\n";

    start = std::chrono::high_resolution_clock::now();
    trianglesNIPPG2 = graph2->countTrianglesNodeIteratorPlusPlus();
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Number of triangles Node Iterator Plus Plus: " << trianglesNIPPG2 << std::endl;
    std::cout << "Elapsed time Node Iterator Plus Plus: " << elapsed_seconds.count()*1000 << "ms\n";


    delete graph1;
    delete graph2;
    delete graphFiller;


    return 0;
}

