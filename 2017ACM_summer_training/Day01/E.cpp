//2017-08-01
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;


bool grid[20][20], tmp[20][20];
int n, m, ans[20], res[20];

void flip(int x, int y)
{
	tmp[x][y] = !tmp[x][y];
	if(x-1>=0)tmp[x-1][y] = !tmp[x-1][y];
	if(y-1>=0)tmp[x][y-1] = !tmp[x][y-1];
	tmp[x+1][y] = !tmp[x+1][y];
	tmp[x][y+1] = !tmp[x][y+1];
}

void solve()
{
	int penn, minflip = 0x3f3f3f3f;
	bool fg = false;
	for(int i = 0; i < (1<<m); i++)
	{
		for(int x = 0; x < n; x++)
		  	for(int y = 0; y < m; y++)
			  	tmp[x][y] = grid[x][y];
		for(int y = 0; y < m; y++)
			if(i&(1<<y))
			  	flip(0, m-1-y);
		ans[0] = i;
		for(int x = 1; x < n; x++){
			penn = 0;
			for(int y = 0; y < m; y++){
				if(tmp[x-1][y]){
					flip(x, y);
					penn += (1<<(m-1-y));
				}
			}
			ans[x] = penn;
		}
		bool ok = true;
		for(int j = 0; j < m; j++)
		  	if(tmp[n-1][j])
			  	ok = false;
		if(ok){
			fg = true;
			int cnt = 0;
			for(int j = 0; j < n; j++){
				for(int pos = 0; pos < m; pos++)
				  	if(ans[j]&(1<<(m-1-pos)))cnt++;
			}
			if(cnt < minflip){
				minflip = cnt;
				for(int k = 0; k < n; k++)
				  	res[k] = ans[k];
			}
		}
	}
	if(!fg)cout<<"IMPOSSIBLE"<<endl;
	else{
		for(int j = 0; j < n; j++){
			for(int pos = 0; pos < m; pos++)
			  	if(pos == m-1)cout<<(res[j]&(1<<(m-1-pos))?1:0)<<endl;
				else cout<<(res[j]&(1<<(m-1-pos))?1:0)<<" ";
		}
	}
}

int main(){
    int T;
    cin>>T;
    for(int kase = 1; kase <= T; kase++){
        n = 5;
        m = 6;
        for(int i = 0; i < n; i++)
	  	    for(int j = 0; j < m; j++)
		  	    cin>>grid[i][j];
        cout<<"PUZZLE #"<<kase<<endl;;
	    solve();
    }

    return 0;
}
