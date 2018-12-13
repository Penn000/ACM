//2017-03-20
#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

struct Heap{
	int h[1010];
	int n;
	void init()
	{
		n = 0;
	}
	void shiftup(int pos)
	{
		int fa, tmp;
		while(pos >= 0){
			fa = (pos-1)/2;
			if(h[fa]>h[pos]){
				tmp = h[pos];
				h[pos] = h[fa];
				h[fa] = tmp;
				pos = fa;
			}else break;
		}
	}
	void addNode(int x)
	{
		h[n++] = x;
		shiftup(n-1);
	}
	void show(){
		for(int i = 0; i < n; i++)
		  	cout<<h[i]<<" ";
		cout<<endl;
	}
};

int main()
{
	int n,m;
	while(cin>>n>>m)
	{
		Heap heap;
		heap.init();
		int a;
		for(int i = 0; i < n; i++)
		{
			cin>>a;
			heap.addNode(a);
		}
		int x, y;
		string s1, s2, s3, s4;
		while(m--)
		{
			cin>>x;
			cin>>s1;
			if(s1[0] == 'a'){
				cin>>y>>s2>>s3;
				int p1, p2;
				for(int i = 0; i < heap.n; i++)
				{
					if(heap.h[i] == x)p1 = i;
					if(heap.h[i] == y)p2 = i;
				}
				if((p1-1)/2 == (p2-1)/2)cout<<"T"<<endl;
				else cout<<"F"<<endl;
			}else{
				cin>>s2;
				if(s2[0] == 'a'){
					cin>>s3>>s4>>y;
					int p1, p2;
					for(int i = 0; i < heap.n; i++)
					{
						if(heap.h[i] == x)p1 = i;
						if(heap.h[i] == y)p2 = i;
					}
					if((p1-1)/2 == p2)cout<<"T"<<endl;
					else cout<<"F"<<endl;	
				}else{
					cin>>s3;
					if(s3[0] == 'r'){
						if(heap.h[0] == x)cout<<"T"<<endl;
						else cout<<"F"<<endl;
					}else{
						cin>>s4>>y;
						int p1, p2;
						for(int i = 0; i < heap.n; i++){
							if(heap.h[i] == x)p1 = i;
							if(heap.h[i] == y)p2 = i;
						}
						if((p2-1)/2 == p1)cout<<"T"<<endl;
						else cout<<"F"<<endl;
					}
				}
			}
		}
	}

    return 0;
}
