#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

vector<int> ar[100001];
lli totalfactors;
int timer,st[100001],et[100001],fl[200001],prime[1000001],vis[100001],cost[100001],level[100001],fre[1000001],block=1000,lca[100001][20],maxN;
lli ans[100001],mi[2000001];

struct query
{
	int l,r,u,i,type;
}Q[100001];

bool comp(query a,query b)
{
	if(a.l/block!=b.l/block)
		return a.l/block < b.l/block;
	return a.r<b.r;
}

void sieve() 
{ 
	int i,j;
    prime[1]=1; 
    for(i=2;i<1000000;i++) 
        prime[i]=i; 
    for (i=4;i<1000000;i+=2) 
        prime[i]=2; 
    for (i=3;i*i<1000000;i++) 
    { 
        if(prime[i]==i) 
        {  
            for(j=i*i;j<1000000;j+=i) 
                if(prime[j]==j) 
                    prime[j]=i; 
        } 
    } 
    
    mi[0] = mi[1] = 1;
	for(i=2;i<2000000;i++)
		mi[i] = (mod - (((mod/i) * 1LL *mi[mod % i])  % mod)) % mod;		// cp-algorithms
}

void DFS(int src,int par,int d)
{
	level[src]=d;
	lca[src][0]=par;
	st[src]=timer;
	fl[timer]=src;
	timer++;
	for(auto child : ar[src])
		if(child!=par)
			DFS(child,src,d+1);
	et[src]=timer;
	fl[timer]=src;
	timer++;
}

void factorization(int val,int add)
{
	int factor=-1;
	while(val!=1)
	{
		if(prime[val]!=factor)
		{
			totalfactors=(totalfactors*(mi[fre[prime[val]]+1]))%mod;
			if(factor!=-1)
				totalfactors=(totalfactors*(fre[factor]+1))%mod;
			factor=prime[val];	
		}
		if(add)
			++fre[prime[val]];
		else
			--fre[prime[val]];
		val/=prime[val];
	}
	totalfactors=(totalfactors*(fre[factor]+1))%mod;
}

void decide(int node)
{
	vis[node]^=1;
	factorization(cost[node],vis[node]);
}

int findLCA(int a,int b)
{
	int i,d;
	if(level[a]>level[b])
		swap(a,b);
	d=level[b]-level[a];
	while(d>0)
	{
		i=log2(d);
		b=lca[b][i];
		d-=(1<<i);
	}
	if(a==b)
		return b;
	for(i=maxN;i>=0;i--)
	{
		if(lca[a][i]!=-1 && (lca[a][i]!=lca[b][i]))
		{
			a=lca[a][i];
			b=lca[b][i];
		}
	}
	return lca[a][0];
}

int main()
{
	fastio;
	sieve();
	int t;
	cin>>t;
	while(t--)
	{
		totalfactors=timer=1;
		int n,q,a,b,i,LCA,j;
		cin>>n;
		
		maxN=log2(n)+1;
		
		for(i=1;i<=n;i++)		// clearing
		{
			ar[i].clear();
			vis[i]=0;
		}
		
		memset(fre,0,sizeof(fre));		// clearing
		
		if(n<=1000 && q<=1000)
		{
			for(j=0;j<=maxN;j++)
				for(i=1;i<=n;i++)
					lca[i][j]=-1;
		}
		
		for(i=0;i<n-1;i++)
		{
			cin>>a>>b;
			ar[a].pb(b);
			ar[b].pb(a);
		}
		
		for(i=1;i<=n;i++)
			cin>>cost[i];
		
		DFS(1,-1,0);
		
		for(j=1;j<=maxN;j++)
			for(i=1;i<=n;i++)
			{
				if(lca[i][j-1]!=-1)
				{
					int par=lca[i][j-1];
					lca[i][j]=lca[par][j-1];
				}
			}

		cin>>q;

		for(i=0;i<q;i++)
		{
			cin>>a>>b;
//			cout<<findLCA(a,b);
			LCA=findLCA(a,b);
			if(st[a]>st[b])
				swap(a,b);
			if(a==LCA || b==LCA)
			{
				Q[i].l=st[a];
				Q[i].r=st[b];
				Q[i].type=0;	
			}
			else
			{
				Q[i].l=et[a];
				Q[i].r=st[b];
				Q[i].type=LCA; 
			}
			Q[i].i=i;
		}
		sort(Q,Q+q,comp);
		
		int l,r,ML=1,MR=0;
		
		for(i=0;i<q;i++)
		{
			l=Q[i].l;
			r=Q[i].r;
		
			while(ML>l)
				decide(fl[--ML]);
		
			while(MR<r)
				decide(fl[++MR]);
		
			while(ML<l)
				decide(fl[ML++]);
		
			while(MR>r)
				decide(fl[MR--]);
		
			if(Q[i].type!=0)
			{
				decide(Q[i].type);
				ans[Q[i].i]=totalfactors;
				decide(Q[i].type);
			}
			else
				ans[Q[i].i]=totalfactors;
		}

		for(i=0;i<q;i++)
			cout<<ans[i]<<"\n";
	}
	return 0;
}

