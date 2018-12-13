#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

string name[210];
int arr[210][210], a[210];

int main()
{
	int T, n, q, c, m;
	cin>>T;
	while(T--)
	{
		cin>>n>>q;
		cin>>c;
		map<string, int> mp;
		memset(arr, 0, sizeof(arr));
		for(int i = 0; i < c; i++){
		  	cin>>name[i];
			mp[name[i]] = i;
		}
		for(int i = 0; i < q; i++){
			cin >> m;
			string str;
			for(int j = 0; j < m; j++)
			{
				cin >> str;
				arr[mp[str]][i] = 1;
			}
		}/*
		for(int i = 0; i < c; i++)
		{
			for(int j = 0; j < q; j++)
			  	cout<<arr[i][j]<<" ";
			cout<<endl;
		}*/
		bool fg[210];
		for(int i = 0; i < n; i++)
		{
			memset(fg, 0, sizeof(fg));
			for(int j = 0; j < q; j++)
			{
				cin>>a[j];
				for(int k = 0; k < c; k++){
					if(arr[k][j] != a[j])
					  	fg[k] = 1;
				}
			}
			int cnt = 0, pos = 0;
			for(int j = 0; j < c; j++)
			{
				if(fg[j] == 0){
					pos = j;
					cnt++;
				}
			}
			if(cnt == 1){
				cout<<name[pos]<<endl;
			}else cout<<"Let's go to the library!!"<<endl;
		}
	}

	return 0;
}
