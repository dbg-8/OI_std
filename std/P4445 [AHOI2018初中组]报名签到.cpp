#include <stdio.h>

int main () {
	long long n, a, last, ans = 0;
	scanf("%lld %lld", &n, &last);
	for (int i = 2; i <= n; i++)
		scanf("%lld", &a),
		ans += last > a ? last : a,
		last = a;
	printf("%lld\n", ans);
	return 0;
} 
