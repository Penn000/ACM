#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 10005;

int fa[N];

void init(int n){
	for(int i = 1; i <= n; i++)
	  fa[i] = i;
}

int getfa(int x){
	if(fa[x] == x)return x;
	return fa[x] = getfa(fa[x]);
}

void Merge(int a, int b){
	int af = getfa(a);
	int bf = getfa(b);
	if(af != bf){
		fa[bf] = af;
	}
}

int main()
{
	int n;
	while(cin >> n){
		init(n);
		char op;
		int c1, c2;
		while(cin>>op){
			if(op == 'I'){
				cin>>c1>>c2;
				Merge(c1, c2);
			}else if(op == 'C'){
				cin>>c1>>c2;
				int c1f = getfa(c1);
				int c2f = getfa(c2);
					if(c1f == c2f){
						cout<<"yes"<<endl;
					}else cout<<"no"<<endl;
			}else if(op == 'S')
			  break;
		}
		int cnt = 0;
		for(int i = 1; i <= n; i++)
		  if(fa[i] == i)
			cnt++;
		if(cnt == 1)cout<<"The network is connected."<<endl;
		else cout<<"There are "<<cnt<<" components."<<endl;
	}

	return 0;
}
