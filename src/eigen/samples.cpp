#include <iostream>
#include <Eigen/Dense>

int main() {

    // initialization
    Eigen::MatrixXd X(3, 3);
    X << 1, 2, 3, 4, 5, 6, 7, 8, 9;
    // Eigen::MatrixXd X = Eigen::MatrixXd::Zero(100, 3);
    // Eigen::MatrixXd X = Eigen::MatrixXd::Ones(100, 3);
    // Eigen::MatrixXd X = Eigen::MatrixXd::Random(100, 3);
    // Eigen::MatrixXd X = Eigen::MatrixXd::Identity(3, 3);

    // Resize
    // X.resize(X.rows()+1, X.cols()); // 要素を保持しない
    X.conservativeResize(X.rows()+1, Eigen::NoChange); // 要素を保持する

    std::cout << X << std::endl;

}
