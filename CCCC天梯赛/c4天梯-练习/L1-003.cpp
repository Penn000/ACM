//2017-03-15
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int book[15];
string str;

int main()
{
	while(cin>>str)
	{
		memset(book, 0, sizeof(book));
		for(int i = 0; i < str.length(); i++)
		  	book[str[i]-'0']++;
		for(int i = 0; i < 10; i++)
		  	if(book[i])
			  	cout<<i<<":"<<book[i]<<endl;
	}

    return 0;
}
