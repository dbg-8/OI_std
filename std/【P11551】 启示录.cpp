#include <iostream>
#include <algorithm>
#define ll long long

ll f[24][3], d[24];

inline void init () {
    f[0][0] = 1;
	f[0][1] = f[0][2] = d[0] = 0;
    for (int i = 1; i < 24; i++) {
        f[i][0] = 9 * (f[i - 1][0] + f[i - 1][1] + f[i - 1][2]);
        f[i][1] = f[i - 1][0];
        f[i][2] = f[i - 1][1];
        d[i] = 10 * d[i - 1] + f[i - 1][2];
    }
	
}
inline int getw (int x) {
	int ret = 3;
    while (1) { 
    	if (d[ret] >= x)
    		break;
        ret++;
    }
    return ret;
}
inline void sovle () {
	int x;
	scanf("%d", &x);
    int w = getw(x);
    for (int i = w, k = 0; i > 0; i--) {
        for (int j = 0; j <= 9; j++) {
            ll ret = d[i - 1]; 
            if (j == 6 || k == 3)
                for (int o = std:: max(3 - k - (j == 6 ? 1 : 0), 0); o < 3; o++)
                    ret += f[i - 1][o];
            if (ret < x)
	             	x -= ret;
            else {
                printf("%d", j);
                if (k < 3) {
                    if (j == 6)
						k++;
                    else
						k = 0;
                }
                break;
            }
        } 
    }
    printf("\n");
} 

int main() {
    int t;
    scanf("%d", &t);
    while (t--) 
    	sovle();
    return 0;
}
