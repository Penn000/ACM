//=============================================//
//                   _ooOoo_                   //
//                  o8888888o                  //
//                  88" . "88                  //
//                  (| -_- |)                  //
//                   O\ = /O                   //
//               ____/`---'\____               //
//                .' \\| |// `.                //
//              / \\||| : |||// \              //
//            / _||||| -:- |||||- \            //
//            | | | \\\ - /// | | |            //
//            | \_| ''\---/'' | / |            //
//             \ .-\__ `-` ___/-. /            //
//          ___`. .' /--.--\ `. . __           //
//       ."" '< `.___\_<|>_/___.' >'"".        //
//      | | : `- \`.;`\ _ /`;.`/ - `: | |      //
//        \ \ `-. \_ __\ /__ _/ .-` / /        //
//======`-.____`-.___\_____/___.-`____.-'======//
//                   `=---='                   //
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^//
//              佛祖保佑 永无BUG               //
//  本模块已经经过开光处理，绝无可能再产生bug  //
//=============================================//
//2017-09-05
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 520;
const int M = 11000;

int n, m;
struct DSU{
	int fa[N];
	void init(){
		for(int i = 0; i < N; i++)
		  fa[i] = i;
	}
	int getfa(int x){
		if(x == fa[x])return x;
		return fa[x] = getfa(fa[x]);
	}
	void merge(int a, int b){
		int af = getfa(a);
		int bf = getfa(b);
		if(af != bf){
			fa[bf] = af;
		}
	}
}dsu1[M], dsu2[M];//dsu1[i]表示由前i条边生成的并查集，dsu2[i]表示由后i条边生成的并查集

int work(DSU ldsu, DSU rdsu){
	//将两棵并查集合并
	for(int i = 1; i <= n; i++)
	  	ldsu.merge(i, rdsu.getfa(i));
	int ans = 0;
	for(int i = 1; i <= n; i++)
	  	if(ldsu.fa[i] == i)
		  	ans++;
	return ans;
}
pair<int, int> line[M];
int main()
{
	std::ios::sync_with_stdio(false);
	cin.tie(0);
	//freopen("inputL.txt", "r", stdin);
	while(cin>>n>>m){
		for(int i = 1; i <= m; i++)
			cin>>line[i].first>>line[i].second;
		dsu1[0].init();
		for(int i = 1; i <= m; i++){
			dsu1[i] = dsu1[i-1];
			dsu1[i].merge(line[i].first, line[i].second);
		}
		dsu2[m+1].init();
		for(int i = m; i >= 1; i--){
			dsu2[i] = dsu2[i+1];
			dsu2[i].merge(line[i].first, line[i].second);
		}
		int  k, l, r;
		cin>>k;
		while(k--){
			cin>>l>>r;
			cout<<work(dsu1[l-1], dsu2[r+1])<<endl;
		}
	}

	return 0;
}
