#include <stdio.h>
#include <stack>
#include <queue>

int n;

inline void kagari () {
	std:: stack < int > s;
	std:: queue < int > q;
	std:: priority_queue < int > p;
	bool st = true, qu = true, pq = true;
	for (int i = 1; i <= n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		if (x == 1) {
			s.push(y);
			q.push(y);
			p.push(y);
		}
		else {
			if (s.empty()) {
				st = qu = pq = false;
				continue;
			}
			if (s.top() != y)
				st = false;
			if (q.front() != y)
				qu = false;
			if (p.top() != y)
				pq = false;
			s.pop();	q.pop();	p.pop();
		}
	}
	if ((st && qu) || (qu && pq) || (pq && st))
		printf("not sure\n");
	else if (st)
		printf("stack\n");
	else if (qu)
		printf("queue\n");
	else if (pq)
		printf("priority queue\n");
	else
		printf("impossible\n");
}

int main () {
	while (~scanf("%d", &n))
		kagari();
	return 0;
}
