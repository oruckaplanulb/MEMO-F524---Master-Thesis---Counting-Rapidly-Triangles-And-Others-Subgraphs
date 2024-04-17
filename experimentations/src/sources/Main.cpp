#include "../headers/Graph.hpp"
#include "../headers/Matrix.hpp"
#include "../headers/GraphFiller.hpp"
#include "../tests/TestMatrices.hpp"
#include "../tests/TestNodeIterators.hpp"
#include "../tests/TestNodeIteratorsIndividual.hpp"
#include "../tests/TestForward.hpp"
#include "../tests/TestChibaNishizeki.hpp"
#include <chrono>
#include <thread>

using namespace std;

int main(int argc, char *argv[]){


    //TestNodeIterators::testFindNodeIteratorPlusPlusMIncreasing(10);
    //TestNodeIterators::testFindNodeIteratorPlusPlusNIncreasing(10);

    
    GraphFiller *graphFiller = new GraphFiller();
    GraphAdjListVUS *g1 = new GraphAdjListVUS();
    graphFiller->setGraphFromFileMapped(argv[1], g1);
    GraphAdjMatrixVV *g2 = new GraphAdjMatrixVV();
    graphFiller->setGraphFromFileMapped(argv[1], g2);
    GraphAdjListVV *g3 = new GraphAdjListVV();
    graphFiller->setGraphFromFileMapped(argv[1], g3);

    cout << "- Graph VUS -" << endl;
    cout << "Vertices: " << g1->getNumVertices() << endl;
    cout << "Edges: " << g1->getNumEdges() << endl;
    cout << "- Graph MTX VV -" << endl;
    cout << "Vertices: " << g2->getNumVertices() << endl;
    cout << "Edges: " << g2->getNumEdges() << endl;
    cout << "- Graph LST VV-" << endl;
    cout << "Vertices: " << g3->getNumVertices() << endl;
    cout << "Edges: " << g3->getNumEdges() << endl;

    delete graphFiller;

    cout << "avg degeneracy: " << g1->getAverageDegeneracy() << endl;
    
    long int cpt = 0;
    auto start = chrono::high_resolution_clock::now();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_seconds;

    /*start = chrono::high_resolution_clock::now();
    cpt = g2->countTrianglesMatrixCube(Matrix::multiplyBlasSSYMM, 1);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    cout << "Number of C3: " << cpt << endl;
    cout << "Elapsed time: " << elapsed_seconds.count()*1000 << "ms" << endl;
    cout << "Actual number of C3: " << g1->countTrianglesNodeIteratorPlusPlus() << endl;*/

    start = chrono::high_resolution_clock::now();
    cpt = g2->count4CyclesMatrixPow4(Matrix::multiplyBlasSSYMM, 1);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    cout << "Number of C4: " << cpt << endl;
    cout << "Elapsed time: " << elapsed_seconds.count()*1000 << "ms" << endl;
    cout << "Actual number of C4: " << g1->count4CyclesBasic() << endl;
    cout << "Nb C4 with listing: " << g1->find4Cycles().size() << endl;

    cpt = 0;
    vector<int> v = g1->count4CyclesVertexLocal();
    for (int i = 0; i < v.size(); i++){
        cpt += v[i];
    }

    cout << "Nb C4 with local Vrtx: " << cpt/4 << endl;

    cpt = 0;
    map<pair<int, int>, int> edgeCount = g3->count4CyclesEdgeLocal();
    for (auto it = edgeCount.begin(); it != edgeCount.end(); it++){
        cpt += it->second;
    }
    cout << "Nb C4 with local Edge: " << cpt/4 << endl;

    /*start = chrono::high_resolution_clock::now();
    cpt = g2->count5CyclesMatrixPow5(Matrix::multiplyBlasSSYMM, 1);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    cout << "Number of C5: " << cpt << endl;
    cout << "Elapsed time: " << elapsed_seconds.count()*1000 << "ms" << endl;*/
    
    /*vector<int> distri = g1->getClusturingCoefficientDistrubition();
    for(int i = 0; i < distri.size(); i++){
        cout << (double)(i+1)/distri.size() << ": " << distri[i] << endl;
    }*/

    return 0;
}
