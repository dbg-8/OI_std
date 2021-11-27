#include <stdio.h>
#define ll long long

int m;
ll x, P;
ll a[400003];

inline void upload (int p) {
	a[p] = a[p << 1] * a[p << 1 | 1] % P;
}

inline void build (int p, int l, int r) {
	a[p] = 1;
	if (l == r) 
		return;
	int mid = (l + r) >> 1;
	build(p << 1, l, mid);
	build(p << 1 | 1, mid + 1, r);
}

inline void change (int p, int l, int r, int to, ll x) {
	if (l == r) {
		a[p] = (x == 0 ? 1 : x);
		return;
	}
	int mid = (l + r) >> 1;
	if (to <= mid)
		change(p << 1, l, mid, to, x);
	else
		change(p << 1 | 1, mid + 1, r, to, x);
	upload(p);
	return;
}

inline void sovle () {
	scanf("%d %lld", &m, &P);
	build(1, 1, m);
	for (int i = 1; i <= m; i++) {
		int op; ll x;
		scanf("%d %lld", &op, &x);
		change(1, 1, m, (op == 1) ? i : x, (op == 1) ? x : 0);
		printf("%lld\n", a[1] % P);
	}
	return;
} 

int main() {
	int t;
	scanf("%d", &t);
	while (t--) 
		sovle();
	return 0;
}
