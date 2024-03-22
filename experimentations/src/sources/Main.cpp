#include "../headers/Graph.hpp"
#include "../headers/Matrix.hpp"
#include "../headers/GraphFiller.hpp"
#include "../tests/TestMatrices.hpp"
#include "../tests/TestNodeIterators.hpp"
#include <chrono>
#include <thread>

using namespace std;

int main(int argc, char* argv[]){

    TestNodeIterators::testNodeIteratorsFacebook(10);

    return 0;
}

