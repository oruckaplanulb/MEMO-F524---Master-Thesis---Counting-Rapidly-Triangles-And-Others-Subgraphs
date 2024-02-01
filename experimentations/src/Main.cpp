#include "Graph.hpp"

int main() {
    // Create a graph with 5 vertices using the matrix-based implementation
    Graph* graph = new GraphAdjacencyMatrixBased(3);

    // Add edges
    graph->addEdge(0, 1);
    graph->addEdge(0, 2);
    graph->addEdge(1, 2);

    // Print the graph
    std::cout << "Graph:" << std::endl;
    graph->printGraph();

    // Check if there is an edge between two vertices
    //std::cout << "Has edge between 1 and 3: " << (graph->hasEdge(1, 3) ? "Yes" : "No") << std::endl;
    //std::cout << "Has edge between 2 and 3: " << (graph->hasEdge(2, 3) ? "Yes" : "No") << std::endl;

    // Count the number of triangles using the node iterator
    std::cout << "Number of triangles: " << graph->countTrianglesNodeIterator() << std::endl;

    delete graph; // Don't forget to delete the dynamically allocated object

    return 0;
}

