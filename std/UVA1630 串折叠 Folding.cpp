#include <stdio.h>
#include <string.h>
#define ci const int &

int n = 0;
char a[105];
int d[103][103];
int h[103][103], mod[103][103];
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
inline void print (ci l, ci r) {
	if (mod[l][r] == 0) 
		for (int i = l; i <= r; i++)
			printf("%c", a[i]);
	else if (mod[l][r] == 1) {
		print(l, h[l][r]);
		print(h[l][r] + 1, r);
	}
	else {
		printf("%d(", (r - l + 1) / h[l][r]);
		print(l, l + h[l][r] - 1);
		printf(")"); 
	}
}
inline void sovle () {
	n = strlen(a + 1);
	memset(d, 0x3F, sizeof(d));
	for (int len = 1; len <= n; len++) 
		for (int l = 1; l + len - 1 <= n; l++) {
			int r = l + len - 1;
			if (len == 1)
				d[l][r] = len;
			else
			for (int i = l; i < r; i++)
				if (d[l][i] + d[i + 1][r] < d[l][r]) {
					d[l][r] = d[l][i] + d[i + 1][r];
					h[l][r] = i;
					mod[l][r] = 1;
				}
			for (int sr = r + len, cnt = 2; sr <= n && check(l, r, sr); sr += len, cnt++) {
				if (d[l][r] + 2 + numlen(cnt) < d[l][sr]) {
					d[l][sr] = d[l][r] + 2 + numlen(cnt);
					h[l][sr] = len;
					mod[l][sr] = 2;
				}
			}
		}
	print(1, n);
	printf("\n");
	return;
}
int main() {
	while (~scanf("%s", a + 1)) 
		sovle();
	return 0;
}
