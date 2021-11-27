#include <stdio.h>
#define ll long long

int n;
ll f0 = 0ll, f1 = 0ll;

int main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		ll x;
		scanf("%lld", &x);
		if (i % 2 == 0)
			f0 += x >> 1ll,
			f1 += x - (x >> 1ll);
		else
			f1 += x >> 1ll,
			f0 += x - (x >> 1ll);
	}
	printf("%lld\n", (f1 < f0 ? f1 : f0));
	return 0;
} 
