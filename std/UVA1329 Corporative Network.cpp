#include <stdio.h>
#define abs(x) ((x) > 0 ? (x) : -(x))

int n;
int fa[20003];
int dis[20003];

inline int getfa (int x) {
	if (fa[x] == x)
		return x;
	int nf = getfa(fa[x]); 
	dis[x] += dis[fa[x]];
	return fa[x] = nf; 
}

inline void kagari () {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		fa[i] = i, dis[i] = 0;
	while (1) {
		char ch;
		scanf(" %c", &ch);
		if (ch == 'I') {
			int x, y;
			scanf("%d %d", &x, &y);
			fa[x] = y;
			dis[x] += abs(x - y) % 1000;
		}
		else if (ch == 'E') {
			int x;
			scanf("%d", &x);
			getfa(x);
			printf("%d\n", dis[x]);
		}
		else if (ch == 'O')
			break;
	}
}

int main () {
	int t;
	scanf("%d", &t);
	while (t--)
		kagari();
	return 0;
}
