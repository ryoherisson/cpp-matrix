#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>

using namespace Eigen;

int main() {
    MatrixXd A_orig = MatrixXd::Random(3, 3);
    MatrixXd A_dump = A_orig; // Deep Copy

    A_orig(0, 0) = 1111;

    std::cout << A_orig << std::endl << std::endl;

    std::cout << A_dump << std::endl << std::endl;

    // swapping
    std::cout << "  (Swapping A_orig <--> A_dump)" << std::endl << std::endl;
    A_orig.swap(A_dump);

    std::cout << A_orig << std::endl << std::endl;
    std::cout << A_dump << std::endl << std::endl;

    return 0;
}