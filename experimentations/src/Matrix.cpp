#include "Matrix.hpp"
#include <iostream>
#include <thread>

using namespace std;

vector<vector<int>> operator+(const vector<vector<int>>& m1, const vector<vector<int>>& m2) {
    vector<vector<int>> result;

    if (m1.size() != m2.size() || m1.empty() || m1[0].size() != m2[0].size()) {
        cerr << "Error: Matrices must have the same dimensions for addition.\n";
        return result; // Returning empty matrix
    }

    result.resize(m1.size(), vector<int>(m1[0].size(), 0));

    for (size_t i = 0; i < m1.size(); ++i) {
        for (size_t j = 0; j < m1[i].size(); ++j) {
            result[i][j] = m1[i][j] + m2[i][j];
        }
    }

    return result;
}

vector<vector<int>> operator-(const vector<vector<int>>& m1, const vector<vector<int>>& m2) {
    vector<vector<int>> result;

    if (m1.size() != m2.size() || m1.empty() || m1[0].size() != m2[0].size()) {
        cerr << "Error: Matrices must have the same dimensions for subtraction.\n";
        return result; // Returning empty matrix
    }

    result.resize(m1.size(), vector<int>(m1[0].size(), 0));

    for (size_t i = 0; i < m1.size(); ++i) {
        for (size_t j = 0; j < m1[i].size(); ++j) {
            result[i][j] = m1[i][j] - m2[i][j];
        }
    }

    return result;
    
}

vector<vector<int>> Matrix::multiplyNaive(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2) {
    vector<vector<int>> result;
    int n = mat1.size();
    int m = mat2[0].size();
    int p = mat2.size();
    result.resize(n, vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        /*if(i%50 == 0)
            cout << "i: " << i << endl;*/
        for (int j = 0; j < m; ++j) {
            for (int k = 0; k < p; ++k) {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return result;
}

vector<vector<int>> Matrix::multiplyNaiveParallel(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2, int numThreads) {
    vector<vector<int>> result;
    int n = mat1.size();
    int m = mat2[0].size();
    int p = mat2.size();
    result.resize(n, vector<int>(m, 0));
    vector<thread> threads;
    int chunkSize = n / numThreads;
    for (int i = 0; i < numThreads; ++i) {
        threads.push_back(thread([i, chunkSize, &mat1, &mat2, &result, m, p, numThreads] {
            int start = i * chunkSize;
            int end = (i == numThreads - 1) ? mat1.size() : start + chunkSize;
            for (int i = start; i < end; ++i) {
                for (int j = 0; j < m; ++j) {
                    for (int k = 0; k < p; ++k) {
                        result[i][j] += mat1[i][k] * mat2[k][j];
                    }
                }
            }
        }));
    }
    for (auto& t : threads) {
        t.join();
    }
    return result;
}


vector<vector<int>> Matrix::multiplyStrassen(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2) {
    int n = mat1.size();

    if (n == 1) {
        vector<vector<int>> C(1, vector<int>(1, 0));
        C[0][0] = mat1[0][0] * mat2[0][0];
        return C;
    }

    int newSize = n / 2;
    vector<vector<int>> A11(newSize, vector<int>(newSize, 0));
    vector<vector<int>> A12(newSize, vector<int>(newSize, 0));
    vector<vector<int>> A21(newSize, vector<int>(newSize, 0));
    vector<vector<int>> A22(newSize, vector<int>(newSize, 0));

    vector<vector<int>> B11(newSize, vector<int>(newSize, 0));
    vector<vector<int>> B12(newSize, vector<int>(newSize, 0));
    vector<vector<int>> B21(newSize, vector<int>(newSize, 0));
    vector<vector<int>> B22(newSize, vector<int>(newSize, 0));

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

    vector<vector<int>> M1 = multiplyStrassen(A11 + A22, B11 + B22);
    vector<vector<int>> M2 = multiplyStrassen(A21 + A22, B11);
    vector<vector<int>> M3 = multiplyStrassen(A11, B12 - B22);
    vector<vector<int>> M4 = multiplyStrassen(A22, B21 - B11);
    vector<vector<int>> M5 = multiplyStrassen(A11 + A12, B22);
    vector<vector<int>> M6 = multiplyStrassen(A21 - A11, B11 + B12);
    vector<vector<int>> M7 = multiplyStrassen(A12 - A22, B21 + B22);

    vector<vector<int>> C11 = (M1 + M4) - (M5 - M7);
    vector<vector<int>> C12 = M3 + M5;
    vector<vector<int>> C21 = M2 + M4;
    vector<vector<int>> C22 = (M1 - M2) + (M3 + M6);

    vector<vector<int>> result(2 * newSize, vector<int>(2 * newSize, 0));
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
