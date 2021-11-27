#include <stdio.h>
#include <algorithm>
#define ci const int &

int n;
char ch[103];
int d[103][103];
int f[103][103];

inline int mathsovle (ci x, ci y, const char &op) {
	return (op == 't' ? (x + y) : (x * y));
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf(" %c %d", &ch[i], &d[i][i]), 
		ch[n + i] = ch[i],
		d[n + i][n + i] = d[i][i], f[i][i] = d[i][i], f[n + i][n + i] = d[i][i];
	for (int len = 2; len <= n; len++) 
		for (int l = 1; l + len - 1 <= 2 * n; l++) {
			int r = l + len - 1;
			d[l][r] = -0x3F3F3F3F, f[l][r] = 0x3F3F3F3F;
			for (int i = l; i < r; i++)
				d[l][r] = std:: max(d[l][r], mathsovle(d[l][i], d[i + 1][r], ch[i + 1])),
				d[l][r] = std:: max(d[l][r], mathsovle(f[l][i], f[i + 1][r], ch[i + 1])),
				d[l][r] = std:: max(d[l][r], mathsovle(d[l][i], f[i + 1][r], ch[i + 1])),
				d[l][r] = std:: max(d[l][r], mathsovle(f[l][i], d[i + 1][r], ch[i + 1])),
				f[l][r] = std:: min(f[l][r], mathsovle(d[l][i], d[i + 1][r], ch[i + 1])),
				f[l][r] = std:: min(f[l][r], mathsovle(f[l][i], f[i + 1][r], ch[i + 1])),
				f[l][r] = std:: min(f[l][r], mathsovle(d[l][i], f[i + 1][r], ch[i + 1])),
				f[l][r] = std:: min(f[l][r], mathsovle(f[l][i], d[i + 1][r], ch[i + 1]));
		}
	int ans = -0x3F3F3F3F;
	for (int i = 1; i <= n; i++) 
		ans = std:: max(ans, d[i][i + n - 1]);
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++)
		if (d[i][i + n - 1] == ans)
			printf("%d ", i);
	printf("\n");
	return 0;
}
