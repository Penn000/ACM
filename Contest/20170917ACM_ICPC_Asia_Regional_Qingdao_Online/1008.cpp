//2017-09-18
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<string, int> mp;

int main()
{
	mp["rat"] = 1;
	mp["ox"] = 2;
	mp["tiger"] = 3;
	mp["rabbit"] = 4;
	mp["dragon"] = 5;
	mp["snake"] = 6;
	mp["horse"] = 7;
	mp["sheep"] = 8;
	mp["monkey"] = 9;
	mp["rooster"] = 10;
	mp["dog"] = 11;
	mp["pig"] = 12;

	int T;
	cin>>T;
	string str1, str2;
	while(T--){
		cin>>str1>>str2;
		int ans = ((mp[str2]-mp[str1])+12)%12;
		if(ans == 0)ans = 12;
		cout<<ans<<endl;
	}

	return 0;
}
