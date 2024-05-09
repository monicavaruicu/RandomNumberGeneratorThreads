#include <iostream>
#include <thread>
#include <vector>
#include <ctime>

unsigned long long midSquareRandom(unsigned long long seed, int iterations) {
    unsigned long long num = seed;
    unsigned long long result = 0;
    for (int i = 0; i < iterations; ++i) {
        num *= num;
        num /= 100;
        result = result * 10 + (num % 10);
    }
    return result;
}

unsigned long long linearCongruentialRandom(unsigned long long seed, unsigned long long a, unsigned long long c, unsigned long long m, int iterations) {
    unsigned long long num = seed;
    unsigned long long result = 0;
    for (int i = 0; i < iterations; ++i) {
        num = (a * num + c) % m;
        result = result * 10 + (num % 10);
    }
    return result;
}

int main() {
    unsigned long long seed = std::time(0);
    int iterations = 5; 

    std::thread midSquareThread([&]() {
        std::cout << "Metoda patratului mijlociu:\n";
        std::cout << "Rezultat: " << midSquareRandom(seed, iterations) << std::endl;
        });

    std::thread linearCongruentialThread([&]() {
        unsigned long long a = 1664525;
        unsigned long long c = 1013904223;
        unsigned long long m = 4294967296; // 2^32
        std::cout << "\nGeneratorul liniar congruential:\n";
        std::cout << "Rezultat: " << linearCongruentialRandom(seed, a, c, m, iterations) << std::endl;
        });

    midSquareThread.join();
    linearCongruentialThread.join();

    return 0;
}
