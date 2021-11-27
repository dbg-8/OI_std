#include <stdio.h>
#include <algorithm>
#define ll long long

int n;
int a[100003], b[100003];

int main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d %d", &a[i], &b[i]);
	std:: sort(a + 1, a + n + 1);
	std:: sort(b + 1, b + n + 1);
	ll ans = (ll)n;
	for (int i = 1; i <= n; i++)
		ans += (ll)(a[i] > b[i] ? a[i] : b[i]);
	printf("%lld\n", ans);
	return 0;
}
