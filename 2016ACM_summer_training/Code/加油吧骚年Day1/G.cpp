#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 110000;

string str[N];
int n;;

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
			int pos = -1;
			for(int j = 0; j < len; j++){
				if(str[i][j] == '?')continue;
				if(str[i][j] > str[i-1][j]){
					pos = j;
					break;
				}
			}
			/*if(pos != -1){
			  int pos2 = -1;
			  bool fgbig = true;
			  for(int j = pos; j >= 0; j--){
			  if(str[i][j] < )
			  }
			  for(int j = 0; j < pos; j++){
			  if(str[i][j] == '?')
			  str[i][j] = str[i-1][j];
			  else if(str[i][j] < str[i-1][j]){
			  cout<<"NO"<<endl;;
			  return;
			  }
			  }
			  for(int j = pos+1; j < len; j++)
			  if(str[i][j] == '?')
			  str[i][j] = '0';
			  }else{*/
			bool ffg = false;
			for(int j = len-1; j >= 0; j--){
				if(str[i][j] == '?'){
					if(ffg){
						for(; j>=0; j--)
						  if(str[i][j] == '?')str[i][j] = str[i-1][j];
					}else{
						if(str[i-1][j]=='9'){
							str[i][j] = '0';
						}else{
							str[i][j] = str[i-1][j]+1;
							j--;
							for(; j >= 0; j--){
								if(str[i][j] == '?')str[i][j] = str[i-1][j];
							}
						}
					}
				}else{
					if(str[i-1][j]<str[i][j])ffg = true;
					if(str[i-1][j]>str[i][j])ffg = false;
				}
			}
			bool fg = true;
			for(int j = 0; j < len; j++)
			  if(str[i][j] > str[i-1][j])
				fg = false;
			if(fg){
				cout<<"NO"<<endl;
				return;
			}
			//}
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
		if(n==-1000){
			cout<<"YES"<<endl;
			int pos = -1;
			for(int i = 0; i < n; i++)
			  if(str[i] == "57?1199"){
				  pos = i;break;
			  }
			for(int i = pos-10; i < pos+10; i++)
			  cout<<i<<" "<<str[i]<<endl;
		}
		solve();
	}

	return 0;
}
