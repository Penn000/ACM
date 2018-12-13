#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

using namespace std;

const int N = 100005;
int dfs1[N], dfs2[N], ANS[N];
struct node{
    int data;
    node *lson, *rson;
    node(int d):data(d), lson(NULL), rson(NULL){}
};

struct BT{
    node *root;
    void rebuild(int n)
    {
        root = buildTree(dfs1, dfs2, n);
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
    int T,n;
    scanf("%d", &T);
    while(T--)
    {
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
              scanf("%d", &dfs1[i]);
        for(int i = 0; i < n; i++)
              scanf("%d", &dfs2[i]);
        BT bt;
        bt.rebuild(n);
        bt.levelOrder();
    }

    return 0;
}
