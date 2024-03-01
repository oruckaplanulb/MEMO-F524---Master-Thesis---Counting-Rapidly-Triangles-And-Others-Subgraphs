#include "../headers/Graph.hpp"
#include "../headers/Matrix.hpp"
#include "../headers/GraphFiller.hpp"
#include "../headers/Triangle.hpp"
#include <chrono>

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

//function to test different number of threads
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

//function to test the different matrix squaring methods
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

void fct5(int argc, char* argv[]){
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
    cpt = Triangle::countTrianglesNodeIterator(graphListVUS);
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Number of triangles NI Generic Triangle Class: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    cpt = Triangle::countTrianglesNodeIteratorPlusPlus(graphListVUS);
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Number of triangles NIPP Generic Triangle Class: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    cpt = graphListVUS->countTrianglesNodeIterator();
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Number of triangles NI Function directly From Graph Class: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    cpt = graphListVUS->countTrianglesNodeIteratorPlusPlus();
    end = std::chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    std::cout << "Number of triangles NIPP Function directly From Graph Class: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << std::endl;

    delete graphListVUS;
    delete graphFiller;
}

int main(int argc, char* argv[]){
    fct5(argc, argv);

    return 0;
}

