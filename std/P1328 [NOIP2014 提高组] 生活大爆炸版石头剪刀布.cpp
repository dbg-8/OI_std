#include <stdio.h>

const int score[5][5] = {
	{ 0, 0, 1, 1, 0 },
	{ 1, 0, 0, 1, 0 },
	{ 0, 1, 0, 0, 1 },
	{ 0, 0, 1, 0, 1 },
	{ 1, 1, 0, 0, 0 }
};

int n, n1, n2;
int a[203], b[203];

int main () {
	scanf("%d %d %d", &n, &n1, &n2);
	for (int i = 0; i < n1; i++)
		scanf("%d", &a[i]);
	for (int i = 0; i < n2; i++)
		scanf("%d", &b[i]);
	int ans1 = 0, ans2 = 0;
	for (int i = 0; i < n; i++) {
		ans1 += score[a[i % n1]][b[i % n2]];
		ans2 += score[b[i % n2]][a[i % n1]];
	}
	printf("%d %d\n", ans1, ans2);
	return 0;
}
