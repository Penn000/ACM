//2017.01.20
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int n, m, x, y;
	long long k;
	long long maximum, minimum, cnt;
	while(cin>>n>>m>>k>>x>>y)
	{
		if(n==1){
			if(k%m==0)maximum = minimum = k/m;
			else{
				maximum = k/m+1;
				minimum = maximum-1;
			}
		}else{
			long long row = k/m;
			if(row*m != k)row++;
			if(n==2)maximum = (row+1)/n;
			else maximum = (row-2)/(n-1)+1;
			minimum = (row+n-2)/(2*n-2);
			if(minimum*(2*n-2) == (row+n-2) && row*m != k)
			  	minimum--;
		}
		int pos = (x-1)*m+y;
		if(n==1)
		{
			if(pos <= k%m)cnt = maximum;
			else cnt = minimum;
		}else
		{
			long long cyc = k/(m*(2*n-2));
			cnt = (x==1||x==n) ? cyc : 2*cyc;
			long long other = k-cyc*(m*(2*n-2));
			if(other < pos)cnt+=0;
			else if(((n-1-x)*m+y)>(other-m*n)||(x==1||x==n))cnt+=1;
			else cnt+=2;
		}

		cout<<maximum<<" "<<minimum<<" "<<cnt<<endl;
		
	}
	

    return 0;
}
