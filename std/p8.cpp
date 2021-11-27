#include <stdio.h>
#include <iostream>
using namespace std;
int d1[1003], d2[1003];
int main() {
	int cnt=0;
	for (int i =1 ; i<=4;i++)
		for(int j = 1; j <= 4; j++)
			for (int k = 1; k <= 4; k++)
				for (int l = 1; l <= 4; l++) {
					if(i == k || j == l)
						continue;
					bool fl = 0;
					for (int o = 1; o <= cnt; o++)
						if(d1[o] == k&& d2[o] == l)
							fl = 1;
					if (fl) 
						continue;
					d1[++cnt] = k, d2[cnt] =  l;
				} 
	cout<<cnt << '\n';
	printf("Sto lds Orz\n\nSto zzy Orz\n\n");
	return 0;
} 
