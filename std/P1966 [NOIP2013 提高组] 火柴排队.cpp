#include <stdio.h>
#include <algorithm>
#define MOD 99999997
#define ll long long

int n;
int c[100003], d[100003], e[100003], f[100003];

struct NODE {
	int x, pos;
	inline bool operator < (const NODE &rhs) const {
		return x < rhs.x;
	}
} a[100003], b[100003];

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%lld", &a[i].x), a[i].pos = i;
	for (int i = 1; i <= n; i++)
		scanf("%lld", &b[i].x), b[i].pos = i;
	std:: sort(a + 1, a + n + 1);
	std:: sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; i++)
		c[i] = a[i].pos, d[i] = b[i].pos, printf("^%d %d\n", b[i].pos, b[i].x);
	for (int i = 1; i <= n; i++)
		f[c[i]] = i;
	for (int i = 1; i <= n; i++)
		e[i] = f[d[i]];
	for (int i = 1; i <= n; i++)
		printf("~%d\n",c[i]);
	for (int i = 1; i <= n; i++)
		printf("~~%d\n",d[i]);
	for (int i = 1; i <= n; i++)
		printf("~~~%d\n",e[i]);
	
//	printf("%lld\n", ans);
	return 0;
}
