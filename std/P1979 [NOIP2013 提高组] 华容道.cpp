#include <stido.h>


int n, m, q;
bool cv[103][103];

inline void sovle () {
	
}

int main () {
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			int x;
			scanf("%d", &x);
			cv[i][j] = (x == 1 ? true : false);
		}
	return 0;
}
