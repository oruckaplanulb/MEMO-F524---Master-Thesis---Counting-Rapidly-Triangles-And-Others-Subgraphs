#include "../headers/Graph.hpp"
#include "../headers/Matrix.hpp"
#include "../headers/GraphFiller.hpp"
#include "../tests/TestMatrices.hpp"
#include "../tests/TestNodeIterators.hpp"
#include "../tests/TestNodeIteratorsIndividual.hpp"
#include "../tests/TestNodeIteratorsAcceleration.hpp"
#include "../tests/TestForward.hpp"
#include "../tests/TestChibaNishizeki.hpp"
#include "../tests/Test4CycleCounting.hpp"
#include "../tests/TestExtra.hpp"
#include "../tests/TestGeneralisation.hpp"
#include "../tests/TestParallel.hpp"
#include <chrono>
#include <thread>

using namespace std;

void usage_example();
void tests_usage();
void other_usage(char *argv[]);

int main(int argc, char *argv[]){ 

    usage_example();
    return 0;
}

void usage_example(){

    GraphAdjMatrixVV* graphMatrixVV = new GraphAdjMatrixVV(); //empty graph same applies for GraphAdjListVUS and GraphAdjListVV
    GraphFiller* graphFiller = new GraphFiller(); //GraphFiller is used to fill the graph from a file
    //fill the graph from a file (do a mapping because some graphs has vertices that are not in a sequence from 0 to n-1)
    graphFiller->setGraphFromFileMapped("../graphs/Social-Network/ego-facebook.txt", graphMatrixVV);

    //Counting triangles with Matrix Squaring
    graphMatrixVV->countTrianglesMatrixSquaring(Matrix::multiplyBlasSSYMM,1); //here we give the function to multiply two matrices and the number of threads

    //For other functions check the Graph.hpp file to know the functions available and class to use
    //For matrix multiplication check the Matrix.hpp file to know the functions available
}

void tests_usage(){

    int nbRuns = 10;
    //The tests headers used to generate the datas for plots are in the "tests" folder and the results are in the "results" folder
    TestParallel::testNodeIteratorPlusPlusFacebook(nbRuns);
}

void other_usage(char *argv[]) {

    //Adjacency matrix based graph
    GraphFiller* graphFiller = new GraphFiller();
    GraphAdjMatrixVV* graphMatrixVV = new GraphAdjMatrixVV();
    graphFiller->setGraphFromFileMapped(argv[1], graphMatrixVV);

    //Counting 5-cycles with A5 and A3
    auto start = chrono::high_resolution_clock::now();
    long long int cpt = graphMatrixVV->count5CyclesMatrixPow5(Matrix::multiplyBlasSSYMM,1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_seconds = end-start;
    cout << "nb 5cycles: " << cpt << " in " << elapsed_seconds.count()*1000 << "ms" << endl;

    //Counting 5-cycles with A5 and NodeIterator
    start = chrono::high_resolution_clock::now();
    cpt = graphMatrixVV->count5CyclesMatrixPow5NodeIterator(Matrix::multiplyBlasSSYMM,1);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    cout << "nb 5cycles: " << cpt << " in " << elapsed_seconds.count()*1000 << "ms" << endl;

    //Adjacency list based graph
    GraphAdjListVUS* gVUS = new GraphAdjListVUS();
    graphFiller->setGraphFromFileMapped(argv[1], gVUS);

    //Counting triangles with NodeIterator
    start = chrono::high_resolution_clock::now();
    cpt = gVUS->countTrianglesNodeIterator();
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    cout << "NodeIterator: " << cpt << " in " << elapsed_seconds.count()*1000 << "ms" << endl;

    //Counting triangles with NodeIteratorParallel with 1 thread
    start = chrono::high_resolution_clock::now();
    cpt = gVUS->countTrianglesNodeIteratorParallel(1);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    cout << "NodeIteratorParallel1TH: " << cpt << " in " << elapsed_seconds.count()*1000 << "ms" << endl;

    //Counting triangles with NodeIteratorParallel with 2 threads
    start = chrono::high_resolution_clock::now();
    cpt = gVUS->countTrianglesNodeIteratorParallel(2);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    cout << "NodeIteratorParallel2TH: " << cpt << " in " << elapsed_seconds.count()*1000 << "ms" << endl;

    //Counting triangles with NodeIteratorParallel with 4 threads
    start = chrono::high_resolution_clock::now();
    cpt = gVUS->countTrianglesNodeIteratorParallel(4);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    cout << "NodeIteratorParallel4TH: " << cpt << " in " << elapsed_seconds.count()*1000 << "ms" << endl;

    //Counting triangles with NodeIteratorParallel with 8 threads
    start = chrono::high_resolution_clock::now();
    cpt = gVUS->countTrianglesNodeIteratorParallel(8);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    cout << "NodeIteratorParallel8TH: " << cpt << " in " << elapsed_seconds.count()*1000 << "ms" << endl;

    //////////

    //Counting triangles with NodeIteratorPlusPlus
    start = chrono::high_resolution_clock::now();
    cpt = gVUS->countTrianglesNodeIteratorPlusPlus();
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    cout << "NodeIteratorPlusPlus: " << cpt << " in " << elapsed_seconds.count()*1000 << "ms" << endl;

    //Counting triangles with NodeIteratorPlusPlusParallel with 1 thread
    start = chrono::high_resolution_clock::now();
    cpt = gVUS->countTrianglesNodeIteratorPlusPlusParallel(1);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    cout << "NodeIteratorPlusPlusParallel1TH: " << cpt << " in " << elapsed_seconds.count()*1000 << "ms" << endl;

    //Counting triangles with NodeIteratorPlusPlusParallel with 2 threads
    start = chrono::high_resolution_clock::now();
    cpt = gVUS->countTrianglesNodeIteratorPlusPlusParallel(2);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    cout << "NodeIteratorPlusPlusParallel2TH: " << cpt << " in " << elapsed_seconds.count()*1000 << "ms" << endl;

    //Counting triangles with NodeIteratorPlusPlusParallel with 4 threads
    start = chrono::high_resolution_clock::now();
    cpt = gVUS->countTrianglesNodeIteratorPlusPlusParallel(4);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    cout << "NodeIteratorPlusPlusParallel4TH: " << cpt << " in " << elapsed_seconds.count()*1000 << "ms" << endl;

    //Counting triangles with NodeIteratorPlusPlusParallel with 8 threads
    start = chrono::high_resolution_clock::now();
    cpt = gVUS->countTrianglesNodeIteratorPlusPlusParallel(8);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    cout << "NodeIteratorPlusPlusParallel8TH: " << cpt << " in " << elapsed_seconds.count()*1000 << "ms" << endl;

    delete graphMatrixVV;
    delete gVUS;
    delete graphFiller;
}
