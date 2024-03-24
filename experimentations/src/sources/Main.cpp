#include "../headers/Graph.hpp"
#include "../headers/Matrix.hpp"
#include "../headers/GraphFiller.hpp"
#include "../tests/TestMatrices.hpp"
#include "../tests/TestNodeIterators.hpp"
#include <chrono>
#include <thread>

using namespace std;

int main(int argc, char *argv[]){

    /*GraphFiller *graphFiller = new GraphFiller();
    GraphAdjListVUS *g = new GraphAdjListVUS();
    graphFiller->setGraphFromFileMapped(argv[1], g);

    cout << "- Graph Matrix VV-" << endl;
    cout << "Vertices: " << g->getNumVertices() << endl;
    cout << "Edges: " << g->getNumEdges() << endl;

    int cpt = 0;
    auto start = chrono::high_resolution_clock::now();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_seconds;

    start = chrono::high_resolution_clock::now();
    cpt = g->AYZ_Algorithm();
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;

    cout << "Number of triangles: " << cpt << " True number: " << g->countTrianglesNodeIteratorPlusPlus() << endl;
    cout << "Elapsed time: " << elapsed_seconds.count()*1000 << "ms" << endl;*/


    TestNodeIterators::testNodeIteratorAdjListNIncreasing(10);
    TestNodeIterators::testNodeIteratorPlusPlusAdjListNIncreasing(10);
    TestNodeIterators::testNodeIteratorAdjMatrixNIncreasing(10);
    TestNodeIterators::testNodeIteratorPlusPlusAdjMatrixNIncreasing(10);

    return 0;
}
