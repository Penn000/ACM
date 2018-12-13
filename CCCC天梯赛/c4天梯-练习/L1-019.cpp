//2017-03-16
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int a, b, n, A, B;
	while(cin>>a>>b)
	{
		A = a; B = b;
		int n;
		cin>>n;
		int a1, a2, b1, b2;
		for(int i = 0; i < n; i++)
		{
			cin>>a1>>a2>>b1>>b2;
			if(a < 0 || b < 0)continue;
			if(a2==a1+b1 && b2!=a1+b1)a--;
			if(a < 0 || b < 0)continue;
			if(a2!=a1+b1 && b2==a1+b1)b--;
		}
		if(a<0)cout<<"A"<<endl<<B-b<<endl;
		else if(b<0) cout<<"B"<<endl<<A-a<<endl;
	}

	return 0;
}
