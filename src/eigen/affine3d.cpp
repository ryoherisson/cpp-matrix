#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>

int main() {
  using namespace Eigen;

    // 3D
    {
        // 平行移動(x, y, z)
        Translation<float, 3> translation = Translation<float, 3>(10.0f, 0.5f, -3.0f);

        // スケーリング
        DiagonalMatrix<float, 3> scaling = Scaling(2.0f, 1.5f, 1.0f);

        // 回転(クォータニオン)
        Quaternionf rotate(AngleAxisf(0.2f, Vector3f::UnitY()));

        // アフィン変換用行列
        Affine3f matrix;

        // 色々掛け合わせて、変換行列を求める
        matrix = translation * scaling * rotate;

        // p0を変換行列で変換してp1に格納
        Vector3f p0(1.0f, -1.0f, 0.5f);
        Vector3f p1 = matrix * p0;

        std::cout << "p1:\n" << p1 << std::endl;

        Vector3f v1(1.0f, 0.0f, -1.0f);
        Vector3f v2;

        // 行列を介さずとも座標変換が可能
        // これがすごく便利
        v2 = translation * v1;
        v2 = scaling * v1;
        v2 = rotate * v1;
        v2 = translation * scaling * rotate * v1;

        std::cout << "v2:\n" << v2 << std::endl;

        // 汎用的な行列への変換にはメンバ関数matrixを使う
        Matrix4f& m = matrix.matrix();
    }

    // 2D
    {
        // 回転
        Rotation2Df rotate(3.1415f);

        // 平行移動
        Translation<float, 2> translation = Translation<float, 2>(10.0f, 0.5f);

        // スケーリング
        DiagonalMatrix<float, 2> scaling = Scaling(2.0f, 1.5f);

        // アフィン変換用の行列
        Affine2f m;
        m = rotate * translation * scaling;

        Vector2f v1(1.0f, 0.0f);
        Vector2f v2;
        v2 = m * v1;

        // 2Dの場合も横着して座標変換の計算をまとめて書ける
        v2 = rotate * translation * scaling * v1;
    }

    return 0;
}
