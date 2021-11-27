#include <stdio.h>
#define ll long long
#define abs(x) ((x) < 0 ? -(x) : (x))
#define max(x, y) ((x) > (y) ? (x) : (y))

int n, m = 0;
ll a[100003];
ll b[100003];
ll d[100003];

inline ll sovle (int p) {
	ll ret = 0;
	d[0] = d[1] = 0;
	for (int i = (p == 1 ? 1 : 2); i <= n; i++)
		d[i] = max(d[i - 1], i % 2 == p ? 0 : d[i - 1]) + b[i] * (i % 2 == p ? 1 : -1),
		ret = max(ret, d[i]);
	return ret;
} 

int main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	for (int i = 1; i < n; i++)
		b[i] = abs(a[i] - a[i + 1]);
	ll x = sovle(1), y = sovle(0);
	printf("%lld\n", max(x, y));
	return 0;
} 
