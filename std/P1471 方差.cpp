#include <stdio.h>

int n;
int a[100003];
struct NODE {
	int l, r;
	int len;
	int x;
	int lazy;
	double sum;		// 所有数的和 
	double fsum;	// 所有数的平方的和 
	#define ar (sum / len)	// 平均数 
	#define dv (fsum - 2 * sum * len * ar + len * ar * ar)	// 方差
	
	#define l(p) tr[p].l
	#define r(p) tr[p].r
	#define intlen(p) tr[p].intlen
	#define len(p) tr[p].len
	#define x(p) tr[p].x
	#define lazy(p) tr[p].lazy
	#define sum(p) tr[p].sum
	#define fsum(p) tr[p].fsum
	#define ar(p) tr[p].ar
	#define dv(p) tr[p].dv
} tr[400003];
#define mid ((l + r) >> 1)
#define lc (p << 1)
#define rc (p << 1 | 1)
#define ls lc, l, mid
#define rs rc, mid + 1, r

#define stdate(p) sum(p) = x(p), fsum(p) = x(p) * x(p)
#define upload(p) sum(p) = sum(lc) + sum(rc), fsum(p) = fsum(lc) + fsum(rc)
#define download(p) if (lazy(p))) { lazy(lc) += lazy(p), lazy(rc) += lazy(p), sum(lc) += lazy(p) * len(lc), sum(rc) += lazy(p) * len(rc), lazy(p) = 0 }

inline void build (int p, int l, int r) {
	l(p) = l, r(p) = r, len = r - l + 1;
	if (l == r) {
		stdate(p);
		return;
	}
	build(ls);
	build(rs);
	upload(p);
	return;
}
inline void change (int p, int wl, int wr, int wx) {
	int l = l(p), r = r(p);
	if (r < wl || wr < l)
		return;
	if (wl <= l && r <= wr) {
		sum(p) += wx * intlen(p);
		lazy(p) += wx;
		return;
	}
	download(p);
	if (wr <= mid)
		build(lc, wl, wr, wx);
	if (wl > mid)
		build(rc, wl, wr, wx);
	upload(p);
	return;
}
inline NODE clac(NODE x, NODE y) {
	NODE nd;
	nd.l = x.l, nd.r = y.r;
	nd.sum = x.sum + y.sum;
	nd.fsum = x.fsum + y.fsum;
	return;
}
inline NODE query (int p, int wl, int wr, int mood) {
	int l = l(p), r = r(p);
	if (r < wl || wr < l)
		return;
	if (wl <= l && r <= wr) {
		sum(p) += wx * intlen(p);
		lazy(p) += wx;
		return;
	}
	download(p);
	if (wr <= mid)
		nd = clac(nd, build(lc, wl, wr, wx))
	if (wl > mid)
		build(rc, wl, wr, wx);
	upload(p);
	return;
}
int main () {
	scanf()
	return 0;
}
