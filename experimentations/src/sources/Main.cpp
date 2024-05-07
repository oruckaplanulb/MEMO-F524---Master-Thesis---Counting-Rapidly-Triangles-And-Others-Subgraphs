#include "../headers/Graph.hpp"
#include "../headers/Matrix.hpp"
#include "../headers/GraphFiller.hpp"
#include "../tests/TestMatrices.hpp"
#include "../tests/TestNodeIterators.hpp"
#include "../tests/TestNodeIteratorsIndividual.hpp"
#include "../tests/TestNodeIteratorsAcceleration.hpp"
#include "../tests/TestForward.hpp"
#include "../tests/TestChibaNishizeki.hpp"
#include "../tests/Test4CycleCounting.hpp"
#include "../tests/TestExtra.hpp"
#include <chrono>
#include <thread>

using namespace std;

int main(int argc, char *argv[]){ 

    TestExtra::getGraphInfosNb4Cycles();


    return 0;
}
