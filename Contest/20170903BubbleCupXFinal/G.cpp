#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

char wenhao[10] = {'a', 'b', 'c', 'd', 'e'};
int position[5], tot;
int main()
{
	//	std::ios::sync_with_stdio(false);
	freopen("inputG.txt", "r", stdin);
	int n, m;
	while(scanf("%d%d", &n, &m) != EOF){
		map<string, int> mp, book;
		map<string, int>::iterator iter;
		string str;
		while(n--){
			cin>>str;
			mp[str]++;
			book[str] = 0;
		}
		while(m--){
			tot = 0;
			int ans = 0;
			cin>>str;
			int len = str.length();
			for(int i = 0; i < len; i++)
			  if(str[i] == '?')
				position[tot++] = i;
			if(tot == 0){
				ans += mp[str];
			}else if(tot == 1){
				for(int i = 0; i < 5; i++){
					str[position[0]] = wenhao[i];
					iter = mp.find(str);
					if(iter != mp.end())
					  ans += iter->second;
				}
				str.erase(position[0], 1);
				iter = mp.find(str);
				if(iter != mp.end())
				  ans += iter->second;
			}else if(tot == 2){
				for(int i = 0; i < 5; i++){
					for(int j = 0; j < 5; j++){
						str[position[0]] = wenhao[i];
						str[position[1]] = wenhao[j];
						iter = mp.find(str);
						if(iter != mp.end())
						  ans += iter->second;
					}
				}
				string tmp(str);
				tmp.erase(position[0], 1);
				for(int i = 0; i < 5; i++){
					tmp[position[1]-1] = wenhao[i];
					iter = mp.find(tmp);
					if(iter != mp.end() && book[tmp] == 0){
						ans += iter->second;
						book[tmp] = 1;
					}
				}

				string tmp2(str);
				tmp2.erase(position[1], 1);
				for(int i = 0; i < 5; i++){
					tmp2[position[0]] = wenhao[i];
					iter = mp.find(tmp2);
					if(iter != mp.end() && book[tmp2] == 0){
						ans += iter->second;
						book[tmp2] = 1;
					}
				}

				tmp.erase(position[1]-1, 1);
				iter = mp.find(tmp);
				if(iter != mp.end())
				  ans += iter->second;
			}else if(tot == 3){
				for(int i = 0; i < 5; i++){
					for(int j = 0; j < 5; j++){
						for(int k = 0; k < 5; k++){
							str[position[0]] = wenhao[i];
							str[position[1]] = wenhao[j];
							str[position[2]] = wenhao[k];
							iter = mp.find(str);
							if(iter != mp.end())
							  ans += iter->second;
						}
					}
				}
				string tmp1(str);
				tmp1.erase(position[0], 1);
				for(int i = 0; i < 5; i++){
					for(int j = 0; j < 5; j++){
						tmp1[position[1]-1] = wenhao[i];
						tmp1[position[2]-1] = wenhao[j];
						iter = mp.find(tmp1);
						if(iter != mp.end() && book[tmp1] == 0){
							ans += iter->second;
							book[tmp1] = 1;
						}
					}
				}

				string tmp2(str);
				tmp2.erase(position[1], 1);
				for(int i = 0; i < 5; i++){
					for(int j = 0; j < 5; j++){
						tmp2[position[0]] = wenhao[i];
						tmp2[position[2]-1] = wenhao[j];
						iter = mp.find(tmp2);
						if(iter != mp.end() && book[tmp2] == 0){
							ans += iter->second;
							book[tmp2] = 1;
						}
					}
				}

				string tmp3(str);
				tmp3.erase(position[2], 1);
				for(int i = 0; i < 5; i++){
					for(int j = 0; j < 5; j++){
						tmp3[position[0]] = wenhao[i];
						tmp3[position[1]] = wenhao[j];
						iter = mp.find(tmp3);
						if(iter != mp.end() && book[tmp3] == 0){
							ans += iter->second;
							book[tmp3] = 1;
						}
					}
				}

				tmp1.erase(position[1]-1, 1);
				for(int i = 0; i < 5; i++){
					tmp1[position[2]-2] = wenhao[i];
					iter = mp.find(tmp1);
					if(iter != mp.end() && book[tmp1] == 0){
						ans += iter->second;
						book[tmp1] = 1;
					}
				}

				tmp2.erase(position[2]-1, 1);
				for(int i = 0; i < 5; i++){
					tmp2[position[0]] = wenhao[i];
					iter = mp.find(tmp2);
					if(iter != mp.end() && book[tmp2] == 0){
						ans += iter->second;
						book[tmp2] = 1;
					}
				}

				tmp3.erase(position[0], 1);
				for(int i = 0; i < 5; i++){
					tmp3[position[1]-1] = wenhao[i];
					iter = mp.find(tmp3);
					if(iter != mp.end() && book[tmp3] == 0){
						ans += iter->second;
						book[tmp3] = 1;
					}
				}

				tmp1.erase(position[2]-2, 1);
				iter = mp.find(tmp1);
				if(iter != mp.end())
				  ans += iter->second;
			}
			cout<<ans<<endl;
		}
	}

	return 0;
}
