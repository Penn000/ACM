//2016.10.09
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int K = 26;
const int N = 500010;

struct node//AC自动机中的节点
{
	node *ch[K], *fail;
	int match;
	void Clear(){
		memset(this, 0, sizeof(node));
	}
}*que[N];

struct AC_automaton
{
	node nodes[N], *root, *superRoot, *cur;
	node* newNode(){
		cur->Clear();
		return cur++;
	}
	void Clear(){//初始化字典树
		cur = nodes;
		superRoot = newNode();
		root = newNode();
		root->fail = superRoot;
		for(int i = 0; i < K; i++)
		  	superRoot->ch[i] = root;
		superRoot->match = -1;
	}
	void Insert(char *s){//向字典树中插入一个字符串
		node *t = root;
		for(; *s; s++){
			int p = *s-'a';
			if(t->ch[p] == NULL)
			  	t->ch[p] = newNode();
			t = t->ch[p];
		}
		t->match++;
	}
	void build(){//构建自动机
		int p = 0, q = 0;
		que[q++] = root;
		while(p != q){//bfs求失配指针
			node *t = que[p++];
			for(int i = 0; i < K; i++){
				if(t->ch[i]){
					t->ch[i]->fail = t->fail->ch[i];
					que[q++] = t->ch[i];
				}else{
					t->ch[i] = t->fail->ch[i];
				}
			}
		}
	}
	int run(char* s){//计算str串中模式串出现的次数
		int ans = 0;
		node *t = root;
		for(; *s; s++){
			int p = *s-'a';
			t = t->ch[p];
			for(node *u = t; u->match != -1; u = u->fail){
				ans += u->match;
				u->match = -1;
			}
		}
		return ans;
	}
};

char str[1000005];
AC_automaton ac;

int main()
{
	int n, T;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		getchar();
		ac.Clear();
		for(int i = 0; i < n; i++){
			scanf("%s", str);
			ac.Insert(str);
		}
		ac.build();
		scanf("%s", str);
		printf("%d\n", ac.run(str));
	}

    return 0;
}
