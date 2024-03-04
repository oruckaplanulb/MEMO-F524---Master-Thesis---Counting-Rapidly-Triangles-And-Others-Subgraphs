#include "../headers/Graph.hpp"
#include "../headers/Matrix.hpp"
#include "../headers/GraphFiller.hpp"
#include "../headers/Triangle.hpp"
#include "../tests/TestCases.hpp"
#include <chrono>

using namespace std;

void fct2(int argc, char* argv[]){

    GraphFiller* graphFiller = new GraphFiller();
    string filePath = argv[1];

    GraphAdjListVUS* graphListVUS = new GraphAdjListVUS();
    graphFiller->setGraphFromFileMapped(filePath, graphListVUS);
    cout << "- Graph List VUS-"<< endl;
    cout << "Vertices: " << graphListVUS->getNumVertices() << endl;
    cout << "Edges: " << graphListVUS->getNumEdges() << endl;

    int cpt = 0;
    auto start = chrono::high_resolution_clock::now();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_seconds;

    start = chrono::high_resolution_clock::now();
    cpt = graphListVUS->countTrianglesNodeIterator();
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    cout << "Number of triangles Node Iterator: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << endl;

    start = chrono::high_resolution_clock::now();
    cpt = graphListVUS->countTrianglesNodeIteratorPlusPlus();
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    cout << "Number of triangles Node Iterator Plus Plus: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << endl;

    start = chrono::high_resolution_clock::now();
    cpt = graphListVUS->count4CyclesBasic();
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    cout << "Number of 4-cycles Basic: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << endl;

    delete graphListVUS;
    delete graphFiller;
}

//function to test different number of threads
void fct3(int argc, char* argv[]){

    GraphFiller* graphFiller = new GraphFiller();
    string filePath = argv[1];

    GraphAdjMatrixVV* graphMatrixVV = new GraphAdjMatrixVV();
    graphFiller->setGraphFromFileMapped(filePath, graphMatrixVV);
    cout << "- Graph List VUS-"<< endl;
    cout << "Vertices: " << graphMatrixVV->getNumVertices() << endl;
    cout << "Edges: " << graphMatrixVV->getNumEdges() << endl;

    int cpt = 0;
    auto start = chrono::high_resolution_clock::now();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_seconds;

    start = chrono::high_resolution_clock::now();
    cpt = graphMatrixVV->countTrianglesMatrixSquaring(Matrix::multiplyNaiveParallel, 1);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    cout << "Number of triangles MS1: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << endl;

    start = chrono::high_resolution_clock::now();
    cpt = graphMatrixVV->countTrianglesMatrixSquaring(Matrix::multiplyNaiveParallel, 2);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    cout << "Number of triangles MS2: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << endl;

    start = chrono::high_resolution_clock::now();
    cpt = graphMatrixVV->countTrianglesMatrixSquaring(Matrix::multiplyNaiveParallel, 4);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    cout << "Number of triangles MS4: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << endl;

    start = chrono::high_resolution_clock::now();
    cpt = graphMatrixVV->countTrianglesMatrixSquaring(Matrix::multiplyNaiveParallel, 8);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    cout << "Number of triangles MS8: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << endl;

    start = chrono::high_resolution_clock::now();
    cpt = graphMatrixVV->countTrianglesMatrixCube(Matrix::multiplyNaiveParallel, 8);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    cout << "Number of triangles MC8: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << endl;


    delete graphMatrixVV;
    delete graphFiller;
}

//function to test the different matrix squaring methods
void fct4(int argc, char* argv[]){

    GraphFiller* graphFiller = new GraphFiller();
    string filePath = argv[1];

    GraphAdjMatrixVV* graphMatrixVV = new GraphAdjMatrixVV();
    graphFiller->setGraphFromFileMapped(filePath, graphMatrixVV);
    cout << "- Graph List VUS-"<< endl;
    cout << "Vertices: " << graphMatrixVV->getNumVertices() << endl;
    cout << "Edges: " << graphMatrixVV->getNumEdges() << endl;

    int cpt = 0;
    auto start = chrono::high_resolution_clock::now();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_seconds;

    start = chrono::high_resolution_clock::now();
    cpt = graphMatrixVV->countTrianglesMatrixSquaring(Matrix::multiplyNaive);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    cout << "Number of triangles MS1 NaiveFct: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << endl;

    start = chrono::high_resolution_clock::now();
    cpt = graphMatrixVV->countTrianglesMatrixSquaring(Matrix::multiplyNaiveParallel, 1);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    cout << "Number of triangles MS1 ParallelFct: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << endl;

    delete graphMatrixVV;
    delete graphFiller;
}

void fct5(int argc, char* argv[]){
    GraphFiller* graphFiller = new GraphFiller();
    string filePath = argv[1];

    GraphAdjListVUS* graph = new GraphAdjListVUS();
    graphFiller->setGraphFromFileMapped(filePath, graph);

    cout << "- Graph List VUS-"<< endl;
    cout << "Vertices: " << graph->getNumVertices() << endl;
    cout << "Edges: " << graph->getNumEdges() << endl;

    int cpt = 0;
    auto start = chrono::high_resolution_clock::now();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_seconds;

    start = chrono::high_resolution_clock::now();
    cpt = Triangle::countTrianglesNodeIterator(graph);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    cout << "Number of triangles NI Generic Triangle Class: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << endl;

    start = chrono::high_resolution_clock::now();
    cpt = Triangle::countTrianglesNodeIteratorPlusPlus(graph);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    cout << "Number of triangles NIPP Generic Triangle Class: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << endl;

    start = chrono::high_resolution_clock::now();
    cpt = graph->countTrianglesNodeIterator();
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    cout << "Number of triangles NI Function directly From Graph Class: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << endl;

    start = chrono::high_resolution_clock::now();
    cpt = graph->countTrianglesNodeIteratorPlusPlus();
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    cout << "Number of triangles NIPP Function directly From Graph Class: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << endl;

    delete graph;
    delete graphFiller;
}

int main(int argc, char* argv[]){
    //execute the tests in the test cases
    //TestCases::testGnutellasNodeIteratorPlusPlus(100);
    //TestCases::testGnutellasNodeIterator(100);
    fct5(argc, argv);



    return 0;
}

