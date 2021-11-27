#include <stdio.h>
#include <stack>
#define ll long long
#define MDN 10007ll
#define kl -1
#define kr -2
#define jia -3
#define cheng -4
int n, m = 0;
ll d[100003][2];	// [i][k] 前 i 个进行计算的符号计算结果为 k 的答案数量 

int main () {
	scanf("%d", &n);
	std:: stack <int> ch;	// -1, (   -2, )   -3, +   -4 * 
	for (int i = 1; i <= n; i++) {
		char ch;
		scanf("%c", &ch);
		
	}
	return 0;
}
