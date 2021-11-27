#include <stdio.h>
#define M114514 19650827
int n;
int a[1003];
int d[1003][1003];	// ���һ���˴���߲���ʱ����[l,r]�ķ������� 
int f[1003][1003];	// ���һ���˴��ұ߲���ʱ����[l,r]�ķ������� 

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]), d[i][i] =  1;
	for (int len = 2; len <= n; len++) {
		for (int l = 1; l + len - 1 <= n; l++) {
			int r = l + len - 1;
			
			// ���� d, ������Ϊ l 
			if (a[l] < a[l + 1])	// ǰһ��������Ϊ l + 1
				d[l][r] += d[l + 1][r];
			if (a[l] < a[r])	// ǰһ��������Ϊ r
				d[l][r] += f[l + 1][r];
			d[l][r] %= M114514;
			
			// ���� f, ������Ϊ r 
			if (a[l] < a[r])	// ǰһ��������Ϊ l
				f[l][r] += d[l][r - 1];
			if (a[r - 1] < a[r])	// ǰһ��������Ϊ r - 1
				f[l][r] += f[l][r - 1];
			f[l][r] %= M114514;
		}
	}
	printf("%d\n", (d[1][n] + f[1][n]) % M114514);
	return 0;
} 
