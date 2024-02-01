#include "Graph.hpp"

int main() {
    // Create a graph with 5 vertices using the matrix-based implementation
    Graph* graph = new GraphAdjacencyMatrixBased(3);
    Graph* graph2 = new GraphAdjacencyListBased(3);

    // Add edges
    graph->addEdge(0, 1);
    graph->addEdge(0, 2);
    graph->addEdge(1, 2);
    graph2->addEdge(0, 1);
    graph2->addEdge(0, 2);
    graph2->addEdge(1, 2);

    // Print the graph
    std::cout << "Graph:" << std::endl;
    graph->printGraph();
    std::cout << "Graph2:" << std::endl;
    graph2->printGraph();

    // Check if there is an edge between two vertices
    //std::cout << "Has edge between 1 and 3: " << (graph->hasEdge(1, 3) ? "Yes" : "No") << std::endl;
    //std::cout << "Has edge between 2 and 3: " << (graph->hasEdge(2, 3) ? "Yes" : "No") << std::endl;

    // Count the number of triangles using the node iterator
    std::cout << "Number of triangles: " << graph->countTrianglesNodeIterator() << std::endl;
    std::cout << "Number of triangles: " << graph2->countTrianglesNodeIterator() << std::endl;

    delete graph; // Don't forget to delete the dynamically allocated object
    delete graph2;

    return 0;
}

