#include <stdio.h>
#include <iostream>
#define ll long long
using namespace std;
struct NODE {
	int l, r;
	ll sum, add;
	#define l(i) t[i].l
	#define r(i) t[i].r
	#define sum(i) t[i].sum
	#define add(i) t[i].add 
} t[400003];
int n, a[100003];
inline void build (int p, int l, int r) {
	l(p) = l, r(p) = r;
	if (l == r) {
		sum(p) = a[l];
		return;
	}
	int mid = (l + r) / 2;
	build(p * 2, l, mid);
	build(p * 2 + 1, mid + 1, r);
	sum(p) = sum(p * 2) + sum(p * 2 + 1);
	return;
}
inline void spread (int p) { // ��ǰ�ڵ� p, �������ӽڵ㴫�� add ��ֵ, ���������ص����� 
	if (add(p)) {		// �ڵ� p �й���� 
		// 1. �ֱ���������ӽڵ�� sum() 
		sum(p * 2) += add(p) * (r(p * 2) - l(p * 2) + 1);
		sum(p * 2 + 1) += add(p) * (r(p * 2 + 1) - l(p * 2 + 1) + 1);
		// 2. �ֱ���������ӽڵ�� add() 
		add(p * 2) += add(p);
		add(p * 2 + 1) += add(p);
		// 3. ʹ�ڵ� p �� add ���� 
		add(p) = 0;
	}
}
inline void change (int p, int l, int r, int x) {		// ��ǰ�ڵ� p, Ŀ������ [l, r], ����ֵ x 
	if (l <= l(p) && r(p) <= r) {
		sum(p) += (ll)x * (r(p) - l(p) + 1);
		add(p) += x;
		return;
	}
	spread(p);
	int mid = (l(p) + r(p)) / 2;
	if (l <= mid)
		change(p * 2, l, r, x);
	if (r > mid)
		change(p * 2 + 1, l, r, x);
	sum(p) = sum(p * 2) + sum(p * 2 + 1); 
	return;
}
inline ll ask (int p, int l, int r) {		// ��ǰ�ڵ� p, Ŀ������ [l, r] 
	if (l <= l(p) && r(p) <= r)
		return sum(p);
	int mid = (l(p) + r(p)) / 2;
	ll ans = 0;
	spread(p);
	if (l <= mid)
		ans += ask(p * 2, l, r);
	if (r > mid) 
		ans += ask(p * 2 + 1, l, r);
	return ans; 
}
int main() {
	int m;
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	build(1, 1, n);
	for (int i = 1; i <= m; i++) {
		int a, b, c, d;
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1) {
			scanf("%d", &d);
			change(1, b, c, d);
		}
		else
			printf("%lld\n", ask(1, b, c));
	}
	return 0;
}
