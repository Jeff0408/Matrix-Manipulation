
#include "matrix.hpp"
#include <iostream>
#include <vector>
#include <cstring>

// build matrix by indicated rows and column
void Matrix::constructMatrix() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << "Enter element at (" << i + 1 << "," << j + 1 << "): ";
            std::cin >> matrix[i][j];
        }
    }
    std::cout << std::endl;
}
// function to display matrix  
void Matrix::display() {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}
// funtion to  display result matrix with one argument
void Matrix::display_result(const Matrix& A) {
    for (int i = 0; i < A.rows; ++i) {
        for (int j = 0; j < A.cols; ++j) {
            std::cout << A.matrix[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}

// function to  multiply two matrix
void Matrix::multiply(const Matrix& other) {
    int otherCols = other.cols;
    Matrix ans(rows, otherCols);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < otherCols; ++j) {
            float val = 0;
            for (int k = 0; k < cols; ++k) {
                if (matrix[i][k] == 0 || other.matrix[k][j] == 0) continue;
                val += matrix[i][k] * other.matrix[k][j];
            }
            ans.matrix[i][j] = val;
        }
    }
    display_result(ans);
}

void Matrix::operator*(const Matrix& other) { multiply(other); }

// function to do transpose
void Matrix::transpose() {
    Matrix ans(cols, rows);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            ans.matrix[j][i] = matrix[i][j];
        }
    }
    display_result(ans);
}

// To do multiply with input by user
void Manipulation::matrixMultiply() {
    int firstRows = 0, firstCols = 0;
    int secondRows = 0, secondCols = 0;

    // get dimensions of two matrices
    std::cout << "Enter number of rows and columns for first matrix..." << std::endl;
    std::cout << "Number of rows: ";
    std::cin >> firstRows;
    std::cout << "Number of columns: ";
    std::cin >> firstCols;

    std::cout << "Enter number of rows and columns for second matrix..." << std::endl;
    std::cout << "Number of rows: ";
    std::cin >> secondRows;
    std::cout << "Number of columns: ";
    std::cin >> secondCols;
    std::cout << std::endl;

    // if invalid dim
    if (firstRows == 0 || firstCols == 0 || secondRows == 0 || secondCols == 0 ||
        std::isalpha(firstRows) || std::isalpha(firstCols) || std::isalpha(secondRows) ||
        std::isalpha(secondCols)) {
        std::cout << "Invalid matrix dimensions!" << std::endl;
        return;
    }
    if (firstCols != secondRows) {
        std::cout << "Matrix dimensions mismatch!" << std::endl;
        return;
    }

    // init
    Matrix A(firstRows, firstCols);
    Matrix B(secondRows, secondCols);

    // display
    std::cout << "Enter matrix element for first matrix..." << std::endl;
    A.constructMatrix();

    std::cout << "Enter matrix element for second matrix..." << std::endl;
    B.constructMatrix();

    std::cout << "First Matrix: " << std::endl;
    A.display();

    std::cout << "Second Matrix: " << std::endl;
    B.display();

    std::cout << "First Matrix * Second Matrix: " << std::endl;
    A.multiply(B);
}

// To do transpose with input by user
void Manipulation::matrixTranspose() {
    int rows = 0, cols = 0;

    // get dimensions of two matrices
    std::cout << "Enter number of rows and columns for first matrix..." << std::endl;
    std::cout << "Number of rows: ";
    std::cin >> rows;
    std::cout << "Number of columns: ";
    std::cin >> cols;
    std::cout << std::endl;

    // if invalid dim
    if (rows == 0 || cols == 0 || std::isalpha(rows) || std::isalpha(cols)) {
        std::cout << "Invalid matrix dimensions!" << std::endl;
        return;
    }

    // init
    Matrix A(rows, cols);
    A.constructMatrix();

    // display
    std::cout << "Original Matrix: " << std::endl;
    A.display();

    std::cout << "Transposed Matrix: " << std::endl;
    A.transpose();
}
