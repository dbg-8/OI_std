#include <stdio.h>
#include <string.h>
#include <algorithm>
#define ci const int &

int n = 0;
char a[105];
int d[103][103];
inline int numlen (ci x) {
	if (x < 10)
		return 1;
	if (x < 100)
		return 2;
	return 3;
}
inline bool check (ci l, ci r, ci sr) {	// [l,r] ÄÜ·ñ×ªÎª [l,sr] 
	int len = r - l + 1, slen = sr - l + 1; 
	if (slen % len != 0)
		return false;
	for (int i = l; i <= sr; i++)
		if (a[i] != a[l + (i - l) % len])
			return false;
	return true;
}
int main() {
	char ch;
	while (~scanf("%c", &ch)) {
		if (ch < 'A' || ch > 'Z')
			break;
		a[++n] = ch;
	}
	memset(d, 0x3F, sizeof(d));
	for (int len = 1; len <= n; len++) 
		for (int l = 1; l + len - 1 <= n; l++) {
			int r = l + len - 1;
			if (len == 1)
				d[l][r] = len;
			else
			for (int i = l; i < r; i++)
				d[l][r] = std:: min(d[l][r], d[l][i] + d[i + 1][r]);
			for (int sr = r + len, cnt = 2; sr <= n && check(l, r, sr); sr += len, cnt++) 
				d[l][sr] = std:: min(d[l][sr],  d[l][r] + 2 + numlen(cnt));
		}
	printf("%d\n", d[1][n]);
	return 0;
}
