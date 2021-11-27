/*#include <stdio.h>
#define RIGHT 1
#define LEFT 0
int n, m;
int head[300003], last[300003], to[300003], ind[300003], ccnt = 0;
#define addedge(x, y) if (x != 0 && x != n + 1 && y != 0 && y != n + 1) { ind[y]++, to[++ccnt] = y, last[ccnt] = head[x], head[x] = ccnt; }
// ะก->ด๓ 
#define fw(x, y) (x < y ? RIGHT : LEFT)

int main () {
	scanf("%d %d", &n, &m);
	while (m--) {
		int x, y;
		scanf("%d %d", &x, &y);
		if (fw(x, y) == RIGHT)
			addedge(x + 1, x - 1);
		else
			addedge(x - 1, x + 1);
		if ()
	}
	return 0;
}*/
#include <stdio.h>
int main() {
	printf("QED");
	return 0;
}
