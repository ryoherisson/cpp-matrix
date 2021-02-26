#include <iostream>
#include <vector>
#include <Eigen/Core>
#include <Eigen/Geometry>

using namespace Eigen;
using namespace std;

int main() {

    MatrixXd A(3,3);
    A << 1,2,3, 4,5,6, 7,8,9;
    VectorXd v(2);
    v << 3,5;
    VectorXd a = A.diagonal(); // 行列の対角成分を要素とするベクトルへの変換
    MatrixXd V = v.asDiagonal(); // ベクトルの要素を対角成分とする対角行列への変換
    MatrixXd B = A.cwiseSqrt(); // 各要素を平方根に変換

    cout << A.trace() << endl << a << endl << V << endl; // .trace()は対角成分の和

    return 0;
}