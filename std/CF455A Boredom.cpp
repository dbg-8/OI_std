#include <stdio.h>
#include <algorithm>
#define ll long long
#define max(x, y) ((x) > (y) ? (x) : (y))

int n, m = 0;
ll a[100003];
ll d[100005];
ll ans = 0;

int main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		a[x]++;
	}
	d[1] = a[1];
	for (int i = 1; i <= 100000; i++) {	
		d[i] = max(d[i - 1], d[i - 2] + a[i] * (ll)i);
		ans = max(ans, d[i]);
	}
	printf("%lld\n", ans);
	return 0;
}
