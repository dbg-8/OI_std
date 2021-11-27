#include <stdio.h>
#define ull unsigned long long

ull n, k, x = 1;

int main () {
	scanf("%llu %llu", &n, &k);
	for (ull i = 1; i <= n; i++)
		x = x << 1ull;
	ull l = 0ull, r = x - 1ull;
	bool flag = false;
	while (x != 1ull) {
		if (k < x >> 1ull)
			printf("0");
		else
			printf("1"), k = x - k - 1ll;
		x = x >> 1ull;
	}
	return 0;
}
