#ifndef UTILS_HPP
#define UTILS_HPP

#include "Graph.hpp"
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <chrono>

using namespace std;

class Utils {
public:
    Utils() = default;

    int comb(int n, int k) {
        int result = 1;
        for (int i = 1; i <= k; ++i) {
            result *= (n - k + i);
            result /= i;
        }
        return result;
    }
};


#endif