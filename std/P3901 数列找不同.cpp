#include <stdio.h>
#include <math.h>
#include <algorithm> 
#define ci const int &

int n, m;
int sn;				// =sqrt(n), �ֿ��� 
int curl, curr;		// ��ǰ���� 
int sum = 0;		// ��ǰ����Ĵ� 
int a[100003];
int cnt[100003];	// ����ÿ���� x �ڵ�ǰ����[curl, curr]�г��ֵĴ��� 
bool ans[100003];

struct QUERY {
	int l, r;	// ѯ������Ӧ���� 
	int p;		// ѯ�ʵı�� 
} q[100003]; 

// �ֳ� sqrt(n) �������˵�����, ����˵����ڿ���ͬ���Ҷ˵����� 
inline bool cmp (const QUERY &x, const QUERY &y) {
	return x.l / sn == y.l / sn ? x.r < y.r : x.l < y.l;  
}

inline void add (ci pos) {		// �������ӽڵ� pos 
	cnt[a[pos]]++; 
	if (cnt[a[pos]] == 1)
		sum++;
	return;
}
inline void del (ci pos) {		// ����ɾȥ�ڵ� pos 
	cnt[a[pos]]--;
	if (cnt[a[pos]] == 0)
		sum--;
	return;
}

int main () {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= m; i++)
		scanf("%d %d", &q[i].l, &q[i].r), q[i].p = i;

	sn = sqrt(n);
	std:: sort(q + 1, q + m + 1, cmp);
	for (int i = 1; i <= m; i++) {
		int l = q[i].l, r = q[i].r;
		while (curl < l)
			del(curl++);
		while (curl > l)
			add(--curl);
		while (curr < r)
			add(++curr);
		while (curr > r)
			del(curr--);
		if (sum == (r - l + 1))
			ans[q[i].p] = true; 
	}

	for (int i = 1; i <= m; i++)
		printf("%s\n", ans[i] == true ? "Yes" : "No");
	return 0;
}
