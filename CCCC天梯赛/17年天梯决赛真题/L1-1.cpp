#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int ans = -1;
	int n, cnt = 0;
	while(cin>>n){
		cnt++;
		if(ans != -1)continue;
		if(n == 250)ans = cnt;
	}
	cout<<ans<<endl;

	return 0;
}
