#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

lli sum=0;
int a[250001],dist[250001],leftchild[250001]={0},rightchild[250001]={0},LCA[250001][20],maxN,level[250001];
vector<int> ar[500001];

void DFS(int src,int d,int par)
{
	level[src]=d;
	LCA[src][0]=par;
	
	for(int child : ar[src])
		if(child != par)	
			DFS(child,d+1,src);
}

int findLca(int src,int dest)
{
	if(level[dest]<level[src])
		swap(src,dest);
	int d= level[dest]-level[src];
	
	while(d>0)
	{
		int i= log2(d);
		dest=LCA[dest][i];
		d-=1<<i;
	}
	if(src==dest)
		return src;
		
	for(int i=maxN;i>=0;i--)
		if(LCA[src][i]!=0 && (LCA[src][i]!=LCA[dest][i]))
		{
			src=LCA[src][i] , dest=LCA[dest][i];
		}
	return LCA[src][0];
}

void insert(int node,int root)
{
	if(node<root)
	{
		if(leftchild[root]==0)
		{
			ar[root].pb(node);
			ar[node].pb(root);
			leftchild[root]=node;
			dist[node]=dist[root]+1;
		}
		else
			insert(node,leftchild[root]);
	}
	else
	{
		if(rightchild[root]==0)
		{
			ar[root].pb(node);
			ar[node].pb(root);
			rightchild[root]=node;
			dist[node]=dist[root]+1;
		}
		else
			insert(node,rightchild[root]);
	}
}

int main()
{
	fastio;
	int n,i,j,node,root,lca;
	cin>>n;
	maxN=log2(n)+1;
	cin>>root;
	a[0]=root;
	dist[root]=0;
	for(i=1;i<n;i++)
	{
		cin>>a[i];
		insert(a[i],root);
	}
	DFS(root,1,-1);
	
	for(i=1;i<=maxN;i++)
		for(j=1;j<=n;j++)
		{
			if(LCA[j][i-1]!=-1)
			{
				lca=LCA[j][i-1];
				LCA[j][i]=LCA[lca][i-1];
			}
		}
	
	cout<<0<<"\n";
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(a[j]==root)
				sum+=dist[a[i]];
			else if((a[j]>root && a[i]<root) || (a[j]<root && a[i]>root))
				sum+=dist[a[j]]+dist[a[i]];
			else
			{
				lca=findLca(a[j],a[i]);
				sum+=dist[a[j]]+dist[a[i]]-2*dist[lca];
			}
		}
		cout<<sum<<"\n";	
	}
	return 0;
}

