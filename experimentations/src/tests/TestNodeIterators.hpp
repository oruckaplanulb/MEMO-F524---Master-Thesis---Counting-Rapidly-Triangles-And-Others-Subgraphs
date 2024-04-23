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

    static void testNodeIteratorAdjListMIncreasing(int nbRuns) {
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
            cout << "- Graph List VUS -"<< endl;
            cout << "Vertices: " << g->getNumVertices() << endl;
            cout << "Edges: " << g->getNumEdges() << endl;

            int cpt = 0;
            auto start = chrono::high_resolution_clock::now();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds;
            chrono::duration<double> total_seconds;
            vector<chrono::duration<double>> times;

            cout << "Graph: " << graphPath << " | Function: " << "NodeIteratorAdjListMIncreasing" << " NbRun: "<< nbRuns << endl;
            for (int i = 0; i < nbRuns; ++i) {
                //cout << "Run number: " << i << endl;
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
            resultsEncoder->encodeResults("../results/NodeIterator/mIncreasing/NodeIteratorAdjListMIncreasing.txt", graphPath, "NodeIteratorAdjListMIncreasing", times, cpt); 
        }
    }

    static void testNodeIteratorPlusPlusAdjListMIncreasing(int nbRuns) {
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
            cout << "- Graph List VUS -"<< endl;
            cout << "Vertices: " << g->getNumVertices() << endl;
            cout << "Edges: " << g->getNumEdges() << endl;

            int cpt = 0;
            auto start = chrono::high_resolution_clock::now();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds;
            chrono::duration<double> total_seconds;
            vector<chrono::duration<double>> times;

            cout << "Graph: " << graphPath << " | Function: " << "NodeIteratorPlusPlusAdjListMIncreasing" << " NbRun: "<< nbRuns << endl;
            for (int i = 0; i < nbRuns; ++i) {
                //cout << "Run number: " << i << endl;
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
            resultsEncoder->encodeResults("../results/NodeIterator/mIncreasing/NodeIteratorPlusPlusAdjListMIncreasing.txt", graphPath, "NodeIteratorPlusPlusAdjListMIncreasing", times, cpt); 
        }
    }

    static void testNodeIteratorAdjMatrixMIncreasing(int nbRuns) {
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
            GraphAdjMatrixVV* g = new GraphAdjMatrixVV();
            graphFiller->setGraphFromFileMapped(graphPath, g);
            cout << "- Graph Matrix VV -"<< endl;
            cout << "Vertices: " << g->getNumVertices() << endl;
            cout << "Edges: " << g->getNumEdges() << endl;

            int cpt = 0;
            auto start = chrono::high_resolution_clock::now();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds;
            chrono::duration<double> total_seconds;
            vector<chrono::duration<double>> times;

            cout << "Graph: " << graphPath << " | Function: " << "NodeIteratorAdjMatrixMIncreasing" << " NbRun: "<< nbRuns << endl;
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
            resultsEncoder->encodeResults("../results/NodeIterator/mIncreasing/NodeIteratorAdjMatrixMIncreasing.txt", graphPath, "NodeIteratorAdjMatrixMIncreasing", times, cpt); 
        }
    }

    static void testNodeIteratorPlusPlusAdjMatrixMIncreasing(int nbRuns) {
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
            GraphAdjMatrixVV* g = new GraphAdjMatrixVV();
            graphFiller->setGraphFromFileMapped(graphPath, g);
            cout << "- Graph Matrix VV -"<< endl;
            cout << "Vertices: " << g->getNumVertices() << endl;
            cout << "Edges: " << g->getNumEdges() << endl;

            int cpt = 0;
            auto start = chrono::high_resolution_clock::now();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds;
            chrono::duration<double> total_seconds;
            vector<chrono::duration<double>> times;

            cout << "Graph: " << graphPath << " | Function: " << "NodeIteratorPlusPlusAdjMatrixMIncreasing" << " NbRun: "<< nbRuns << endl;
            for (int i = 0; i < nbRuns; ++i) {
                cout << "Run number: " << i << endl;
                start = chrono::high_resolution_clock::now();
                cpt = g->countTrianglesNodeIteratorPlusPlusWithOrder();
                end = chrono::high_resolution_clock::now();
                elapsed_seconds = end-start;
                total_seconds += elapsed_seconds;
                times.push_back(elapsed_seconds);
            }
            cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;
            delete g;
            delete graphFiller;

            ResultsEncoder* resultsEncoder = new ResultsEncoder();
            resultsEncoder->encodeResults("../results/NodeIterator/mIncreasing/NodeIteratorPlusPlusAdjMatrixMIncreasing.txt", graphPath, "NodeIteratorPlusPlusAdjMatrixMIncreasing", times, cpt); 
        }
    }




    //============


        static void testNodeIteratorAdjListNIncreasing(int nbRuns) {
        vector<string> graphsPaths = {  "../graphs/Network-gtc/email-eu-core.txt",
                                        "../graphs/Social-Network/ego-facebook.txt",
                                        "../graphs/Social-Network/wiki-Vote.txt",
                                        "../graphs/Collaboration-Network/CA-HepPh.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella25.txt",
                                        "../graphs/Citation-Network/Cit-HepTh.txt"};

        //for each graph Path
        for (const string& graphPath : graphsPaths) {
            GraphFiller* graphFiller = new GraphFiller();
            GraphAdjListVUS* g = new GraphAdjListVUS();
            graphFiller->setGraphFromFileMapped(graphPath, g);
            cout << "- Graph List VUS -"<< endl;
            cout << "Vertices: " << g->getNumVertices() << endl;
            cout << "Edges: " << g->getNumEdges() << endl;

            int cpt = 0;
            auto start = chrono::high_resolution_clock::now();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds;
            chrono::duration<double> total_seconds;
            vector<chrono::duration<double>> times;

            cout << "Graph: " << graphPath << " | Function: " << "NodeIteratorAdjListNIncreasing" << " NbRun: "<< nbRuns << endl;
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
            resultsEncoder->encodeResults("../results/NodeIterator/nIncreasing/NodeIteratorAdjListNIncreasing.txt", graphPath, "NodeIteratorAdjListNIncreasing", times, cpt); 
        }
    }

    static void testNodeIteratorPlusPlusAdjListNIncreasing(int nbRuns) {
        vector<string> graphsPaths = {  "../graphs/Network-gtc/email-eu-core.txt",
                                        "../graphs/Social-Network/ego-facebook.txt",
                                        "../graphs/Social-Network/wiki-Vote.txt",
                                        "../graphs/Collaboration-Network/CA-HepPh.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella25.txt",
                                        "../graphs/Citation-Network/Cit-HepTh.txt"};

        //for each graph Path
        for (const string& graphPath : graphsPaths) {
            GraphFiller* graphFiller = new GraphFiller();
            GraphAdjListVUS* g = new GraphAdjListVUS();
            graphFiller->setGraphFromFileMapped(graphPath, g);
            cout << "- Graph List VUS -"<< endl;
            cout << "Vertices: " << g->getNumVertices() << endl;
            cout << "Edges: " << g->getNumEdges() << endl;

            int cpt = 0;
            auto start = chrono::high_resolution_clock::now();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds;
            chrono::duration<double> total_seconds;
            vector<chrono::duration<double>> times;

            cout << "Graph: " << graphPath << " | Function: " << "NodeIteratorPlusPlusAdjListNIncreasing" << " NbRun: "<< nbRuns << endl;
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
            resultsEncoder->encodeResults("../results/NodeIterator/nIncreasing/NodeIteratorPlusPlusAdjListNIncreasing.txt", graphPath, "NodeIteratorPlusPlusAdjListNIncreasing", times, cpt); 
        }
    }

    static void testNodeIteratorAdjMatrixNIncreasing(int nbRuns) {
        vector<string> graphsPaths = {  "../graphs/Network-gtc/email-eu-core.txt",
                                        "../graphs/Social-Network/ego-facebook.txt",
                                        "../graphs/Social-Network/wiki-Vote.txt",
                                        "../graphs/Collaboration-Network/CA-HepPh.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella25.txt",
                                        "../graphs/Citation-Network/Cit-HepTh.txt"};

        //for each graph Path
        for (const string& graphPath : graphsPaths) {
            GraphFiller* graphFiller = new GraphFiller();
            GraphAdjMatrixVV* g = new GraphAdjMatrixVV();
            graphFiller->setGraphFromFileMapped(graphPath, g);
            cout << "- Graph Matrix VV -"<< endl;
            cout << "Vertices: " << g->getNumVertices() << endl;
            cout << "Edges: " << g->getNumEdges() << endl;

            int cpt = 0;
            auto start = chrono::high_resolution_clock::now();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds;
            chrono::duration<double> total_seconds;
            vector<chrono::duration<double>> times;

            cout << "Graph: " << graphPath << " | Function: " << "NodeIteratorAdjMatrixNIncreasing" << " NbRun: "<< nbRuns << endl;
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
            resultsEncoder->encodeResults("../results/NodeIterator/nIncreasing/NodeIteratorAdjMatrixNIncreasing.txt", graphPath, "NodeIteratorAdjMatrixNIncreasing", times, cpt); 
        }
    }

    static void testNodeIteratorPlusPlusAdjMatrixNIncreasing(int nbRuns) {
        vector<string> graphsPaths = {  "../graphs/Network-gtc/email-eu-core.txt",
                                        "../graphs/Social-Network/ego-facebook.txt",
                                        "../graphs/Social-Network/wiki-Vote.txt",
                                        "../graphs/Collaboration-Network/CA-HepPh.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella25.txt",
                                        "../graphs/Citation-Network/Cit-HepTh.txt"};

        //for each graph Path
        for (const string& graphPath : graphsPaths) {
            GraphFiller* graphFiller = new GraphFiller();
            GraphAdjMatrixVV* g = new GraphAdjMatrixVV();
            graphFiller->setGraphFromFileMapped(graphPath, g);
            cout << "- Graph Matrix VV -"<< endl;
            cout << "Vertices: " << g->getNumVertices() << endl;
            cout << "Edges: " << g->getNumEdges() << endl;

            int cpt = 0;
            auto start = chrono::high_resolution_clock::now();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds;
            chrono::duration<double> total_seconds;
            vector<chrono::duration<double>> times;

            cout << "Graph: " << graphPath << " | Function: " << "NodeIteratorPlusPlusAdjMatrixNIncreasing" << " NbRun: "<< nbRuns << endl;
            for (int i = 0; i < nbRuns; ++i) {
                cout << "Run number: " << i << endl;
                start = chrono::high_resolution_clock::now();
                cpt = g->countTrianglesNodeIteratorPlusPlusWithOrder();
                end = chrono::high_resolution_clock::now();
                elapsed_seconds = end-start;
                total_seconds += elapsed_seconds;
                times.push_back(elapsed_seconds);
            }
            cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;
            delete g;
            delete graphFiller;

            ResultsEncoder* resultsEncoder = new ResultsEncoder();
            resultsEncoder->encodeResults("../results/NodeIterator/nIncreasing/NodeIteratorPlusPlusAdjMatrixNIncreasing.txt", graphPath, "NodeIteratorPlusPlusAdjMatrixNIncreasing", times, cpt); 
        }
    }


    //===================

    static void testFindNodeIteratorPlusPlusNIncreasing(int nbRuns) {
        vector<string> graphsPaths = {  "../graphs/Network-gtc/email-eu-core.txt",
                                        "../graphs/Social-Network/ego-facebook.txt",
                                        "../graphs/Social-Network/wiki-Vote.txt",
                                        "../graphs/Collaboration-Network/CA-HepPh.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella25.txt",
                                        "../graphs/Citation-Network/Cit-HepTh.txt"};

        //for each graph Path
        for (const string& graphPath : graphsPaths) {
            GraphFiller* graphFiller = new GraphFiller();
            GraphAdjListVUS* g = new GraphAdjListVUS();
            graphFiller->setGraphFromFileMapped(graphPath, g);
            cout << "- Graph List VUS -"<< endl;
            cout << "Vertices: " << g->getNumVertices() << endl;
            cout << "Edges: " << g->getNumEdges() << endl;

            int cpt = 0;
            auto start = chrono::high_resolution_clock::now();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds;
            chrono::duration<double> total_seconds;
            vector<chrono::duration<double>> times;

            cout << "Graph: " << graphPath << " | Function: " << "FindNodeIteratorPlusPlusNIncreasing" << " NbRun: "<< nbRuns << endl;
            for (int i = 0; i < nbRuns; ++i) {
                //cout << "Run number: " << i << endl;
                start = chrono::high_resolution_clock::now();
                cpt = g->findTrianglesNodeIteratorPlusPlus().size();
                end = chrono::high_resolution_clock::now();
                elapsed_seconds = end-start;
                total_seconds += elapsed_seconds;
                times.push_back(elapsed_seconds);
            }
            cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;
            delete g;
            delete graphFiller;

            ResultsEncoder* resultsEncoder = new ResultsEncoder();
            resultsEncoder->encodeResults("../results/NodeIterator/nIncreasing/FindNodeIteratorPlusPlusNIncreasing.txt", graphPath, "FindNodeIteratorPlusPlusNIncreasing", times, cpt); 
        }
    }

    static void testFindNodeIteratorPlusPlusMIncreasing(int nbRuns) {
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
            cout << "- Graph List VUS -"<< endl;
            cout << "Vertices: " << g->getNumVertices() << endl;
            cout << "Edges: " << g->getNumEdges() << endl;

            int cpt = 0;
            auto start = chrono::high_resolution_clock::now();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds;
            chrono::duration<double> total_seconds;
            vector<chrono::duration<double>> times;

            cout << "Graph: " << graphPath << " | Function: " << "FindNodeIteratorPlusPlusMIncreasing" << " NbRun: "<< nbRuns << endl;
            for (int i = 0; i < nbRuns; ++i) {
                //cout << "Run number: " << i << endl;
                start = chrono::high_resolution_clock::now();
                cpt = g->findTrianglesNodeIteratorPlusPlus().size();
                end = chrono::high_resolution_clock::now();
                elapsed_seconds = end-start;
                total_seconds += elapsed_seconds;
                times.push_back(elapsed_seconds);
            }
            cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;
            delete g;
            delete graphFiller;

            ResultsEncoder* resultsEncoder = new ResultsEncoder();
            resultsEncoder->encodeResults("../results/NodeIterator/mIncreasing/FindNodeIteratorPlusPlusMIncreasing.txt", graphPath, "FindNodeIteratorPlusPlusMIncreasing", times, cpt); 
        }
    }


    //================================================================

    static void testFindNodeIteratorPlusPlusLowMedHigh(int nbRuns) {
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
            cout << "- Graph List VUS -"<< endl;
            cout << "Vertices: " << g->getNumVertices() << endl;
            cout << "Edges: " << g->getNumEdges() << endl;

            int cpt = 0;
            auto start = chrono::high_resolution_clock::now();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds;
            chrono::duration<double> total_seconds;
            vector<chrono::duration<double>> times;

            cout << "Graph: " << graphPath << " | Function: " << "FindNodeIteratorPlusPlusLowMedHigh" << " NbRun: "<< nbRuns << endl;
            for (int i = 0; i < nbRuns; ++i) {
                //cout << "Run number: " << i << endl;
                start = chrono::high_resolution_clock::now();
                cpt = g->findTrianglesNodeIteratorPlusPlus().size();
                end = chrono::high_resolution_clock::now();
                elapsed_seconds = end-start;
                total_seconds += elapsed_seconds;
                times.push_back(elapsed_seconds);
            }
            cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;
            delete g;
            delete graphFiller;

            ResultsEncoder* resultsEncoder = new ResultsEncoder();
            resultsEncoder->encodeResults("../results/NodeIterator/lowmedhigh/FindNodeIteratorPlusPlusLowMedHigh.txt", graphPath, "FindNodeIteratorPlusPlusLowMedHigh", times, cpt); 
        }
    }

    static void testCountNodeIteratorPlusPlusLowMedHigh(int nbRuns) {
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
            cout << "- Graph List VUS -"<< endl;
            cout << "Vertices: " << g->getNumVertices() << endl;
            cout << "Edges: " << g->getNumEdges() << endl;

            int cpt = 0;
            auto start = chrono::high_resolution_clock::now();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds;
            chrono::duration<double> total_seconds;
            vector<chrono::duration<double>> times;

            cout << "Graph: " << graphPath << " | Function: " << "CountNodeIteratorPlusPlusLowMedHigh" << " NbRun: "<< nbRuns << endl;
            for (int i = 0; i < nbRuns; ++i) {
                //cout << "Run number: " << i << endl;
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
            resultsEncoder->encodeResults("../results/NodeIterator/lowmedhigh/CountNodeIteratorPlusPlusLowMedHigh.txt", graphPath, "CountNodeIteratorPlusPlusLowMedHigh", times, cpt); 
        }
    }

};

#endif