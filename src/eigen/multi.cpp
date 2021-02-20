#include <iostream>
#include <Eigen/Dense>
using namespace Eigen;

int main() {

    Matrix2d mat;
    mat << 1, 2,
           3, 4;
    std::cout << "mat * 2.5 = \n" << mat * 2.5 << std::endl;
    std::cout << "mat * mat = \n" << mat * mat << std::endl;

    Vector3d v(1, 2, 3);
    Vector3d w(1, 2, 3);
    std::cout << "Dot product: \n" << v.dot(w) << std::endl;
    std::cout << "Cross product: \n" << v.cross(w) << std::endl;

    return 0;
}
