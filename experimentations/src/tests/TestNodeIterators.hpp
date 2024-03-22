#ifndef TESTNODEITERATORS_HPP
#define TESTNODEITERATORS_HPP

#include "../headers/Graph.hpp"
#include "../headers/Matrix.hpp"
#include "../headers/GraphFiller.hpp"
#include "../headers/ResultsEncoder.hpp"
#include <chrono>
#include <iostream>

using namespace std;

class TestNodeIterators {
public:
    static void testNodeIteratorsFacebook(int nbRuns) {
        string graphPath = "../graphs/Social-Network/ego-facebook.txt";
        GraphFiller* graphFiller = new GraphFiller();
        GraphAdjMatrixVV* graphMatrixVV = new GraphAdjMatrixVV();
        graphFiller->setGraphFromFileMapped(graphPath, graphMatrixVV);
        cout << "- Graph Matrix VV-"<< endl;
        cout << "Vertices: " << graphMatrixVV->getNumVertices() << endl;
        cout << "Edges: " << graphMatrixVV->getNumEdges() << endl;

        int cpt = 0;
        auto start = chrono::high_resolution_clock::now();
        auto end = chrono::high_resolution_clock::now();
        chrono::duration<double> elapsed_seconds;
        chrono::duration<double> total_seconds;
        vector<chrono::duration<double>> NodeIteratorVVtimes;
        vector<chrono::duration<double>> NodeIteratorPlusPlusVVtimes;
        vector<chrono::duration<double>> NodeIteratorPlusPlusOrderVVtimes;
        vector<chrono::duration<double>> NodeIteratorVUStimes;
        vector<chrono::duration<double>> NodeIteratorPlusPlusVUStimes;
        ResultsEncoder* resultsEncoder = new ResultsEncoder();

        cout << "Graph: " << graphPath << " | Function: " << "NodeIteratorVV" << " NbRun: "<< nbRuns << endl;
        total_seconds = chrono::duration<double>::zero();
        for (int i = 0; i < nbRuns; ++i) {
            cout << "Run number: " << i << endl;
            start = chrono::high_resolution_clock::now();
            cpt = graphMatrixVV->countTrianglesNodeIterator();
            end = chrono::high_resolution_clock::now();
            elapsed_seconds = end-start;
            total_seconds += elapsed_seconds;
            NodeIteratorVVtimes.push_back(elapsed_seconds);
        }
        cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;
        resultsEncoder->encodeResults("../results/NodeIterator/NodeIteratorsFacebook.txt", graphPath, "NodeIteratorVV", NodeIteratorVVtimes, cpt);

        cout << "Graph: " << graphPath << " | Function: " << "NodeIteratorPlusPlusVV" << " NbRun: "<< nbRuns << endl;
        total_seconds = chrono::duration<double>::zero();
        for (int i = 0; i < nbRuns; ++i) {
            cout << "Run number: " << i << endl;
            start = chrono::high_resolution_clock::now();
            cpt = graphMatrixVV->countTrianglesNodeIteratorPlusPlus();
            end = chrono::high_resolution_clock::now();
            elapsed_seconds = end-start;
            total_seconds += elapsed_seconds;
            NodeIteratorPlusPlusVVtimes.push_back(elapsed_seconds);
        }
        cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;
        resultsEncoder->encodeResults("../results/NodeIterator/NodeIteratorsFacebook.txt", graphPath, "NodeIteratorPlusPlusVV", NodeIteratorPlusPlusVVtimes, cpt);

        cout << "Graph: " << graphPath << " | Function: " << "NodeIteratorPlusPlusOrderVV" << " NbRun: "<< nbRuns << endl;
        total_seconds = chrono::duration<double>::zero();
        for (int i = 0; i < nbRuns; ++i) {
            cout << "Run number: " << i << endl;
            start = chrono::high_resolution_clock::now();
            cpt = graphMatrixVV->countTrianglesNodeIteratorPlusPlusWithOrder();
            end = chrono::high_resolution_clock::now();
            elapsed_seconds = end-start;
            total_seconds += elapsed_seconds;
            NodeIteratorPlusPlusOrderVVtimes.push_back(elapsed_seconds);
        }
        cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;
        resultsEncoder->encodeResults("../results/NodeIterator/NodeIteratorsFacebook.txt", graphPath, "NodeIteratorPlusPlusOrderVV", NodeIteratorPlusPlusOrderVVtimes, cpt);

        delete graphMatrixVV;

        GraphAdjListVUS* graphListVUS = new GraphAdjListVUS();
        graphFiller->setGraphFromFileMapped(graphPath, graphListVUS);

        cout << "Graph: " << graphPath << " | Function: " << "NodeIteratorVUS" << " NbRun: "<< nbRuns << endl;
        total_seconds = chrono::duration<double>::zero();
        for (int i = 0; i < nbRuns; ++i) {
            cout << "Run number: " << i << endl;
            start = chrono::high_resolution_clock::now();
            cpt = graphListVUS->countTrianglesNodeIterator();
            end = chrono::high_resolution_clock::now();
            elapsed_seconds = end-start;
            total_seconds += elapsed_seconds;
            NodeIteratorVUStimes.push_back(elapsed_seconds);
        }
        cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;
        resultsEncoder->encodeResults("../results/NodeIterator/NodeIteratorsFacebook.txt", graphPath, "NodeIteratorVUS", NodeIteratorVUStimes, cpt);

        cout << "Graph: " << graphPath << " | Function: " << "NodeIteratorPlusPlusVUS" << " NbRun: "<< nbRuns << endl;
        total_seconds = chrono::duration<double>::zero();
        for (int i = 0; i < nbRuns; ++i) {
            cout << "Run number: " << i << endl;
            start = chrono::high_resolution_clock::now();
            cpt = graphListVUS->countTrianglesNodeIteratorPlusPlus();
            end = chrono::high_resolution_clock::now();
            elapsed_seconds = end-start;
            total_seconds += elapsed_seconds;
            NodeIteratorPlusPlusVUStimes.push_back(elapsed_seconds);
        }
        cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;
        resultsEncoder->encodeResults("../results/NodeIterator/NodeIteratorsFacebook.txt", graphPath, "NodeIteratorPlusPlusVUS", NodeIteratorPlusPlusVUStimes, cpt);

        delete graphListVUS;
        delete graphFiller; 
    }

};

#endif