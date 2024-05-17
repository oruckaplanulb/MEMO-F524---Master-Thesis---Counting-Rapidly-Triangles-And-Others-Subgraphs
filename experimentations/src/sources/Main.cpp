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

int main(int argc, char *argv[]){ 

    //TestParallel::testNodeIteratorEpinions1(10);
    //TestParallel::testNodeIteratorPlusPlusEpinions1(10);
    //TestParallel::testNodeIteratorFacebook(10);
    TestParallel::testMatrixCubeNincreasingDSYMM(10);

    /*GraphFiller* graphFiller = new GraphFiller();
    GraphAdjMatrixVV* graphMatrixVV = new GraphAdjMatrixVV();
    graphFiller->setGraphFromFileMapped(argv[1], graphMatrixVV);

    //set timer
    auto start = chrono::high_resolution_clock::now();
    long long int cpt = graphMatrixVV->count5CyclesMatrixPow5(Matrix::multiplyBlasSSYMM,1);
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_seconds = end-start;
    cout << "nb 5cycles: " << cpt << " in " << elapsed_seconds.count()*1000 << "ms" << endl;

    //set timer
    start = chrono::high_resolution_clock::now();
    cpt = graphMatrixVV->count5CyclesMatrixPow5NodeIterator(Matrix::multiplyBlasSSYMM,1);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    cout << "nb 5cycles: " << cpt << " in " << elapsed_seconds.count()*1000 << "ms" << endl;*/

    /*
    GraphFiller* graphFiller = new GraphFiller();
    GraphAdjListVUS* gVUS = new GraphAdjListVUS();
    graphFiller->setGraphFromFileMapped(argv[1], gVUS);

    int cpt = 0;

    //set timer
    auto start = chrono::high_resolution_clock::now();
    cpt = gVUS->countTrianglesNodeIterator();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_seconds = end-start;
    cout << "NodeIterator: " << cpt << " in " << elapsed_seconds.count()*1000 << "ms" << endl;

    //set timer
    start = chrono::high_resolution_clock::now();
    cpt = gVUS->countTrianglesNodeIteratorParallel(1);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    cout << "NodeIteratorParallel1TH: " << cpt << " in " << elapsed_seconds.count()*1000 << "ms" << endl;

    //set timer
    start = chrono::high_resolution_clock::now();
    cpt = gVUS->countTrianglesNodeIteratorParallel(2);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    cout << "NodeIteratorParallel2TH: " << cpt << " in " << elapsed_seconds.count()*1000 << "ms" << endl;

    //set timer
    start = chrono::high_resolution_clock::now();
    cpt = gVUS->countTrianglesNodeIteratorParallel(4);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    cout << "NodeIteratorParallel4TH: " << cpt << " in " << elapsed_seconds.count()*1000 << "ms" << endl;

    //set timer
    start = chrono::high_resolution_clock::now();
    cpt = gVUS->countTrianglesNodeIteratorParallel(8);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    cout << "NodeIteratorParallel8TH: " << cpt << " in " << elapsed_seconds.count()*1000 << "ms" << endl;

    //////////

    //set timer
    start = chrono::high_resolution_clock::now();
    cpt = gVUS->countTrianglesNodeIteratorPlusPlus();
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    cout << "NodeIteratorPlusPlus: " << cpt << " in " << elapsed_seconds.count()*1000 << "ms" << endl;

    //set timer
    start = chrono::high_resolution_clock::now();
    cpt = gVUS->countTrianglesNodeIteratorPlusPlusParallel(1);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    cout << "NodeIteratorPlusPlusParallel1TH: " << cpt << " in " << elapsed_seconds.count()*1000 << "ms" << endl;

    //set timer
    start = chrono::high_resolution_clock::now();
    cpt = gVUS->countTrianglesNodeIteratorPlusPlusParallel(2);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    cout << "NodeIteratorPlusPlusParallel2TH: " << cpt << " in " << elapsed_seconds.count()*1000 << "ms" << endl;

    //set timer
    start = chrono::high_resolution_clock::now();
    cpt = gVUS->countTrianglesNodeIteratorPlusPlusParallel(4);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    cout << "NodeIteratorPlusPlusParallel4TH: " << cpt << " in " << elapsed_seconds.count()*1000 << "ms" << endl;

    //set timer
    start = chrono::high_resolution_clock::now();
    cpt = gVUS->countTrianglesNodeIteratorPlusPlusParallel(8);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end-start;
    cout << "NodeIteratorPlusPlusParallel8TH: " << cpt << " in " << elapsed_seconds.count()*1000 << "ms" << endl;*/


    return 0;
}
