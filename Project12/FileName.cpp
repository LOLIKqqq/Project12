#include <iostream>
#include <chrono>
#include <cmath>

using namespace std;

bool isPrime(int number, int approach) {
    if (number <= 1) { return false; }

    int limit;

    if (approach == 1) {
        limit = number;
    }
    else if (approach == 2) {
        limit = number / 2;
    }
    else {
        limit = sqrt(number);
    }

    for (int i = 2; i <= limit; ++i) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int number;
    cout << "Enter a number: ";
    cin >> number;

    for (int i = 1; i <= 3; ++i) {
        auto start = chrono::high_resolution_clock::now();
        bool prime = isPrime(number, i);
        auto end = chrono::high_resolution_clock::now();

        cout << "Approach " << i << " Result: " << (prime ? "Prime" : "Not Prime") << endl;
        cout << "Approach " << i << " Time: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;
    }

    return 0;
}