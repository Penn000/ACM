//2017-02-14
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int main()
{
	int n, cnt1, cnt2;
	string src, line;
	while(cin>>n)
	{
		cnt1 = 0;
		cnt2 = 0;
		cin >> src;
		for(int i = 0; i < n; i++)
		{
			cin>>line;
			if(src[0]==line[0]&&src[1]==line[1]&&src[2]==line[2])cnt1++;
			if(src[0]==line[5]&&src[1]==line[6]&&src[2]==line[7])cnt2++;
		}
		if(cnt1==cnt2)cout<<"home"<<endl;
		else cout<<"contest"<<endl;
	}

    return 0;
}
