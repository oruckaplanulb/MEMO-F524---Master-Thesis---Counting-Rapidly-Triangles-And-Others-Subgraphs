#ifndef TESTGENERALISATION_HPP
#define TESTGENERALISATION_HPP

#include "../headers/Graph.hpp"
#include "../headers/Matrix.hpp"
#include "../headers/GraphFiller.hpp"
#include "../headers/ResultsEncoder.hpp"
#include <chrono>
#include <iostream>

using namespace std;

class TestGeneralisation {
public:
    static void testNIncreasingSSYMM(int nbRuns) {
        vector<string> graphsPaths = {  "../graphs/Network-gtc/email-eu-core.txt",
                                        "../graphs/Social-Network/ego-facebook.txt",
                                        "../graphs/Social-Network/wiki-Vote.txt",
                                        "../graphs/Collaboration-Network/CA-HepPh.txt",
                                        "../graphs/p2p-Gnutella/p2p-Gnutella25.txt",
                                        "../graphs/Citation-Network/Cit-HepTh.txt"};

        //for each graph Path
        for (const string& graphPath : graphsPaths) {
            GraphFiller* graphFiller = new GraphFiller();
            GraphAdjMatrixVV* graphMatrixVV = new GraphAdjMatrixVV();
            graphFiller->setGraphFromFileMapped(graphPath, graphMatrixVV);
            delete graphFiller;
            cout << "- Graph Matrix VV-"<< endl;
            cout << "Vertices: " << graphMatrixVV->getNumVertices() << endl;
            cout << "Edges: " << graphMatrixVV->getNumEdges() << endl;

            long long int cpt = 0;
            auto start = chrono::high_resolution_clock::now();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds;
            chrono::duration<double> total_seconds;
            vector<chrono::duration<double>> timesCube;
            vector<chrono::duration<double>> timesPOW4;
            vector<chrono::duration<double>> timesPOW5;
            ResultsEncoder* resultsEncoder = new ResultsEncoder();

            cout << "Graph: " << graphPath << " | Function: " << "MatrixCubingSSYMM" << " NbRun: "<< nbRuns << endl;
            for (int i = 0; i < nbRuns; ++i) {
                //cout << "Run number: " << i << endl;
                start = chrono::high_resolution_clock::now();
                cpt = graphMatrixVV->countTrianglesMatrixCube(Matrix::multiplyBlasSSYMM,1); //1 thread
                end = chrono::high_resolution_clock::now();
                elapsed_seconds = end-start;
                total_seconds += elapsed_seconds;
                timesCube.push_back(elapsed_seconds);
            }
            cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;
            total_seconds = chrono::duration<double>();
            resultsEncoder->encodeResults("../results/Generalisation/NIncreasingSSYMM.txt", graphPath, "MatrixCubingSSYMM", timesCube, cpt); 

            cout << "Graph: " << graphPath << " | Function: " << "MatrixPow4SSYMM" << " NbRun: "<< nbRuns << endl;
            for (int i = 0; i < nbRuns; ++i) {
                //cout << "Run number: " << i << endl;
                start = chrono::high_resolution_clock::now();
                cpt = graphMatrixVV->count4CyclesMatrixPow4(Matrix::multiplyBlasSSYMM,1); //1 thread
                end = chrono::high_resolution_clock::now();
                elapsed_seconds = end-start;
                total_seconds += elapsed_seconds;
                timesPOW4.push_back(elapsed_seconds);
            }
            cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;
            total_seconds = chrono::duration<double>();
            resultsEncoder->encodeResults("../results/Generalisation/NIncreasingSSYMM.txt", graphPath, "MatrixPow4SSYMM", timesPOW4, cpt);

            cout << "Graph: " << graphPath << " | Function: " << "MatrixPow5SSYMM" << " NbRun: "<< nbRuns << endl;
            for (int i = 0; i < nbRuns; ++i) {
                //cout << "Run number: " << i << endl;
                start = chrono::high_resolution_clock::now();
                cpt = graphMatrixVV->count5CyclesMatrixPow5(Matrix::multiplyBlasSSYMM,1); //1 thread
                end = chrono::high_resolution_clock::now();
                elapsed_seconds = end-start;
                total_seconds += elapsed_seconds;
                timesPOW5.push_back(elapsed_seconds);
            }
            cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;
            total_seconds = chrono::duration<double>();
            resultsEncoder->encodeResults("../results/Generalisation/NIncreasingSSYMM.txt", graphPath, "MatrixPow5SSYMM", timesPOW5, cpt); 

            delete graphMatrixVV;
        }
    }

