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
#include <chrono>
#include <thread>

using namespace std;

int main(int argc, char *argv[]){ 

    //Test4CycleCounting::testCount4CycleLowMedHigh(10);
    //Test4CycleCounting::testCount4CycleVertexLocalLowMedHigh(10);
    Test4CycleCounting::testCount4CycleEdgeLocalLowMedHigh(10);
    
    /*GraphFiller *graphFiller = new GraphFiller();
    GraphAdjMatrixVV *g1 = new GraphAdjMatrixVV();
    graphFiller->setGraphFromFileMapped(argv[1], g1);

    GraphAdjListVUS *g2 = new GraphAdjListVUS();
    graphFiller->setGraphFromFileMapped(argv[1], g2);

    cout << "- Graph VUS -" << endl;
    cout << "Vertices: " << g1->getNumVertices() << endl;
    cout << "Edges: " << g1->getNumEdges() << endl;
    
    long int cpt = 0;
    auto start = chrono::high_resolution_clock::now();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_secondsNI;
    chrono::duration<double> elapsed_secondsNIPP;

    start = chrono::high_resolution_clock::now();
    cpt = g1->countTrianglesMatrixCube(Matrix::multiplyBlasSSYMM,1);
    end = chrono::high_resolution_clock::now();
    elapsed_secondsNI = end - start;
    cout << "Nb Triangle " << cpt << endl;
    cout << "Elapsed time: " << elapsed_secondsNI.count()*1000 << "ms" << endl;

    start = chrono::high_resolution_clock::now();
    cpt = g1->countTrianglesMatrixSquaring(Matrix::multiplyBlasSSYMM,1);
    end = chrono::high_resolution_clock::now();
    elapsed_secondsNI = end - start;
    cout << "Nb Triangle " << cpt << endl;
    cout << "Elapsed time: " << elapsed_secondsNI.count()*1000 << "ms" << endl;

    start = chrono::high_resolution_clock::now();
    cpt = g1->count4CyclesMatrixPow4(Matrix::multiplyBlasSSYMM,1);
    end = chrono::high_resolution_clock::now();
    elapsed_secondsNI = end - start;
    cout << "Nb 4Cycles " << cpt << endl;
    cout << "Elapsed time: " << elapsed_secondsNI.count()*1000 << "ms" << endl;

    delete g1;
    delete g2;
    delete graphFiller;*/

    /*GraphFiller *graphFiller = new GraphFiller();
    GraphAdjListVV *g1 = new GraphAdjListVV();
    graphFiller->setGraphFromFileMapped(argv[1], g1);
    GraphAdjListVUS *g2 = new GraphAdjListVUS();
    graphFiller->setGraphFromFileMapped(argv[1], g2);

    cout << "- Graph VUS -" << endl;
    cout << "Vertices: " << g1->getNumVertices() << endl;
    cout << "Edges: " << g1->getNumEdges() << endl;

    vector<vector<int>> edgecount;
    auto start = chrono::high_resolution_clock::now();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_secondsNI;
    chrono::duration<double> elapsed_secondsNIPP;

    long int cpt = 0;
    start = chrono::high_resolution_clock::now();
    cpt = g2->count4CyclesBasic();
    end = chrono::high_resolution_clock::now();
    elapsed_secondsNI = end - start;
    cout << "Nb 4Cycles " << cpt << endl;
    cout << "Elapsed time: " << elapsed_secondsNI.count()*1000 << "ms" << endl;


    start = chrono::high_resolution_clock::now();
    edgecount = g1->count4CyclesEdgeLocalVector();
    end = chrono::high_resolution_clock::now();
    elapsed_secondsNI = end - start;

    cpt = 0;
    for (int i = 0; i < edgecount.size(); ++i) {
        cpt += edgecount[i][2];
    }
    cout << "Nb 4Cycles " << cpt/4 << endl;
    cout << "Elapsed time: " << elapsed_secondsNI.count()*1000 << "ms" << endl;*/

    return 0;
}
