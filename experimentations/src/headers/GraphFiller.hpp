#ifndef GRAPHFILLER_HPP
#define GRAPHFILLER_HPP

#include "Graph.hpp"
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>

class GraphFiller{
public:
    GraphFiller() = default;

    /*template <typename T>
    void setGraphFromFile(const std::string &path, Graph<T> *g);*/

    void setGraphFromFileMapped(const std::string &path, Graph *g)
    {
        std::cout << "Path: " << path << std::endl;

        std::unordered_map<int, int> idMap;

        int nbV = 0;

        std::ifstream file(path);
        std::string line;
        if (file.is_open())
        {
            while (std::getline(file, line))
            {
                if (line.empty() || line[0] == '#')
                    continue;

                std::istringstream iss(line);
                int v1, v2;
                if (!(iss >> v1 >> v2))
                {
                    std::cerr << "Error reading edge from file." << std::endl;
                    continue;
                }

                if (idMap.find(v1) == idMap.end())
                {
                    idMap[v1] = nbV++;
                }
                if (idMap.find(v2) == idMap.end())
                {
                    idMap[v2] = nbV++;
                }
            }
            file.close();

            g->setSize(nbV);

            std::ifstream file2(path);
            if (file2.is_open())
            {
                while (std::getline(file2, line))
                {
                    if (line.empty() || line[0] == '#')
                        continue;

                    std::istringstream iss(line);
                    int v1, v2;
                    if (!(iss >> v1 >> v2))
                    {
                        std::cerr << "Error reading edge from file." << std::endl;
                        continue;
                    }

                    if (!g->hasEdge(idMap[v1], idMap[v2]) && idMap[v1] != idMap[v2])
                    {
                        g->addEdge(idMap[v1], idMap[v2]);
                    }
                }
                file2.close();
            }
            else
            {
                std::cerr << "Failed to open file: " << path << std::endl;
            }
        }
        else
        {
            std::cerr << "Failed to open file: " << path << std::endl;
        }
    }

private:
    //int getVertexMax(const std::string &path);
};

#endif