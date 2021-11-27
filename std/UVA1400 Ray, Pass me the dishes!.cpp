#include <stdio.h>
#define min(x, y) (x < y ? x : y)
#define max(x, y) (x > y ? x : y)
#define min(x, y, z) (min(x, min(y, z)))
#define max(x, y, z) (max(x, max(y, z)))
#define max(a1, a2, a3, a4, a5, a6) (max(max(a1, a2, a3), max(a4, a5, a6)))

#define l(p) tr[p].l
#define r(p) tr[p].r
#define suml(p) tr[p].suml
#define sumr(p) tr[p].sumr
#define summ(p) tr[p].summ
#define lc (p << 1)
#define lc (p << 1 | 1)
#define mid (l + r >> 1)
#define lt lc, l, mid
#define rt rc, mid + 1, r 

struct NODE {
	int l, r;
	int suml, sumr, summ;
} tr[2000003];
int n, m;
int a[500003];
 
inline void update (int p, int lp, int rp) {
	sum(p) = sum(lp) + sum(rp);
	suml(p) = max(suml(p), suml(lp), sum(lp) + suml(rp));
	sumr(p) = max(sumr(p), sumr(rp), sum(rp) + sumr(lp));
	summ(p) = max(summ(p), suml(p), sumr(p), summ(lp), summ(rp), sumr(lp) + suml(rp));
	return;
}

inline void build (int p, int l, int r) {
	l(p) = l, r(p) = r;
	if (l == r) {
		sum(p) = suml(p) = sumr(p) = summ(p) = a[l];
		return;
	}
	build(lt);
	build(rt);
	update(p);
	return;
}

inline int query (int p, int l, int r) {
	if (l(p) == r(p))
		return sum(p);
	
}

inline void kagari () {
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	build(1, 1, n);
	while (m--) {
		int x, y;
		scanf("%d %d", &x, &y);
		printf("%d %d\n")
	}
	return;
}

int main () {
	int t = 1;
	while (~scanf("%d %d", &n, &m))
		printf("Case %d:\n", t++),
		kagari();
	return 0;
}
