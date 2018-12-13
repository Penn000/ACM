// 2018-07-29
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int n, a;
	cin>>n;
	long long sum = 0;
	int mx=0;
	for(int i = 0; i < n; i++){
		cin>>a;
		sum += a;
		mx = max(mx, a);
	}
	if(mx > sum-mx)cout<<sum-mx<<endl;
	else cout<<sum/2<<endl;

	return 0;
}
