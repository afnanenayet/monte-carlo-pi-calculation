#include <iostream>
#include <cmath>
#include <random>
#include <algorithm>
#include <iterator>

using namespace std;

// uses monte carlo method to estimate the value of pi
long double estimate_pi(long places) {
    long double n = pow(10, places);
    long double hits = 0;

    // init random number gen
    auto rng = std::default_random_engine(std::random_device{}());
    std::uniform_real_distribution<long double> dist(-1, 1);

    #pragma omp parallel for
    for (auto i = 0; i < n; i++) {
        auto x = dist(rng);
        auto y = dist(rng);

        if (sqrt(pow(x, 2) + pow(y, 2)) < 1) {
            #pragma omp atomic
            hits++;
        }
    }
    // hits \ n * (area of square)
    return (hits / n) * 4;
}

int main() {
    long n;
    cout << "Enter desired precision:\n";
    cin >> n;
    cout << "calculating pi...\n";

    auto pi = estimate_pi(n);
    cout << pi << endl;
    return 0;
}
