#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

const int N = 112345;

struct Node{
	int a, b;
	Node(int _a, int _b):a(_a), b(_b){}
	bool operator==(const Node nd){
		return (a==nd.a && b==nd.b);
	}
};

int main()
{
	int T, n, k, a, b;
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		map<Node, int> mp;
		while(n--){
			scanf("%d", &k);
			set<Node> st;
			while(k--){
				scanf("%d%d", &a, &b);
				st.insert(Node(a, b));
			}
			for(auto &x: mp){
				Node nd = x
			}
		}
	}

	return 0;
}
