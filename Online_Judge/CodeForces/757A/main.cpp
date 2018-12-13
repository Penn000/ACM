//2017.01.18
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int inf = 0x3f3f3f3f;
int book[100];

int main()
{
	string str;
	string bul = "Bulbbasaur";
	while(cin >> str)
	{
		memset(book, 0, sizeof(book));
		for(int i = 0; i < str.length(); i++)
		  	book[str[i]]++;
		book['u']/=2;
		book['a']/=2;
		int ans = inf;
		for(int i = 0; i < bul.length(); i++)
		  	if(ans > book[bul[i]])
			  	ans = book[bul[i]];
		cout<<ans<<endl;
	}

    return 0;
}
