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
    std::cout << "---------" << std::endl;

    MatrixXd D(2, 4);
    D << 2, 3, 4, 5,
         6, 7, 8, 9;
    MatrixXd E = MatrixXd::Constant(2, 4, 2);

    std::cout << D << std::endl;
    std::cout << D(1, 0) << std::endl << D.rowwise().mean() << std::endl;
    std::cout << D.array() + E.array() << std::endl << D.array() * E.array() << std::endl;


    return 0;
}