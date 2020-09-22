#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

lli lmax,rmax,mx,ans=-mod;
int lca[100001][1],level[100001],maxN,cost[100001];
vector<int> ar[100001],s,d,r;

void DFS(int src,int d,int par)
{
    level[src]=d;
    lca[src][0]=par;
    for(auto child : ar[src])
        if(child!=par)
            DFS(child,d+1,src);
}

void calcMax(int src,int dest)
{
    if(level[src]<level[dest])
        swap(src,dest);
    int dif=level[src]-level[dest];
    s.pb(src);
    while(dif>0)
    {
        dif--;
        src=lca[src][0];
        s.pb(src);
    }
    if(src==dest)
    {
        d.pb(src);
        while(dest!=1)
        {
            dest=lca[dest][0];
            mx+=cost[dest];
        }
        return;
    }
    while(src!=dest)
    {
        rmax+=cost[dest];
        d.pb(dest);
        src=lca[src][0];
        dest=lca[dest][0];
        if(src==dest)
        {
            d.pb(dest);
            s.pb(dest);
            while(dest!=1)
            {
                dest=lca[dest][0];
                mx+=cost[dest];
            }
            break;
        }
        s.pb(src);
    }
}

int main()
{
    int n,i,a,b,q,j;
    string type;
    scanf("%d",&n);
    
    for(i=0;i<n-1;i++)
    {
        scanf("%d %d",&a,&b);
        ar[a].pb(b);
        ar[b].pb(a);
    }
    
    DFS(1,1,-1);
    
    cin>>q;
    while(q--)
    {
        mx=0;
        ans=-mod;
        cin>>type;
        if(type=="add")
        {
            scanf("%d %d",&a,&b);
            cost[a]+=b;
        }
        else
        {
            scanf("%d %d",&a,&b);
            calcMax(a,b);
            lmax=rmax=mx;
            for(i=s.size()-1;i>=0;i--)
            {
                lmax+=cost[s[i]];
                ans=max(ans,lmax);
            }
            for(i=d.size()-1;i>=0;i--)
            {
                rmax+=cost[d[i]];
                ans=max(ans,rmax);
            }
            s.clear();
            d.clear();
            printf("%lld\n",ans);
        }
    }
    return 0;
}
