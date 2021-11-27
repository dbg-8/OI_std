#include <stdio.h>
#include <algorithm>
#define max(x, y) ((x) > (y) ? (x) : (y))
#define min(x, y) ((x) < (y) ? (x) : (y))
#define sw(x, y) std:: swap(x, y)

double a1, a2, b1, b2;		// the line 
double x1, x2, y1, y2;		// the square 
 
#define gety(x) ((b2 - b1) / (a2 - a1) * (x - a1) + b1)

inline void kagari () {
	scanf("%lf %lf %lf %lf %lf %lf %lf %lf", &a1, &b1, &a2, &b2, &x1, &y1, &x2, &y2);
	if (a1 > a2)	sw(a1, a2), sw(b1, b2);
	if (x1 > x2)	sw(x1, x2);
	if (y1 > y2)	sw(y1, y2);
	if (a2 < x1 || a1 > x2 || min(b1, b2) > y2 || max(b1, b2) < y1)		// x | y 轴上无重合点 
		printf("F\n");
	else if (a1 == a2 || b1 == b2)	// 函数形如 y = k | x = k 
		printf("T\n");
	else if ((y2 < gety(max(a1, x1)) && y2 < gety(min(a2, x2))) ||
			 (y1 > gety(max(a1, x1)) && y1 > gety(min(a2, x2))) )	// 无交点 
		printf("F\n");
	else
		printf("T\n");
//	printf("x = %.2lf, y = %.2lf\n", x1, gety(x1));
//	printf("x = %.2lf, y = %.2lf\n", x2, gety(x2));
	return;
}

int main () {
	register int t;
	scanf("%d", &t);
	while (t--)
		kagari();
	return 0;
}
