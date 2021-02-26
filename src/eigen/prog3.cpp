// https://www01.do-johodai.ac.jp/IntroDataAnalysis/slides/cplusplus/slide2.html#7
#include <iostream>
#include <vector>
#include <fstream>
#include <Eigen/Dense>

using namespace Eigen;
using namespace std;

int main(int argc, char* argv[]) {
    string fileName = argv[1];
    ifstream ifile(fileName);
    vector<double> vec;
    double d;

    while (ifile >> d) {
        cout << d << " " << endl;

        vec.emplace_back(d);
    }

    MatrixXd X = Map<MatrixXd>(&(vec[0]), 3, 2).transpose();

    cout << X << endl;
    return 0;
}