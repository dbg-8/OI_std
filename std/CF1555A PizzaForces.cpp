#include <stdio.h>
#define ll long long
int main() {
	int t;
	scanf("%d", &t);
	while (t--) {
		ll x;
		scanf("%lld", &x);
		printf("%lld\n", x <= 6ll ? 15ll : (x + (x % 2 ? 1 : 0)) / 2 * 5);
	}
	return 0;
}
