#include <math.h>
#include "contracts.h"

float sin_integral(float a, float b, float e) {
    if (e <= 0.0f) return 0.0f;
    float s = 0.0f;
    for (float x = a; x < b; x += e) {
        float w = (x + e < b) ? e : b - x;
        s += sinf(x) * w;
    }
    return s;
}

int prime_count(int a, int b) {
    if (a < 2) a = 2;
    int count = 0;
    for (int n = a; n <= b; ++n) {
        int is_prime = 1;
        for (int d = 2; d < n; ++d) {
            if (n % d == 0) {
                is_prime = 0;
                break;
            }
        }
        count += is_prime;
    }
    return count;
}
