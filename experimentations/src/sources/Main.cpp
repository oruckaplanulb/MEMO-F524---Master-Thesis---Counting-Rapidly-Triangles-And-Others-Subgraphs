#include "../headers/Graph.hpp"
#include "../headers/Matrix.hpp"
#include "../headers/GraphFiller.hpp"
#include "../tests/TestMatrices.hpp"
#include "../tests/TestNodeIterators.hpp"
#include "../tests/TestNodeIteratorsIndividual.hpp"
#include <chrono>
#include <thread>

using namespace std;

int main(int argc, char *argv[]){


    //TestNodeIteratorsIndividual::testNodeIteratorAdjListNotreDameVsRoadNetPA(10);
    //TestNodeIteratorsIndividual::testNodeIteratorPlusPlusAdjListNotreDameVsRoadNetPA(10);
    //TestNodeIteratorsIndividual::testNodeIteratorAdjListGnutella08VsEmailEuCore(10);
    //TestNodeIteratorsIndividual::testNodeIteratorPlusPlusAdjListGnutella08VsEmailEuCore(10);

    GraphFiller *graphFiller = new GraphFiller();
    GraphAdjListVUS *g1 = new GraphAdjListVUS();
    graphFiller->setGraphFromFileMapped(argv[1], g1);
    //GraphAdjMatrixVV *g2 = new GraphAdjMatrixVV();
    //graphFiller->setGraphFromFileMapped(argv[1], g2);


    cout << "- Graph -" << endl;
    cout << "Vertices: " << g1->getNumVertices() << endl;
    cout << "Edges: " << g1->getNumEdges() << endl;

    delete graphFiller;
    
    /*long int cpt = 0;
    auto start = chrono::high_resolution_clock::now();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_seconds;

    start = chrono::high_resolution_clock::now();
    cpt = g2->count4CyclesMatrixPow4(Matrix::multiplyBlasSSYMM, 8);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    cout << "Number of C4: " << cpt << endl;
    cout << "Elapsed time: " << elapsed_seconds.count()*1000 << "ms" << endl;

    start = chrono::high_resolution_clock::now();
    cpt = g1->count4CyclesBasic();
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    cout << "Number of C4: " << cpt << endl;
    cout << "Elapsed time: " << elapsed_seconds.count()*1000 << "ms" << endl;*/
    //print all triangles
    
    vector<int> distri = g1->getClusturingCoefficientDistrubition();
    for(int i = 0; i < distri.size(); i++){
        cout << (double)(i+1)/distri.size() << ": " << distri[i] << endl;
    }

    return 0;
}
