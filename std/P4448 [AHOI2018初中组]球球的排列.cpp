#include <stdio.h>
#include <math.h>
#define ll long long
#define P 1000000007

int n;
ll a[303];
bool ch[303][303];
int d[303][303];

inline bool isnp (ll x) {
	register ll l = 1, r = 1e9;
	while (l < r) {
		register ll mid = (l + r) >> 1;
		if (mid * mid >= x)
			r = mid;
		else
			l = mid + 1;
	}	
	return (l * l != x);
}

int main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j)
				ch[i][j] = isnp(a[i] * a[j]);
	for (int len = 1; len <= n; len++)
		for (int l = 1, r = l + len - 1; r <= n; l++, r++) 
			for (int k = 1; )
	return 0;
}
