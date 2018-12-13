#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

int ord[26];

struct Node{
	string str;
	bool operator<(Node x) const{
		int len1 = str.length();
		int len2 = x.str.length();
		for(int i = 0; i < len1 && i < len2; i++){
			if(str[i] == x.str[i])continue;
			return ord[str[i]-'a'] < ord[x.str[i]-'a'];
		}
		if(len1 < len2)return true;
		else return false;
	}
}node[1010];

int main()
{
	int n;
	string str;
	while(cin>>n){
		cin>>str;
		for(int i = 0; i < 26; i++){
			ord[str[i]-'a'] = i;
		}
		for(int i = 0; i < n; i++){
			cin>>node[i].str;
		}
		sort(node, node+n);
		for(int i = 0; i < n; i++)
		  	cout<<node[i].str<<endl;
	}

	return 0;
}
