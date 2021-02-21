#include <iostream>

#include <Eigen/Core>
using namespace Eigen;

int main() {
    // DefaultはColMajor
    Matrix<int, 2, 3> m;
    m <<
        1, 2, 3,
        4, 5, 6;

    for (int i = 0; i < m.size(); i++) {
        std::cout << *(m.data()+i) << " "; // 1, 4, 2, 3, 5, 6
    }
    std::cout << std::endl;

    // RowMajor
    Matrix<int, 2, 3, RowMajor> m2;
    m2 <<
        1, 2, 3,
        4, 5, 6;

    for (int i = 0; i < m2.size(); i++) {
        std::cout << *(m2.data()+i) << " "; // 1, 2, 3, 4, 5, 6
    }
    std::cout << std::endl;

    return 0;
}