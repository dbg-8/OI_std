#include <stdio.h>
#define ll long long

int n, m, r;
ll P;
ll a[100003], b[100003];

inline void bmo (ll &qwq) {
	qwq %= P;
	return;
}
inline void swap (int &x, int &y) {
	x ^= y;
	y ^= x;
	x ^= y;
	return; 
}

int head[100003], last[100003], to[100003], ccnt = 0;
#define addedge(x, y) to[++ccnt] = y, last[ccnt] = head[x], head[x] = ccnt

struct SMT {
	struct NODE {
		int l, r;
		ll sum;
		ll lazy;
	} st[400003];
	#define l(p) st[p].l
	#define r(p) st[p].r
	#define sum(p) st[p].sum 
	#define lazy(p) st[p].lazy
	#define lc (p << 1)
	#define rc ((p << 1) + 1)
	#define smid ((l + r) >> 1)
	#define lt lc, l, smid
	#define rt rc, smid + 1, r
	inline void upload (int p) {
		sum(p) = sum(lc) + sum(rc); 
		bmo(sum(p));
		return;
	}
	inline void download (int p) {
		if (lazy(p)) {
			sum(lc) += (r(lc) - l(lc) + 1) * lazy(p);
			sum(rc) += (r(rc) - l(rc) + 1) * lazy(p);
			bmo(sum(lc));
			bmo(sum(rc));
			lazy(lc) += lazy(p);
			lazy(rc) += lazy(p);
			lazy(p) = 0ll;
		}
		return;
	}
	inline void build (int p, int l, int r) {
		l(p) = l, r(p) = r;
		if (l == r) {
			sum(p) = a[p];
			return;
		}
		build(lt);
		build(rt);
		upload(p);
		return;
	}
	inline void change (int p, int wl, int wr, ll wx) {
		int l = l(p), r = r(p);
		if (r < wl || wr < l)
			return;
		if (wl <= l && r <= wr) {
			lazy(p) += wx;
			sum(p) += wx * (r(p) - l(p) + 1);
			bmo(sum(p));
			return;
		}
		download(p);
		change(lc, wl, wr, wx);
		change(rc, wl, wr, wx);
		upload(p);
	}
	inline ll query (int p, int wl, int wr) {
		int l = l(p), r = r(p);
		if (r < wl || wr < l)
			return 0ll;
		if (wl <= l && r <= wr) 
			return sum(p);
		download(p);
		ll ret = 0;
		ret += query(lc, wl, wr);
		ret += query(rc, wl, wr);
		bmo(ret);
		return ret;
	}
} sm;

int fa[100003], dep[100003], hson[100003], size[100003], top[100003], oid[100003], nid[100003], cnt = 0;
inline void dfs1 (int cur, int father, int depth) {	// »ñÈ¡ fa, dep, hson, size
	fa[cur] = father; 
	dep[cur] = depth;
	size[cur] = 1;
	for (int i = head[cur]; i; i = last[i])
		if (to[i] != father) {
			dfs1(to[i], cur, depth + 1);
			size[cur] += size[to[i]];
			if (size[to[i]] > size[hson[cur]])
				hson[cur] = to[i];
		}
	return;
}
inline void dfs2 (int cur, int father, int grand) {
	top[cur] = grand;
	nid[cur] = ++cnt;
	oid[cnt] = cur;
	if (hson[cur])
		dfs2(hson[cur], cur, grand);
	for (int i = head[cur]; i; i = last[i])
		if (to[i] != father && to[i] != hson[i])
			dfs2(to[i], cur, to[i]);
	return;
}

inline void sovle1 (int x, int y, ll z) {
	while (top[x] != top[y]) {
		if (dep[top[x]] < dep[top[y]])
			swap(x, y);
		sm.change(1, x, y, z);
		x = fa[top[x]];
	}
	if (dep[x] > dep[y])
		swap(x, y);
		
}
inline void sovle2 () {
	
}

inline void tatara () {
	scanf("%d %d %d %d", &n, &m, &r, &P);
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		addedge(x, y);
		addedge(y, x);
	}
}
inline void ogasa () {
	dfs1(r, 0, 1);
	dfs2(r, 0, r);
	while (m--) {
		
	}
}

#define Tatara tatara();
#define Ogasa ogasa();
int main() {
	Tatara Ogasa
	return 0;
}
