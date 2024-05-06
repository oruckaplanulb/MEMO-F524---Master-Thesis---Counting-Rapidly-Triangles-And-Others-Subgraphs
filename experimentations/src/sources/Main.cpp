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

    /*Test4CycleCounting::testCount4CycleNMIncreasingVV(10);
    Test4CycleCounting::testCount4CycleVertexLocalNMIncreasingVV(10);
    Test4CycleCounting::testCount4CycleEdgeLocalNMIncreasingVV(10);*/

    GraphFiller *graphFiller = new GraphFiller();
    GraphAdjListVV *g1 = new GraphAdjListVV();
    graphFiller->setGraphFromFileMapped(argv[1], g1);
    delete graphFiller;
    g1->count4CyclesEdgeLocalVector();
    //g1->count4CyclesVertexLocal();
    //g1->count4CyclesBasic();
    delete g1;


    /*GraphFiller *graphFiller = new GraphFiller();
    GraphAdjListVV *g1 = new GraphAdjListVV();
    graphFiller->setGraphFromFileMapped(argv[1], g1);
    GraphAdjListVUS *g2 = new GraphAdjListVUS();
    graphFiller->setGraphFromFileMapped(argv[1], g2);

    cout << "- Graph VUS -" << endl;
    cout << "Vertices: " << g1->getNumVertices() << endl;
    cout << "Edges: " << g1->getNumEdges() << endl;

    long long int cpt = 0;
    auto start = chrono::high_resolution_clock::now();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_seconds;

    start = chrono::high_resolution_clock::now();
    cpt = g1->count4CyclesBasic();
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    cout << "Nb 4 Cycle " << cpt << endl;
    cout << "Elapsed time VV: " << elapsed_seconds.count()*1000 << "ms" << endl;

    start = chrono::high_resolution_clock::now();
    cpt = g2->count4CyclesBasic();
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    cout << "Nb 4 Cycle " << cpt << endl;
    cout << "Elapsed time VUS: " << elapsed_seconds.count()*1000 << "ms" << endl;*/


    /*vector<vector<int>> edgecount;
    vector<long long int> edgecount2;
    auto start = chrono::high_resolution_clock::now();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_secondsNI;

    long long int cpt = 0;
    start = chrono::high_resolution_clock::now();
    cpt = g2->count4CyclesBasic();
    end = chrono::high_resolution_clock::now();
    elapsed_secondsNI = end - start;
    cout << "Nb 4Cycles " << cpt << endl;
    cout << "Elapsed time: " << elapsed_secondsNI.count()*1000 << "ms" << endl;

    start = chrono::high_resolution_clock::now();
    edgecount2 = g2->count4CyclesVertexLocal();
    end = chrono::high_resolution_clock::now();
    elapsed_secondsNI = end - start;

    cpt = 0;
    for (int i = 0; i < edgecount2.size(); ++i) {
        cpt += edgecount2[i];
    }
    cout << "Nb 4Cycles " << cpt/4 << endl;
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
