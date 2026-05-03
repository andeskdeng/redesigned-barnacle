#include <iostream>
#include <vector>
#include <cmath>

void generatePrimes(int limit) {
    // Create a boolean vector "isPrime[0..limit]" and initialize
    // all entries it as true. 
    std::vector<bool> isPrime(limit + 1, true);
    
    isPrime[0] = isPrime[1] = false; // 0 and 1 are not prime

    for (int p = 2; p * p <= limit; p++) {
        // If isPrime[p] is not changed, then it is a prime
        if (isPrime[p]) {
            // Update all multiples of p greater than or equal to the square of it
            // numbers which are multiple of p and are less than p^2 
            // are already been marked.
            for (int i = p * p; i <= limit; i += p)
                isPrime[i] = false;
        }
    }

    // Print all prime numbers
    std::cout << "Prime numbers up to " << limit << ":" << std::endl;
    for (int p = 2; p <= limit; p++) {
        if (isPrime[p]) {
            std::cout << p << " ";
        }
    }
    std::cout << std::endl;
}

int main() {
    int n;
    std::cout << "Enter the limit to generate primes: ";
    std::cin >> n;

    if (n < 2) {
        std::cout << "There are no primes less than 2." << std::endl;
    } else {
        generatePrimes(n);
    }

    return 0;
}
