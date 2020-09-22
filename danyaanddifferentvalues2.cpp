#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

vector<int> ar[200001];
int st[200001],et[200001],fl[400002],block=1000,timer=1,cnt,cost[200001],level[200001],vis[200001];

void DFS(int src,int par,int d)
{
	level[src]=d;
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

void add(int pos,int fre[])
{
	if(++fre[cost[pos]]==1)
		cnt++;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		cnt=0;
		timer=1;
		int n,i,a,b,q,x,d,X,D,l,r;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			ar[i].clear();
		for(i=2;i<=n;i++)
		{
			scanf("%d",&a);
			ar[i].pb(a);
			ar[a].pb(i);		
		}
		for(i=1;i<=n;i++)
			scanf("%d",&cost[i]);
		DFS(1,-1,0);
		scanf("%d",&q);
		while(q--)
		{
			int fre[n+1]={0};
			scanf("%d %d",&x,&d);
			X=x^cnt;
			D=d^cnt;
			cnt=0;
			l=st[X],r=et[X];
			for(i=l;i<=r;i++)
			{
				if(level[fl[i]]-level[X]<=D && vis[fl[i]]==1)
				{
					vis[fl[i]]==1;
					add(fl[i],fre);
				}
				else
					vis[fl[i]]^=1;
			}
			printf("%d\n",cnt);
		}
	}
	return 0;
}

