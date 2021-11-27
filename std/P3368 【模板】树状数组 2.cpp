#include <stdio.h>
#include <iostream>
using namespace std;
int n, m;
inline int lowbit (int x) {
	return x & (-x);
}
int a[500003];
struct NODE {
	int c[500003];
	inline void add(int x, int d) {
		while (x <= n) {
			c[x] += d;
			x += lowbit(x);
		}
	}
	inline int sum(int x) {
		int ret = 0;
		while (x > 0) {
			ret += c[x];
			x -= lowbit(x);
		}
		return ret;
	}
} t;
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
		scanf("%d", &a[i]);
	while (m--) {
		int d, x, y, z;
		scanf("%d %d", &d, &x);
		if (d == 1) {
			scanf("%d %d", &y, &z);
			t.add(x, z);
			t.add(y + 1, -z);
		}
		else 
			printf("%d\n", a[x] + t.sum(x));
	}
	return 0;
}
