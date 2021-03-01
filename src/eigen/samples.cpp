#include <iostream>
#include <Eigen/Dense>

int main() {

    // initialization
    // Eigen::MatrixXd X(3, 3);
    // X << 1, 2, 3, 4, 5, 6, 7, 8, 9;
    // Eigen::MatrixXd X = Eigen::MatrixXd::Zero(100, 3);
    // Eigen::MatrixXd X = Eigen::MatrixXd::Ones(100, 3);
    // Eigen::MatrixXd X = Eigen::MatrixXd::Random(100, 3);
    // Eigen::MatrixXd X = Eigen::MatrixXd::Identity(3, 3);

    // Resize
    // X.resize(X.rows()+1, X.cols()); // 要素を保持しない
    // X.conservativeResize(X.rows()+1, Eigen::NoChange); // 要素を保持する
    // std::cout << X << std::endl;

    Eigen::MatrixXd X = Eigen::MatrixXd::Random(10, 10);

    // 部分行列
    std::cout << X << std::endl;

    std::cout << "--row(3)--" << std::endl;
    std::cout << X.row(3) << std::endl;
    std::cout << "--topRows(5)--" << std::endl;
    std::cout << X.topRows(5) << std::endl;
    std::cout << "--bottomRows(5)--" << std::endl;
    std::cout << X.bottomRows(5) << std::endl;

    std::cout << "--col(3)--" << std::endl;
    std::cout << X.col(3) << std::endl;
    std::cout << "--leftCols(5)--" << std::endl;
    std::cout << X.leftCols(5) << std::endl;
    std::cout << "--rightCols(5)--" << std::endl;
    std::cout << X.rightCols(5) << std::endl;

    std::cout << "--block(2, 3, 4, 5)--" << std::endl;
    std::cout << X.block(2, 3, 4, 5) << std::endl;
    std::cout << "--topLeftCorner(2, 3)--" << std::endl;
    std::cout << X.topLeftCorner(2, 3) << std::endl;
    std::cout << "--topRightCorner(2, 3)--" << std::endl;
    std::cout << X.topRightCorner(2, 3) << std::endl;
    std::cout << "--bottomLeftCorner(2, 3)--" << std::endl;
    std::cout << X.bottomLeftCorner(2, 3) << std::endl;
    std::cout << "--bottomRightCorner(2, 3)--" << std::endl;
    std::cout << X.bottomRightCorner(2, 3) << std::endl;

    return 0;

}
