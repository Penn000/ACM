//2017-03-19
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N = 1005;
int bt[N], bst1[N], bst2[N], ANS[N], n, cnt;
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
				if(a < p->data){
					p = p->lson;
				}else{
					p = p->rson;
				}
			}
			if(a < q->data)q->lson = nd;
			else q->rson = nd;
		}
	}
};

void preOrder1(node* id)
{
	if(id != NULL)
	{
		bst1[cnt] = id->data;
		cnt++;
		preOrder1(id->lson);
		preOrder1(id->rson);
	}
}

void preOrder2(node* id)
{
	if(id != NULL)
	{
		bst2[cnt] = id->data;
		cnt++;
		preOrder2(id->rson);
		preOrder2(id->lson);
	}
}

void postOrder1(node* id)
{
	if(id != NULL){
		postOrder1(id->lson);
		postOrder1(id->rson);
		ANS[cnt] = id->data;
		cnt++;
	}
}

void postOrder2(node* id)
{
	if(id != NULL){
		postOrder2(id->rson);
		postOrder2(id->lson);
		ANS[cnt] = id->data;
		cnt++;
	}
}

int main()
{
	while(cin>>n)
	{
		BST bst;
		for(int i = 0; i < n; i++)
		{
			cin>>bt[i];
			bst.insert(bt[i]);
		}
		cnt = 0;
		preOrder1(bst.rt);
		cnt = 0;
		preOrder2(bst.rt);
		bool fg1 = true, fg2 = true;
		for(int i = 0; i < n; i++){
			if(bt[i] != bst1[i])fg1 = false;
			if(bt[i] != bst2[i])fg2 = false;
		}
		if(fg1){
			cout<<"YES"<<endl;
			cnt = 0;
			postOrder1(bst.rt);
			for(int i = 0; i < n; i++)
			  	if(i == n-1)cout<<ANS[i]<<endl;
				else cout<<ANS[i]<<" ";
		}else if(fg2){
			cout<<"YES"<<endl;
			cnt = 0;
			postOrder2(bst.rt);
			for(int i = 0; i < n; i++)
			  	if(i == n-1)cout<<ANS[i]<<endl;
				else cout<<ANS[i]<<" ";
		}else cout<<"NO"<<endl;
	}

    return 0;
}
