#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 110000;

struct Node{
	int l, f;
	Node(int _l, int _f): l(_l), f(_f){}
	bool operator<(const Node& x) const{
		return f < x.f;
	}
};

vector<Node> vec[6];
int op[7];

int tpye_to_id(string str){
	if(str == "CV") return 0;
	if(str == "DD") return 1;
	if(str == "CL") return 2;
	if(str == "CA") return 3;
	if(str == "BB") return 4;
	if(str == "BC") return 5;
	else return -1;
}

int work(){
	int ans = 0, &g = op[6];
	for(int i = 0; i < 6; i++){
		int cnt = 0;
		for(auto &node: vec[i]){
			if(node.l >= g){
				ans += node.f;
				cnt++;
			}
			if(cnt >= op[i])break;
		}
		if(cnt < op[i])return -1;
	}
	return ans;
}

int main()
{
	int T, n, m;
	string str;
	cin>>T;
	while(T--){
		for(int i = 0; i < 6; i++)vec[i].clear();
		cin>>n>>m;
		while(n--){
			cin>>str>>op[0]>>op[1];
			vec[tpye_to_id(str)].push_back(Node(op[0], op[1]));
		}
		for(int i = 0; i < 6; i++)
		  sort(vec[i].begin(), vec[i].end());
		while(m--){
			for(int i = 0; i < 7; i++)cin>>op[i];
			cout<<work()<<endl;
		}
	}


	return 0;
}
