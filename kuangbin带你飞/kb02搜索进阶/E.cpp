//2017-03-07
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

string DNA[10];
char ch[4] = {'A', 'T', 'C', 'G'};
int deep, n, pos[10];//pos[i]表示第i个DNA串匹配到了pos[i]位
bool ok;

int Astar()//估价函数，返回当前状态最少还需要多少位
{
	int h = 0;
	for(int i = 0; i < n; i++)
	  	if(h < DNA[i].length()-pos[i])
		  	h = DNA[i].length()-pos[i];
	return h;
}

void IDAstar(int step)//枚举所求串每一位的字符，step表示所求串当前处理到哪一位。
{
	if(ok)return;
	int h = Astar();
	if(step + h > deep)return;//剪枝
	if(h == 0){//h为0表示短串全部处理完
		ok = true;
		return;
	}
	for(int i = 0; i < 4; i++)
	{
		int tmp[10];
		for(int j = 0; j < n; j++)tmp[j] = pos[j];
		bool fg = false;
		for(int j = 0; j < n; j++)
		{
			if(DNA[j][pos[j]] == ch[i]){
				fg = true;//表示所求串第step为可以是ch[i]
				pos[j]++;
			}
		}
		if(fg){
			IDAstar(step+1);
		}
		for(int j = 0; j < n; j++)pos[j] = tmp[j];
	}
}

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		deep = 0;
		for(int i = 0; i < n; i++)
		{
			cin>>DNA[i];
			if(DNA[i].length() > deep)deep = DNA[i].length();
		}
		ok = false;
		while(!ok)
		{
			memset(pos, 0, sizeof(pos));
			IDAstar(0);
			deep++;
		}
		cout<<deep-1<<endl;
	}

    return 0;
}
