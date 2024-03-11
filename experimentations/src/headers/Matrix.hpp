#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <vector>

class Matrix {
public:
    static std::vector<std::vector<int>> multiplyNaive(const std::vector<std::vector<int>>& mat1, const std::vector<std::vector<int>>& mat2);
    static std::vector<std::vector<int>> multiplyNaiveParallel(const std::vector<std::vector<int>>& mat1, const std::vector<std::vector<int>>& mat2, int numThreads = 1);
    static std::vector<std::vector<int>> multiplyBlas(const std::vector<std::vector<int>>& A, const std::vector<std::vector<int>>& B);
    static std::vector<std::vector<int>> multiplyDivideConquer(const std::vector<std::vector<int>>& mat1, const std::vector<std::vector<int>>& mat2);
    static std::vector<std::vector<int>> multiplyStrassen(const std::vector<std::vector<int>>& mat1, const std::vector<std::vector<int>>& mat2);
};

#endif