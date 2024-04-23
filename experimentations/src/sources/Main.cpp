#include "../headers/Graph.hpp"
#include "../headers/Matrix.hpp"
#include "../headers/GraphFiller.hpp"
#include "../tests/TestMatrices.hpp"
#include "../tests/TestNodeIterators.hpp"
#include "../tests/TestNodeIteratorsIndividual.hpp"
#include "../tests/TestNodeIteratorsAcceleration.hpp"
#include "../tests/TestForward.hpp"
#include "../tests/TestChibaNishizeki.hpp"
#include "../tests/TestExtra.hpp"
#include <chrono>
#include <thread>

using namespace std;

int main(int argc, char *argv[]){

    TestNodeIterators::testFindNodeIteratorPlusPlusLowMedHigh(10);
    TestNodeIterators::testCountNodeIteratorPlusPlusLowMedHigh(10);
    TestChibaNishizeki::testFindChibaNishizekiLowMedHigh(10);
    TestChibaNishizeki::testCountChibaNishizekiLowMedHigh(10);
    TestForward::testFindForwardLowMedHigh(10);
    TestForward::testCountForwardLowMedHigh(10);

    /*
    GraphFiller *graphFiller = new GraphFiller();
    GraphAdjListVUS *g1 = new GraphAdjListVUS();
    graphFiller->setGraphFromFileMapped(argv[1], g1);

    cout << "- Graph VUS -" << endl;
    cout << "Vertices: " << g1->getNumVertices() << endl;
    cout << "Edges: " << g1->getNumEdges() << endl;

    delete graphFiller;

    cout << "avg degeneracy: " << g1->getAverageDegeneracy() << endl;
    cout << "avg clustering coefficient: " << g1->getAverageClusturingCoefficient() << endl;

    vector<int> v = g1->getClusturingCoefficientDistribution(10);

    for (int i = 0; i < v.size(); i++){
        cout << "Clustering coefficient " << i << ": " << v[i] << endl;
    }

    delete g1;*/
    
    /*long int cpt = 0;
    auto start = chrono::high_resolution_clock::now();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_secondsNI;
    chrono::duration<double> elapsed_secondsNIPP;

    start = chrono::high_resolution_clock::now();
    cpt = g1->countTrianglesNodeIterator();
    end = chrono::high_resolution_clock::now();
    elapsed_secondsNI = end - start;
    cout << "Nb Triangle " << cpt << endl;
    cout << "Elapsed time: " << elapsed_secondsNI.count()*1000 << "ms" << endl;*/

    return 0;
}
