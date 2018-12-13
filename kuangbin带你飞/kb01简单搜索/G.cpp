//2017-02-27
#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

string shuffle(string &s1, string &s2, int len)
{
	string tmp(2*len, ' ');
	for(int i = 0; i < 2*len; i++)
	{
		if(i%2==1)tmp[i] = s1[i/2];
		else tmp[i] = s2[i/2];
	}
	for(int i = 0; i < len; i++)
	  	s1[i] = tmp[i];
	for(int i = 0; i < len; i++)
	  	s2[i] = tmp[i+len];
	return tmp;
}

int main()
{
	int T, n, ans;
	string s1, s2, s12, tmp;
	cin >> T;
	for(int kase = 1; kase <= T; kase++)
	{
		cin>>n>>s1>>s2>>s12;
		set<string> s;
		ans = 0;
		while(1){
			tmp = shuffle(s1, s2, n);
			if(tmp == s12){
				ans++;
				break;
			}
			set<string>::iterator it = s.find(tmp);
			if(it != s.end()){
				ans = -1;
				break;
			}else{
				s.insert(tmp);
				ans++;
			}
		}
		cout<<kase<<" "<<ans<<endl;
	}

    return 0;
}
