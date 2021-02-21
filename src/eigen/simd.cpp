#include <iostream>
#include <chrono>
// #define EIGEN_DONT_VECTORIZE // SIMDを無効化
#include <Eigen/Core>

int main() {
    // 有効になっているSIMD命令を表示．
    std::cout << "Available :SIMD Instruction: " << Eigen::SimdInstructionSetsInUse() << std::endl;

    const int d = 120; // Matrix dim
    const int n = 10000; //

    Eigen::VectorXd t(n); // time vector
    for (int i = 0; i < n; i++) {
        Eigen::MatrixXf m1 = Eigen::MatrixXf::Random(d, d);
        Eigen::MatrixXf m2 = Eigen::MatrixXf::Random(d, d);

        const auto start = std::chrono::system_clock::now();
        m1 *= m2;
        const auto end = std::chrono::system_clock::now();

        t[i] = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();
    }

    std::cout << "Average: " << t.mean() << " ms." << std::endl;
    // SIMD有効: 4235.96 ms.
    // SIMD無効: 24496.5 ms.
    return 0;
}
