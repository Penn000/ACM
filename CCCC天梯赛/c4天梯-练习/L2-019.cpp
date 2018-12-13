//2018-03-14
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

const int N = 5005;

string strs[2*N];
int arr[2*N];
set<string> st, ans_st;

int main()
{
	int n, m;
	while(cin>>n){
		string str;
		st.clear();
		for(int i = 0; i < n; i++){
			cin>>str;
			st.insert(str);
		}
		cin>>m;
		int sum = 0;
		for(int i = 0; i < m; i++){
			cin>>strs[i]>>arr[i];
			sum += arr[i];
		}
		double avg = 1.0*sum/m;
		set<string>::iterator iter;
		ans_st.clear();
		for(int i = 0; i < m; i++){
			if((iter = st.find(strs[i])) == st.end() && arr[i] > avg){
				ans_st.insert(strs[i]);
			}
		}
		if(ans_st.empty()){
			cout<<"Bing Mei You"<<endl;
		}else{
			for(auto x: ans_st){
				cout<<x<<endl;
			}
		}
	}

	return 0;
}
