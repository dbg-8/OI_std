#include <stdio.h>
#include <algorithm>

struct NODE {
	int x, y;
	int op;
} qs[10003];
int ip[20003];
int n, m;
int fa[20003]; 
int dis[20003];

inline int get (int x) {
	if (fa[x] == x)
		return x;
	int root = get(fa[x]);
	dis[x] = dis[x] ^ dis[fa[x]];
	fa[x] = root;
	return fa[x];
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < 20003; i++)
		fa[i] = i, dis[i] = 0;
	for (int i = 1; i <= m; i++) {
		NODE nd;
		char ch[10];
		scanf("%d %d %s", &nd.x, &nd.y, &ch);
		nd.x -= 1;
		nd.op = (ch[0] == 'e' ? 0 : 1);
		ip[i * 2 - 2] = nd.x;
		ip[i * 2 - 1] = nd.y;
		qs[i] = nd;
	}
	std:: sort(ip, ip + 2 * m - 2);
	n = std:: unique(ip, ip + 2 * m) - ip;
	for (int i = 1; i <= m; i++) {
		int x = std:: lower_bound(ip, ip + n, qs[i].x) - ip;
		int y = std:: lower_bound(ip, ip + n, qs[i].y) - ip;
		int fx = get(x), fy = get(y);
		if (fx == fy && dis[x] ^ dis[y] != qs[i].op) {
			printf("%d\n", i - 1);
			return 0;
		}
		else if (fx != fy) {
			fa[fx] = fy;
			dis[fx] = dis[x] ^ dis[y] ^ qs[i].op;
		}
	}
	printf("%d\n", m);
	return 0;
}
