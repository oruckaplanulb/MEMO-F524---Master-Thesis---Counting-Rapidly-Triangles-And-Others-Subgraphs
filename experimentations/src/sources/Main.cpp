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
    GraphAdjListVUS *g2 = new GraphAdjListVUS();
    graphFiller->setGraphFromFileMapped(argv[1], g2);


    cout << "- Graph -" << endl;
    cout << "Vertices: " << g2->getNumVertices() << endl;
    cout << "Edges: " << g2->getNumEdges() << endl;

    delete graphFiller;
    
    int cpt = 0;
    auto start = chrono::high_resolution_clock::now();
    auto end = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed_seconds;

    start = chrono::high_resolution_clock::now();
    cpt = g2->countTrianglesChibaNishizeki();
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    cout << "Number of C3: " << cpt << endl;
    cout << "Elapsed time: " << elapsed_seconds.count()*1000 << "ms" << endl;

    start = chrono::high_resolution_clock::now();
    cpt = g2->countTrianglesNodeIteratorPlusPlus();
    end = chrono::high_resolution_clock::now();
    elapsed_seconds = end - start;
    cout << "Number of C3: " << cpt << endl;
    cout << "Elapsed time: " << elapsed_seconds.count()*1000 << "ms" << endl;
    //print all triangles
    /*for (const vector<int>& triangle : triangles) {
        cout << triangle[0] << " " << triangle[1] << " " << triangle[2] << endl;
    }*/

    /*GraphFiller *graphFiller = new GraphFiller();
    GraphAdjListVUS *g2 = new GraphAdjListVUS();
    graphFiller->setGraphFromFileMapped(argv[1], g2);

    //print nb vertices and edges
    cout << "Vertices: " << g2->getNumVertices() << endl;
    cout << "Edges: " << g2->getNumEdges() << endl;*/

    return 0;
}
