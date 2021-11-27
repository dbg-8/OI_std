#include <stdio.h>

#define f(x) (x == 1 ? 0 : 1)
struct NODE {
    int x, y;
    inline bool operator < (const NODE &rhs) const {
        return x < rhs.x;
    }
};

inline void kagari () {
    printf("I love kagari forever!!\n");
    return;
}

inline void sovle () {
    int x, y;
    scanf("%d %d", &x, &y);
    printf("%d\n", x + y);
}

int main () {
    kagari();
    sovle();
    return 0;
}
