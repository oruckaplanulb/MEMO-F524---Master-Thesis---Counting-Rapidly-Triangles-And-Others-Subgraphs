#include "../headers/Graph.hpp"
#include "../headers/Matrix.hpp"
#include "../headers/GraphFiller.hpp"
#include "../tests/TestMatrices.hpp"
#include "../tests/TestNodeIterators.hpp"
#include <chrono>
#include <thread>

using namespace std;

int main(int argc, char *argv[]){

    TestNodeIterators::testNodeIteratorPlusPlusAdjListMIncreasing(100);
    TestNodeIterators::testNodeIteratorAdjListMIncreasing(100);

    /*GraphFiller *graphFiller = new GraphFiller();
    GraphAdjMatrixVV *g = new GraphAdjMatrixVV();
    graphFiller->setGraphFromFileMapped(argv[1], g);

    cout << "WITH -lpthread" << endl;
    int nbThreads = atoi(argv[2]);
    cout << "Number of threads: " << nbThreads << endl;

    cout << "- Graph -" << endl;
    cout << "Vertices: " << g->getNumVertices() << endl;
    cout << "Edges: " << g->getNumEdges() << endl;

    delete graphFiller;
    
    int cpt = 0;
    auto start = chrono::high_resolution_clock::now();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_seconds;

    start = chrono::high_resolution_clock::now();
    cpt = g->countTrianglesMatrixSquaring(Matrix::multiplyBlasSSYMM,nbThreads);
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;

    cout << "Number of triangles: " << cpt << endl;
    cout << "Elapsed time: " << elapsed_seconds.count()*1000 << "ms" << endl;*/

    return 0;
}
