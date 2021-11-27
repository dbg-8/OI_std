#include <stdio.h>

inline char getch () {
	char ch;
	if (!(~scanf("%c", &ch)))
		return 0;
	if (ch == '\n' || ch == EOF)
		return 0;
	return ch;
}
int main() {
//	freopen("system4.in", "r", stdin);
//	freopen("systemmy.out", "w", stdout);
	char ch;
	bool r = false, n = false;
	while (1) {
		ch = getch();
		if (!ch)
			break;
		if (ch == '\\') {
			ch = getch();
			if (!ch)
				break;
			if (ch == 'r')
				r = true;
			else if (ch == 'n')
				n = true;
		}
	}
	if (r && n)
		printf("windows\n");
	else if (n)
		printf("linux\n");
	else if (r)
		printf("mac\n");
	return 0;
}
