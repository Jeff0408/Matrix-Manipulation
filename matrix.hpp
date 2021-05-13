#include <iostream>
#include <vector>
#include <cstring>

//class to define matrices and do multiply and transpose
class Matrix {
    
    int rows, cols;
    std::vector<std::vector<float>> matrix;

   public:
    Matrix(int a, int b) : rows(a), cols(b), matrix(a, std::vector<float>(b, 0)) {}

    void constructMatrix();
    void display();
    void display_result(const Matrix& A);
    void multiply(const Matrix& other);
    void operator*(const Matrix& other);
    void transpose();

    
};

// class to do manpulation user can customize their input and get result of multiply and transpose
class Manipulation {
   public:
    Manipulation(){};
    void matrixMultiply();
    void matrixTranspose();

};
