#include <stdio.h>
#include <stdbool.h>
#define N 514
int i, j;

inline int max (int x, int y) {
	return x > y ? x : y;
}

inline bool inn (int x) {
	return x != N;
}

struct NODE {
	char i;
	bool cr;
	int val;
	int sum;
} a[103];

inline char getch () {
	char ch;
	while (1) {
		scanf("%c", &ch);
		if ('A' <= ch && ch <= 'Z' || 'a' <= ch && ch <= 'z' || '0' <= ch && ch <= '9')
			return ch;
	}
}

inline int getx () {
	char ch = getch();	int x;
	if (ch == 'n') 
		x = N;
	else {
		x = ch - '0';
		while (1) {
			scanf("%c", &ch);
			if (!('0' <= ch && ch <= '9'))
				break;
			x = x * 10 + ch - '0';
		}
	}
	return x;
}



int main () {
	int t;
	scanf("%d", &t);
	while (t--) {
		int n = getx(), tw = 0;	
		char ch = getch();
		ch = getch();
		if (ch == 'n')
			tw = getx();
		int ans = 0, cnt = 0;
		bool error = false;
		for (i = 1; i <= n; i++) {
			ch = getch();
			if (ch == 'F') {
				cnt++;
				a[cnt].i = getch();
				int x = getx(), y = getx(), val = 0;
				a[cnt].sum = 0;
				a[cnt].cr = true;
				// 变量重复导致 CE 的判断 
				for (j = 1; j < cnt; j++)
					if (a[j].i == a[cnt].i)
						error = true;
				
				
				// 时间复杂度判断 
				if (x > y)	// 无法执行的循环 
					a[cnt].cr = false, val = 0;
				else if (inn(x) && inn(y))	// 没有 n: O(1) 
					val = 0;
				else if (!inn(x) && !inn(y))	// 都是 n: O(1)
				 	val = 0;
				else 
					val = 1;
				
				bool flag = true; // 当前循环是否可以运行 
				for (j = 1; j <= cnt; j++)
					if (a[j].cr == false)
						flag = false;
				if (flag == false)
					continue;
				
				a[cnt].sum = a[cnt - 1].sum + val;
				ans = max(ans, a[cnt].sum);
			} 
			else {
				if (cnt == 0)
					error = true;
				else
					cnt--;
			}
		}
		if (cnt != 0)
			error = true;
		printf("%s\n", error ? "ERR" : (ans == tw ? "Yes" : "No"));
	}
	return 0;
}
