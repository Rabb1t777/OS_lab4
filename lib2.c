#include <math.h>
#include <stdlib.h>
#include "contracts.h"

float sin_integral(float a, float b, float e) {
    if (e <= 0.0f) return 0.0f;
    float s = 0.0f;
    for (float x = a; x < b; x += e) {
        float nx = (x + e > b) ? b : x + e;
        s += (sinf(x) + sinf(nx)) * (nx - x) / 2.0f;
    }
    return s;
}

int prime_count(int a, int b) {
    if (b < 2 || a > b) return 0;
    if (a < 2) a = 2;
    char *mark = calloc((size_t)b + 1, sizeof(char));
    if (!mark) return -1;
    for (long long i = 2; i * i <= b; ++i)
        if (!mark[i])
            for (long long j = i * i; j <= b; j += i)
                mark[j] = 1;
    int count = 0;
    for (int n = a; n <= b; ++n)
        if (!mark[n]) ++count;
    free(mark);
    return count;
}
