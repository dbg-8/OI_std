#include <stdio.h>
#include <algorithm>
#define max(x, y) ((x) > (y) ? (x) : (y))

struct NODE {
	int oldnum;
	int oldid;
	int truerank;
	const inline bool operator < (const NODE &rhs) const {
		return oldnum < rhs.oldnum;
	}
} ma[200003];

int n;

int a[400003];
int d[400003];
int ans = 0;
int st;

int main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]),
		ma[i].oldnum = a[i],
		ma[i].oldid = i;
	std:: sort(ma + 1, ma + n + 1);
	for (int i = 1; i <= n; i++)
		if (ma[i].oldnum == ma[i - 1].oldnum)
			ma[i].truerank = ma[i - 1].truerank;
		else if (ma[i - 1].oldnum + 1 == ma[i].oldnum)	// 可以 AC 的离散化, 好耶!! 
			ma[i].truerank = ma[i - 1].truerank + 1;
		else
			ma[i].truerank = ma[i - 1].truerank + 2;
	for (int i = 1; i <= n; i++)
		a[ma[i].oldid] = ma[i].truerank;
	for (int i = n; i >= 1; i--) {
		d[a[i]] = d[a[i] + 1] + 1;
		if (ans < d[a[i]]) {
			st = a[i];
			ans = d[a[i]];
		}
	}
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++)
		if (a[i] == st)
			printf("%d ", i),
			st++;
	printf("\n");
	return 0;
}
