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
lli cost[100001],D[100001];
int fre[100001],cnt,block=1000,st[100001],et[100001],fl[200001],ans[100001],timer=1;

struct query
{
	int l,r,i;
}Q[100001];

bool comp(query a,query b)
{
	if(a.l/block!=b.l/block)
		return a.l/block<b.l/block;
	return a.r<b.r;
}

void DFS(int src,int par)
{
	st[src]=timer;
	fl[timer]=src;
	timer++;
	for(auto child : ar[src])
		if(child!=par)
			DFS(child,src);
	et[src]=timer;
	fl[timer]=src;
	timer++;
}

void add(int pos)
{
	if(++fre[cost[fl[pos]]]==1)
		cnt++;	
}

void remove(int pos)
{
	if(--fre[cost[fl[pos]]]==0)
		cnt--;
}

int main()
{
	fastio;
	map<int,int> mp;
	int n,q,a,b,i,j,root;
	cin>>n>>q>>root;
	for(i=0;i<n-1;i++)
	{
		cin>>a>>b;
		ar[a].pb(b);
		ar[b].pb(a);
	}
	
	DFS(root,-1);
	
	for(i=1;i<=n;i++)
	{
		cin>>cost[i];
		D[i]=cost[i];
	}
	
	sort(D+1, D+n+1);
	j=1;
	for(i=1;i<=n;i++)		// coordinate compression
	{
		if(!mp[D[i]])
		{
			mp[D[i]]=j;
			j++;
		}
	}
	for(i=1;i<=n;i++)
		cost[i]=mp[cost[i]];
	
	for(i=0;i<q;i++)
	{
		cin>>root;
		Q[i].l=st[root];
		Q[i].r=et[root];
		Q[i].i=i;
	}
	
	sort(Q,Q+q,comp);
	int ML=1,MR=0,l,r;
	
	for(i=0;i<q;i++)
	{
		l=Q[i].l;
		r=Q[i].r;
		
		while(ML>l)
			ML-- , add(ML);
		while(MR<r)
			MR++ , add(MR);
		while(ML<l)
			remove(ML) , ML++;
		while(MR>r)
			remove(MR) , MR--;
		ans[Q[i].i]=cnt;
	}
	
	for(i=0;i<q;i++)
		cout<<ans[i]<<"\n";
	return 0;
}

