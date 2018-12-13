struct nod{
    int l,r;
    vector<int> q;
}que[100005];

int main()
{
    tot=0;
    que[++tot].l=1; que[tot].r=k; 
    for (int i=1;i<=Q;i++)
        que[tot].q.push_back(l[i]*100001+r[i]);
    int now=1;
    for (int step=k/2;step>=1;step=step>>1)
    {
        for (int i=1;i<=k;i++)
        {
            ins(1,L[i],R[i],T[i]);
            if (i==(que[now].r+que[now].l)/2)
            {
                for (int j=0;j<que[now].q.size();j++)
                {
                    int temp=que[now].q[j];
                    int x,y;
                    y=temp%100001;
                    x=temp/100001;
                    long long ans=query(1,1,k,x,y);
                    if (ans>=AMB[x])
                    {
                        que[now*2].q.push_back(x*100001+y);
                        if (que[now*2].q.size()==1)
                            que[now*2].l=que[now].l,
                            que[now*2].r=(que[now].r+que[now].l)/2;
                    }
                    else
                    {
                        que[now*2+1].q.push_back(x*100001+y);
                        if (que[now*2+1].q.size()==1)
                            que[now*2+1].l=(que[now].r+que[now].l)/2+1,
                            que[now*2+1].r=que[now].r;
                    }
                }
                now++;
            }
        }

    }
}