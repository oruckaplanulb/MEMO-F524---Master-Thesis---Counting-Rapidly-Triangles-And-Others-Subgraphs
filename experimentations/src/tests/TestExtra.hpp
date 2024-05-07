#ifndef TESTEXTRA_HPP
#define TESTEXTRA_HPP

#include "../headers/Graph.hpp"
#include "../headers/Matrix.hpp"
#include "../headers/GraphFiller.hpp"
#include "../headers/ResultsEncoder.hpp"
#include <chrono>
#include <iostream>
#include <filesystem>

using namespace std;

class TestExtra {
public:

    static void getGraphInfos1() {
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
            delete graphFiller;
            cout << "- Graph -"<< endl;
            cout << "Vertices: " << g->getNumVertices() << endl;
            cout << "Edges: " << g->getNumEdges() << endl;

            auto start = chrono::high_resolution_clock::now();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds;
            double density = 0;
            double avgDegeneracy = 0;
            double avgClusteringCoefficient = 0;
            vector<int> clusteringCoefficientDistribution;

            string resultsPath = "../results/GraphsInfos/informations.txt";
            string result;

            cout << "Graph: " << graphPath << " - Infos"<< endl;
            result = "Graph: " + graphPath + " - Infos\n";

            start = chrono::high_resolution_clock::now();
            density = ((double)g->getNumEdges()) / ((double)g->getNumVertices() * ((double)g->getNumVertices() - 1)/2.0);
            end = chrono::high_resolution_clock::now();
            elapsed_seconds = end-start;
            cout << "Density: " << density << " | computed in: "<< elapsed_seconds.count()*1000 << "ms" << endl;
            result += "Density: " + to_string(density) + " | computed in: " + to_string(elapsed_seconds.count()*1000) + "ms\n";

            start = chrono::high_resolution_clock::now();
            avgDegeneracy = g->getAverageDegeneracy();
            end = chrono::high_resolution_clock::now();
            elapsed_seconds = end-start;
            cout << "Average Degeneracy: " << avgDegeneracy << " | computed in: "<< elapsed_seconds.count()*1000 << "ms" << endl;
            result += "Average Degeneracy: " + to_string(avgDegeneracy) + " | computed in: " + to_string(elapsed_seconds.count()*1000) + "ms\n";

            start = chrono::high_resolution_clock::now();
            avgClusteringCoefficient = g->getAverageClusturingCoefficient();
            end = chrono::high_resolution_clock::now();
            elapsed_seconds = end-start;
            cout << "Average Clustering Coefficient: " << avgClusteringCoefficient << " | computed in: "<< elapsed_seconds.count()*1000 << "ms" << endl;
            result += "Average Clustering Coefficient: " + to_string(avgClusteringCoefficient) + " | computed in: " + to_string(elapsed_seconds.count()*1000) + "ms\n";

            start = chrono::high_resolution_clock::now();
            clusteringCoefficientDistribution = g->getClusturingCoefficientDistribution(10);
            end = chrono::high_resolution_clock::now();
            elapsed_seconds = end-start;
            cout << "Clustering Coefficient Distribution: " << " (computed in: "<< elapsed_seconds.count()*1000 << "ms)" << endl;
            result += "Clustering Coefficient Distribution: (computed in: " + to_string(elapsed_seconds.count()*1000) + "ms)\n";
            double ccdsize = clusteringCoefficientDistribution.size();
            for (int i = 0; i < clusteringCoefficientDistribution.size(); i++){
                cout << "Clustering coefficient " << i/ccdsize << " - " << (i+1)/ccdsize << ": " << clusteringCoefficientDistribution[i] << endl;
                result += "Clustering coefficient " + to_string(i/ccdsize) + " - " + to_string((i+1)/ccdsize) + ": " + to_string(clusteringCoefficientDistribution[i]) + "\n";
            }

            //write results to file
            ResultsEncoder* resultsEncoder = new ResultsEncoder();

            resultsEncoder->write(resultsPath, result);

            delete g;

        }
    }

    static void getGraphInfosNb4Cycles() {

        vector<string> graphsPaths;
        for (const auto& entry : filesystem::recursive_directory_iterator("../graphs")) {
        if (entry.is_regular_file() && entry.path().extension() == ".txt") {
            if (entry.path().parent_path() != filesystem::path("../graphs")) {
                auto s = entry.path().string();
                std::replace(s.begin(), s.end(), '\\', '/');
                cout << s << endl;
                graphsPaths.push_back(s);
            }
        }
        }

        //for each graph Path
        for (const string& graphPath : graphsPaths) {
            GraphFiller* graphFiller = new GraphFiller();
            GraphAdjListVV* g = new GraphAdjListVV();
            graphFiller->setGraphFromFileMapped(graphPath, g);
            delete graphFiller;
            cout << "- Graph -"<< endl;
            cout << "Vertices: " << g->getNumVertices() << endl;
            cout << "Edges: " << g->getNumEdges() << endl;

            auto start = chrono::high_resolution_clock::now();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds;
            long long int nb4Cycles = 0;

            string resultsPath = "../results/GraphsInfos/4cyclecountinformations.txt";
            string result;

            cout << "Graph: " << graphPath << " - Infos"<< endl;
            result = "Graph: " + graphPath + " - Infos\n";

            start = chrono::high_resolution_clock::now();
            nb4Cycles = g->count4CyclesBasic();
            end = chrono::high_resolution_clock::now();
            elapsed_seconds = end-start;
            cout << "Nb 4-cycles: " << nb4Cycles << " | computed in: "<< elapsed_seconds.count()*1000 << "ms" << endl;
            result += "Nb 4-cycles: " + to_string(nb4Cycles) + " | computed in: " + to_string(elapsed_seconds.count()*1000) + "ms\n";

            //write results to file
            ResultsEncoder* resultsEncoder = new ResultsEncoder();

            resultsEncoder->write(resultsPath, result);

            delete g;

        }
    }

};

#endif