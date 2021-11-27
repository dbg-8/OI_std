#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int n, p, h, m, c[10003];
bool vis[10003][10003];
int main() {
	cin >> n >> p >> h >> m;
	for (int i = 1; i <= m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (vis[a][b] || vis[b][a])	continue;
		vis[a][b] = true;
		c[min(a,b) + 1]--;
		c[max(a,b)]++;
	}
	for (int i = 1; i <= n; i++) {
		c[i] += c[i-1];
		printf("%d\n", c[i] + h);
	}
	return 0;
}
