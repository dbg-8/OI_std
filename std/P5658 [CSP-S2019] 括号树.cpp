#include <stdio.h>
#define ll long long

int n;
int fa[500003];
ll h[500003], w[500003];
char ch[500003];
int head[500003], last[500003], to[500003], cnt = 0;
#define addedge(x, y) to[++cnt] = y, last[cnt] = head[x], head[x] = cnt
inline void dfs (int x) {
	w[x] = w[fa[x]];
	if (ch[x] == '(')
		w[x] = x;
	else if (w[x] != 0)
		h[x] = 1 + h[fa[w[x]]],
		w[x] = w[fa[w[x]]];
	for (int i = head[x]; i; i = last[i])
		dfs(to[i]);
	return;
}

int main () {
	scanf("%d%s", &n, ch + 1);
	for (int i = 2; i <= n; i++) {
		int x;
		scanf("%d", &x);
		fa[i] = x;
		addedge(x, i);
	}
	dfs(1);
	ll ans = h[1];
	for (int i = 2; i <= n; i++)
		h[i] += h[fa[i]],
		ans = ans ^ ((ll)i * h[i]);
	printf("%lld\n", ans);
	return 0;
}
