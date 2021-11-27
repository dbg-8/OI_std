#include <stdio.h>

int n, m;
char word[103][100003];

int main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int x;
		scanf("%d", &x);
		scanf("%s", word[x]);
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		bool isnum = true;
		while (1) {
//			printf("%d\n", isnum);
			char ch;	int x;
			if (isnum) {
				scanf("%d", &x);
				printf("%s", word[x]);
			}
			else {
				scanf("%c", &ch);
				if (ch == '\n')
					continue;
				else if (ch == ',')
					printf(",");
				else if (ch == '.') {
					printf(".\n");
					break;
				}
			}
			isnum = !isnum;
		}
	}
	return 0;
}
