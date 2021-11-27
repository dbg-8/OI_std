#include <stdio.h>
#define ll long long
#define P 1000000007

int n;
ll l, r;
ll l0, l1, l2, r0, r1, r2, f0, f1, f2;
ll d[200003][3]; // 前 i 个数 % 3 = j 的方案数量 

int main () {
	scanf("%d %lld %lld", &n, &l, &r);
	l0 = l / 3, l1 = l0 + (l % 3 >= 1 ? 1 : 0), l2 = l0 + (l % 3 >= 2 ? 1 : 0);
	r0 = r / 3, r1 = r0 + (r % 3 >= 1 ? 1 : 0), r2 = r0 + (r % 3 >= 2 ? 1 : 0);
	f0 = r0 - l0 + (l % 3 == 0 ? 1 : 0), f1 = r1 - l1 + (l % 3 == 1 ? 1 : 0), f2 = r2 - l2 + (l % 3 == 2 ? 1 : 0);
	d[1][0] = f0, d[1][1] = f1, d[1][2] = f2;
	for (int i = 2; i <= n; i++) {
		d[i][0] = (d[i - 1][0] * f0 + d[i - 1][1] * f2 + d[i - 1][2] * f1) % P;
		d[i][1] = (d[i - 1][0] * f1 + d[i - 1][1] * f0 + d[i - 1][2] * f2) % P;
		d[i][2] = (d[i - 1][0] * f2 + d[i - 1][1] * f1 + d[i - 1][2] * f0) % P;
	}
	printf("%lld\n", d[n][0] % P);
	return 0;
}
