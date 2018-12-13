//2017-03-19
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

string str;
int len;

int search(int pos)
{
	int l, r, ans = 1;
	l = pos-1;
	r = pos+1;
	while(l >= 0 && r < len)
	{
		if(str[l] == str[r])
		{
			ans+=2;
			l--;
			r++;
		}else break;
	}
	return ans;
}

int search2(int pos)
{
	int l, r, ans = 0;
	l = pos;
	r = pos+1;
	while(l >= 0 && r < len)
	{
		if(str[l] == str[r])
		{
			ans+=2;
			l--;
			r++;
		}else break;
	}
	return ans;
}

int main()
{
	while(getline(cin, str))
	{
		len = str.length();
		int ans = 0, tmp;
		for(int i = 0; i < len; i++)
		{
			tmp = search(i);
			if(tmp>ans)ans = tmp;
			tmp = search2(i);
			if(tmp>ans)ans = tmp;
		}
		cout<<ans<<endl;
	}

    return 0;
}
