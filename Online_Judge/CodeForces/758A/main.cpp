//2017.01.19
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int a[110];

int main()
{
	int n; 
	while(cin >> n)
	{
		int maxium = 0;
		for(int i = 0; i < n; i++)
		{
			cin >> a[i];
			if(a[i] > maxium)
			  	maxium = a[i];
		}
		int ans = 0;
		for(int i = 0; i < n; i++)
		  	ans += maxium-a[i];
		cout << ans << endl;
	}

    return 0;
}
