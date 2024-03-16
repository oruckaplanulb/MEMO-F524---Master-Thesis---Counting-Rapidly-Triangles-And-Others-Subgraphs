#include "../headers/Graph.hpp"
#include "../headers/Matrix.hpp"
#include "../headers/GraphFiller.hpp"
#include "../tests/TestMatrices.hpp"
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
    //cpt = graphMatrixVV->countTrianglesMatrixSquaring(Matrix::multiplyNaive);
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

    GraphAdjMatrixVV* g = new GraphAdjMatrixVV();
    graphFiller->setGraphFromFileMapped(filePath, g);
    cout << "- Graph Edg List-"<< endl;
    cout << "Vertices: " << g->getNumVertices() << endl;
    cout << "Edges: " << g->getNumEdges() << endl;

    int cpt = 0;
    auto start = chrono::high_resolution_clock::now();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_seconds;

    start = chrono::high_resolution_clock::now();
    cpt = g->countTrianglesMatrixSquaring(Matrix::multiplyBlasDSYMM, 8);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    cout << "Number of triangles Matrix Squaring Blas: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << endl;

    start = chrono::high_resolution_clock::now();
    cpt = g->countTrianglesMatrixSquaring(Matrix::multiplyBlasSSYMM, 8);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    cout << "Number of triangles Matrix Squaring Blas: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << endl;

    start = chrono::high_resolution_clock::now();
    cpt = g->countTrianglesMatrixCube(Matrix::multiplyBlasDSYMM, 8);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    cout << "Number of triangles Matrix Cube Blas: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << endl;

    start = chrono::high_resolution_clock::now();
    cpt = g->countTrianglesMatrixCube(Matrix::multiplyBlasSSYMM, 8);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    cout << "Number of triangles Matrix Cube Blas: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << endl;

    start = chrono::high_resolution_clock::now();
    cpt = g->countTrianglesNodeIterator();
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    cout << "Number of triangles Node Iterator: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << endl;

    delete g;
    delete graphFiller;
}

int main(int argc, char* argv[]){

    TestMatrices::testCubeNIncreasingSSYMM(10);

    return 0;
}

