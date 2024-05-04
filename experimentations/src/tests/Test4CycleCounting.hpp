#ifndef TEST4CYCLECOUNTING_HPP
#define TEST4CYCLECOUNTING_HPP

#include "../headers/Graph.hpp"
#include "../headers/Matrix.hpp"
#include "../headers/GraphFiller.hpp"
#include "../headers/ResultsEncoder.hpp"
#include <chrono>
#include <iostream>
#include <filesystem>

using namespace std;

class Test4CycleCounting {
public:

    static void testCount4CycleLowMedHigh(int nbRuns) {
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
            GraphAdjListVUS* g = new GraphAdjListVUS();
            graphFiller->setGraphFromFileMapped(graphPath, g);
            cout << "- Graph List VV -"<< endl;
            cout << "Vertices: " << g->getNumVertices() << endl;
            cout << "Edges: " << g->getNumEdges() << endl;

            long long int cpt = 0;
            auto start = chrono::high_resolution_clock::now();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds;
            chrono::duration<double> total_seconds;
            vector<chrono::duration<double>> times;

            cout << "Graph: " << graphPath << " | Function: " << "Count4CycleLowMedHigh" << " NbRun: "<< nbRuns << endl;
            for (int i = 0; i < nbRuns; ++i) {
                //cout << "Run number: " << i << endl;
                start = chrono::high_resolution_clock::now();
                cpt = g->count4CyclesBasic();
                end = chrono::high_resolution_clock::now();
                elapsed_seconds = end-start;
                total_seconds += elapsed_seconds;
                times.push_back(elapsed_seconds);
            }
            cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;
            delete g;
            delete graphFiller;

            ResultsEncoder* resultsEncoder = new ResultsEncoder();
            resultsEncoder->encodeResults("../results/4Cycle/lowmedhigh/Count4CycleLowMedHigh.txt", graphPath, "Count4CycleLowMedHigh", times, cpt); 
        }
    }

    static void testCount4CycleVertexLocalLowMedHigh(int nbRuns) {
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
            GraphAdjListVUS* g = new GraphAdjListVUS();
            graphFiller->setGraphFromFileMapped(graphPath, g);
            cout << "- Graph List VV -"<< endl;
            cout << "Vertices: " << g->getNumVertices() << endl;
            cout << "Edges: " << g->getNumEdges() << endl;

            int cpt = 0;
            auto start = chrono::high_resolution_clock::now();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds;
            chrono::duration<double> total_seconds;
            vector<chrono::duration<double>> times;

            cout << "Graph: " << graphPath << " | Function: " << "Count4CycleVertexLocalLowMedHigh" << " NbRun: "<< nbRuns << endl;
            for (int i = 0; i < nbRuns; ++i) {
                //cout << "Run number: " << i << endl;
                start = chrono::high_resolution_clock::now();
                cpt = g->count4CyclesVertexLocal().size();
                end = chrono::high_resolution_clock::now();
                elapsed_seconds = end-start;
                total_seconds += elapsed_seconds;
                times.push_back(elapsed_seconds);
            }
            cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;
            delete g;
            delete graphFiller;

            ResultsEncoder* resultsEncoder = new ResultsEncoder();
            resultsEncoder->encodeResults("../results/4Cycle/lowmedhigh/Count4CycleVertexLocalLowMedHigh.txt", graphPath, "Count4CycleVertexLocalLowMedHigh", times, cpt); 
        }
    }

    static void testCount4CycleEdgeLocalLowMedHigh(int nbRuns) {
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
            GraphAdjListVV* g = new GraphAdjListVV();
            graphFiller->setGraphFromFileMapped(graphPath, g);
            cout << "- Graph List VV -"<< endl;
            cout << "Vertices: " << g->getNumVertices() << endl;
            cout << "Edges: " << g->getNumEdges() << endl;

            int cpt = 0;
            auto start = chrono::high_resolution_clock::now();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds;
            chrono::duration<double> total_seconds;
            vector<chrono::duration<double>> times;

            cout << "Graph: " << graphPath << " | Function: " << "Count4CycleEdgeLocalLowMedHigh" << " NbRun: "<< nbRuns << endl;
            for (int i = 0; i < nbRuns; ++i) {
                //cout << "Run number: " << i << endl;
                start = chrono::high_resolution_clock::now();
                cpt = g->count4CyclesEdgeLocalVector().size();
                end = chrono::high_resolution_clock::now();
                elapsed_seconds = end-start;
                total_seconds += elapsed_seconds;
                times.push_back(elapsed_seconds);
            }
            cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;
            delete g;
            delete graphFiller;

            ResultsEncoder* resultsEncoder = new ResultsEncoder();
            resultsEncoder->encodeResults("../results/4Cycle/lowmedhigh/Count4CycleEdgeLocalLowMedHigh.txt", graphPath, "Count4CycleEdgeLocalLowMedHigh", times, cpt); 
        }
    }



    //====================================================================================================

    static void testCount4CycleNMIncreasing(int nbRuns) {
        vector<string> graphsPaths = {  "../graphs/p2p-Gnutella/p2p-Gnutella08.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella09.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella06.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella05.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella04.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella25.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella24.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella30.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella31.txt"};

        //for each graph Path
        for (const string& graphPath : graphsPaths) {
            GraphFiller* graphFiller = new GraphFiller();
            GraphAdjListVUS* g = new GraphAdjListVUS();
            graphFiller->setGraphFromFileMapped(graphPath, g);
            cout << "- Graph List VV -"<< endl;
            cout << "Vertices: " << g->getNumVertices() << endl;
            cout << "Edges: " << g->getNumEdges() << endl;

            long long int cpt = 0;
            auto start = chrono::high_resolution_clock::now();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds;
            chrono::duration<double> total_seconds;
            vector<chrono::duration<double>> times;

            cout << "Graph: " << graphPath << " | Function: " << "Count4CycleNMIncreasing" << " NbRun: "<< nbRuns << endl;
            for (int i = 0; i < nbRuns; ++i) {
                //cout << "Run number: " << i << endl;
                start = chrono::high_resolution_clock::now();
                cpt = g->count4CyclesBasic();
                end = chrono::high_resolution_clock::now();
                elapsed_seconds = end-start;
                total_seconds += elapsed_seconds;
                times.push_back(elapsed_seconds);
            }
            cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;
            delete g;
            delete graphFiller;

            ResultsEncoder* resultsEncoder = new ResultsEncoder();
            resultsEncoder->encodeResults("../results/4Cycle/NMIncreasing/Count4CycleNMIncreasing.txt", graphPath, "Count4CycleNMIncreasing", times, cpt); 
        }
    }

    static void testCount4CycleVertexLocalNMIncreasing(int nbRuns) {
        vector<string> graphsPaths = {  "../graphs/p2p-Gnutella/p2p-Gnutella08.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella09.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella06.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella05.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella04.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella25.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella24.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella30.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella31.txt"};

        //for each graph Path
        for (const string& graphPath : graphsPaths) {
            GraphFiller* graphFiller = new GraphFiller();
            GraphAdjListVUS* g = new GraphAdjListVUS();
            graphFiller->setGraphFromFileMapped(graphPath, g);
            cout << "- Graph List VV -"<< endl;
            cout << "Vertices: " << g->getNumVertices() << endl;
            cout << "Edges: " << g->getNumEdges() << endl;

            int cpt = 0;
            auto start = chrono::high_resolution_clock::now();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds;
            chrono::duration<double> total_seconds;
            vector<chrono::duration<double>> times;

            cout << "Graph: " << graphPath << " | Function: " << "Count4CycleVertexLocalNMIncreasing" << " NbRun: "<< nbRuns << endl;
            for (int i = 0; i < nbRuns; ++i) {
                //cout << "Run number: " << i << endl;
                start = chrono::high_resolution_clock::now();
                cpt = g->count4CyclesVertexLocal().size();
                end = chrono::high_resolution_clock::now();
                elapsed_seconds = end-start;
                total_seconds += elapsed_seconds;
                times.push_back(elapsed_seconds);
            }
            cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;
            delete g;
            delete graphFiller;

            ResultsEncoder* resultsEncoder = new ResultsEncoder();
            resultsEncoder->encodeResults("../results/4Cycle/NMIncreasing/Count4CycleVertexLocalNMIncreasing.txt", graphPath, "Count4CycleVertexLocalNMIncreasing", times, cpt); 
        }
    }

    static void testCount4CycleEdgeLocalNMIncreasing(int nbRuns) {
        vector<string> graphsPaths = {  "../graphs/p2p-Gnutella/p2p-Gnutella08.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella09.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella06.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella05.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella04.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella25.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella24.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella30.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella31.txt"};

        //for each graph Path
        for (const string& graphPath : graphsPaths) {
            GraphFiller* graphFiller = new GraphFiller();
            GraphAdjListVV* g = new GraphAdjListVV();
            graphFiller->setGraphFromFileMapped(graphPath, g);
            cout << "- Graph List VV -"<< endl;
            cout << "Vertices: " << g->getNumVertices() << endl;
            cout << "Edges: " << g->getNumEdges() << endl;

            int cpt = 0;
            auto start = chrono::high_resolution_clock::now();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds;
            chrono::duration<double> total_seconds;
            vector<chrono::duration<double>> times;

            cout << "Graph: " << graphPath << " | Function: " << "Count4CycleEdgeLocalNMIncreasing" << " NbRun: "<< nbRuns << endl;
            for (int i = 0; i < nbRuns; ++i) {
                //cout << "Run number: " << i << endl;
                start = chrono::high_resolution_clock::now();
                cpt = g->count4CyclesEdgeLocalVector().size();
                end = chrono::high_resolution_clock::now();
                elapsed_seconds = end-start;
                total_seconds += elapsed_seconds;
                times.push_back(elapsed_seconds);
            }
            cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;
            delete g;
            delete graphFiller;

            ResultsEncoder* resultsEncoder = new ResultsEncoder();
            resultsEncoder->encodeResults("../results/4Cycle/NMIncreasing/Count4CycleEdgeLocalNMIncreasing.txt", graphPath, "Count4CycleEdgeLocalNMIncreasing", times, cpt); 
        }
    }

    static void testCount4CycleEdgeLocalNMIncreasingTtime(int nbRuns) {
        vector<string> graphsPaths = {  "../graphs/p2p-Gnutella/p2p-Gnutella08.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella09.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella06.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella05.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella04.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella25.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella24.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella30.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella31.txt"};

        //for each graph Path
        for (const string& graphPath : graphsPaths) {
            GraphFiller* graphFiller = new GraphFiller();
            GraphAdjListVV* g = new GraphAdjListVV();
            graphFiller->setGraphFromFileMapped(graphPath, g);
            cout << "- Graph List VV -"<< endl;
            cout << "Vertices: " << g->getNumVertices() << endl;
            cout << "Edges: " << g->getNumEdges() << endl;

            auto start = chrono::high_resolution_clock::now();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds;
            chrono::duration<double> total_seconds;
            vector<chrono::duration<double>> times;
            chrono::duration<double> Ttime;
            vector<chrono::duration<double>> Ttimes;

            cout << "Graph: " << graphPath << " | Function: " << "Count4CycleEdgeLocalNMIncreasing" << " NbRun: "<< nbRuns << endl;
            for (int i = 0; i < nbRuns; ++i) {
                //cout << "Run number: " << i << endl;
                start = chrono::high_resolution_clock::now();
                Ttime = g->count4CyclesEdgeLocalTtime();
                end = chrono::high_resolution_clock::now();
                elapsed_seconds = end-start;
                total_seconds += elapsed_seconds;
                times.push_back(elapsed_seconds);
                Ttimes.push_back(Ttime);
            }
            cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;
            delete g;
            delete graphFiller;

            ResultsEncoder* resultsEncoder = new ResultsEncoder();
            resultsEncoder->encodeResults("../results/4Cycle/NMIncreasing/Count4CycleEdgeLocalNMIncreasingTtime.txt", graphPath, "Count4CycleEdgeLocalNMIncreasing", times, 0); 
            resultsEncoder->encodeResults("../results/4Cycle/NMIncreasing/Count4CycleEdgeLocalNMIncreasingTtime.txt", graphPath, "Count4CycleEdgeLocalNMIncreasingTtime", Ttimes, 0); 
        }
    }
    

};

#endif