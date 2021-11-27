#include <stdio.h>
#define ll long long

int n;
ll sum[500003];	// 前 i 个区间价值之和 
ll tzs[500003];	// 前 i 个区间有多少个团子 
int top = 0;
ll depth = 0; // 栈内有多少个团子 
struct NODE {
	ll x, y;
} st[500003];
#define val(x, y) ((x + y) * (y - (x) + 1) / 2)

int main () {
//	freopen("stack2.in", "r", stdin);
//	freopen("stack2my.out", "w", stdout);
	scanf("%d", &n);
	for (register int i = 1; i <= n; i++) {
		register int x;	register ll y, z;	register ll ans = 0;
		scanf("%d %lld", &x, &y);
		if (x == 1) {
			scanf("%lld", &z);
			st[++top].x = y, st[top].y = z;
			sum[top] = sum[top - 1] + val(y, z);
			tzs[top] = tzs[top - 1] + (z - y + 1);
			depth = tzs[top]; 
		}
		else {
			register int l = 1, r = top;
			while (l < r) {
				int mid = (l + r) >> 1;
				if (tzs[top] - tzs[mid - 1] < y)
					r = mid;
				else
					l = mid + 1;
			}
			if (tzs[top] - tzs[l - 1] > y)
				l++;
		//	for (int i = 1; i <= top; i++)
		//		printf("(%d, %d, %d, %d)%c", st[i].x, st[i].y, sum[i], tzs[i], i == top ? '\n' : ' '); 
			// l 和他右边的所有都是被购买的区间 
			z = y - tzs[top] + tzs[l - 1];
			ans += sum[top] - sum[l - 1];
			top = l - 1;
		//	printf("\t %d %d %d\n", l, top);
			ans += val(st[top].y - z + 1, st[top].y);
			sum[top] -= val(st[top].y - z + 1, st[top].y);
			tzs[top] -= z;
			st[top].y -= z;
			sum[top + 1] = 0;
			printf("%lld\n", ans);
		}
	}
	return 0;
}
