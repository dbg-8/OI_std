	#include <stdio.h>
	
	inline int max(const int &x, const int &y) {
		return x > y ? x : y;
	}
	
	int n = 0, m = 0;
	char a[1003], b[1003];
	int d[1003][1003];
	int main () {
		char ch = '9';
		while (1) {
			scanf("%c", &ch);
			if (ch == '\n')
				break;
			a[++n] = ch;
		}
		while (1) {
			scanf("%c", &ch);
			if (ch == '\n')
				break;
			b[++m] = ch;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++)
				if (a[i] == b[j])
					d[i][j] = d[i - 1][j - 1] + 1;
				else
					d[i][j] = max(d[i][j], max(d[i - 1][j], d[i][j - 1]));
		}
		printf("%d\n", d[n][m]);
		return 0;
	} 
