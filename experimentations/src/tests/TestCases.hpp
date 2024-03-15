#ifndef TESTCASES_HPP
#define TESTCASES_HPP

#include "../headers/Graph.hpp"
#include "../headers/Matrix.hpp"
#include "../headers/GraphFiller.hpp"
#include <chrono>
#include <iostream>

using namespace std;

class TestCases {
public:
    static void testGnutellasNodeIterator(int nbRuns) {
        string path = "../graphs/p2p-Gnutella/";
        vector<string> graphsNames = {"p2p-Gnutella08","p2p-Gnutella09","p2p-Gnutella06",
                                                "p2p-Gnutella05","p2p-Gnutella04","p2p-Gnutella25",
                                                "p2p-Gnutella24","p2p-Gnutella30","p2p-Gnutella31"};
        vector<string> avgtimes;
        vector<int> results;

        for (const string& graphName : graphsNames) {
            GraphFiller* graphFiller = new GraphFiller();
            GraphAdjListVUS* graphListVUS = new GraphAdjListVUS();
            graphFiller->setGraphFromFileMapped(path+graphName+".txt", graphListVUS);
            cout << "- Graph List VUS-"<< endl;
            cout << "Vertices: " << graphListVUS->getNumVertices() << endl;
            cout << "Edges: " << graphListVUS->getNumEdges() << endl;

            int cpt = 0;
            auto start = chrono::high_resolution_clock::now();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds;
            chrono::duration<double> total_seconds;
            for (int i = 0; i < 100; ++i) {
                start = chrono::high_resolution_clock::now();
                cpt = graphListVUS->countTrianglesNodeIterator();
                end = chrono::high_resolution_clock::now();
                elapsed_seconds = end-start;
                total_seconds += elapsed_seconds;
                //cout << "Number of triangles NodeIterator: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << endl;
            }
            cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;
            avgtimes.push_back(to_string(total_seconds.count()*(1000/nbRuns)));
            results.push_back(cpt);
            delete graphListVUS;
            delete graphFiller;
        }
        cout << "======================" << endl;
        cout << "NodeIterator Average times: " << endl;
        for (int i = 0; i < graphsNames.size(); ++i) {
            cout << graphsNames[i] << ": " << avgtimes[i] << "ms" << " result:"<< results[i] << endl;
        }
    }

    static void testGnutellasNodeIteratorPlusPlus(int nbRuns) {
        string path = "../graphs/p2p-Gnutella/";
        vector<string> graphsNames = {"p2p-Gnutella08","p2p-Gnutella09","p2p-Gnutella06",
                                                "p2p-Gnutella05","p2p-Gnutella04","p2p-Gnutella25",
                                                "p2p-Gnutella24","p2p-Gnutella30","p2p-Gnutella31"};
        vector<string> avgtimes;
        vector<int> results;


        for (const string& graphName : graphsNames) {
            GraphFiller* graphFiller = new GraphFiller();
            GraphAdjListVUS* graphListVUS = new GraphAdjListVUS();
            graphFiller->setGraphFromFileMapped(path+graphName+".txt", graphListVUS);
            cout << "- Graph List VUS-"<< endl;
            cout << "Vertices: " << graphListVUS->getNumVertices() << endl;
            cout << "Edges: " << graphListVUS->getNumEdges() << endl;

            int cpt = 0;
            auto start = chrono::high_resolution_clock::now();
            auto end = chrono::high_resolution_clock::now();
            chrono::duration<double> elapsed_seconds;
            chrono::duration<double> total_seconds;
            for (int i = 0; i < 100; ++i) {
                start = chrono::high_resolution_clock::now();
                cpt = graphListVUS->countTrianglesNodeIteratorPlusPlus();
                end = chrono::high_resolution_clock::now();
                elapsed_seconds = end-start;
                total_seconds += elapsed_seconds;
                //cout << "Number of triangles NodeIteratorPlusPlus: " << cpt << " ("<< elapsed_seconds.count()*1000 << "ms)" << endl;
            }
            cout << "Average time: " << total_seconds.count()*(1000/nbRuns) << "ms" << endl;
            avgtimes.push_back(to_string(total_seconds.count()*(1000/nbRuns)));
            results.push_back(cpt);
            delete graphListVUS;
            delete graphFiller;
        }
        cout << "======================" << endl;
        cout << "NodeIteratorPlusPlus Average times: " << endl;
        for (int i = 0; i < graphsNames.size(); ++i) {
            cout << graphsNames[i] << ": " << avgtimes[i] << "ms" << " result:"<< results[i] << endl;
        }
    }
};

#endif