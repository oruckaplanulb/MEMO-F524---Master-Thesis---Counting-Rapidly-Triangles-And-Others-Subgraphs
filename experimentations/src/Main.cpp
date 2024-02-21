#include "Graph.hpp"
#include "Matrix.hpp"
#include "GraphFiller.hpp"
#include <chrono>

int main(int argc, char* argv[]){
    GraphFiller* graphFiller = new GraphFiller();

    //get file path from args
    std::string filePath = argv[1];

    GraphAdjMatrixVV* graphMatrix = new GraphAdjMatrixVV();
    GraphAdjListVL* graphListVL = new GraphAdjListVL();
    GraphAdjListVUS* graphListVUS = new GraphAdjListVUS();
    graphFiller->setGraphFromFile(filePath, graphMatrix);
    graphFiller->setGraphFromFile(filePath, graphListVL);
    graphFiller->setGraphFromFile(filePath, graphListVUS);

    //print nb vertices and edges
    std::cout << "- Graph Matrix -"<< std::endl;
    std::cout << "Vertices: " << graphMatrix->getNumVertices() << std::endl;
    std::cout << "Edges: " << graphMatrix->getNumEdges() << std::endl;
    //graphMatrix->printGraph();
    std::cout << std::endl;
    std::cout << "- Graph List VL-"<< std::endl;
    std::cout << "Vertices: " << graphListVL->getNumVertices() << std::endl;
    std::cout << "Edges: " << graphListVL->getNumEdges() << std::endl;
    //graphListVL->printGraph();
    std::cout << std::endl;
    std::cout << "- Graph List VUS-"<< std::endl;
    std::cout << "Vertices: " << graphListVUS->getNumVertices() << std::endl;
    std::cout << "Edges: " << graphListVUS->getNumEdges() << std::endl;
    //graphListVUS->printGraph();
    std::cout << std::endl;

    int cpt = 0;
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds;

    std::cout << "- Graph Matrix Tests -"<<std::endl;

    start = std::chrono::high_resolution_clock::now();
    cpt = graphMatrix->countTrianglesNodeIterator();
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Number of triangles Node Iterator: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    cpt = graphMatrix->countTrianglesNodeIteratorPlusPlus();
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Number of triangles Node Iterator Plus Plus: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    cpt = graphMatrix->AYZ_Algorithm();
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Number of triangles AYZ Algorithm: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    cpt = graphMatrix->countTrianglesMatrixSquaring();
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Number of triangles Matrix Squaring: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    cpt = graphMatrix->countTrianglesMatrixCube();
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Number of triangles Matrix Cube: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << std::endl;

    //================================================================================================

    std::cout << "- Graph List VL Tests -"<<std::endl;

    start = std::chrono::high_resolution_clock::now();
    cpt = graphListVL->countTrianglesNodeIterator();
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Number of triangles Node Iterator: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    cpt = graphListVL->countTrianglesNodeIteratorPlusPlus();
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Number of triangles Node Iterator Plus Plus: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << std::endl;

    /*start = std::chrono::high_resolution_clock::now();
    cpt = graphListVL->AYZ_Algorithm();
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Number of triangles AYZ Algorithm: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << std::endl;*/

    //================================================================================================

    std::cout << "- Graph List VUS Tests -"<<std::endl;

    start = std::chrono::high_resolution_clock::now();
    cpt = graphListVUS->countTrianglesNodeIterator();
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Number of triangles Node Iterator: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    cpt = graphListVUS->countTrianglesNodeIteratorPlusPlus();
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Number of triangles Node Iterator Plus Plus: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << std::endl;

    /*start = std::chrono::high_resolution_clock::now();
    cpt = graphListVUS->AYZ_Algorithm();
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Number of triangles AYZ Algorithm: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << std::endl;*/


    delete graphMatrix;
    delete graphListVL;
    delete graphFiller;


    return 0;
}

