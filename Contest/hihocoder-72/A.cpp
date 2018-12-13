//2018-08-12
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 350;
const int INF = 0x3f3f3f3f;

int M[N][N], n, m, s;

int main()
{
	while(cin>>n>>m>>s){
		for(int i = 0; i < n; i++)
		  for(int j = 0; j < m; j++){
			  cin>>M[i][j];
		  }
		for(int i = 1; i < n; i++)
		  for(int j = 0; j < m; j++)
			M[i][j] += M[i-1][j];
		for(int j = 1; j < m; j++)
		  for(int i = 0; i < n; i++)
			M[i][j] += M[i][j-1];
		int ans = -INF;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				for(int x = 0; x <= i; x++){
					for(int y = 0; y <= j; y++){
						if((i-x+1)*(j-y+1) < s)break;
						int tmp = M[i][j];
						if(x-1 >= 0)tmp -= M[x-1][j];
						if(y-1 >= 0)tmp -= M[i][y-1];
						if(y-1>=0 && x-1>=0)tmp += M[x-1][y-1];
						ans = max(ans, tmp);
					}
				}
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}
