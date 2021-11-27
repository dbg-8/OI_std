#include <stdio.h>
#define max(x, y) ((x) > (y) ? (x) : (y))
#define abs(x) ((x) > 0 ? (x) : (-(x)))
#define ll long long

int n, a[100003];
ll s1 = 0ll, s2 = 0ll;

int main () {
	scanf("%d", &n);
	for (register int i = 1; i <= n; i++)
		scanf("%d", &a[i]),
		a[0] = a[i],
		s1 += (ll)max(a[i] - a[i - 1], 0),
		s2 += (ll)max(a[i - 1] - a[i], 0);
	printf("%lld\n%lld\n", max(s1, s2), abs(s1 - s2) + 1);
	return 0;
}
