#include <stdio.h>
#define ll long long
#define max(x, y) ((x) > (y) ? (x) : (y))

int n, m;
ll a[2000003];
ll b[2000003];
ll sa[2000003];
ll sb[2000003];

int main () {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]), a[i + n] = a[i];
	for (int i = 1; i <= n; i++)
		scanf("%lld", &b[i]), b[i + n] = b[i];
	for (int i = 1; i <= 2 * n; i++)
		sa[i] = sa[i - 1] + a[i],
		sb[i] = sb[i - 1] + b[i];
	ll sr = 0, ans = -10000000000000000ll;
	for (int i = 1; i <= m; i++)
		sr += i * b[i];
	ans = sa[m] - sr;
	for (int i = m + 1; i + m <= 2 * n; i++) {
		sr = sr - (sb[i - 1] - sb[i - m - 1]) + b[i] * m;
		ll ret = sa[i] - sa[i - m] - sr;
		ans = max(ans, ret);
	}
	printf("%lld\n", ans);
	return 0;
} 
