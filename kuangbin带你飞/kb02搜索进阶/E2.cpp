#include <iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int n;     
int ans;        //最后答案 
char str[10][10];  //记录n个字符串
int deep;       //搜索深度
char DNA[4]={'A','T','C','G'};    //四种可能
int Max(int x,int y){     
	if(x>y)return x;
	else return y;
}
void Dfs(int index,int len[]){
	if(index>deep)return;        //大于限制的深度，不用往下搜索  
	int i,j,maxx=0;       //预计还要匹配的字符串的最大长度  
	for(i=0;i<n;i++){
		maxx=Max(strlen(str[i])-len[i],maxx);
	}
	if(maxx==0){ //条件全部满足即为最优解 
		ans=index;
		return;
	}
	if(index+maxx>deep)      //剪枝 
		return;             //当前的深度＋最少还有加深的深度是否大于限制的长度，若是，则退回
	for(i=0;i<4;i++){
		int flag=0;
		int pos[10];
		for(j=0;j<n;j++){
			if(str[j][len[j]]==DNA[i]){//表示该字母可以往下搜索
				flag=1;
				pos[j]=len[j]+1;
			}
			else pos[j]=len[j];
		}
		for(int k = 0; k < n; k++)cout<<pos[k]<<" ";
		cout<<endl;
		if(flag)Dfs(index+1,pos);
		if(ans!=-1)return;    //已经搜到最优解 不必再往下搜
	}
}
int main()
{
	int t,i;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		deep=0;
		for(i=0;i<n;i++){
			scanf("%s",str[i]);
			deep=Max(deep,strlen(str[i]));//找出最长的串的长度，作为初始时的迭代DFS的限制
		}
		ans=-1;
		int pos[10]={0};    //记录n个字符串目前匹配到的位置  
		while(1){
			Dfs(0,pos);
			if(ans!=-1)
				break;
			deep++; //加深迭代
		}
		printf("%d\n",ans);
	}
	return 0;
}
