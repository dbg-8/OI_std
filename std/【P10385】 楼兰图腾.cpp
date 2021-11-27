#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
long long n, a[200003], l[200003], r[200003];
inline long long lowbit(long long x) {
	return x & (-x);
}
struct NODE {
	long long c[200003];
	inline void restart() {
		memset(c, 0ll, sizeof(c));
	}
	inline void add(long long x, long long d) {
		while (x <= n) {
			c[x] += d;
			x += lowbit(x);
		}
	}
	inline long long sum(long long x) {
		long long ret = 0;
		while (x > 0) {
			ret += c[x];
			x -= lowbit(x);
		}
		return ret;
	}
} t;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	t.restart();
	for (int i = 1; i <= n; i++) {
		l[i] = t.sum(a[i] - 1);
		t.add(a[i], 1);
	}
	t.restart();
	for (int i = n; i >= 1; i--) {
		r[i] = t.sum(a[i] - 1);
		t.add(a[i], 1);
	}
	long long ans1 = 0, ans2 = 0;
	for (int i = 2; i < n; i++) {
		ans1 += (i - 1 - l[i]) * (n - i - r[i]);
 		ans2 += l[i] * r[i];
	}
	printf ("%lld %lld\n", ans1, ans2);
	return 0;
}
