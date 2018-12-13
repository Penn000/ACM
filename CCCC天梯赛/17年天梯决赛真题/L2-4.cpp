#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 11000;

int fa[N];

void init(){
	for(int i = 1; i < N; i++)
	  fa[i] = i;
}

int getfa(int x){
	if(x == fa[x])return x;
	return fa[x] = getfa(fa[x]);
}

void merge(int a, int b){
	int af = getfa(a);
	int bf = getfa(b);
	if(af != bf)fa[bf] = af;
}

int main()
{
	int n;
	while(cin>>n){
		init();
		int k, a, b, maxId = 0;
		while(n--){
			cin>>k;
			cin>>a;
			maxId = max(maxId, a);
			k--;
			while(k--){
				cin>>b;
				maxId = max(maxId, b);
				merge(a, b);
			}
		}
		int cnt = 0;
		for(int i = 1; i<= maxId; i++)
		  if(fa[i] == i)
			cnt++;
		cout<<maxId<<" "<<cnt<<endl;
		cin>>k;
		while(k--){
			cin>>a>>b;
			int af = getfa(a);
			int bf = getfa(b);
			if(af == bf)cout<<"Y"<<endl;
			else cout<<"N"<<endl;
		}
	}

	return 0;
}
