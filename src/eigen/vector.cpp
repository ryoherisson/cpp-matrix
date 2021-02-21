#include <iostream>
#include <Eigen/Core>
#include <Eigen/Geometry>
using namespace Eigen;

int main() {

    // (1, 0, 0)
    Vector3f v;
    v = Vector3f::Identity();
    std::cout << v << std::endl;

    // (0, 0, 0)
    v = Vector3f::Zero();
    std::cout << v << std::endl;

    // (1, 1, 1)
    v = Vector3f::Ones();
    std::cout << v << std::endl;

    // (1, 0, 0)
    v = Vector3f::UnitX();
    std::cout << v << std::endl;

    // (0, 1, 0)
    v = Vector3f::UnitY();
    std::cout << v << std::endl;

    // (0, 0, 1)
    v = Vector3f::UnitZ();
    std::cout << v << std::endl;

    // Random
    // FIXME::std::rand() is used
    v = Vector3f::Random();
    std::cout << v << std::endl;

    // constant
    v = Vector3f::Constant(0.5f);
    std::cout << v << std::endl;

    // 各要素への読み書き
    float x, y, z;
    x = v.x();
    y = v.y();
    z = v.z();

    v.x() = x;
    v.y() = y;
    v.z() = z;

    v(0) = x;
    v(1) = y;
    v(2) = z;

    x = v[0];
    y = v[1];
    z = v[2];

    v << 0.5f, 1.2f, -2.0f;

    Vector3f v1;
    v1 = v;

    Vector3f v2;
    v2 = v + v1;
    v2 = v - v1;

    v1 = v.array() + 2.0f;
    std::cout << v1 << std::endl;

    v1 = v * 2.0f;
    v1 = v / 2.0f;

    // dot, cross
    float dot = v.dot(v1);
    Vector3f cross = v.cross(v1);

    // length
    float norm = v.norm();

    // vector with length 1
    Vector3f n = v.normalized();

    // normalization
    v.normalize();

    return 0;
}