#ifndef TESTNODEITERATORSACCELERATION_HPP
#define TESTNODEITERATORSACCELERATION_HPP

#include "../headers/Graph.hpp"
#include "../headers/Matrix.hpp"
#include "../headers/GraphFiller.hpp"
#include "../headers/ResultsEncoder.hpp"
#include <chrono>
#include <iostream>

using namespace std;

class TestNodeIteratorsAcceleration {
public:

static void testNodeIteratorVSNodeIteratorPlusPlusMincreasing(int nbRuns) {
        vector<string> graphsPaths = {  "../graphs/p2p-Gnutella/p2p-Gnutella08.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella09.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella06.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella05.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella04.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella25.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella24.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella30.txt"};

        //for each graph Path
        for (const string& graphPath : graphsPaths) {
            GraphFiller* graphFiller = new GraphFiller();
            GraphAdjListVUS* g = new GraphAdjListVUS();
            graphFiller->setGraphFromFileMapped(graphPath, g);
            delete graphFiller;
            cout << "- Graph -"<< endl;
            cout << "Vertices: " << g->getNumVertices() << endl;
            cout << "Edges: " << g->getNumEdges() << endl;

            int cpt = 0;
            auto start = chrono::high_resolution_clock::now();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds;
            chrono::duration<double> total_seconds;
            vector<chrono::duration<double>> timesNI;
            vector<chrono::duration<double>> timesNIPP;
            int nbTrianglesNI = 0;
            int nbTrianglesNIPP = 0;

            cout << "Graph: " << graphPath << " | Function: " << "NodeIteratorVSNodeIteratorPlusPlusMincreasing" << " NbRun: "<< nbRuns << endl;
            for (int i = 0; i < nbRuns; ++i) {
                cout << "Run number: " << i << endl;
                start = chrono::high_resolution_clock::now();
                cpt = g->countTrianglesNodeIterator();
                end = chrono::high_resolution_clock::now();
                elapsed_seconds = end-start;
                total_seconds += elapsed_seconds;
                timesNI.push_back(elapsed_seconds);
            }
            nbTrianglesNI = cpt;
            cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;
            for (int i = 0; i < nbRuns; ++i) {
                //cout << "Run number: " << i << endl;
                start = chrono::high_resolution_clock::now();
                cpt = g->countTrianglesNodeIteratorPlusPlus();
                end = chrono::high_resolution_clock::now();
                elapsed_seconds = end-start;
                total_seconds += elapsed_seconds;
                timesNIPP.push_back(elapsed_seconds);
            }
            nbTrianglesNIPP = cpt;
            cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;

            double nb2pathNI = g->nbTwoPathsNodeIterator();
            double nb2pathNIPP = g->nbTwoPathsNodeIteratorPlusPlus();
            cout << "Nb 2 paths: " << "Node Iterator: " << nb2pathNI << " Node Iterator++: " << nb2pathNIPP << endl;
            cout << "Expected acceleration: " << nb2pathNI / nb2pathNIPP << endl;

            delete g;

            ResultsEncoder* resultsEncoder = new ResultsEncoder();
            resultsEncoder->encodeResultsAcceleration("../results/NodeIterator/accelerationtests/AccelerationMincreasing.txt", graphPath, "NodeIteratorVSNodeIteratorPlusPlusMincreasing",
                                                        timesNI, timesNIPP, nbTrianglesNI, nbTrianglesNIPP, nb2pathNI, nb2pathNIPP); 
        }
    }

};

#endif