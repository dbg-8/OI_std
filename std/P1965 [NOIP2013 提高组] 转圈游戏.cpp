#include <stdio.h>
#define ll long long

inline ll power (ll a, ll b, const ll p) {	// return a ^ b % p
	register ll ans = 1ll;
	while (b) {
		if (b & 1)
			ans = ans * a % p;
		a = a * a % p;
		b = b >> 1;
	}
	return ans;
}

int main () {
	register ll n, m, k, nk = 1;
	register int x;
	scanf("%lld %lld %lld %d", &n, &m, &k, &x);
	nk = power(10ll, k, n);
	for (register int i = 1; i <= nk; i++)
		x = (x + m) % n;
	printf("%d\n", x);
	return 0;
} 
