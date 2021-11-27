#include <stdio.h>
#include <string.h>
#include <algorithm>

int m, n;
int s[53];
int d[53][53];

inline void kagari () {
	scanf("%d", &n);
	memset(d, 0x3F, sizeof(d));
	s[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%d", &s[i]);
		d[i - 1][i] = 0;
	}
	s[++n] = m;	d[n - 1][n] = 0;
	#define r len + l
	for (int len = 2; len <= n; len++)
		for (int l = 0; r <= n; l++)	// [l, r]
			for (int k = l + 1; k < r; k++)
				d[l][r] = std:: min(d[l][r], d[l][k] + d[k][r] + s[r] - s[l]);
	printf("The minimum cutting is %d.\n", d[0][n]);
	return;
}

int main() {
	while (scanf("%d", &m) && m) 
		kagari();
	return 0;
}
