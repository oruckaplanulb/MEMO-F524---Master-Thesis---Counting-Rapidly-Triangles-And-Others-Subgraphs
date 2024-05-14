#ifndef TESTPARALLEL_HPP
#define TESTPARALLEL_HPP

#include "../headers/Graph.hpp"
#include "../headers/Matrix.hpp"
#include "../headers/GraphFiller.hpp"
#include "../headers/ResultsEncoder.hpp"
#include <chrono>
#include <iostream>

using namespace std;

class TestParallel {
public:
    static void testNodeIteratorLowMedHigh(int nbRuns) {
        vector<string> graphsPaths = {  /*"../graphs/Road-Network/roadNet-PA.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella08.txt",
                                        "../graphs/Social-Network/soc-Slashdot0811.txt",
                                        "../graphs/Web-graph/web-NotreDame.txt",
                                        "../graphs/Network-gtc/com-youtube.txt",
                                        "../graphs/Communication-Network/WikiTalk.txt",
                                        "../graphs/Web-graph/web-BerkStan.txt",
                                        "../graphs/Web-graph/web-Stanford.txt"*/};

        //for each graph Path
        for (const string& graphPath : graphsPaths) {
            GraphFiller* graphFiller = new GraphFiller();
            GraphAdjListVUS* graphListVUS = new GraphAdjListVUS();
            graphFiller->setGraphFromFileMapped(graphPath, graphListVUS);
            delete graphFiller;
            cout << "- Graph Matrix VUS-"<< endl;
            cout << "Vertices: " << graphListVUS->getNumVertices() << endl;
            cout << "Edges: " << graphListVUS->getNumEdges() << endl;

            for(int nbTH = 1 ; nbTH<=8 ; nbTH*=2){
                long long int cpt = 0;
                auto start = chrono::high_resolution_clock::now();
                auto end = chrono::high_resolution_clock::now();
                chrono::duration<double> elapsed_seconds;
                chrono::duration<double> total_seconds;
                vector<chrono::duration<double>> times;
                ResultsEncoder* resultsEncoder = new ResultsEncoder();
                cout << "Graph: " << graphPath << " | Function: " << "NodeIterator"<< nbTH <<"TH" << " NbRun: "<< nbRuns << endl;
                for (int i = 0; i < nbRuns; ++i) {
                    //cout << "Run number: " << i << endl;
                    start = chrono::high_resolution_clock::now();
                    cpt = graphListVUS->countTrianglesNodeIteratorParallel(nbTH);
                    end = chrono::high_resolution_clock::now();
                    elapsed_seconds = end-start;
                    total_seconds += elapsed_seconds;
                    times.push_back(elapsed_seconds);
                }
                cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;
                total_seconds = chrono::duration<double>();
                resultsEncoder->encodeResults("../results/Parallel/NodeIteratorLowMedHigh.txt", graphPath, "NodeIterator"+to_string(nbTH)+"TH", times, cpt);
            }
            delete graphListVUS;
        }
    }

    static void testNodeIteratorPlusPlusLowMedHigh(int nbRuns) {
        vector<string> graphsPaths = {  "../graphs/Road-Network/roadNet-PA.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella08.txt",
                                        "../graphs/Social-Network/soc-Slashdot0811.txt",
                                        "../graphs/Web-graph/web-NotreDame.txt",
                                        "../graphs/Network-gtc/com-youtube.txt",
                                        "../graphs/Communication-Network/WikiTalk.txt",
                                        "../graphs/Web-graph/web-BerkStan.txt",
                                        "../graphs/Web-graph/web-Stanford.txt"};

        //for each graph Path
        for (const string& graphPath : graphsPaths) {
            GraphFiller* graphFiller = new GraphFiller();
            GraphAdjListVUS* graphListVUS = new GraphAdjListVUS();
            graphFiller->setGraphFromFileMapped(graphPath, graphListVUS);
            delete graphFiller;
            cout << "- Graph Matrix VUS-"<< endl;
            cout << "Vertices: " << graphListVUS->getNumVertices() << endl;
            cout << "Edges: " << graphListVUS->getNumEdges() << endl;

            for(int nbTH = 1 ; nbTH<=8 ; nbTH*=2){
                long long int cpt = 0;
                auto start = chrono::high_resolution_clock::now();
                auto end = chrono::high_resolution_clock::now();
                chrono::duration<double> elapsed_seconds;
                chrono::duration<double> total_seconds;
                vector<chrono::duration<double>> times;
                ResultsEncoder* resultsEncoder = new ResultsEncoder();
                cout << "Graph: " << graphPath << " | Function: " << "NodeIteratorPlusPlus"<< nbTH <<"TH" << " NbRun: "<< nbRuns << endl;
                for (int i = 0; i < nbRuns; ++i) {
                    //cout << "Run number: " << i << endl;
                    start = chrono::high_resolution_clock::now();
                    cpt = graphListVUS->countTrianglesNodeIteratorPlusPlusParallel(nbTH);
                    end = chrono::high_resolution_clock::now();
                    elapsed_seconds = end-start;
                    total_seconds += elapsed_seconds;
                    times.push_back(elapsed_seconds);
                }
                cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;
                total_seconds = chrono::duration<double>();
                resultsEncoder->encodeResults("../results/Parallel/NodeIteratorPlusPlusLowMedHigh.txt", graphPath, "NodeIteratorPlusPlus"+to_string(nbTH)+"TH", times, cpt);
            }
            delete graphListVUS;
        }
    }

