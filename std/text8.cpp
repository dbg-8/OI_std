#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
template<typename T> T readIn() {
    T x(0), f(1);
    char ch = getchar();
    while (ch < '0' || ch > '9') {if (ch == '-') f = -1; ch = getchar();}
    while (ch >= '0' && ch <= '9') {x = x * 10 + ch - '0'; ch = getchar();}
    return x * f;
}
const int MAX_N = 100000 + 3;
const int MOD = 99999997;
const int INF = 0x3f3f3f3f;
int n;
int a[MAX_N], b[MAX_N];
int c[MAX_N], d[MAX_N];
int q[MAX_N];
int ans;

namespace fenwickTree {
    int vec[MAX_N];

    inline int lowbit(int x) {
        return x & (-x);
    }

    inline void modify(int id, int x) {
        while (id <= n) {
            vec[id] += x;
            id += lowbit(id);
        }
    }

    inline int query(int id) {
        int res = 0;
        while (id >= 1) {
            res += vec[id];
            id -= lowbit(id);
        }
        return res;
    }
}
using namespace fenwickTree;

// 60%
/*
inline void solve() {
    ans = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = i + 1; j <= n; ++j) if (i < j && q[i] > q[j]) {
            swap(q[i], q[j]);
            ++ans;
        }
    }
    printf("%d\n", (ans % MOD + MOD) % MOD);
}
*/


// 100%
inline void solve() {
    ans = 0;
    for (int i = n; i >= 1; --i) {
//        printf("%d %d\n", q[i], query(q[i] - 1));
        ans += query(q[i] - 1);
        modify(q[i], 1);
        if (ans >= MOD) ans -= MOD;
    }

    printf("%d\n", (ans % MOD + MOD) % MOD);
}


inline bool cmp1(int i, int j) {
    return a[i] < a[j];
}

inline bool cmp2(int i, int j) {
    return b[i] < b[j];
}

int main()
{
    n = readIn<int>();
    for (int i = 1; i <= n; ++i) a[i] = readIn<int>(), c[i] = i;
    for (int i = 1; i <= n; ++i) b[i] = readIn<int>(), d[i] = i;

    sort(c + 1, c + n + 1, cmp1); sort(d + 1, d + n + 1, cmp2);

    for (int i = 1; i <= n; ++i) printf("%d ", c[i]); printf("\n");
    for (int i = 1; i <= n; ++i) printf("%d ", d[i]); printf("\n");
    
    memset(q, 0, sizeof q);
    for (int i = 1; i <= n; ++i) q[c[i]] = d[i];
//    for (int i = 1; i <= n; ++i) printf("%d ", q[i]); printf("\n");

    solve();
    return 0;
}
