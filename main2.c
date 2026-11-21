#include <stdio.h>
#include <dlfcn.h>
#include "contracts.h"

typedef float (*integral_fn)(float, float, float);
typedef int (*count_fn)(int, int);

int main(void) {
    const char *paths[2] = {"./libcalc1.so", "./libcalc2.so"};
    void *libs[2];
    integral_fn integral[2];
    count_fn count[2];
    for (int i = 0; i < 2; ++i) {
        libs[i] = dlopen(paths[i], RTLD_LAZY);
        if (!libs[i]) {
            fprintf(stderr, "%s\n", dlerror());
            return 1;
        }
        integral[i] = (integral_fn)dlsym(libs[i], "sin_integral");
        count[i] = (count_fn)dlsym(libs[i], "prime_count");
        if (!integral[i] || !count[i]) {
            fprintf(stderr, "%s\n", dlerror());
            return 1;
        }
    }
    int cur = 0;
    int cmd;
    while (scanf("%d", &cmd) == 1) {
        if (cmd == 0) {
            cur = 1 - cur;
            printf("implementation: %d\n", cur + 1);
        } else if (cmd == 1) {
            float a, b, e;
            if (scanf("%f %f %f", &a, &b, &e) != 3) break;
            printf("%f\n", integral[cur](a, b, e));
        } else if (cmd == 2) {
            int a, b;
            if (scanf("%d %d", &a, &b) != 2) break;
            printf("%d\n", count[cur](a, b));
        }
    }
    dlclose(libs[0]);
    dlclose(libs[1]);
    return 0;
}
