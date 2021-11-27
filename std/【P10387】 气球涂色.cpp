#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int c[100003];
int main() {
	int n;
	while (~scanf("%d", &n) && n) {
		memset(c, 0, sizeof(c));
		for (int i = 1; i <= n; i++) {
			int a, b;
			cin >> a >> b;
			c[a]++;
			c[b + 1]--;
		}
		for (int i = 1; i <= n; i++) {
			c[i] += c[i - 1];
			if (i == n)
				printf("%d", c[i]);
			else
				printf ("%d ", c[i]); 
		}
		printf("\n");
	}
	return 0;
} 