    static void testNIncreasingNaive(int nbRuns) {
        vector<string> graphsPaths = {  "../graphs/Network-gtc/email-eu-core.txt",
                                        "../graphs/Social-Network/ego-facebook.txt",
                                        "../graphs/Social-Network/wiki-Vote.txt"};

        //for each graph Path
        for (const string& graphPath : graphsPaths) {
            GraphFiller* graphFiller = new GraphFiller();
            GraphAdjMatrixVV* graphMatrixVV = new GraphAdjMatrixVV();
            graphFiller->setGraphFromFileMapped(graphPath, graphMatrixVV);
            delete graphFiller;
            cout << "- Graph Matrix VV-"<< endl;
            cout << "Vertices: " << graphMatrixVV->getNumVertices() << endl;
            cout << "Edges: " << graphMatrixVV->getNumEdges() << endl;

            long long int cpt = 0;
            auto start = chrono::high_resolution_clock::now();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds;
            chrono::duration<double> total_seconds;
            vector<chrono::duration<double>> timesCube;
            vector<chrono::duration<double>> timesPOW4;
            vector<chrono::duration<double>> timesPOW5;
            ResultsEncoder* resultsEncoder = new ResultsEncoder();

            cout << "Graph: " << graphPath << " | Function: " << "MatrixCubingNaive" << " NbRun: "<< nbRuns << endl;
            for (int i = 0; i < nbRuns; ++i) {
                cout << "Run number: " << i << endl;
                start = chrono::high_resolution_clock::now();
                cpt = graphMatrixVV->countTrianglesMatrixCube(Matrix::multiplyNaiveParallel,1); //1 thread
                end = chrono::high_resolution_clock::now();
                elapsed_seconds = end-start;
                total_seconds += elapsed_seconds;
                timesCube.push_back(elapsed_seconds);
            }
            cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;
            total_seconds = chrono::duration<double>();
            resultsEncoder->encodeResults("../results/Generalisation/NIncreasingNaive.txt", graphPath, "MatrixCubingNaive", timesCube, cpt); 

            cout << "Graph: " << graphPath << " | Function: " << "MatrixPow4Naive" << " NbRun: "<< nbRuns << endl;
            for (int i = 0; i < nbRuns; ++i) {
                cout << "Run number: " << i << endl;
                start = chrono::high_resolution_clock::now();
                cpt = graphMatrixVV->count4CyclesMatrixPow4(Matrix::multiplyNaiveParallel,1); //1 thread
                end = chrono::high_resolution_clock::now();
                elapsed_seconds = end-start;
                total_seconds += elapsed_seconds;
                timesPOW4.push_back(elapsed_seconds);
            }
            cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;
            total_seconds = chrono::duration<double>();
            resultsEncoder->encodeResults("../results/Generalisation/NIncreasingNaive.txt", graphPath, "MatrixPow4Naive", timesPOW4, cpt);

            cout << "Graph: " << graphPath << " | Function: " << "MatrixPow5Naive" << " NbRun: "<< nbRuns << endl;
            for (int i = 0; i < nbRuns; ++i) {
                cout << "Run number: " << i << endl;
                start = chrono::high_resolution_clock::now();
                cpt = graphMatrixVV->count5CyclesMatrixPow5(Matrix::multiplyNaiveParallel,1); //1 thread
                end = chrono::high_resolution_clock::now();
                elapsed_seconds = end-start;
                total_seconds += elapsed_seconds;
                timesPOW5.push_back(elapsed_seconds);
            }
            cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;
            total_seconds = chrono::duration<double>();
            resultsEncoder->encodeResults("../results/Generalisation/NIncreasingNaive.txt", graphPath, "MatrixPow5Naive", timesPOW5, cpt); 

            delete graphMatrixVV;
        }
    }
};

#endif