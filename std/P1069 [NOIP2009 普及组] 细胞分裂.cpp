#include <stdio.h>
#define ll long long

int n;
ll a[10003];
ll m1, m2;
ll mm = 1;
ll ans = 0x3F3F3F3F;

int main () {
	scanf("%d %lld %lld", &n, &m1, &m2);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	for (int i = 1; i <= n; i++) {
		ll t = 0, cnt = 1;
		while (t < ans && t <= 1000000) {
			if (cnt % mm == 0)
				break;
			cnt = cnt * a[i];
			t++;
		}
		if (t != 10001 && t < ans)
			ans = t;
	}
	printf("%lld\n", ans == 0x3F3F3F3F ? -1 : ans);
	return 0;
}
