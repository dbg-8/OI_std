#include <stdio.h>
#include <vector>

int n, m, q;
int a[50003][50003];

inline void sovle50 () {
	while (q--) {
		int x, y, rea;
		scanf("%d %d", &x, &y);
		printf("%d\n", a[x][y]);
		rea = a[x][y];
		a[x][y] = 0;
		for (int j = 1; j <= m; j++)
			if (a[x][j] == 0)
				a[x][j] = a[x][j + 1], a[x][j + 1] = 0;
		for (int j = 1; j <= m; j++)
			if (a[x][j] == 0) {
				y = j;
				break;
			}
		for (int i = 1; i <= n; i++)
			if (a[i][y] == 0)
				a[i][y] = a[i + 1][y], a[i + 1][y] = 0;
		a[n][m] = rea;
/*		printf("------\n");
		for (int i = 1; i <= n; i++, printf("\n"))
			for (int j = 1; j <= m; j++)
				printf("%d ", a[i][j]);
		printf("------\n\n\n");*/
	}
}

inline void sovlen1 () {
	std:: vector < int > v;
	for (int i = 1; i <= m; i++)
		v.push_back(i);
	while (q--) {
		int x, rea;
		scanf("%d %d", &x, &x);
		rea = v[x - 1];
		printf("%d\n", v[x - 1]);
		v.erase(v.begin() + x - 1);
		v.push_back(rea);
	}
}
int main() {
	scanf("%d %d %d", &n, &m, &q);
	if (n == 1) {
		sovlen1();
		return 0;
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			a[i][j] = (i - 1) * m + j;
  	sovle50();
	return 0;
} 
