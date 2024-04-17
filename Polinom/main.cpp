#include "Polynomial.h"

int main() {
    Polynomial fib[10], poly;
    Monomial zero(0, 0), one(1, 0), x(1, 1);
    fib[0].vec.push_back(zero);
    cout << "  F[0] = 0 \n";
    for (int i = 1; i < 10; ++i) {
        if (i < 2) fib[i].vec.push_back(one);
        else {
            fib[i] = x * fib[i - 1];
            fib[i] = fib[i] + fib[i - 2];
        }
        cout << "  F[" << i << "] = " << fib[i];
    }
}