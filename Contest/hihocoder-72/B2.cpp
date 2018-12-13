#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

int main()
{
	for(int n = 1; n <= 10; n++){
		for(int k = 1; k <= n; k++){
			string str(n, '.');
			queue<string> que;
			set<string> st;
			set<string>::iterator iter;
			for(int i = 0; i < n; i++)
			  str[i] = 'a'+i;
			que.push(str);
			st.insert(str);
			while(!que.empty()){
				string ss = que.front();
				que.pop();
				for(int i = 0; i+k < n; i++){
					string ss1(ss, i, k);
					string ss2 = "";
					for(int j = 0; j < i; j++)
					  ss2.push_back(ss[j]);
					for(int j = i+k; j < n; j++)
					  ss2.push_back(ss[j]);
					string s1 = ss1+ss2;
					iter = st.find(s1);
					if(iter == st.end()){
						st.insert(s1);
						que.push(s1);
					}
					string s2 = ss2+ss1;
					iter = st.find(s2);
					if(iter == st.end()){
						st.insert(s2);
						que.push(s2);
					}
				}
			}
			cout<<n<<" "<<k<<" -> "<<st.size()<<endl;
		}
	}

	return 0;
}
