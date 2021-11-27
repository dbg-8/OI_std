#include <stdio.h>
#define lll __int128
#define ulll __uint128_t

inline lll read () {
	char ch = getchar();
	lll ret = 0, c = 1;
	while (1) {
		if (ch >= '0' && ch <= '9')
			break;
		if (ch == '-')
			c = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		ret = ret * 10 + ch - '0';
		ch = getchar();
	}
	ret = ret * c;
	return ret;
}

inline void write (lll x) {
	if (x < 0)	printf("-"), x = -x;
	if (x > 9)
		write(x / 10);
	putchar(x % 10 + '0');
}

int main () {
	lll x, y;	// sovle the a + b problem by __int128
	x = read(), y = read();
	write(x + y);
	return 0;
}
