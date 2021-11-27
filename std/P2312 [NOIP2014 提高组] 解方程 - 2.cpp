#include <stdio.h>
#define ll long long
#define P 1000000007

int n;
ll m;
ll a[103];
ll ans[1000003];	int cnt = 0;

inline ll getbignum () {
	ll ret = 0, cs = 1;
	char ch;
	scanf("%c", &ch);
	if (ch == '-')	cs = -1;
	else	ret = ch - '0';
	while (scanf("%c", &ch) && ch >= '0' && ch <= '9')
		ret = (ret * 10 + ch - '0') % P;
	return ret * cs;
}

inline ll sovle (ll x) {
	ll ret = 0;
	ll xf = 1;
	for (int i = 0; i <= n; i++)
		ret = (ret + a[i] * xf) % P,
		xf = xf * x % P;
	return ret;
}

int main () {
	scanf("%d %lld ", &n, &m);
	for (int i = 0; i <= n; i++)
		a[i] = getbignum();
	for (ll x = 1; x <= m; x++)
		if (sovle(x) == 0)
			ans[++cnt] = x;
	printf("%d\n", cnt);
	for (int i = 1; i <= cnt; i++)
		printf("%lld\n", ans[i]);
	return 0;
}
