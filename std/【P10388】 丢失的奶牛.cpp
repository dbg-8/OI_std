// nͷţ ÿһͷţ��һ����ͬ�ı�� (1-n ���ظ�)��
// ֪��ÿͷţ��߱��Լ����С��ţ����Ŀ
// ��ÿͷţ�ı�š�
#include <stdio.h>
#include <iostream>
using namespace std;
int n, a[8003], ans[8003];
bool vis[8003] = { false };
int main() {
	cin >> n;
	for (int i = 2; i <= n; i++) 
		scanf("%d", &a[i]);
	vis[a[n] + 1] = true;
	ans[n] = a[n] + 1;
	for (int i = n - 1; i >= 1; i--) {
		int j, sum = a[i];
		for (j = 1; j <= n; j++) 
			if (!vis[j]) {
				sum--;
				if (sum < 0) {
					vis[j] = true;
					break;
				}
			}
		ans[i] = j;
	}
	for (int i = 1; i <= n; i++)
		printf("%d\n", ans[i]);
	return 0;
} 
