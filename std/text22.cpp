#include<cstdio>
#include<algorithm>
using namespace std;
double k,a1,a2,b1,b2,dx,dy,b;
double x1,x2,y1,y2,res;
int t;
int main()
{
	scanf("%d",&t);
	for(int i=1;i<=t;++i)
	{
		scanf("%lf%lf%lf%lf%lf%lf%lf%lf",&a1,&b1,&a2,&b2,&x1,&y1,&x2,&y2);
		if(x1>x2)
			swap(x1,x2);
		if(y1>y2)
			swap(y1,y2);
		if(max(a1,a2)<x1||min(a1,a2)>x2||max(b1,b2)<y1||min(b1,b2)>y2)
			printf("F\n");
		else if(a1==a2)
			printf("T\n");
		else {
			k=(b1-b2)/(a1-a2);
			b=b1-k*a1;
			if(k>0)
			{
				if((b1-b2)/(a1-a2)*x1+b1 - k * a1 > y2||k*x2+b<y1)
				printf("F\n");
				else
				printf("T\n");
			}
			else if(k<0) {
				if(k*x1+b<y1||k*x2+b>y2)
					printf("F\n");
				else
					printf("T\n");
			}
			else
				printf("T\n");
		}
	}
	return 0;
}
