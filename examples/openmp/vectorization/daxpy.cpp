#include <iostream>
#include <string>
#include <valarray>
#include <algorithm>
#include <random>

int main(int argc, char* argv[]) {
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " i j k" << std::endl;
        return 1;
    }
    unsigned long int m = std::stoul(argv[1]);
    unsigned long int n = std::stoul(argv[2]);
    unsigned long int p = std::stoul(argv[3]);
    std::valarray<double> A(m*n);
    std::valarray<double> B(n*p);
    std::valarray<double> C(m*p);
    std::valarray<double> D(m*p);
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    A = dist(rng);
    B = dist(rng);
    C = A*B;
    D = 0;
    for (unsigned long int i; i < m; i++) {
        for (unsigned long int j; j < n; j++) {
            for (unsigned long int k; k < p; k++) {
                D[] += A[i][j] * B[j][k];
            }
        }
    }
    std::cout << C-D << std::endl;
    return 0;
}

