#include "../headers/Graph.hpp"
#include "../headers/Matrix.hpp"
#include "../headers/GraphFiller.hpp"
#include "../tests/TestMatrices.hpp"
#include "../tests/TestNodeIterators.hpp"
#include "../tests/TestNodeIteratorsIndividual.hpp"
#include "../tests/TestNodeIteratorsAcceleration.hpp"
#include "../tests/TestForward.hpp"
#include "../tests/TestChibaNishizeki.hpp"
#include <chrono>
#include <thread>

using namespace std;

int main(int argc, char *argv[]){

    TestNodeIteratorsAcceleration::testNodeIteratorVSNodeIteratorPlusPlusMincreasing(10);

    
    /*GraphFiller *graphFiller = new GraphFiller();
    GraphAdjListVUS *g1 = new GraphAdjListVUS();
    graphFiller->setGraphFromFileMapped(argv[1], g1);

    cout << "- Graph VUS -" << endl;
    cout << "Vertices: " << g1->getNumVertices() << endl;
    cout << "Edges: " << g1->getNumEdges() << endl;

    delete graphFiller;

    cout << "avg degeneracy: " << g1->getAverageDegeneracy() << endl;
    
    long int cpt = 0;
    auto start = chrono::high_resolution_clock::now();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_secondsNI;
    chrono::duration<double> elapsed_secondsNIPP;

    start = chrono::high_resolution_clock::now();
    cpt = g1->countTrianglesNodeIterator();
    end = chrono::high_resolution_clock::now();
    elapsed_secondsNI = end - start;
    cout << "Nb Triangle " << cpt << endl;
    cout << "Elapsed time: " << elapsed_secondsNI.count()*1000 << "ms" << endl;

    start = chrono::high_resolution_clock::now();
    cpt = g1->countTrianglesNodeIteratorPlusPlus();
    end = chrono::high_resolution_clock::now();
    elapsed_secondsNIPP = end - start;
    cout << "Nb Triangle " << cpt << endl;
    cout << "Elapsed time: " << elapsed_secondsNIPP.count()*1000 << "ms" << endl;

    cout << "Speedup: " << elapsed_secondsNI.count()/elapsed_secondsNIPP.count() << endl;
    double nb2pathNI = g1->nbTwoPathsNodeIterator();
    double nb2pathNIPP = g1->nbTwoPathsNodeIteratorPlusPlus();
    cout << "Nb 2 paths: " << "Node Iterator: " << nb2pathNI << " Node Iterator++: " << nb2pathNIPP << endl;
    cout << "Delta 2 paths: " << nb2pathNI / nb2pathNIPP << endl;*/

    return 0;
}
