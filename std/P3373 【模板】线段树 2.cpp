#include <stdio.h>
#define ll long long

int n;
ll P;
int L[400003], R[400003];
ll lazy[400003], lazy2[400003], sum[400003];
ll a[100003];

inline void build (int p, int l, int r) {
	lazy[p] = 0;
	lazy2[p] = 1;
	L[p] = l, R[p] = r;
	if (l == r) {
		sum[p] = a[l] % P;
		return;
	}
	int mid = (l + r) / 2;
	build(p * 2, l, mid);
	build(p * 2 + 1, mid + 1, r);
	sum[p] = (sum[p * 2] + sum[p * 2 + 1]) % P;
	return;
}

inline void spread (int p) {
	sum[p * 2] = sum[p * 2] * lazy2[p] % P;
	sum[p * 2] = (sum[p * 2] + lazy[p] *(ll)(R[p * 2] - L[p * 2] + 1)) % P;
	sum[p * 2 + 1] = sum[p * 2 + 1] * lazy2[p] % P; 
	sum[p * 2 + 1] = (sum[p * 2 + 1] + lazy[p] * (ll)(R[p * 2 + 1] - L[p * 2 + 1] + 1)) % P;
	lazy[p * 2] = (lazy[p * 2] * lazy2[p] + lazy[p]) % P;
	lazy[p * 2 + 1] = (lazy[p * 2 + 1] * lazy2[p] + lazy[p]) % P;
	lazy2[p * 2] = (lazy2[p * 2] * lazy2[p]) % P;
	lazy2[p * 2 + 1] = (lazy2[p * 2 + 1] * lazy2[p]) % P;	
	lazy[p] = 0; 
	lazy2[p] = 1;
	return; 
}

inline void change (int p, int l, int r, ll x) {
	if (l <= L[p] && R[p] <= r) {
		lazy[p] = (lazy[p] + x) % P;
		sum[p] = (sum[p] + x * (ll)(R[p] - L[p] + 1)) % P;
		return;
	}
	spread(p);
	int mid = (L[p] + R[p]) / 2;
	if (l <= mid)
		change(p * 2, l, r, x);
	if (r > mid)
		change(p * 2 + 1, l, r, x);
	sum[p] = (sum[p * 2] + sum[p * 2 + 1]) % P;
	return;
}

inline void change2 (int p, int l, int r, ll x) {
	if (l <= L[p] && R[p] <= r) {
		lazy[p] = lazy[p] * x % P;
		lazy2[p] = lazy2[p] * x % P;
		sum[p] = sum[p] * x % P;
		return;
	}
	spread(p);
	int mid = (L[p] + R[p]) / 2;
	if (l <= mid)
		change2(p * 2, l, r, x);
	if (r > mid)
		change2(p * 2 + 1, l, r, x);
	sum[p] = (sum[p * 2] + sum[p * 2 + 1]) % P;
	return;
}

inline ll query (int p, int l, int r) {
	if (l <= L[p] && R[p] <= r) 
		return sum[p];
	spread(p);
	int mid = (L[p] + R[p]) / 2;
	ll ans = 0;
	if (l <= mid)
		ans = (ans + query(p * 2, l, r)) % P;
	if (r > mid)
		ans = (ans + query(p * 2 + 1, l, r)) % P;
	return ans;
}

int main() {
	int m;
	scanf("%d %d %lld", &n, &m, &P);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	build(1, 1, n);
	for (int i = 1; i <= m; i++) {
		int a, b, c; ll d;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1) {
			scanf("%lld", &d);
			change2(1, b, c, d);
		}
		else if (a == 2) {
			scanf("%lld", &d);
			change(1, b, c, d);
		}
		else
			printf("%lld\n", query(1, b, c));
	}
	return 0;
}
