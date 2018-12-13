//2017-02-23
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int ans[110], n;
bool ok;

void dfs(unsigned long long num, int pos)
{
	if(ok || pos == 20)return;
	if(num%n==0){
		cout<<num<<endl;
		ok = true;
		return;
	}else{
		dfs(num*10, pos+1);
		dfs(num*10+1, pos+1);
	}
}

int main()
{
	while(cin>>n && n)
	{
		ok = false;
		dfs(1, 0);	
	}

    return 0;
}
