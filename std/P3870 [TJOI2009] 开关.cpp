#include <stdio.h>
inline void swap (int &x, int &y) { x ^= y, y ^= x, x ^= y; }

int n, m;
struct NODE {
	int l, r;
	int sum1, sum2;
	int lazy;
	#define l(p) tr[p].l
	#define r(p) tr[p].r
	#define s1(p) tr[p].sum1
	#define s2(p) tr[p].sum2
	#define lazy(p) tr[p].lazy
} tr[400003];
#define lc (p << 1)
#define rc ((p << 1) | 1)
#define mid ((l + r) >> 1)
#define lt lc, l, mid
#define rt rc, mid + 1, r

inline void upload (int p) {
	s1(p) = s1(lc) + s1(rc);
	s2(p) = s2(lc) + s2(rc);
	return;
}

inline void download (int p) {
	if (lazy(p)) {
		swap(s1(lc), s2(lc));
		swap(s1(rc), s2(rc));
		lazy(lc) ^= 1;
		lazy(rc) ^= 1;
		lazy(p) = 0;
	}
	return;
}

inline void build (int p, int l, int r) {
	l(p) = l, r(p) = r;
	lazy(p) = 0;
	if (l == r) {
		s1(p) = 1;
		s2(p) = 0;
		return;
	}
	build(lt);
	build(rt);
	upload(p);
	return;
}

inline void change (int p, int wl, int wr) {
	int l = l(p), r = r(p);
	if (r < wl || wr < l)
		return;
	if (wl <= l && r <= wr) {
		lazy(p) ^= 1;
		swap(s1(p), s2(p));
		return;
	}
	download(p);
	change(lc, wl, wr);
	change(rc, wl, wr);
	upload(p);
	return;
}

inline int query (int p, int wl, int wr) {
	int l = l(p), r = r(p);
	if (r < wl || wr < l)
		return 0;
	if (wl <= l && r <= wr)
		return s2(p);
	download(p);
	int ret = 0;
	ret += query(lc, wl, wr);
	ret += query(rc, wl, wr);
	return ret;
}

int main () {
	scanf("%d %d", &n, &m);
	build(1, 1, n);
	while (m--) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		if (x == 0) 
			change(1, y, z);
		else
			printf("%d\n", query(1, y, z));
	}
	return 0;
}
