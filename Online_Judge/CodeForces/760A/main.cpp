//2017.01.31
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int mouth[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main()
{
	int m, d;
	while(cin>>m>>d)
	{
		int ans = (mouth[m]-(7-d+1)-1)/7+1+1;
		cout<<ans<<endl;
	}

    return 0;
}
