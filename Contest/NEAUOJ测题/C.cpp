#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int book[256];

int main()
{
	string str;
	while(cin>>str){
		memset(book, 0, sizeof(book));
		for(int i = 0; i < str.length(); i++)
			book[str[i]]++;
		int maxinum = 0;
		char ch;
		for(int i = 'a'; i <= 'z'; i++){
			if(book[i] > maxinum){
				maxinum = book[i];
				ch = i;
			}
		}
		printf("%c\n", ch);
	}

	return 0;
}
