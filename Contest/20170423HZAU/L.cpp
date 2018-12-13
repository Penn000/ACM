#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int T;
	string str;
	cin>>T;
	for(int kase = 1; kase <= T; kase++)
	{
		cin>>str;
		int len = str.length(), ans = 0;
		for(int i = 0; i < len-1; i++)
			if(str[i] == 'A' && str[i+1] == 'B')
			  	ans++;
		cout<<"Case #"<<kase<<":"<<endl;
		cout<<ans<<endl;
	}

	return 0;
}
