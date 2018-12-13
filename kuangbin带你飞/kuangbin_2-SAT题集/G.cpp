//2017-08-28
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 20010;
const int M = 100000;
const int INF = 0x3f3f3f3f;
int head[N], tot;
struct Edge{
	int to, next;
}edge[M];

void init(){
	tot = 0;
	memset(head, -1, sizeof(head));
}

void add_edge(int u, int v){
	edge[tot].to = v;
	edge[tot].next = head[u];
	head[u] = tot++;
}

bool book[N];
vector<int> vec;//保存dfs过程中经过的点

//input: u 顶点
//output: true 从u开始染色，不会出现NOT u和u染为同一种颜色; false dfs染色失败
bool dfs(int u){
	if(book[u^1])return false;//表示染到非u，染色失败
	if(book[u])return true;
	book[u] = true;
	vec.push_back(u);
	for(int i = head[u]; i != -1; i = edge[i].next){
		int v = edge[i].to;
		if(!dfs(v))
		  return false;
	}
	return true;
}

//input：n 图的顶点数
//output：true 存在可行解; false 不存在可行解
bool twoSAT(int n){
	memset(book, 0, sizeof(book));
	for(int u = 0; u < n; u += 2){
		if(book[u] || book[u^1])continue;
		vec.clear();
		if(!dfs(u)){//如果选u不成功，把dfs过程中的点都从答案中删去
			for(int i = 0; i < vec.size(); i++)
				book[vec[i]] = 0;
			vec.clear();
			if(!dfs(u^1))return false;//如果选NOT u也不成功，说明不存在可行解
		}
	}
	return true;
}

int n, m;

int main()
{
	std::ios::sync_with_stdio(false);
	//freopen("inputG.txt", "r", stdin);
	while(cin>>n>>m){
		init();
		int u, v;
		while(m--){
			cin>>u>>v;
			u--; v--;
			add_edge(u, v^1);// u -> NOT v
			add_edge(v, u^1);// v -> NOT u
		}
		if(twoSAT(n<<1)){
			for(int i = 0; i < (n<<1); i++)//字典序输出解
			  	if(book[i])
				  	cout<<i+1<<endl;
		}else cout<<"NIE"<<endl;
	}
	return 0;
}
