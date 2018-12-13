//2017-08-30
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 5010;

struct Point{
	int x, y;
	Point(){}
	Point(int _x, int _y):x(_x), y(_y){}
	//a-b 表示向量 ba
	Point operator- (const Point &b) const {
		return Point(x-b.x, y-b.y);
	}
	//向量叉积
	int operator* (const Point &b) const {
		return x*b.y - y*b.x;
	}
}A, B;

int ans[N], U[N], L[N];
int n, m;

bool check(int id, int x, int y){
	Point a(L[id], B.y);
	Point b(U[id], A.y);
	Point c(x, y);
	//令I = 向量ab 叉乘 向量 bc，若I为正，点c在向量ab的左侧（沿向量方向看）；为负则在右侧
	return ((c-a)*(b-a)) > 0;
}

int get_position(int x, int y){
	int l = 0, r = n+1, mid, ans;
	while(l <= r){
		mid = (l+r)>>1;
		if(check(mid, x, y)){
			ans = mid;
			l = mid+1;
		}else r = mid-1;
	}
	return ans;
}

int main()
{
	std::ios::sync_with_stdio(false);
	//freopen("inputA.txt", "r", stdin);
	while(cin>>n && n){
		cin>>m>>A.x>>A.y>>B.x>>B.y;
		U[0] = L[0] = A.x;
		U[n+1] = L[n+1] = B.x;
		for(int i = 1; i <= n; i++)
		  cin>>U[i]>>L[i];
		memset(ans, 0, sizeof(ans));
		int x, y;
		for(int i = 0; i < m; i++){
			cin>>x>>y;
			ans[get_position(x, y)]++;
		}
		for(int i = 0; i <= n; i++)
		  cout<<i<<": "<<ans[i]<<endl;
		cout<<endl;
	}

	return 0;
}
