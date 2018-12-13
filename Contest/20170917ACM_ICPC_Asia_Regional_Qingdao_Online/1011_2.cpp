#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long  p;
		cin>>p;
		double x=sqrt(12*p-3);
		if(x!=(long long)x)
		{
			cout<<"NO"<<endl;
			continue;

		}
		double y=(3+x)/6;
		if(y!=(long long)y)
		{
			cout<<"NO"<<endl;
			continue;

		}
		double z=(3-x)/6;
		if(z!=(long long)z && z>=0)
		{
			cout<<"NO"<<endl;
			continue;

		}
		cout<<"YES"<<endl;

	}

}