    static void testNodeIteratorFacebook(int nbRuns) {
        vector<string> graphsPaths = {"../graphs/Social-Network/ego-facebook.txt"};
                                        
        //for each graph Path
        for (const string& graphPath : graphsPaths) {
            GraphFiller* graphFiller = new GraphFiller();
            GraphAdjListVUS* graphListVUS = new GraphAdjListVUS();
            graphFiller->setGraphFromFileMapped(graphPath, graphListVUS);
            delete graphFiller;
            cout << "- Graph Matrix VUS-"<< endl;
            cout << "Vertices: " << graphListVUS->getNumVertices() << endl;
            cout << "Edges: " << graphListVUS->getNumEdges() << endl;

            for(int nbTH = 1 ; nbTH<=8 ; nbTH*=2){
                long long int cpt = 0;
                auto start = chrono::high_resolution_clock::now();
                auto end = chrono::high_resolution_clock::now();
                chrono::duration<double> elapsed_seconds;
                chrono::duration<double> total_seconds;
                vector<chrono::duration<double>> times;
                ResultsEncoder* resultsEncoder = new ResultsEncoder();
                cout << "Graph: " << graphPath << " | Function: " << "NodeIterator"<< nbTH <<"TH" << " NbRun: "<< nbRuns << endl;
                for (int i = 0; i < nbRuns; ++i) {
                    //cout << "Run number: " << i << endl;
                    start = chrono::high_resolution_clock::now();
                    cpt = graphListVUS->countTrianglesNodeIteratorParallel(nbTH);
                    end = chrono::high_resolution_clock::now();
                    elapsed_seconds = end-start;
                    total_seconds += elapsed_seconds;
                    times.push_back(elapsed_seconds);
                }
                cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;
                total_seconds = chrono::duration<double>();
                resultsEncoder->encodeResults("../results/Parallel/NodeIteratorFacebook.txt", graphPath, "NodeIterator"+to_string(nbTH)+"TH", times, cpt);
            }
            delete graphListVUS;
        }
    }

    static void testNodeIteratorPlusPlusFacebook(int nbRuns) {
        vector<string> graphsPaths = {"../graphs/Social-Network/ego-facebook.txt"};

        //for each graph Path
        for (const string& graphPath : graphsPaths) {
            GraphFiller* graphFiller = new GraphFiller();
            GraphAdjListVUS* graphListVUS = new GraphAdjListVUS();
            graphFiller->setGraphFromFileMapped(graphPath, graphListVUS);
            delete graphFiller;
            cout << "- Graph Matrix VUS-"<< endl;
            cout << "Vertices: " << graphListVUS->getNumVertices() << endl;
            cout << "Edges: " << graphListVUS->getNumEdges() << endl;

            for(int nbTH = 1 ; nbTH<=8 ; nbTH*=2){
                long long int cpt = 0;
                auto start = chrono::high_resolution_clock::now();
                auto end = chrono::high_resolution_clock::now();
                chrono::duration<double> elapsed_seconds;
                chrono::duration<double> total_seconds;
                vector<chrono::duration<double>> times;
                ResultsEncoder* resultsEncoder = new ResultsEncoder();
                cout << "Graph: " << graphPath << " | Function: " << "NodeIteratorPlusPlus"<< nbTH <<"TH" << " NbRun: "<< nbRuns << endl;
                for (int i = 0; i < nbRuns; ++i) {
                    //cout << "Run number: " << i << endl;
                    start = chrono::high_resolution_clock::now();
                    cpt = graphListVUS->countTrianglesNodeIteratorPlusPlusParallel(nbTH);
                    end = chrono::high_resolution_clock::now();
                    elapsed_seconds = end-start;
                    total_seconds += elapsed_seconds;
                    times.push_back(elapsed_seconds);
                }
                cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;
                total_seconds = chrono::duration<double>();
                resultsEncoder->encodeResults("../results/Parallel/NodeIteratorPlusPlusFacebook.txt", graphPath, "NodeIteratorPlusPlus"+to_string(nbTH)+"TH", times, cpt);
            }
            delete graphListVUS;
        }
    }
};

#endif