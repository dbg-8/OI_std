#include <stdio.h> 
#include <string.h>

char ch[1000003];
int main () {
	scanf("%s", &ch);
	int n = strlen(ch);
	for (int i = 0; i <= n - 3; i++)
		if (ch[i] == 'Q' && ch[i + 1] == 'A' && ch[i + 2] == 'Q') {
			printf("%d\n", i + 1);
			return 0;
		}
	return 0;
}
