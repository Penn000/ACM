//2018-08-06
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 60;
const int dx[4] = {0, 0, 1, -1};
const int dy[4] = {1, -1, 0, 0};

char M[N][N];
int cnt, n, m;

void dfsX(int x, int y){
	for(int i = 0; i < 4; i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx<0 || nx>=n || ny<0 || ny>=m || M[nx][ny]=='.' || M[nx][ny]=='*')
		  continue;
		if(M[nx][ny]=='X'){
			M[nx][ny] = '*';
			dfsX(nx, ny);
		}
	}
}

void dfs(int x, int y){
	for(int i = 0; i < 4; i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx<0 || nx>=n || ny<0 || ny>=m || M[nx][ny]=='.')
		  continue;
		if(M[nx][ny]=='X'){
			M[nx][ny] = '*';
			dfsX(nx, ny);
			cnt++;
		}
		if(M[nx][ny]=='*'){
			M[nx][ny] = '.';
			dfs(nx, ny);
		}
	}
}

int main()
{
	int kase = 0;
	freopen("input.txt", "r", stdin);
	while(cin>>m>>n){
		if(!n&&!m)break;
		for(int i = 0; i < n; i++)
		  for(int j = 0; j < m; j++)
			cin>>M[i][j];
		vector<int> vec;
		for(int i = 0; i < n; i++)
		  for(int j = 0; j < m; j++)
			if(M[i][j] == '*'){
				cnt = 0;
				M[i][j] = '.';
				dfs(i, j);
				vec.push_back(cnt);
			}
		sort(vec.begin(), vec.end());
		int len = vec.size();
		cout<<"Throw "<<++kase<<endl;
		for(int i = 0; i < len; i++){
			cout<<vec[i];
			if(i == len-1)cout<<endl;
			else cout<<" ";
		}
		cout<<endl;
	}

	return 0;
}
