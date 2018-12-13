#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

const int NN = 100010;

int a[NN],b[NN],lb,n,m;  
struct segmenttree  
{  
    int l,r,s;  
}tree[NN*25];  
int node;  
int root[NN];  
int search(int x)  
{  
    int l=0,r=lb,mid;  
    while (l<r)  
    {  
        mid=l+r+1>>1;  
        if(b[mid]<=x) l=mid;  
        else r=mid-1;  
    }  
    return l;  
}  
int build(int l,int r)  
{  
    int k=++node;  
    tree[k].s=0;  
    if(l==r) return k;  
    int m=l+r>>1;  
    if(l<=m) tree[k].l=build(l,m);  
    if(r>m) tree[k].r=build(m+1,r);  
    return k;  
}  
int change(int rt,int l,int r,int x)  
{  
    int k=++node,root=k,mid;  
    tree[k]=tree[rt];  
    tree[k].s++;  
    while (l<r)  
    {  
        mid=l+r>>1;  
        if(x<=mid)  
        {  
            rt=tree[rt].l;  
            tree[k].l=++node;  
            k=node;  
            tree[k]=tree[rt];  
            tree[k].s++;  
            r=mid;  
        }  
        else  
        {  
            rt=tree[rt].r;  
            tree[k].r=++node;  
            k=node;  
            tree[k]=tree[rt];  
            tree[k].s++;  
            l=mid+1;  
        }  
    }  
    return root;  
}  
int query(int L,int R,int l,int r,int x)  
{  
    int mid,ans=0;  
    while (l<r)  
    {  
        mid=l+r>>1;  
        if(mid>=x)  
        {  
            r=mid;  
            L=tree[L].l;  
            R=tree[R].l;  
        }  
        else  
        {  
            l=mid+1;  
            ans+=tree[tree[R].l].s-tree[tree[L].l].s;  
            L=tree[L].r;  
            R=tree[R].r;  
        }  
    }  
    if(l==r)  
    {  
        if(x<l) return 0;  
        else return ans+tree[R].s-tree[L].s;  
    }  
}  
int u,v,w,i;  
int fastget(){
	int a;
	scanf("%d", &a);
	return a;
}
void fastput(int a){
	printf("%d\n", a);
}
int main()  
{  
		freopen("dataN.txt", "r", stdin);
    int tt=fastget();  
    for(int cs=1;cs<=tt;cs++)  
    {  
        n=fastget();  
        m=fastget();  
        for(i=1;i<=n;i++)  
            b[i]=a[i]=fastget();  
        lb=1;  
        sort(b+1,b+1+n);  
        for(i=2;i<=n;i++)  
            if(b[i]!=b[lb]) b[++lb]=b[i];  
        node=0;  
        root[0]=build(1,lb);  
        for(i=1;i<=n;i++)  
            root[i]=change(root[i-1],1,lb,search(a[i]));  
        for(int i = 0; i < node; i++){
			cout<<i<<" "<<tree[i].l<<" "<<tree[i].r<<" "<<tree[i].s<<endl;
		}
        printf("Case %d:\n",cs);  
        while (m--)  
        {  
            u=fastget(),v=fastget(),w=fastget();  
            u++; v++;  
            w=search(w);  
            if(w==0) fastput(0);  
            else fastput(query(root[u-1],root[v],1,lb,w));  
        }  
    }  
    return 0;  
}  

