#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110000;

string str[N];
int n;
bool fg;

bool check(int r1, int r2){
	int sum1 = 0, sum2 = 0, base = 1;
	int len = str[r1].length();
	for(int i = len-1; i >= 0; i--){
		sum1 += (str[r1][i]-'0')*base;
		sum2 += (str[r2][i]-'0')*base;
		base *= 10;
	}
	return sum1<sum2;
}

void dfs(int row, int step){
	if(fg)return;
	int len = str[row].length();
	if(step == len){
		if(check(row-1, row)){
			fg = true;
		}
		return;
	}
	while(step < len && str[row][step]!='?'){
		step++;
	}
	if(step==len)dfs(row, step);
	else{
		int bg = 0;
		if(step==0)bg = 1;
		for(int i = bg; i <= 9; i++){
			str[row][step] = '0'+i;
			dfs(row, step+1);
			if(fg)return;
			str[row][step] = '?';
		}
	}
}
void solve(){
	for(int i = 0; i < str[0].length(); i++){
		if(str[0][i] == '?'){
			if(i==0)str[0][i] = '1';
			else str[0][i] = '0';
		}
	}
	for(int i = 1; i < n; i++){
		int len = str[i].length();
		if(len < str[i-1].length()){
			cout<<"NO"<<endl;
			return;
		}else if(len == str[i-1].length()){
			fg = false;
			dfs(i, 0);
			if(!fg){
				cout<<"NO"<<endl;
				return;
			}
		}else{
			for(int j = 0; j < len; j++)
			  if(str[i][j] == '?'){
				  if(j == 0)str[i][j] = '1';
				  else str[i][j] = '0';
			  }
		}
	}
	cout<<"YES"<<endl;
	for(int i = 0; i < n; i++)
	  cout<<str[i]<<endl;
}

int main()
{
	while(cin>>n){
		for(int i = 0; i < n; i++)
		  cin>>str[i];
		solve();
	}

	return 0;
}
