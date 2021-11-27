#include <stdio.h>
#include <time.h>
#include <stdlib.h>

inline void sovle (int t) {
	printf("=== Case %d ===\n", t);
	system("./random");	// 生成数据
	system("./slow");	// 运行暴力 
	long s1 = clock();
	system("./std");		// 运行正解 
	long s2 = clock(); 
	if (system("diff std.out slow.out"))
		printf("WA\n");
	else
		printf("AC\n");
	printf("%ldms\n\n", s2 - s1); 
}
int main () {
	int t = 30;
	for (int i = 1; i <= t; i++)
		sovle(i);
	return 0;
}
