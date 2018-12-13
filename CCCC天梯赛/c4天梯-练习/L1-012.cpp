//2017-03-16
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[20];

int main()
{
	a[0] = 1;
	for(int i = 1; i < 12; i++)
	  	a[i] = a[i-1]*2;
	int n;
	while(cin>>n)
	{
		cout<<"2^"<<n<<" = "<<a[n]<<endl;
	}

    return 0;
}
