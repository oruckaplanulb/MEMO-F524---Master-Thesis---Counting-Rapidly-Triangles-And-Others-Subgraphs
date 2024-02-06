#include "matrix.hpp"
#include <iostream>

std::vector<std::vector<int>> operator+(const std::vector<std::vector<int>>& m1, const std::vector<std::vector<int>>& m2) {
    std::vector<std::vector<int>> result;

    // Check if matrices have same dimensions
    if (m1.size() != m2.size() || m1.empty() || m1[0].size() != m2[0].size()) {
        std::cerr << "Error: Matrices must have the same dimensions for addition.\n";
        return result; // Returning empty matrix
    }

    // Resize the result matrix
    result.resize(m1.size(), std::vector<int>(m1[0].size(), 0));

    // Perform matrix addition
    for (size_t i = 0; i < m1.size(); ++i) {
        for (size_t j = 0; j < m1[i].size(); ++j) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }

    return result;
}

std::vector<std::vector<int>> operator-(const std::vector<std::vector<int>>& m1, const std::vector<std::vector<int>>& m2) {
    std::vector<std::vector<int>> result;

    // Check if matrices have same dimensions
    if (m1.size() != m2.size() || m1.empty() || m1[0].size() != m2[0].size()) {
        std::cerr << "Error: Matrices must have the same dimensions for subtraction.\n";
        return result; // Returning empty matrix
    }

    // Resize the result matrix
    result.resize(m1.size(), std::vector<int>(m1[0].size(), 0));

    // Perform matrix subtraction
    for (size_t i = 0; i < m1.size(); ++i) {
        for (size_t j = 0; j < m1[i].size(); ++j) {
            result[i][j] = m1[i][j] - m2[i][j];
        }
    }

    return result;
    
}

std::vector<std::vector<int>> Matrix::multiplyNaive(const std::vector<std::vector<int>>& mat1, const std::vector<std::vector<int>>& mat2) {
    std::vector<std::vector<int>> result;
    int n = mat1.size();
    int m = mat2[0].size();
    int p = mat2.size();
    result.resize(n, std::vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < p; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return result;
}

std::vector<std::vector<int>> Matrix::multiplyStrassen(const std::vector<std::vector<int>>& mat1, const std::vector<std::vector<int>>& mat2) {
    int n = mat1.size();

    // Base case
    if (n == 1) {
        std::vector<std::vector<int>> C(1, std::vector<int>(1, 0));
        C[0][0] = mat1[0][0] * mat2[0][0];
        return C;
    }

    // Split matrices into quadrants
    int newSize = n / 2;
    std::vector<std::vector<int>> A11(newSize, std::vector<int>(newSize, 0));
    std::vector<std::vector<int>> A12(newSize, std::vector<int>(newSize, 0));
    std::vector<std::vector<int>> A21(newSize, std::vector<int>(newSize, 0));
    std::vector<std::vector<int>> A22(newSize, std::vector<int>(newSize, 0));

    std::vector<std::vector<int>> B11(newSize, std::vector<int>(newSize, 0));
    std::vector<std::vector<int>> B12(newSize, std::vector<int>(newSize, 0));
    std::vector<std::vector<int>> B21(newSize, std::vector<int>(newSize, 0));
    std::vector<std::vector<int>> B22(newSize, std::vector<int>(newSize, 0));

    for (int i = 0; i < newSize; ++i) {
        for (int j = 0; j < newSize; ++j) {
            A11[i][j] = mat1[i][j];
            A12[i][j] = mat1[i][j + newSize];
            A21[i][j] = mat1[i + newSize][j];
            A22[i][j] = mat1[i + newSize][j + newSize];

            B11[i][j] = mat2[i][j];
            B12[i][j] = mat2[i][j + newSize];
            B21[i][j] = mat2[i + newSize][j];
            B22[i][j] = mat2[i + newSize][j + newSize];
        }
    }

    // Calculate intermediate matrices
    std::vector<std::vector<int>> M1 = multiplyStrassen(A11 + A22, B11 + B22);
    std::vector<std::vector<int>> M2 = multiplyStrassen(A21 + A22, B11);
    std::vector<std::vector<int>> M3 = multiplyStrassen(A11, B12 - B22);
    std::vector<std::vector<int>> M4 = multiplyStrassen(A22, B21 - B11);
    std::vector<std::vector<int>> M5 = multiplyStrassen(A11 + A12, B22);
    std::vector<std::vector<int>> M6 = multiplyStrassen(A21 - A11, B11 + B12);
    std::vector<std::vector<int>> M7 = multiplyStrassen(A12 - A22, B21 + B22);

    // Calculate resulting quadrants
    std::vector<std::vector<int>> C11 = (M1 + M4) - (M5 - M7);
    std::vector<std::vector<int>> C12 = M3 + M5;
    std::vector<std::vector<int>> C21 = M2 + M4;
    std::vector<std::vector<int>> C22 = (M1 - M2) + (M3 + M6);

    // Combine resulting quadrants into the result matrix
    std::vector<std::vector<int>> result(2 * newSize, std::vector<int>(2 * newSize, 0));
    for (int i = 0; i < newSize; ++i) {
        for (int j = 0; j < newSize; ++j) {
            result[i][j] = C11[i][j];
            result[i][j + newSize] = C12[i][j];
            result[i + newSize][j] = C21[i][j];
            result[i + newSize][j + newSize] = C22[i][j];
        }
    }
    return result;
}
