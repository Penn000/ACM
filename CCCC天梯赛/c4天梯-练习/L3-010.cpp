//2017-03-22
#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

int ans[25];

struct node{
	int data;
	node *lson, *rson;
	node(int d):data(d), lson(NULL), rson(NULL){}
};

class BST
{
public:
	node *rt;
	BST():rt(NULL){}
	void insert(int a)
	{
		node* nd = new node(a);
		if(rt == NULL){
			rt = nd;
		}else{
			node *p = rt, *q = NULL;
			while(p != NULL){
				q = p;
				if(a > p->data){
					p = p->lson;
				}else{
					p = p->rson;
				}
			}
			if(a > q->data)q->lson = nd;
			else q->rson = nd;
		}
	}
	void judge()
	{
		queue<node*> q;
		q.push(rt);
		node *tmp;
		bool fg = true;
		int cnt = 0;
		while(!q.empty())
		{
			tmp = q.front();
			q.pop();
			ans[cnt++] = tmp->data;
			if(tmp->lson)q.push(tmp->lson);
			else{
				if(tmp->rson){
					fg = false;
				}
				if(!q.empty()){
					if(q.front()->lson || q.front()->rson){
						fg = false;
					}
				}
			}
			if(tmp->rson)q.push(tmp->rson);
			else{
				if(!q.empty()){
					if(q.front()->lson || q.front()->rson){
						fg = false;
					}
				}
			}
		}
		for(int i = 0; i < cnt; i++)
		  	if(i == cnt-1)cout<<ans[i]<<endl;
			else cout<<ans[i]<<" ";
		if(fg)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
};

int main()
{
	int n, a;
	while(cin>>n)
	{
		BST bst;
		for(int i = 0; i < n; i++)
		{
			cin>>a;
			bst.insert(a);
		}
		bst.judge();
	}

    return 0;
}
