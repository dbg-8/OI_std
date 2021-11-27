#include <stdio.h>

inline void gcd(int a, int b, int &d, int &x, int &y) {
	if(b == 0) {
		d = a;
		x = 1;
		y = 0;
	}
	else {
		gcd(b, a % b, d, y, x);
		y = y - a / b * x;
	}
}
int main() {
//	freopen("mod.in", "r", stdin);
//	freopen("mod.out", "w", stdout);
	int a, b, d = 0, x = 0, y = 0;
	scanf("%d %d", &a, &b);
	gcd(a, b, d, x ,y);
	printf("%d\n", (x % b + b) % b);
	return 0;
}
