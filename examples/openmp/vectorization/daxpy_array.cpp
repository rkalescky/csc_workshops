#include <iostream>
#include <string>
#include <array>
#include <random>

int main(int argc, char* argv[]) {
    if (argc < 4) {
        std::cerr << "Usage: " << argv[0] << " i j k" << std::endl;
        return 1;
    }
    const unsigned long int m = std::stoul(argv[1]);
    const unsigned long int n = std::stoul(argv[2]);
    const unsigned long int p = std::stoul(argv[3]);
    std::array<std::array<double, m>, n> A;
    std::array<std::array<double, n>, p> B;
    std::array<std::array<double, m>, p> C;
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    A = dist(rng);
    B = dist(rng);
    C = 0;
    for (unsigned long int i; i < m; i++) {
        for (unsigned long int j; j < n; j++) {
            for (unsigned long int k; k < p; k++) {
                C[i][k] += A[i][j] * B[j][k];
            }
        }
    }
    return 0;
}

