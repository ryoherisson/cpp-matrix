#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>

int main() {
    using namespace Eigen;

    Matrix3f m;

    // あらかじめ用意された値
    m = Matrix3f::Identity();
    m = Matrix3f::Zero();
    m = Matrix3f::Ones();
    m = Matrix3f::Random();
    m = Matrix3f::Constant(0.25f);

    // 行列の要素へのアクセス
    // matrix(列, 行)
    // 「行」が横方向のインデックス
    // 「列」が縦方向のインデックス
    // m2[0, 1] や m2[0][1] などの書き方はできない
    m(2, 0) = 1.0f;
    float value = m(0, 2);

    Matrix3f m1;
    m1 << 0.0f, 0.0f, 1.0f,
        0.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 0.0f;

    // 加算・減算
    Matrix3f m2;
    m2 = m + m1;
    m2 = m - m1;

    // 乗算・減算
    m2 = m * 2.0f;
    m2 = m / 2.0f;

    // 逆行列
    m2 = m.inverse();

    // 共役行列
    m2 = m.conjugate();

    {
        // 4x4行列の一部を切り取って3x3行列へコピー
        // | a b c d |    | a b c |
        // | e f g h | -> | e f g |
        // | i j k l |    | i j k |
        // | m n o p |
        Matrix4f m_in;
        m_in <<  0.0f,  1.0f,  2.0f,  3.0f,
                4.0f,  5.0f,  6.0f,  7.0f,
                8.0f,  9.0f, 10.0f, 11.0f,
                12.0f, 13.0f, 14.0f, 15.0f;

        Matrix3f m_out = m_in.block(0, 0, 3, 3);
        std::cout << m_out << std::endl;

        // 4x4行列の一部を切り取ってベクトルへコピー
        // | a b c d |
        // | e f g h | -> | g k o |
        // | i j k l |
        // | m n o p |
        Vector3f v_out = m_in.block(1, 2, 3, 1);
        std::cout << v_out << std::endl;
    }

    // 転置行列
    // | a b c |    | a d g |
    // | d e f | -> | b e h |
    // | g h i |    | c f i |
    m2 = m.transpose();

  return 0;
}