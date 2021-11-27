#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long i=1,cnt=0;//¼ÇµÃlong long
	while(++i)
	{
		long long t=(long long)sqrt(0.5*i*(i+1));
		if(2*t*t==i*(i+1))printf("%10lld%10lld\n",t,i),cnt++;
		if(cnt==10)return 0;
	}
}
