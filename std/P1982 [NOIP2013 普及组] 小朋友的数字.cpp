#include <stdio.h>
#define ll long long
#define max(x, y) ((x) > (y) ? (x) : (y))

int n;
ll P;
ll a[1000003];	// 手上数字 
ll b[1000003];	// 特征值 
ll c[1000003];	// 分数 
ll d[1000003];	// d[i] = max(b[j] + c[j]), 1 <= j <= i 
ll ans;

int main () {
	//freopen("P1982_2.in", "r", stdin);
	scanf("%d %lld", &n, &P);
	for (int i = 0; i <= n; i++)
		b[i] = c[i] = d[i] = -P - 1ll;
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	b[1] = a[1] % P;
	for (int i = 2; i <= n; i++)
		if (b[i - 1] > 0)
			b[i] = b[i - 1] + a[i];
		else
			b[i] = a[i];
	for (int i = 2; i <= n; i++)
		b[i] = max(b[i], b[i - 1]);
	c[1] = b[1];
	d[1] = c[1] + b[1];
	for (int i = 2; i <= n; i++)
		c[i] = max(d[i - 2], c[i - 1] + b[i - 1]),
		d[i - 1] = max(d[i - 2], c[i - 1] + b[i - 1]);
	ans = -P - 1ll;
	for (int i = 1; i <= n; i++)
		ans = max(ans, (c[i])) % P;
	printf("%lld\n", ans);
	return 0;
} 
