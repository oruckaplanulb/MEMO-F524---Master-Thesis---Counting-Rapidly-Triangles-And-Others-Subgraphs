#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <functional>
#include <vector>
#include "Graph.hpp"

class Triangle
{
public:
    template <typename T>
    static int countTrianglesNodeIterator(Graph<T> *g){
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
    static int countTrianglesNodeIteratorPlusPlus(Graph<T> *g){
        int count = 0;
        for (int v = 0; v < g->getNumVertices(); ++v)
        {
            for (const int &u : g->getNeighbors(v))
            {
                if (g->isBiggerOrder(u, v))
                {
                    for (const int &w : g->getNeighbors(v))
                    {
                        if (g->isBiggerOrder(w, u) && g->hasEdge(u, w))
                        {
                            count++;
                        }
                    }
                }
            }
        }
        return count;
    }
    
    template <typename T>
    static int AYZ_Algorithm(Graph<T> *g);
};

#endif