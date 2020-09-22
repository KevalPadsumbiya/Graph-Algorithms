#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;
 
int st[100001],et[100001],fl[100001],vis[100001],timer=1,LCA[100001][20],d=1,level[100001],maxN,ans[100001],cnt=0,fre[100001],cost[100001],block=1000,l,r,D[100001];
vector<int> ar[100001];
 
map<int,int> mp;
 
struct query
{
	int a,b,l,r,type;
}Q[100001];
 
bool comp(query a,query b)
{
	if(a.l/block!=b.l/block)
		return a.l/block<b.l/block;
	a.r<b.r;
}
 
void DFS(int src,int par,int d)
{
	st[src]=timer;
	fl[timer]=src;
	level[src]=d;
	LCA[src][0]=par;
	timer++;
	for(int child : ar[src])
		if(child!=par)
			DFS(child,src,d+1);
	et[src]=timer;
	fl[timer]=src;
	timer++;
}
 
int giveLca(int src,int dest)
{
	if(level[dest]<level[src])
		swap(src,dest);
	int d=level[dest]-level[src],i;
	while(d>0)
	{
		i=log2(d);
		dest=LCA[dest][i];
		d-=(1<<i);	
	}	
	if(src==dest)
		return dest;
	for(int i=maxN;i>=0;i--)
		if(LCA[src][i]!=-1 && (LCA[src][i]!=LCA[dest][i]))
		{
			src=LCA[src][i] , dest=LCA[dest][i];
		}	
	return LCA[src][0];
}
 
void add(int pos)
{
	if(vis[fl[pos]]==1 && pos>=l && pos<=r)
	{
		if(--fre[cost[fl[pos]]]==0)
			cnt--;
	}
	else
	{
		if(++fre[cost[fl[pos]]]==1)
			cnt++;
	}
	vis[fl[pos]]^=1;
}
 
void remove(int pos)
{
	if(--fre[cost[fl[pos]]]==0)
		cnt--;
}
 
int main()
{
	int n,m,a,b,q,i,j,lca,total=0;
	scanf("%d",&n);
	maxN=log2(n)+1;
	
	for(i=1;i<=n;i++)
		scanf("%d",&cost[i]);
		
	for(i=0;i<n-1;i++)
	{
		scanf("%d %d",&a,&b);
		ar[a].pb(b);
		ar[b].pb(a);
	}
	
	DFS(1,-1,1);
	
	for(i=1;i<=maxN;i++)
		for(j=1;j<=n;j++)
		{
			if(LCA[j][i-1]!=-1)
			{
				a=LCA[j][i-1];
				LCA[j][i]=LCA[a][i-1];
			}
		}
	int c=0;
	for(i=1;i<n;i++)
	{
		for(j=i+1;j<=n;j++)
		{
			a=i;
			b=j;
			cout<<a<<" "<<b<<"\n";
//			Q[i].i=c++;
			if(st[a]>st[b])
				swap(a,b);
			lca=giveLca(a,b);
			Q[c].a=a;
			Q[c].b=b;
			if(lca==a || lca==b)
			{
				Q[c].l=st[a];
				Q[c].r=st[b];
				Q[c].type=0;
			}
			else
			{
				Q[c].l=et[a];
				Q[c].r=st[b];
				Q[c].type=lca;
			}
			c++;
		}
	}
	int ML=1,MR=0,x=n*(n-1)/2;
	for(i=0;i<x;i++)
	{	
		l=Q[i].l;
		r=Q[i].r;
		cout<<l<<" "<<r<<" , "<<Q[i].a<<" "<<Q[i].b;
		while(ML>l)
			ML-- , add(ML);	
		while(MR<r)
			MR++ , add(MR);
		while(ML<l)
			remove(ML) , ML++;
		while(MR>r)
			remove(MR) , MR--;
		
		if(Q[i].type==0)
		{
			ans[Q[i].a]+=cnt;
			ans[Q[i].b]+=cnt;
			cout<<" , "<<cnt<<"\n";
		}
		else
		{
			if(fre[cost[Q[i].type]]==0)
			{
				ans[Q[i].a]+=cnt+1;
				ans[Q[i].b]+=cnt+1;
				cout<<" , "<<cnt+1<<"\n";
			}
			else
			{
				ans[Q[i].a]+=cnt;
				ans[Q[i].b]+=cnt;
				cout<<" , "<<cnt<<"\n";
			}
		}
	}
	
	for(i=1;i<=n;i++)
		printf("%d\n",ans[i]+1);	
	return 0;
}  
