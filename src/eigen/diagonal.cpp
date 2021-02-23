#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>

using namespace Eigen;

int main() {
    VectorXd v = VectorXd::Random(5);
    MatrixXd D = v.asDiagonal();

    std::cout << v << std::endl;
    std::cout << D << std::endl;

    return 0;
}