#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <vector>

/**
 * @brief
*/
class Matrix {
public:
    /**
     * @brief
    */
    static std::vector<std::vector<int>> multiplyNaive(const std::vector<std::vector<int>>& mat1, const std::vector<std::vector<int>>& mat2);
    /**
     * @brief
    */
    static std::vector<std::vector<int>> multiplyNaiveParallel(const std::vector<std::vector<int>>& mat1, const std::vector<std::vector<int>>& mat2, int numThreads = 1);
    /**
     * @brief
    */
    static std::vector<std::vector<int>> multiplyBlasDGEMM(const std::vector<std::vector<int>>& mat1, const std::vector<std::vector<int>>& mat2, int num_threads = 1);
    /**
     * @brief
    */
    static std::vector<std::vector<int>> multiplyBlasSGEMM(const std::vector<std::vector<int>>& mat1, const std::vector<std::vector<int>>& mat2, int num_threads = 1);
    /**
     * @brief
    */
    static std::vector<std::vector<int>> multiplyBlasDSYMM(const std::vector<std::vector<int>>& mat1, const std::vector<std::vector<int>>& mat2, int num_threads = 1);
    /**
     * @brief
    */
    static std::vector<std::vector<int>> multiplyBlasSSYMM(const std::vector<std::vector<int>>& mat1, const std::vector<std::vector<int>>& mat2, int num_threads = 1);
    /*DOES NOT WORK / NOT TESTED */
    static std::vector<std::vector<int>> multiplyDivideConquer(const std::vector<std::vector<int>>& mat1, const std::vector<std::vector<int>>& mat2);
    /*DOES NOT WORK / NOT TESTED */
    static std::vector<std::vector<int>> multiplyStrassen(const std::vector<std::vector<int>>& mat1, const std::vector<std::vector<int>>& mat2);
};

#endif