#include <stdio.h>
#include <iostream>
using namespace std;
inline int lowbit(int x) {
	return x & (-x);
}
int n, m;
struct NODE {
	int c[5000003];
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
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		t.add(i, x);
	}
	for (int i = 1; i <= m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1) 
			t.add(b, c);
		else
			printf("%d\n", t.sum(c) - t.sum(b - 1));
	}
	return 0;
} 
