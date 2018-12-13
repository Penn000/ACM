#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, G[505][505];

bool judge(int c)
{
	for(int i = 0; i < n; i++){
		if(G[c][i] == 1){
			for(int j = i+1; j < n; j++){
				if(G[c][j] && !G[i][j])
				  	return true;
			}
		}
	}
	return false;
}

int main()
{
	int m;
	while(cin>>n>>m)
	{
		memset(G, 0, sizeof(G));
		int a, b;
		while(m--)
		{
			cin>>a>>b;
			G[a][b] = G[b][a] = 1;
		}
		int k, c;
		cin>>k;
		for(int i = 0; i < k; i++)
		{
			cin>>c;
			if(judge(c))cout<<"Red Alert: City "<<c<<" is lost!"<<endl;
			else cout<<"City "<<c<<" is lost."<<endl;
			for(int i = 0; i < n; i++)
			  	G[c][i] = G[i][c] = 0;
			if(i == n-1)cout<<"Game Over."<<endl;
		}
	}

    return 0;
}
