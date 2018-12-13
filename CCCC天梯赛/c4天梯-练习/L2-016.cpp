//2017-03-21
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1e5+10;
int ma[N], fa[N];
bool mile[N], fg;

void init()
{
	for(int i = 0; i < N-2; i++)
	{
		ma[i] = -1;
		fa[i] = -1;
	}
}

void judge(int a, int b, int step)
{
	if(fg == false)return;
	if(step >= 4)return;
	if((fa[a]==fa[b] && fa[a]!=-1 && fa[b]!=-1) || (ma[a]==ma[b] && ma[a]!=-1 && ma[b]!=-1)){
		fg = false;
		return ;
	}
	if(ma[a] != -1 && ma[b] != -1)judge(ma[a], ma[b], step+1);
	if(ma[a] != -1 && fa[b] != -1)judge(ma[a], fa[b], step+1);
	if(fa[a] != -1 && ma[b] != -1)judge(fa[a], ma[b], step+1);
	if(fa[a] != -1 && fa[b] != -1)judge(fa[a], fa[b], step+1);
}

int main()
{
	int n, id, f, m;
	char ch;
	while(cin>>n)
	{
		init();
		for(int i = 0; i < n; i++){
			cin>>id;
			cin>>ch>>f>>m;
			if(ch == 'M')mile[id] = 1;
			else mile[id] = 0;
			fa[id] = f;
			ma[id] = m;
		}
		int k, a, b;
		cin>>k;
		while(k--)
		{
			cin>>a>>b;
			fg = true;
			if(mile[a] == mile[b])cout<<"Never Mind"<<endl;
			else{
				judge(a, b, 0);
				if(fg)cout<<"Yes"<<endl;
				else cout<<"No"<<endl;
			}
		}
	}

	return 0;
}
