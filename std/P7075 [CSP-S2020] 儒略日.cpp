// #pragma GCC optimize(3)
#include <stdio.h>
#define re register
int n;
int yy, mm, dd;
inline int dim (re int ye, re int mo) {	// 这个月最后一天是多少号 
	if (mo == 1 || mo == 3 || mo == 5 || mo == 7 || mo == 8 || mo == 10 || mo == 12)
		return 31;
	if (mo == 4 || mo == 6 || mo == 9 || mo == 11)
		return 30;
	if (ye < 0 && (-ye - 1) % 4 == 0 ||
		0 < ye && ye <= 1582 && ye % 4 == 0 || 
		ye > 1582 && (ye % 400 == 0 || ye % 4 == 0 && ye % 100 != 0))
		return 29;
	return 28;
}
inline int dim2 (re int ye, re int mo) {	// 这个月有多少天 
	if (ye == 1582 && mo == 10)
		return 21;
	return dim(ye, mo);
}
inline int diy (re int ye) {	// 这年有多少天 
	if (ye == 1582)	// 少 10 天 
		return 355; 
	if (ye < 0 && (-ye - 1) % 4 == 0 ||
		0 < ye && ye <= 1582 && ye % 4 == 0 || 
		ye > 1582 && (ye % 400 == 0 || ye % 4 == 0 && ye % 100 != 0))	// 是闰年 
		return 366;
	return 365;
}
inline void nextyear () {
	if (yy == -1)
		yy = 1;
	else
		yy++;
}
inline void nextmonth () {
	if (mm == 12)
		nextyear(), mm = 1;
	else
		mm++;
}
inline void nextday () {
	if (yy == 1582 && mm == 10 && dd == 4)
		dd = 15;
	else if (dd == dim(yy, mm))
		nextmonth(), dd = 1;
	else
		dd++;
}
inline void sovle () {
	yy = -4713, mm = 1, dd = 1;
	re int x, i = 1;
	scanf("%d", &x);
	while (i <= x) {
		if (i + diy(yy) <= x)
			i += diy(yy), nextyear();
		else if (i + dim2(yy, mm) <= x)
			i += dim2(yy, mm), nextmonth();
		else
			i += 1, nextday();
	}
	printf("%d %d %d%s",dd, mm, yy < 0 ? -yy : yy , yy < 0 ? " BC\n" : "\n");
	return;
}
int main () {
	int q;
	scanf("%d", &q);
	while (q--) 
		sovle();
	return 0;
} 
