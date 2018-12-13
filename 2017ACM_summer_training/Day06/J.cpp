//2017-09-05
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int n;
map<int, int> pos;
set<int> st;
set<int>::iterator iter, it;

int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("inputJ.txt", "r", stdin);
	while(cin>>n){
		st.clear();
		pos.clear();
		int a;
		cin>>a;
		st.insert(a);
		st.insert(0);
		pos[a] = 1;
		for(int i = 2; i <= n; i++){
			cin>>a;
			iter = st.lower_bound(a);//返回第一个大于等于a的数
			it = iter;
			it--;//比a小的最大的数
			if(pos[*it] > pos[*iter])
			  	cout<<*it<<" ";
			else cout<<*iter<<" ";
			pos[a] = i;
			st.insert(a);
		}
		cout<<endl;
	}

	return 0;
}
