#include <stdio.h>

inline int abs (const int &x) {
	return x < 0 ? -x : x;
}

int n;
int fa[30003];	// 当前节点所在树的首领
int s[30003];	// 当前首领所在树的节点数量
int d[30003];	// 当前节点与所在树首领中的节点数量 

#define fa(x) fa[x]
#define size(x) s[x]
#define dis(x) d[x]

inline int get (int x) {
	if (fa(x) == x)
		return x;
	int grandfather = get(fa(x));
	dis(x) += dis(fa(x));
	fa(x) = grandfather;
	return fa(x);
}

int main () {
	scanf("%d", &n);
	for (int i = 1; i < 30003 ; i++) {
		fa(i) = i;
		size(i) = 1;
		dis(i) = 0;
	} 
	for (int i = 1; i <= n; i++) {
		char ch[4];
		int x, y;
		scanf("%s %d %d", &ch, &x, &y);
		int fx = get(x), fy = get(y); // x/y 所在树首领 
		if (ch[0] == 'M') {
			fa(fx) = fy;	// x 所在树并入 y 所在树, 即 fx 的首领变为 fy 
			dis(fx) = size(fy);		// fx 距 fy 的距离即更新前 y/fy 所在树的节点总数 
			size(fy) += size(fx);	// y 所在树节点总数更新 
		}
		else 
			printf("%d\n", fx == fy ? abs(dis(x) - dis(y)) - 1 : -1);
	} 
	return 0;
} 
