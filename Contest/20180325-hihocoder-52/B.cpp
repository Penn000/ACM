#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};
map<string, long long> dp;
string M[25];
int n, m;

bool isOK(int x, int y){
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx < 0 || nx >= n || ny < 0 || ny >= m)
		  continue;
		if(M[nx][ny] == '1')return true;
	}
	return false;
}

string toString(){
	string str(n*m, '0');
	for(int i = 0; i < n; i++)
	  for(int j = 0; j < m; j++)
		str[i*m+j] = M[i][j];
	return str;
}

long long dfs(int mie){
	if(mie == 1)return 1;
	if(dp[toString()] != 0)return dp[toString()];
	dp[toString()] = 0;
	long long sum = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(M[i][j] == '0' && isOK(i, j)){
				M[i][j] = '1';
				sum += dfs(mie-1);
				M[i][j] = '0';
			}
		}
	}
	return dp[toString()] = sum;
}

int main()
{
	while(cin>>n>>m){
		int mie = 0;
		dp.clear();
		for(int i = 0; i < n; i++){
			cin>>M[i];
			for(int j = 0; j < m; j++){
				if(M[i][j] == '0')mie++;
			}
		}
		cout<<dfs(mie)<<endl;
	}

	return 0;
}
