//2016.8.16
#include<iostream>
#include<cstdio>
#include<set>

using namespace std;

set<int> st;

int main()
{
	int T, kase = 0;
	string s;
	cin>>T;
	while(T--)
	{
		cin>>s;
		st.clear();
		for(int i = 0; i < s.size(); i++)
		{
			st.insert(s[i]);
		}
		printf("Case #%d: ", ++kase);
		cout<<st.size()<<endl;
	}

	return 0;
}
