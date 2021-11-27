#include <stdio.h>
#define ll long long

ll l, r;
ll k2[63];
ll ans = 0;

int main () {
	scanf("%lld %lld", &l, &r);
	if (l == r) {
		printf("0\n");
		return 0;
	}
	k2[0] = 1;
	for (int i = 1; i < 63; i++)
		k2[i] = k2[i - 1] * 2ll;
	for (int i = 63; i >= 0; i--) 
		if (l >> i != r >> i) {
			printf("%lld\n", k2[i] * 2 - 1);
			return 0;
		}
	return 0;
}  
