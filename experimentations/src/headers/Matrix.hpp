#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <vector>

/**
 * @brief
*/
class Matrix {
public:
    /**
     * @brief Multiply two matrices using the naive method.
    */
    static std::vector<std::vector<int>> multiplyNaive(const std::vector<std::vector<int>>& mat1, const std::vector<std::vector<int>>& mat2);
    /**
     * @brief Multiply two matrices using the naive method in parallel.
    */
    static std::vector<std::vector<int>> multiplyNaiveParallel(const std::vector<std::vector<int>>& mat1, const std::vector<std::vector<int>>& mat2, int numThreads = 1);
    /**
     * @brief Multiply two matrices using BLAS DGEMM.
    */
    static std::vector<std::vector<int>> multiplyBlasDGEMM(const std::vector<std::vector<int>>& mat1, const std::vector<std::vector<int>>& mat2, int num_threads = 1);
    /**
     * @brief Multiply two matrices using BLAS SGEMM.
    */
    static std::vector<std::vector<int>> multiplyBlasSGEMM(const std::vector<std::vector<int>>& mat1, const std::vector<std::vector<int>>& mat2, int num_threads = 1);
    /**
     * @brief Multiply two matrices using BLAS DSYMM.
    */
    static std::vector<std::vector<int>> multiplyBlasDSYMM(const std::vector<std::vector<int>>& mat1, const std::vector<std::vector<int>>& mat2, int num_threads = 1);
    /**
     * @brief Multiply two matrices using BLAS SSYMM.
    */
    static std::vector<std::vector<int>> multiplyBlasSSYMM(const std::vector<std::vector<int>>& mat1, const std::vector<std::vector<int>>& mat2, int num_threads = 1);
    /*DOES NOT WORK / NOT TESTED */
    static std::vector<std::vector<int>> multiplyDivideConquer(const std::vector<std::vector<int>>& mat1, const std::vector<std::vector<int>>& mat2);
    /*DOES NOT WORK / NOT TESTED */
    static std::vector<std::vector<int>> multiplyStrassen(const std::vector<std::vector<int>>& mat1, const std::vector<std::vector<int>>& mat2);
};

#endif