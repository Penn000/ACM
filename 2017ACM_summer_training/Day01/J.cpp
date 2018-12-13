//2017-10-15
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1100;
bool a[N][N];

int main()
{
	long long k;
	while(cin>>k){
		int n = 0;
		while((1<<n) <= k)
		  	n++;
		if(n)n--;
		int step = n*2+1;
		int num = (1<<n);
		memset(a, 0, sizeof(a));
		n = 3*n+3;
		a[1][3] = 1;
		for(int i = 4; i <= n; i++){
			if(i%3 == 0)a[i][i-1] = a[i][i-2] = 1;
			else if((i-1)%3 == 0)a[i][i-1] = 1;
			else if((i-2)%3 == 0)a[i][i-2] = 1;
		}
		a[n][2] = 1;
		for(int i = n+1; i < n+step; i++)
		  	a[i][i+1] = 1;
		a[n+step-1][2] = 1;
		int tmp = k - num, ptr = 1;
		while(tmp){
			int fg = (1&tmp);
			tmp>>=1;
			if(fg)a[(ptr+1)/2*3][ptr+n] = 1;
			ptr+=2;
		}
		if(k != num)n+=(step-1);
		cout<<n<<endl;
		for(int i = 1; i <= n; i++){
		  	for(int j = 1; j <= n; j++)
				if(a[i][j] || a[j][i])
				  cout<<'Y';
				else cout<<'N';
			cout<<endl;
		}
	}

	return 0;
}
