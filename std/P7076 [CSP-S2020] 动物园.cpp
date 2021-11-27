#include <stdio.h>
#define ull unsigned long long
using namespace std;

ull n, m, c, k;
ull ic, nc;
ull ans;

int main(){
	scanf("%llu %llu %llu %llu", &n, &m, &c, &k);
	for (ull i = 1; i <= n; i++) {
		ull x;
		scanf("%llu", &x);
		ic = ic | x;
	}
	for (ull i = 1; i <= m; i++) {
		ull x, y;
		scanf("%llu %lly", &x, &y);
		nc = nc | (1ull << x);
	}
	for (ull i = 0; i < k; i++)
		ans += !((nc >> 1) & 1) || ((ic >> i) & 1);
	if (ans == 64 && n == 0)
		printf("18446744073709551616\n");
	else
		printf("%llu\n", ans == 64 ? -n : (1ull << (ull)ans) - (ull)n);
	return 0;
}

