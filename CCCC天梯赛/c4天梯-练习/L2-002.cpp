#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <list>

using namespace std;

const int N = 1e6+10;
int ne[N], ke[N], book[10005];
struct node
{
	int add, key, next;
	void setNode(int a, int k, int n){
		this->add = a;
		this->key = k;
		this->next = n;
	}
};

int main()
{
	int s, n, pos;
	while(cin>>s>>n)
	{
		int ad;
		for(int i = 0; i < n; i++)
		{
			cin>>ad;
			cin>>ke[ad]>>ne[ad];
		}
		list<node> l1, l2;
		list<node>::iterator it;
		node tmp;
		memset(book, 0, sizeof(book));
		pos = s;
		book[abs(s)] = 1;
		tmp.setNode(pos, ke[pos], ne[pos]);
		l1.push_back(tmp);
		pos = ne[pos];
		while(pos != -1)
		{
			if(book[abs(ke[pos])]){
				if(!l2.empty()){
					tmp = l2.back();
					tmp.next = pos;
					l2.pop_back();
					l2.push_back(tmp);
				}
				tmp.setNode(pos, ke[pos], ne[pos]);
				l2.push_back(tmp);
			}else{
				book[abs(ke[pos])] = 1;
				if(!l1.empty()){
					tmp = l1.back();
					tmp.next = pos;	
					l1.pop_back();
					l1.push_back(tmp);
				}
				tmp.setNode(pos, ke[pos], ne[pos]);
				l1.push_back(tmp);
			}
			pos = ne[pos];
		}
		tmp = l1.back(); tmp.next = -1;
		l1.pop_back();l1.push_back(tmp);
		for(it = l1.begin(); it != l1.end(); it++){
			if(it->next == -1)printf("%05d %d %d\n", it->add, it->key, it->next);
			else printf("%05d %d %05d\n", it->add, it->key, it->next);
		}
		if(!l2.empty()){
			tmp = l2.back(); tmp.next = -1;
			l2.pop_back();l2.push_back(tmp);
		}
		for(it = l2.begin(); it != l2.end(); it++){
			if(it->next == -1)printf("%05d %d %d\n", it->add, it->key, it->next);
			else printf("%05d %d %05d\n", it->add, it->key, it->next);
		}
	}

    return 0;
}
