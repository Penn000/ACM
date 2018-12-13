#include<stdio.h>
#include<algorithm>
#include<string.h>
#define ll long long
#define M 100007
using namespace std;
struct node
{
    ll l,r,mid,val,mark;
}tree[M<<2];
ll s[M];
void build(ll left,ll right,ll i)//建树
{
    tree[i].l=left;tree[i].r=right;
    tree[i].mid=(left+right)>>1;tree[i].mark=0;
    if(left==right){tree[i].val=s[left]; return;}
    build(left,tree[i].mid,i*2);
    build(tree[i].mid+1,right,i*2+1);
    tree[i].val=tree[i*2].val+tree[i*2+1].val;
}
void update(int pos,ll val,int i)//点更新
{
    tree[i].val+=val;
    if(tree[i].l==tree[i].r)return;
    if(pos<=tree[i].mid)update(pos,val,i*2);
    else update(pos,val,i*2+1);
}
//ll query(int left,int right,int i)//点查询
//{
//    if(tree[i].l==left&&tree[i].r==right)return tree[i].val;
//    if(right<=tree[i].mid)query(left,right,i*2);
//    else if(left>tree[i].mid)query(left,right,i*2+1);
//    else return query(left,tree[i].mid,i*2)+query(tree[i].mid+1,right,i*2+1);
//}
void update(int left,int right,ll val,int i)//区间更新
{
    if(tree[i].l==left&&tree[i].r==right){tree[i].mark+=val;return;}
    tree[i].val+=val*(right-left+1);
    if(tree[i].mid<left)update(left,right,val,2*i+1);
    else if(tree[i].mid>=right)update(left,right,val,2*i);
    else
    {
        update(left,tree[i].mid,val,2*i);
        update(tree[i].mid+1,right,val,2*i+1);
    }
}
ll query(int left,int right,int i)//区间查询
{
    if(tree[i].l==left&&tree[i].r==right)  return tree[i].val+tree[i].mark*(right-left+1);
    if(tree[i].mark!=0)
    {
        tree[i*2].mark+=tree[i].mark;tree[i*2+1].mark+=tree[i].mark;
        tree[i].val+=(tree[i].r-tree[i].l+1)*tree[i].mark;tree[i].mark=0;
    }
    if(tree[i].mid>=right){return query(left,right,i*2);}
    else if(tree[i].mid<left){return query(left,right,i*2+1);}
    else{return query(left,tree[i].mid,i*2)+query(tree[i].mid+1,right,i*2+1);}
}
int main()
{
    ll n,m,i,j,k;
    ll l,f,num;
    char str[5];
    while(scanf("%lld%lld",&n,&m)!=EOF)
    {
        for(int i=1;i<=n;i++)
            scanf("%lld",&s[i]);
        build(0,n,1);

        for(i=0;i<m;i++)
        {
          //  printf("i=%lld",i);
            scanf("%s",str);
            if(str[0]=='Q')
            {
                scanf("%lld%lld",&l,&f);
                printf("%lld\n",query(l,f,1));
            }
            if(str[0]=='C')
            {
                scanf("%lld%lld%lld",&l,&f,&num);
                update(l,f,num,1);
            }
        }



    }
    return 0;
}
