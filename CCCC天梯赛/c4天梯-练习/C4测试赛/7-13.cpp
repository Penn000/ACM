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
		init(N);
		int idn = 0, k;
		while(n--){
			cin >> k;
			int a, b;
			cin >>a;
			idn = max(idn, a);
			k--;
			while(k--){
				cin >>b;
				idn = max(idn, b);
				Merge(a, b);
			}
		}
		int cnt = 0;
		for(int i = 1; i <= idn; i++)
		  if(fa[i] == i)
			cnt++;
		cout<<idn<<" "<<cnt<<endl;
		cin>>n;
		int a, b;
		while(n--){
			cin>>a>>b;
			int af = getfa(a);
			int bf = getfa(b);
			if(af == bf)cout<<"Y"<<endl;
			else cout<<"N"<<endl;
		}
	}

	return 0;
}
