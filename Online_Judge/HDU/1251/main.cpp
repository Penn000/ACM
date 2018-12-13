//2016.10.7
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

struct node//26叉树，num为到该节点截止的前缀有多少个
{
	node* ch[26];
	int num;
	node(){
		num = 0;
		for(int i = 0; i < 26; i++)
		  	ch[i] = NULL;
	}
};

node *root = NULL;
char s[15];

void Insert(char *s)
{
	node* cur = root;
	cur->num++;
	for(int i = 0; i < strlen(s); i++)
	{
		int tmp = s[i]-'a';
		if(cur->ch[tmp] == NULL)
		  	cur->ch[tmp] = new node;
		cur = cur->ch[tmp];
		cur->num++;
	}
}

int query(char *s)
{
	node *cur = root;
	for(int i = 0; i < strlen(s); i++)
	{
		int tmp = s[i]-'a';
		if(cur->ch[tmp] == NULL)return 0;
		cur = cur->ch[tmp];
	}
	return cur->num;
}

int main()
{
	root = new node;
	while(gets(s), strcmp(s, "")){
		Insert(s);
	}
	while(scanf("%s", s)!=EOF){
		printf("%d\n", query(s));
	}

    return 0;
}
