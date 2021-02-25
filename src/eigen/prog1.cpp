#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>

using namespace Eigen;

int main() {
    MatrixXd A = MatrixXd::Ones(3, 2);
    VectorXd v = VectorXd::Constant(2, 7);
    MatrixXd B = MatrixXd::Constant(2, 3, 5);
    MatrixXd C = A.transpose();

    std::cout << C * A << std::endl << (A * v).transpose() << std::endl;
    return 0;
}