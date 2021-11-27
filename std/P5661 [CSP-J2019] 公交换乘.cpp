#include <stdio.h>
#include <utility>
#include <deque>

int n, ans = 0;
std:: deque < std:: pair < int, int > > a;
#define ti first
#define pr second

int main () {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int mod, price, time;
		scanf("%d %d %d", &mod, &price, &time);
		if (mod == 0) 	// subway
			a.push_back(std:: make_pair(time, price));
		else {	// bus
			while (!a.empty())
				if (time - a.front().ti > 45)
					a.pop_front();
				else
					break;
			for (int i = 0; i < a.size(); i++)
				if (a[i].pr != -1 && price <= a[i].pr) {
					a[i].pr = -1;
					price = 0;
					break;
				}
		}
		ans += price; 
	}
	printf("%d\n", ans);
	return 0;
}
