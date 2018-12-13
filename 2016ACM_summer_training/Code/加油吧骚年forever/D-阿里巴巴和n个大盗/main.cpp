#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int n, m;
	while(cin>>n>>m)
	{
		if(n%2==1)
		{
			cout<<"-1"<<endl;
		}
		else
		{
			cout<<m-3<<endl;
		}
	}

	return 0;
}
