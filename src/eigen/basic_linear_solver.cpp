#include <iostream>
#include <Eigen/Dense>

using namespace Eigen;

int main() {
    Matrix3f A;
    Vector3f b;
    A << 1,2,3, 4,5,6, 7,8,10;
    b << 3, 3, 4;
    std::cout << "Here is the matrix A:\n" << A << std::endl;
    std::cout << "Here is the matrix b:\n" << A << std::endl;

    // ColPivHouseholderQR<Matrix3f> dec(A);
    // Vector3f x = dec.solve(b);
    Vector3f x = A.colPivHouseholderQr().solve(b);
    std::cout << "The solution is:\n" << x << std::endl;

    return 0;
}