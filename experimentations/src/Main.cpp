#include "Graph.hpp"
#include "Matrix.hpp"
#include "GraphFiller.hpp"
#include <chrono>

void fct1(int argc, char* argv[]){
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

    start = std::chrono::high_resolution_clock::now();
    cpt = graphListVUS->count4CyclesBasic();
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Number of 4-cycles Basic: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << std::endl;


    delete graphMatrix;
    //delete graphListVL;
    //delete graphListVUS;
    delete graphFiller;
}

void fct2(int argc, char* argv[]){

    GraphFiller* graphFiller = new GraphFiller();
    std::string filePath = argv[1];

    GraphAdjListVUS* graphListVUS = new GraphAdjListVUS();
    graphFiller->setGraphFromFileMapped(filePath, graphListVUS);
    std::cout << "- Graph List VUS-"<< std::endl;
    std::cout << "Vertices: " << graphListVUS->getNumVertices() << std::endl;
    std::cout << "Edges: " << graphListVUS->getNumEdges() << std::endl;

    int cpt = 0;
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds;

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

    start = std::chrono::high_resolution_clock::now();
    cpt = graphListVUS->count4CyclesBasic();
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Number of 4-cycles Basic: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << std::endl;

    delete graphListVUS;
    delete graphFiller;
}

void fct3(int argc, char* argv[]){

    GraphFiller* graphFiller = new GraphFiller();
    std::string filePath = argv[1];

    GraphAdjMatrixVV* graphMatrixVV = new GraphAdjMatrixVV();
    graphFiller->setGraphFromFileMapped(filePath, graphMatrixVV);
    std::cout << "- Graph List VUS-"<< std::endl;
    std::cout << "Vertices: " << graphMatrixVV->getNumVertices() << std::endl;
    std::cout << "Edges: " << graphMatrixVV->getNumEdges() << std::endl;

    int cpt = 0;
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds;

    start = std::chrono::high_resolution_clock::now();
    cpt = graphMatrixVV->countTrianglesMatrixSquaring(Matrix::multiplyNaiveParallel, 1);
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Number of triangles MS1: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    cpt = graphMatrixVV->countTrianglesMatrixSquaring(Matrix::multiplyNaiveParallel, 2);
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Number of triangles MS2: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    cpt = graphMatrixVV->countTrianglesMatrixSquaring(Matrix::multiplyNaiveParallel, 4);
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Number of triangles MS4: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    cpt = graphMatrixVV->countTrianglesMatrixSquaring(Matrix::multiplyNaiveParallel, 8);
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Number of triangles MS8: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    cpt = graphMatrixVV->countTrianglesMatrixCube(Matrix::multiplyNaiveParallel, 8);
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Number of triangles MC8: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << std::endl;


    delete graphMatrixVV;
    delete graphFiller;
}

void fct4(int argc, char* argv[]){

    GraphFiller* graphFiller = new GraphFiller();
    std::string filePath = argv[1];

    GraphAdjMatrixVV* graphMatrixVV = new GraphAdjMatrixVV();
    graphFiller->setGraphFromFileMapped(filePath, graphMatrixVV);
    std::cout << "- Graph List VUS-"<< std::endl;
    std::cout << "Vertices: " << graphMatrixVV->getNumVertices() << std::endl;
    std::cout << "Edges: " << graphMatrixVV->getNumEdges() << std::endl;

    int cpt = 0;
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds;

    start = std::chrono::high_resolution_clock::now();
    cpt = graphMatrixVV->countTrianglesMatrixSquaring(Matrix::multiplyNaive);
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Number of triangles MS1 NaiveFct: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    cpt = graphMatrixVV->countTrianglesMatrixSquaring(Matrix::multiplyNaiveParallel, 1);
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Number of triangles MS1 ParallelFct: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << std::endl;

    delete graphMatrixVV;
    delete graphFiller;
}

int main(int argc, char* argv[]){
    
    GraphFiller* graphFiller = new GraphFiller();
    std::string filePath = argv[1];

    GraphAdjListVUS* graphListVUS = new GraphAdjListVUS();
    graphFiller->setGraphFromFileMapped(filePath, graphListVUS);
    std::cout << "- Graph List VUS-"<< std::endl;
    std::cout << "Vertices: " << graphListVUS->getNumVertices() << std::endl;
    std::cout << "Edges: " << graphListVUS->getNumEdges() << std::endl;

    int cpt = 0;
    auto start = std::chrono::high_resolution_clock::now();
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed_seconds;

    start = std::chrono::high_resolution_clock::now();
    cpt = graphListVUS->countTrianglesNodeIterator();
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Number of triangles NI: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    cpt = graphListVUS->countTrianglesNodeIteratorPlusPlus();
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Number of triangles NIPP: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    cpt = graphListVUS->AYZ_Algorithm();
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Number of triangles AYZ: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << std::endl;

    return 0;
}

