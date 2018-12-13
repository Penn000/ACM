//2017-02-22
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

bool book[200005];
struct node
{
	int pos, step;
};

int main()
{
	int n, k;
	while(cin>>n>>k)
	{
		memset(book, 0, sizeof(book));
		queue<node> q;
		book[n] = 1;
		node tmp;
		tmp.pos = n;
		tmp.step = 0;
		q.push(tmp);
		int pos, step;
		while(!q.empty())
		{
			pos = q.front().pos;
			step = q.front().step;
			q.pop();
			if(pos == k){
				cout<<step<<endl;
				break;
			}
			if(pos-1==k || pos+1==k || 2*pos==k)
			{
				cout<<step+1<<endl;
				break;
			}
			if(pos >= 1 && !book[pos-1]){
				tmp.pos = pos-1;
				tmp.step = step+1;
				q.push(tmp);
				book[pos-1] = 1;
			}
			if(!book[pos+1]){
				book[pos+1] = 1;
				tmp.pos = pos+1;
				tmp.step = step+1;
				q.push(tmp);
			}
			if(2*pos<=200005&&!book[pos*2]){
				book[2*pos] = 1;
				tmp.pos = 2*pos;
				tmp.step = step+1;
				q.push(tmp);
			}
		}
	}

    return 0;
}
