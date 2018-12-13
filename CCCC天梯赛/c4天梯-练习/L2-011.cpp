//2017-03-20
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int pre[35], in[35], ANS[35];
struct node{
	int data;
	node *lson, *rson;
	node(int d):data(d), lson(NULL), rson(NULL){}
};

struct BT{
	node *root;
	void rebuild(int n)
	{
		root = buildTree(pre, in, n);
	}
	node* buildTree(int *pre, int *in, int n)
	{
		if(n < 1)return NULL;
		node *rt = new node(pre[0]);
		if(n == 1)return rt;
		int R;
		for(int i = 0; i < n; i++)
		{
			if(in[i] == pre[0]){
				R = i;
				break;
			}
		}
		rt->lson = buildTree(pre+1, in, R);
		rt->rson = buildTree(pre+1+R, in+R+1, n-R-1);
		return rt;
	}
	void levelOrder()
	{
		queue<node*> q;
		q.push(root);
		node *h;
		int cnt = 0;
		while(!q.empty()){
			h = q.front();
			q.pop();
			ANS[cnt++] = h->data;
			if(h->rson)q.push(h->rson);
			if(h->lson)q.push(h->lson);
		}
		for(int i = 0; i < cnt; i++)
		  	if(i == cnt-1)cout<<ANS[i]<<endl;
			else cout<<ANS[i]<<" ";
	}
};

int main()
{
	int n;
	while(cin>>n)
	{
		for(int i = 0; i < n; i++)
		  	cin>>in[i];
		for(int i = 0; i < n; i++)
		  	cin>>pre[i];
		BT bt;
		bt.rebuild(n);
		bt.levelOrder();
	}

    return 0;
}
饸饹