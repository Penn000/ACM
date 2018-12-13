//2016.8.15
#include<iostream>
#include<cstdio>

using namespace std;

int main()
{
	int n, m, T;
	cin>>T;
	while(T--)
	{
		cin>>n>>m;
		if(n%2==1 || m%2==1)
		  cout<<"UDK"<<endl;
		else
		  cout<<"RU"<<endl;
	}
	return 0;
}
