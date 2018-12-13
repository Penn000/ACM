//2017-03-16
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
	long long a[10];
	int n = 3;
	while(cin>>a[0]>>a[1]>>a[2])
	{
		sort(a, a+n);
		cout<<a[0]<<"->"<<a[1]<<"->"<<a[2]<<endl;
	}

    return 0;
}
