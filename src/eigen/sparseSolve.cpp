#include <iostream>
#include <vector>
#include <Eigen/Sparse>
#include <Eigen/Dense>
#include <Eigen/SparseQR>

typedef Eigen::Triplet<double> T;

int main()
{
    std::vector<T> tripletVec;

    tripletVec.push_back(T(0, 0, 0.2));
    tripletVec.push_back(T(0, 1, 0.5));
    tripletVec.push_back(T(1, 0, 1.0));
    tripletVec.push_back(T(1, 1, 2.0));

    Eigen::SparseMatrix<double> M(2, 2);
    M.setFromTriplets(tripletVec.begin(), tripletVec.end());
    std::cout << M << std::endl;

    Eigen::SparseMatrix<double> b(2, 1);
    std::vector<T> tripletVecb;
    tripletVecb.push_back(T(0, 0, 1.0));
    tripletVecb.push_back(T(1, 0, 2.0));
    b.setFromTriplets(tripletVecb.begin(), tripletVecb.end());
    std::cout << b << std::endl;

    Eigen::VectorXd x;

    Eigen::SparseQR<Eigen::SparseMatrix<double>, Eigen::COLAMDOrdering<int>> solver;
    solver.compute(M);

    if (solver.info() != Eigen::Success)
    {
        std::cerr << "decomposition failed" << std::endl;
    }
    x = solver.solve(b);
    if (solver.info() != Eigen::Success)
    {
        std::cerr << "solving failed" << std::endl;
    }
    std::cout << x << std::endl;

    return 0;
}