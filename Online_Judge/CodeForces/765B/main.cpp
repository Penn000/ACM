//2017-02-14
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int book[30];

int main()
{
	string S;
	char cur_max;
	bool fg;
	while(cin>>S)
	{
		fg = true;
		memset(book, 0, sizeof(book));
		for(int i = 0; i < S.length(); i++)
		  	book[S[i]-'a']++;
		for(int i = 1; i < 26; i++)
		  	if(book[i]!=0 && book[i-1]==0)
			{
				fg = false;
				break;
			}
		cur_max = S[0];
		if(cur_max != 'a')fg = false;
		for(int i = 1; i < S.length(); i++)
		{
			if(S[i]>cur_max && S[i]-cur_max==1)cur_max = S[i];
			else if(S[i]>cur_max && S[i]-cur_max>1){
				fg = false;
				break;
			}
		}
		if(fg)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}

    return 0;
}
