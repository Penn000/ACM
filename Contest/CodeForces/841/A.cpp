//2017-08-22
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, k, book[30];
	string str;
	while(cin>>n>>k){
		cin>>str;
		memset(book, 0, sizeof(book));
		for(int i = 0; i < n; i++)
		  	book[str[i]-'a']++;
		int maxinum = 0;
		for(int i = 0; i < 26; i++){
			maxinum = max(maxinum, book[i]);
		}
		if(maxinum <= k)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}

	return 0;
}
