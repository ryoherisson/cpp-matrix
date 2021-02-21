#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>

using namespace Eigen;

int main() {

    {
        Vector3f in(0.0f, 0.5f, 1.0f);

        Vector3f out = in.array() + 1.0f;
        std::cout << out << std::endl;
    }

    {
        Matrix3f in;
        in << 0.0f, 1.0f, 2.0f,
              3.0f, 4.0f, 5.0f,
              6.0f, 7.0f, 8.0f;
        Matrix3f out = in.array().sin();

        Matrix3f m;
        m << 0.0f, 0.0f, 1.0f,
             0.0f, 1.0f, 0.0f,
             1.0f, 0.0f, 0.0f;

        // 各要素同士の乗算・除算はこう書ける
        out = in.array() * m.array();
        std::cout << out << std::endl;

        // rows and cols
        std::cout << out.rows() << " " << out.cols() << std::endl;
    }

    return 0;
}