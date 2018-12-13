//2017-03-28
//状态压缩dp，sta的二进制所在位为1表示对应的作业已经处理，0表示未处理。sta低位对应为字典序小的课程。
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

const int N = (1<<15)+10;
const int inf = 0x3f3f3f3f;
int pre[N];//pre[i]表示状态i由前一个状态转移来时放入的作业编号
int dp[N];//dp[i]表示达到状态i所扣的最少的分
int tm[N];//tm[i]表示到达状态i花费的最少时间
int order[20];//用于保存最后输出的课程序列
int n;
struct node
{
	string name;
	int d, c;
}work[20];

int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i = 0; i < n; i++)
		  	cin>>work[i].name>>work[i].d>>work[i].c;
		for(int sta = 1; sta < (1<<n); sta++)
		{
			dp[sta] = inf;
			for(int j = n-1; j >= 0; j--)//为使序列倒序输出，从字典序大的作业开始枚举
			{
				int fmsta = (1<<j);//表示当前状态sta可以由sta-fmsta状态转移而来。
				if(!(fmsta&sta))continue;//表示该sta-fmsta不能转移到sta，继续
				int score = tm[sta-fmsta] - (work[j].d - work[j].c);//tm[sta-fmsta]表示转移前状态所花费的最小时间，(work[j].d - work[j].c)表示work[j]能开始的最晚时间。
				if(score < 0)score = 0;//若转移前时间比最晚开始时间早，所需要扣的分为0
				if(dp[sta] > dp[sta-fmsta]+score){
					dp[sta] = dp[sta-fmsta]+score;
					tm[sta] = tm[sta-fmsta] + work[j].c;
					pre[sta] = j;
				}
			}
		}
		cout<<dp[(1<<n)-1]<<endl;
		int cnt = 0, pos = (1<<n)-1;
		stack<int> s;
		while(pos)
		{
			s.push(pre[pos]);
			pos = pos-(1<<pre[pos]);
		}
		while(!s.empty())
		{
			cout<<work[s.top()].name<<endl;
			s.pop();
		}
	}

    return 0;
}
