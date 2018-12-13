#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

struct Node{
	string name;
	int cnt, uniCnt;

	bool operator<(Node x) const{
		if(uniCnt == x.uniCnt)return cnt<x.cnt;
		return uniCnt>x.uniCnt;
	}
}nodes[1510];

int book[1510];

int main()
{
	int n, a;
	while(cin>>n){
		for(int id = 0; id < n; id++){
			cin>>nodes[id].name>>nodes[id].cnt;
			memset(book, 0, sizeof(book));
			for(int i = 0; i < nodes[id].cnt; i++){
				cin>>a;
				book[a] = 1;
			}
			int sum = 0;
			for(int i = 1; i <= 1005; i++)
			  sum+=book[i];
			nodes[id].uniCnt = sum;
		}
		sort(nodes, nodes+n);
		if(n == 0)cout<<"- - -"<<endl;
		if(n == 1)cout<<nodes[0].name<<" - -"<<endl;
		else if(n==2)cout<<nodes[0].name<<" "<<nodes[1].name<<" -"<<endl;
		else cout<<nodes[0].name<<" "<<nodes[1].name<<" "<<nodes[2].name<<endl;
	}
	return 0;
}
