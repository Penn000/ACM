//2017-03-16
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

long long a[20];

int main()
{
	a[1] = 1;
	long long tmp = 1;
	for(int i = 2; i < 12; i++)
	{
		tmp *= i;
		a[i] = a[i-1]+tmp;
	}
	int n;
	while(cin>>n)
	{
		cout<<a[n]<<endl;
	}

    return 0;
}
