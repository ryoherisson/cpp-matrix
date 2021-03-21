#include <iostream>
#include <vector>
#include <Eigen/Core>
#include <Eigen/Sparse>

typedef Eigen::Triplet<double> T;

int main()
{
    std::vector<T> tripletVec;

    tripletVec.push_back(T(0, 0, 0.2));
    tripletVec.push_back(T(0, 1, 0.5));
    tripletVec.push_back(T(1, 0, 1.5));
    tripletVec.push_back(T(1, 1, 2.0));

    Eigen::SparseMatrix<double> M(2, 2);
    M.setFromTriplets(tripletVec.begin(), tripletVec.end());
    std::cout << M << std::endl;

    Eigen::MatrixXd D(2, 2);
    D << 3, 2,
        1, 4;
    std::cout << "M*D: " << M * D << std::endl;

    return 0;
}