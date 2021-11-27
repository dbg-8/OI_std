/*
��ڤ�ڣ��� 
������һ��С������? �㿴����ɰ���!

 
n ����, m �ֻ�ƿ 
d i j    ��ʾǰ i �ֻ�����ǰ�� j ����ƿ��, 
�ҵ� i �ֻ����ڵ� j ����ƿ��ʱ���������ֵ 
d[i][j] = max(d[i][j], d[i-1][k] + a[i][j]), 
	���� i��[2,n], j��[i,m-n+i], k��[i-1,j-1] 
	ͬʱ���Է��� k ������j, ��������ö�� k 
��ʼ�� d[1][i] = a[1][i], ���� i��[1,m]
ans = max(d[n][i]), ���� i��[n, m] 

�����, ����ôû�а�� 
*/
#include <stdio.h> 
#define ll long long

int n, m;
ll a[103][103];		// Power ֵ 
ll d[103][103];		// �©`�ԩ`��, ��ϸ��Ϣ���� 
int history[103][103];	// ��ʾ�� i �仨���ڻ�ƿ j ʹ�� d[i][j] ���ʱ�� i-1 �仨����λ�� 
int ans2[103];

int main () {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%lld", &a[i][j]);
	for (int i = 1; i <= m; i++)
		d[1][i] = a[1][i];
	for (int i = 2; i <= n; i++) {
		ll k = -0x7FFFFFFF;
		int pos;
		for (int j = i; j <= m - n + i; j++) {
			if (k < d[i - 1][j - 1]) {
				k = d[i - 1][j - 1];
				pos = j - 1;
			}
			d[i][j] = k + a[i][j];
			history[i][j] = pos;
		}
	}
	ll ans = -0x7FFFFFFF;
	int pos = n;
	for (int i = n; i <= m; i++) {
		if (d[n][i] > ans) {
			ans = d[n][i];
			pos = i;
		}
	}
	printf("%lld\n", ans);
	for (int i = n; i >= 1; i--) {
		ans2[i] = pos;
		pos = history[i][pos];
	}
	for (int i = 1; i <= n; i++)
		printf("%d ", ans2[i]);
	printf("\n");
	return 0;
}
