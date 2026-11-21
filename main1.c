#include <stdio.h>
#include "contracts.h"

int main(void) {
    int cmd;
    while (scanf("%d", &cmd) == 1) {
        if (cmd == 1) {
            float a, b, e;
            if (scanf("%f %f %f", &a, &b, &e) != 3) return 1;
            printf("%f\n", sin_integral(a, b, e));
        } else if (cmd == 2) {
            int a, b;
            if (scanf("%d %d", &a, &b) != 2) return 1;
            printf("%d\n", prime_count(a, b));
        } else if (cmd == 0) {
            printf("switching is not supported\n");
        }
    }
    return 0;
}
