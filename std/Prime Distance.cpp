#include <stdio.h>
#include <string.h>
#define ll long long
#define max(x, y) ((x) > (y) ? (x) : (y))
#define re register
#define SMN 50000	// sqrt(maxR)

ll l, r;
ll prime[50003], cnt = 0;
bool isp[50003];
bool isp2[1000003];	// isp2[i]: l + i 是否是质数 

inline void getprime (ll cur) {
	for (ll i = 2; i <= cur; i++) {
		if (!isp[i])
			continue;
		for (ll j = i; i * j <= cur; j++)
			isp[i * j] = false;
	}
}

inline void kagari () {
	memset(isp2, true, sizeof(isp2));
	if (l == 1)
		isp[0] = false;
	ll last = -1, minx = 2147483647, min1 = -1, min2 = 0, maxx = 0, max1 = 0, max2 = 0;
	for (ll i = 1; i <= cnt; i++)
		for (ll j = l / prime[i]; j <= r / prime[i]; j++)
			if (prime[i] * j - l >= 0 && j >= 2)
				isp2[prime[i] * j - l] = false;
	for (ll i = l; i <= r; i++) 
		if (isp2[i - l]) {
			if (last != -1) {
				if (i - last < minx)
					minx = i - last, min1 = last, min2 = i;
				if (i - last > maxx)
					maxx = i - last, max1 = last, max2 = i;
			}
			last = i;
		}
	if (min1 != -1)
		printf("%lld,%lld are closest, %lld,%lld are most distant.\n", min1, min2, max1, max2);
	else
		printf("There are no adjacent primes.\n");
	return;
}

int main () {
	memset(isp, true, sizeof(isp));
	getprime(SMN);
	for (int i = 2; i <= SMN; i++)
		if (isp[i])
			prime[++cnt] = i;
	while (~scanf("%lld %lld", &l, &r))
		kagari();
	return 0;
}
