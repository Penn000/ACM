//2017-02-23
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

struct node
{
	int num, step;
};

bool isPrime(int n)
{
	for(int i = 2; i*i <= n; i++)
	  	if(n%i==0)return false;
	return true;
}

int pow(int a, int n)
{
	int ans = 1;
	for(int i = 0; i < n; i++)
		ans *= a;
	return ans;
}

int main()
{
	int n, x, y;
	bool book[10005];
	cin>>n;
	while(n--)
	{
		cin>>x>>y;
		queue<node> q;
		node tmp;
		tmp.num = x;
		tmp.step = 0;
		q.push(tmp);
		int num, step;
		bool ok = false;
		memset(book, 0, sizeof(book));
		book[x] = 1;
		while(!q.empty()){
			num = q.front().num;
			step = q.front().step;
			q.pop();
			if(num == y){
				ok = true;
				cout<<step<<endl;
				break;
			}
			for(int i = 0; i < 4; i++){
				for(int p = 0; p < 10; p++){
					if(i==3 && p==0)continue;
					int nowNum = num-((num/pow(10, i))%10)*pow(10, i)+p*pow(10, i);
				/*if(nowNum == y){
					ok = true;
					cout<<step+1<<endl;
					break;
				}*/
					if(!book[nowNum] && isPrime(nowNum)){
						tmp.num = nowNum;
						tmp.step = step+1;
						q.push(tmp);
						book[nowNum] = 1;
					}
				}
			}
			if(ok)break;
		}
	}

    return 0;
}
