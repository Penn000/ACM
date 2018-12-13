#include<iostream>

using namespace std;

int gcd(int a, int b)
{
	return b ? gcd(b, a%b) : a;
}

int main()
{
	int s, n, m;
	while(cin >> s >> n >> m && s && n && m)
	{
		int g = gcd(n, m);
		int c = n/g;
		int d = m/g;
		if(((n+m)/g)%2==1)cout<<"NO"<<endl;
		else cout<<c+d-1<<endl;
	}

	return 0;
}
