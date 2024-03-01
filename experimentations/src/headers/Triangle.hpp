#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <functional>
#include <vector>
#include "Graph.hpp"

class Triangle
{
public:
    template <typename T>
    static int countTrianglesNodeIterator(const Graph<T> *g)
    {
        double count = 0;
        for (int v = 0; v < g->getNumVertices(); ++v)
        {
            for (const int &u : g->getNeighbors(v))
            {
                for (const int &w : g->getNeighbors(v))
                {
                    if (g->hasEdge(u, w))
                    {
                        count = count + 0.5;
                    }
                }
            }
        }
        return count / 3;
    }

    template <typename T>
    static int countTrianglesNodeIteratorPlusPlus(const Graph<T> *g){
        int count = 0;
        for (int v = 0; v < g->getNumVertices(); ++v){
            for (const int &u : g->getNeighbors(v)){
                if (g->isBiggerOrder(u, v)){
                    for (const int &w : g->getNeighbors(v)){
                        if (g->isBiggerOrder(w, u) && g->hasEdge(u, w)){
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }

    static int countTrianglesMatrixSquaring(const std::vector<std::vector<int>> &m, std::function<std::vector<std::vector<int>>(const std::vector<std::vector<int>> &, const std::vector<std::vector<int>> &, int)> multiplyFunc, int numThreads);
    static int countTrianglesMatrixSquaring(const std::vector<std::vector<int>> &m, std::function<std::vector<std::vector<int>>(const std::vector<std::vector<int>> &, const std::vector<std::vector<int>> &)> multiplyFunc);
    static int countTrianglesMatrixCube(const std::vector<std::vector<int>> &m, std::function<std::vector<std::vector<int>>(const std::vector<std::vector<int>> &, const std::vector<std::vector<int>> &, int)> multiplyFunc, int numThreads);
    static int countTrianglesMatrixCube(const std::vector<std::vector<int>> &m, std::function<std::vector<std::vector<int>>(const std::vector<std::vector<int>> &, const std::vector<std::vector<int>> &)> multiplyFunc);
    template <typename T>
    static int AYZ_Algorithm(const Graph<T> *g);
};

#endif