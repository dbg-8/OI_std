#include <stdio.h>
#include <utility>
#include <stack>
#define N 100003

inline int g (const int &x) {
	return x == 1 ? 0 : 1;
}

struct NODE {
	char op;
	bool isf;
	int father;
	int val;
	int ls, rs;
} a[1000003];

int cnt = N+1;
int n;

inline void start () {
	for (int i = 0; i < 1000003; i++)
		a[i].father = -1, a[i].op = ' ', a[i].isf = false, a[i].ls = -1, a[i].rs = -1, a[i].val = 0;
	return;
}

inline int mathd (const int &x, const int &y, const char &op) {
	if (op == '&')
		return (x == 1 && y == 1) ? 1 : 0;
	else
		return (x == 1 || y == 1) ? 1 : 0;
}

inline void build (int x) {
	if (x <= N) {
		if (a[x].isf)
			a[x].val = g(a[x].val);
		return;
	}
	build(a[x].ls); build(a[x].rs);
	a[x].val = mathd(a[a[x].ls].val, a[a[x].rs].val, a[x].op);
	if (a[x].isf)
		a[x].val = g(a[x].val);
}

inline int update (int x, int ret) {
	if (ret == a[x].val)
		return ret;
	if (a[x].father == -1) {
		return ret;
	}
	int y = a[x].val;	a[x].val = ret;
	int fa = a[x].father;
	int l = a[fa].ls, r = a[fa].rs, qwq = mathd(a[l].val, a[r].val, a[fa].op);
	if (a[fa].isf)
		qwq = g(qwq);
	a[x].val = y;
	return update(a[x].father, qwq);
}

inline void scan () {
	char ch;	int x, y; bool fl, fr;
	std:: stack < std:: pair < int, bool > > st;
	while (1) {
		scanf("%c", &ch);
		if (ch == ' ')
			continue;
		if (ch == '\n')
			break;
		if (ch == 'x') {
			scanf("%d", &x);
			st.push(std:: make_pair(x, false));
		} 
		else if (ch == '!') {
			x = st.top().first, fl = st.top().second;
			st.pop();
			st.push(std:: make_pair(x, g(fl)));
		}
		else {
			x = st.top().first, fl = st.top().second;	st.pop();
			y = st.top().first, fr = st.top().second;	st.pop();
			cnt++;
			a[x].father = cnt, a[x].isf = fl;
			a[y].father = cnt, a[y].isf = fr;
			a[cnt].ls = x, a[cnt].rs = y;
			a[cnt].op = ch;
			st.push(std:: make_pair(cnt, false));
		}
	}
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
		scanf("%d", &a[i].val);
	build(cnt);
	int q;
	scanf("%d", &q);
	while (q--) {
		int x, y;
		scanf("%d", &x);
		printf("%d\n", update(x, g(a[x].val)));
	}
	return;
}

int main() {
	start();
	scan();
	return 0;
}
