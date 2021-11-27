#include <stdio.h>

inline int abs (const int &x) {
	return x < 0 ? -x : x;
}

int n;
int fa[30003];	// ��ǰ�ڵ�������������
int s[30003];	// ��ǰ�����������Ľڵ�����
int d[30003];	// ��ǰ�ڵ��������������еĽڵ����� 

#define fa(x) fa[x]
#define size(x) s[x]
#define dis(x) d[x]

inline int get (int x) {
	if (fa(x) == x)
		return x;
	int grandfather = get(fa(x));
	dis(x) += dis(fa(x));
	fa(x) = grandfather;
	return fa(x);
}

int main () {
	scanf("%d", &n);
	for (int i = 1; i < 30003 ; i++) {
		fa(i) = i;
		size(i) = 1;
		dis(i) = 0;
	} 
	for (int i = 1; i <= n; i++) {
		char ch[4];
		int x, y;
		scanf("%s %d %d", &ch, &x, &y);
		int fx = get(x), fy = get(y); // x/y ���������� 
		if (ch[0] == 'M') {
			fa(fx) = fy;	// x ���������� y ������, �� fx �������Ϊ fy 
			dis(fx) = size(fy);		// fx �� fy �ľ��뼴����ǰ y/fy �������Ľڵ����� 
			size(fy) += size(fx);	// y �������ڵ��������� 
		}
		else 
			printf("%d\n", fx == fy ? abs(dis(x) - dis(y)) - 1 : -1);
	} 
	return 0;
} 
