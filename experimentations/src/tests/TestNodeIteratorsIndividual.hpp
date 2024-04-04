#ifndef TESTNODEITERATORS_HPP
#define TESTNODEITERATORS_HPP

#include "../headers/Graph.hpp"
#include "../headers/Matrix.hpp"
#include "../headers/GraphFiller.hpp"
#include "../headers/ResultsEncoder.hpp"
#include <chrono>
#include <iostream>

using namespace std;

class TestNodeIteratorsIndividual {
public:

    static void testNodeIteratorAdjListNotreDameVsStanford(int nbRuns) {
        vector<string> graphsPaths = {  "../graphs/Web-graph/web-NotreDame.txt",
                                        "../graphs/Web-graph/web-Stanford.txt"};

        //for each graph Path
        for (const string& graphPath : graphsPaths) {
            GraphFiller* graphFiller = new GraphFiller();
            GraphAdjListVUS* g = new GraphAdjListVUS();
            graphFiller->setGraphFromFileMapped(graphPath, g);
            cout << "- Graph -"<< endl;
            cout << "Vertices: " << g->getNumVertices() << endl;
            cout << "Edges: " << g->getNumEdges() << endl;

            int cpt = 0;
            auto start = chrono::high_resolution_clock::now();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds;
            chrono::duration<double> total_seconds;
            vector<chrono::duration<double>> times;

            cout << "Graph: " << graphPath << " | Function: " << "NodeIteratorAdjListNotreDameVsStanford" << " NbRun: "<< nbRuns << endl;
            for (int i = 0; i < nbRuns; ++i) {
                cout << "Run number: " << i << endl;
                start = chrono::high_resolution_clock::now();
                cpt = g->countTrianglesNodeIterator();
                end = chrono::high_resolution_clock::now();
                elapsed_seconds = end-start;
                total_seconds += elapsed_seconds;
                times.push_back(elapsed_seconds);
            }
            cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;
            delete g;
            delete graphFiller;

            ResultsEncoder* resultsEncoder = new ResultsEncoder();
            resultsEncoder->encodeResults("../results/NodeIterator/NotreDameVsStanford.txt", graphPath, "NodeIteratorAdjListNotreDameVsStanford", times, cpt); 
        }
    }

    static void testNodeIteratorPlusPlusAdjListNotreDameVsStanford(int nbRuns) {
        vector<string> graphsPaths = {  "../graphs/Web-graph/web-NotreDame.txt",
                                        "../graphs/Web-graph/web-Stanford.txt"};

        //for each graph Path
        for (const string& graphPath : graphsPaths) {
            GraphFiller* graphFiller = new GraphFiller();
            GraphAdjListVUS* g = new GraphAdjListVUS();
            graphFiller->setGraphFromFileMapped(graphPath, g);
            cout << "- Graph -"<< endl;
            cout << "Vertices: " << g->getNumVertices() << endl;
            cout << "Edges: " << g->getNumEdges() << endl;

            int cpt = 0;
            auto start = chrono::high_resolution_clock::now();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds;
            chrono::duration<double> total_seconds;
            vector<chrono::duration<double>> times;

            cout << "Graph: " << graphPath << " | Function: " << "NodeIteratorPlusPlusAdjListNotreDameVsStanford" << " NbRun: "<< nbRuns << endl;
            for (int i = 0; i < nbRuns; ++i) {
                cout << "Run number: " << i << endl;
                start = chrono::high_resolution_clock::now();
                cpt = g->countTrianglesNodeIteratorPlusPlus();
                end = chrono::high_resolution_clock::now();
                elapsed_seconds = end-start;
                total_seconds += elapsed_seconds;
                times.push_back(elapsed_seconds);
            }
            cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;
            delete g;
            delete graphFiller;

            ResultsEncoder* resultsEncoder = new ResultsEncoder();
            resultsEncoder->encodeResults("../results/NodeIterator/NotreDameVsStanford.txt", graphPath, "NodeIteratorPlusPlusAdjListNotreDameVsStanford", times, cpt); 
        }
    }

    //==================================================================================================

    static void testNodeIteratorAdjListNotreDameVsStanford(int nbRuns) {
        vector<string> graphsPaths = {  "../graphs/Web-graph/web-NotreDame.txt",
                                        "../graphs/Web-graph/web-Stanford.txt"};

        //for each graph Path
        for (const string& graphPath : graphsPaths) {
            GraphFiller* graphFiller = new GraphFiller();
            GraphAdjListVUS* g = new GraphAdjListVUS();
            graphFiller->setGraphFromFileMapped(graphPath, g);
            cout << "- Graph -"<< endl;
            cout << "Vertices: " << g->getNumVertices() << endl;
            cout << "Edges: " << g->getNumEdges() << endl;

            int cpt = 0;
            auto start = chrono::high_resolution_clock::now();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds;
            chrono::duration<double> total_seconds;
            vector<chrono::duration<double>> times;

            cout << "Graph: " << graphPath << " | Function: " << "NodeIteratorAdjListNotreDameVsStanford" << " NbRun: "<< nbRuns << endl;
            for (int i = 0; i < nbRuns; ++i) {
                cout << "Run number: " << i << endl;
                start = chrono::high_resolution_clock::now();
                cpt = g->countTrianglesNodeIterator();
                end = chrono::high_resolution_clock::now();
                elapsed_seconds = end-start;
                total_seconds += elapsed_seconds;
                times.push_back(elapsed_seconds);
            }
            cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;
            delete g;
            delete graphFiller;

            ResultsEncoder* resultsEncoder = new ResultsEncoder();
            resultsEncoder->encodeResults("../results/NodeIterator/NotreDameVsStanford.txt", graphPath, "NodeIteratorAdjListNotreDameVsStanford", times, cpt); 
        }
    }

    static void testNodeIteratorPlusPlusAdjListNotreDameVsStanford(int nbRuns) {
        vector<string> graphsPaths = {  "../graphs/Web-graph/web-NotreDame.txt",
                                        "../graphs/Web-graph/web-Stanford.txt"};

        //for each graph Path
        for (const string& graphPath : graphsPaths) {
            GraphFiller* graphFiller = new GraphFiller();
            GraphAdjListVUS* g = new GraphAdjListVUS();
            graphFiller->setGraphFromFileMapped(graphPath, g);
            cout << "- Graph -"<< endl;
            cout << "Vertices: " << g->getNumVertices() << endl;
            cout << "Edges: " << g->getNumEdges() << endl;

            int cpt = 0;
            auto start = chrono::high_resolution_clock::now();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds;
            chrono::duration<double> total_seconds;
            vector<chrono::duration<double>> times;

            cout << "Graph: " << graphPath << " | Function: " << "NodeIteratorPlusPlusAdjListNotreDameVsStanford" << " NbRun: "<< nbRuns << endl;
            for (int i = 0; i < nbRuns; ++i) {
                cout << "Run number: " << i << endl;
                start = chrono::high_resolution_clock::now();
                cpt = g->countTrianglesNodeIteratorPlusPlus();
                end = chrono::high_resolution_clock::now();
                elapsed_seconds = end-start;
                total_seconds += elapsed_seconds;
                times.push_back(elapsed_seconds);
            }
            cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;
            delete g;
            delete graphFiller;

            ResultsEncoder* resultsEncoder = new ResultsEncoder();
            resultsEncoder->encodeResults("../results/NodeIterator/NotreDameVsStanford.txt", graphPath, "NodeIteratorPlusPlusAdjListNotreDameVsStanford", times, cpt); 
        }
    }

    //==================================================================================================

};

#endif