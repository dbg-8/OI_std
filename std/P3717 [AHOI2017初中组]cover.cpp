#include <stdio.h>
#define f(x) (x == 1 ? 0 : 1)

int n, m;
int a[100003];
int b[100003], cnt = 0;

inline int check (int mid) {
	int ret = 0;
	if (mid == 1) {
		int rret = 0;
		for (int i = 1; i <= n; i++)
			if (a[i] == i % 2)
				ret++;
		for (int i = 1; i <= n; i++)
			if (a[i] != i % 2)
				rret++;
		return (ret < rret ? ret : rret);
	}
	for (int i = 1; i <= cnt; i++)
		if (b[i] > mid)	
			ret += b[i] / (mid + 1);
//	printf("\t%d %d\n", mid, ret);
	return ret;
}

int main () {
	scanf("%d %d ", &n, &m);
	for (int i = 1; i <= n; i++) {
		char ch;
		scanf("%c", &ch);
		if (ch == 'N')	a[i] = 1;
		else	a[i] = 0;
	}
	b[++cnt] = 1;
	for (int i = 2; i <= n; i++) 
		if (a[i] != a[i - 1])
			b[++cnt] = 1;
		else
			b[cnt]++;
	int l = 1, r = n;
	while (l < r) {
		int mid = l + r >> 1;
		if (check(mid) <= m)
			r = mid;
		else
			l = mid + 1;
	}
	printf("%d\n", l);
	return 0;
}
