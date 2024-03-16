#ifndef TESTMATRICES_HPP
#define TESTMATRICES_HPP

#include "../headers/Graph.hpp"
#include "../headers/Matrix.hpp"
#include "../headers/GraphFiller.hpp"
#include "../headers/ResultsEncoder.hpp"
#include <chrono>
#include <iostream>

using namespace std;

class TestMatrices {
public:
    static void testCubeNIncreasingNaive(int nbRuns) {
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
            cout << "- Graph Matrix VV-"<< endl;
            cout << "Vertices: " << graphMatrixVV->getNumVertices() << endl;
            cout << "Edges: " << graphMatrixVV->getNumEdges() << endl;

            int cpt = 0;
            auto start = chrono::high_resolution_clock::now();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds;
            chrono::duration<double> total_seconds;
            vector<chrono::duration<double>> times;

            cout << "Graph: " << graphPath << " | Function: " << "MatrixCubingNaive" << " NbRun: "<< nbRuns << endl;
            for (int i = 0; i < nbRuns; ++i) {
                cout << "Run number: " << i << endl;
                start = chrono::high_resolution_clock::now();
                cpt = graphMatrixVV->countTrianglesMatrixCube(Matrix::multiplyNaiveParallel,1); //1 thread
                end = chrono::high_resolution_clock::now();
                elapsed_seconds = end-start;
                total_seconds += elapsed_seconds;
                times.push_back(elapsed_seconds);
            }
            cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;
            delete graphMatrixVV;
            delete graphFiller;

            ResultsEncoder* resultsEncoder = new ResultsEncoder();
            resultsEncoder->encodeResults("../results/MatrixVV/CubeNaiveNIncreasing.txt", graphPath, "MatrixCubingNaive", times, cpt); 
        }
    }

    static void testSquareNIncreasingNaive(int nbRuns) {
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
            cout << "- Graph Matrix VV-"<< endl;
            cout << "Vertices: " << graphMatrixVV->getNumVertices() << endl;
            cout << "Edges: " << graphMatrixVV->getNumEdges() << endl;

            int cpt = 0;
            auto start = chrono::high_resolution_clock::now();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds;
            chrono::duration<double> total_seconds;
            vector<chrono::duration<double>> times;

            cout << "Graph: " << graphPath << " | Function: " << "MatrixSquaringNaive" << " NbRun: "<< nbRuns << endl;
            for (int i = 0; i < nbRuns; ++i) {
                cout << "Run number: " << i << endl;
                start = chrono::high_resolution_clock::now();
                cpt = graphMatrixVV->countTrianglesMatrixSquaring(Matrix::multiplyNaiveParallel,1); //1 thread
                end = chrono::high_resolution_clock::now();
                elapsed_seconds = end-start;
                total_seconds += elapsed_seconds;
                times.push_back(elapsed_seconds);
            }
            cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;
            delete graphMatrixVV;
            delete graphFiller;

            ResultsEncoder* resultsEncoder = new ResultsEncoder();
            resultsEncoder->encodeResults("../results/MatrixVV/SquareNaiveNIncreasing.txt", graphPath, "MatrixSquaringNaive", times, cpt); 
        }
    }

    static void testCubeNIncreasingSGEMM(int nbRuns) {
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
            cout << "- Graph Matrix VV-"<< endl;
            cout << "Vertices: " << graphMatrixVV->getNumVertices() << endl;
            cout << "Edges: " << graphMatrixVV->getNumEdges() << endl;

            int cpt = 0;
            auto start = chrono::high_resolution_clock::now();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds;
            chrono::duration<double> total_seconds;
            vector<chrono::duration<double>> times;

            cout << "Graph: " << graphPath << " | Function: " << "MatrixCubingSGEMM" << " NbRun: "<< nbRuns << endl;
            for (int i = 0; i < nbRuns; ++i) {
                cout << "Run number: " << i << endl;
                start = chrono::high_resolution_clock::now();
                cpt = graphMatrixVV->countTrianglesMatrixCube(Matrix::multiplyBlasSGEMM,1); //1 thread
                end = chrono::high_resolution_clock::now();
                elapsed_seconds = end-start;
                total_seconds += elapsed_seconds;
                times.push_back(elapsed_seconds);
            }
            cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;
            delete graphMatrixVV;
            delete graphFiller;

            ResultsEncoder* resultsEncoder = new ResultsEncoder();
            resultsEncoder->encodeResults("../results/MatrixVV/CubeSGEMMNIncreasing.txt", graphPath, "MatrixCubingSGEMM", times, cpt); 
        }
    }

    static void testSquareNIncreasingSGEMM(int nbRuns) {
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
            cout << "- Graph Matrix VV-"<< endl;
            cout << "Vertices: " << graphMatrixVV->getNumVertices() << endl;
            cout << "Edges: " << graphMatrixVV->getNumEdges() << endl;

            int cpt = 0;
            auto start = chrono::high_resolution_clock::now();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds;
            chrono::duration<double> total_seconds;
            vector<chrono::duration<double>> times;

            cout << "Graph: " << graphPath << " | Function: " << "MatrixSquaringSGEMM" << " NbRun: "<< nbRuns << endl;
            for (int i = 0; i < nbRuns; ++i) {
                cout << "Run number: " << i << endl;
                start = chrono::high_resolution_clock::now();
                cpt = graphMatrixVV->countTrianglesMatrixSquaring(Matrix::multiplyBlasSGEMM,1); //1 thread
                end = chrono::high_resolution_clock::now();
                elapsed_seconds = end-start;
                total_seconds += elapsed_seconds;
                times.push_back(elapsed_seconds);
            }
            cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;
            delete graphMatrixVV;
            delete graphFiller;

            ResultsEncoder* resultsEncoder = new ResultsEncoder();
            resultsEncoder->encodeResults("../results/MatrixVV/SquareSGEMMNIncreasing.txt", graphPath, "MatrixSquaringSGEMM", times, cpt); 
        }
    }

    static void testCubeNIncreasingSSYMM(int nbRuns) {
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
            cout << "- Graph Matrix VV-"<< endl;
            cout << "Vertices: " << graphMatrixVV->getNumVertices() << endl;
            cout << "Edges: " << graphMatrixVV->getNumEdges() << endl;

            int cpt = 0;
            auto start = chrono::high_resolution_clock::now();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds;
            chrono::duration<double> total_seconds;
            vector<chrono::duration<double>> times;

            cout << "Graph: " << graphPath << " | Function: " << "MatrixCubingSSYMM" << " NbRun: "<< nbRuns << endl;
            for (int i = 0; i < nbRuns; ++i) {
                cout << "Run number: " << i << endl;
                start = chrono::high_resolution_clock::now();
                cpt = graphMatrixVV->countTrianglesMatrixCube(Matrix::multiplyBlasSSYMM,1); //1 thread
                end = chrono::high_resolution_clock::now();
                elapsed_seconds = end-start;
                total_seconds += elapsed_seconds;
                times.push_back(elapsed_seconds);
            }
            cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;
            delete graphMatrixVV;
            delete graphFiller;

            ResultsEncoder* resultsEncoder = new ResultsEncoder();
            resultsEncoder->encodeResults("../results/MatrixVV/CubeSSYMMNIncreasing.txt", graphPath, "MatrixCubingSSYMM", times, cpt); 
        }
    }

    static void testSquareNIncreasingSSYMM(int nbRuns) {
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
            cout << "- Graph Matrix VV-"<< endl;
            cout << "Vertices: " << graphMatrixVV->getNumVertices() << endl;
            cout << "Edges: " << graphMatrixVV->getNumEdges() << endl;

            int cpt = 0;
            auto start = chrono::high_resolution_clock::now();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds;
            chrono::duration<double> total_seconds;
            vector<chrono::duration<double>> times;

            cout << "Graph: " << graphPath << " | Function: " << "MatrixSquaringSSYMM" << " NbRun: "<< nbRuns << endl;
            for (int i = 0; i < nbRuns; ++i) {
                cout << "Run number: " << i << endl;
                start = chrono::high_resolution_clock::now();
                cpt = graphMatrixVV->countTrianglesMatrixSquaring(Matrix::multiplyBlasSSYMM,1); //1 thread
                end = chrono::high_resolution_clock::now();
                elapsed_seconds = end-start;
                total_seconds += elapsed_seconds;
                times.push_back(elapsed_seconds);
            }
            cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;
            delete graphMatrixVV;
            delete graphFiller;

            ResultsEncoder* resultsEncoder = new ResultsEncoder();
            resultsEncoder->encodeResults("../results/MatrixVV/SquareSSYMMNIncreasing.txt", graphPath, "MatrixSquaringSSYMM", times, cpt); 
        }
    }
        
};

#endif