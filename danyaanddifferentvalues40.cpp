#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

vector<int> a,ar[200001];
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

void merge(int index,vector<int> segtree[])
{
	vector<int> u=segtree[index<<1];
	vector<int> v=segtree[index<<1|1];
	int i=0,j=0;
	
	while(i<u.size() || j<v.size())
	{
		if(i==u.size())	
			segtree[index].pb(v[j++]);
		else if(j==v.size())
			segtree[index].pb(u[i++]);
		else
		{
			if(u[i]<=v[j])
				segtree[index].pb(u[i++]);
			else
				segtree[index].pb(v[j++]);
		}
	}	
}

void make_segTree(int index,int start,int end,vector<int> segtree[])
{
	if(start==end)
	{
		segtree[index].pb(a[start]);
		return;	
	}	
	int mid=(start+end)>>1;
	make_segTree(index<<1,start,mid,segtree);
	make_segTree(index<<1|1,mid+1,end,segtree);
	
//	merge(index,segtree);
	merge(segtree[index<<1].begin(),segtree[index<<1].end(),segtree[index<<1|1].begin(),segtree[index<<1|1].end(),back_inserter(segtree[index]));	// std	
}

int find_unique(int index,int r,vector<int> segtree[])
{
	int low=0,up=segtree[index].size()-1,last_index=segtree[index].size(),mid;
	while(low<=up)
	{
		mid=(low+up)>>1;
		if(segtree[index][mid]>r)
		{
			last_index=min(last_index,mid);
			up=mid-1;
		}
		else
			low=mid+1;
	}	
	return segtree[index].size()-last_index;
}

int query(int index,int start,int end,int l,int r,int x,vector<int> segtree[])
{
	if(l==start && r==end)
		return find_unique(index,x,segtree);
	
	int mid=(start+end)>>1;
	if(r<=mid)
		return query(index<<1,start,mid,l,r,x,segtree);
	else if(l>=mid+1)
		return query(index<<1|1,mid+1,end,l,r,x,segtree);
	else
		return	query(index<<1,start,mid,l,mid,x,segtree) + query(index<<1|1,mid+1,end,mid+1,r,x,segtree);	
}

int main()
{ 
	int t;
	scanf("%d",&t);
	while(t--)
	{
		unordered_map<int,int> m;
		int n,q,i,x,d,l,r,X,D;
		bool isbamboo=true;
		scanf("%d",&n);
		a.resize(n);
		vector<int> segtree[4*n];
		for(i=1;i<=n;i++)
			ar[i].clear();
		for(i=2;i<=n;i++)
		{
			scanf("%d",&x);
			if(x!=i-1)
				isbamboo=false;
			ar[i].pb(x);
			ar[x].pb(i);		
		}
		for(i=0;i<n;i++)
			scanf("%d",&cost[i]);
		cnt=0;
		scanf("%d",&q);
		if(isbamboo)
		{
			for(i=n-1;i>=0;i--)
			{
				if(m.find(cost[i])==m.end())
					a[i]=mod;
				else
					a[i]=m[cost[i]];
				m[cost[i]]=i;
			}
			
			make_segTree(1,0,n-1,segtree);
			
			while(q--) 
			{
		        scanf("%d %d",&x,&d);
		        x^=cnt;
		        d^=cnt;
		        l=x-1,r=min(x-1+d,n-1);
		        assert(l<n && l>=0);
		        assert(r<n && r>=0);
		        cnt=query(1,0,n-1,l,r,r,segtree);
				printf("%d\n",cnt);
	    	}
		}
		else
		{
			DFS(1,-1,0);
			while(q--)
			{
				set<int> s;
				scanf("%d %d",&x,&d);
				X=x^cnt;
				D=d^cnt;
				l=st[X],r=et[X];
				for(i=l;i<=r;i++)
				{
					if(level[fl[i]]-level[X]<=D && vis[fl[i]]==1)
					{
						vis[fl[i]]==1;
						s.insert(cost[fl[i]-1]);
					}
					else
						vis[fl[i]]^=1;
				}
				cnt=s.size();
				printf("%d\n",cnt);
			}	
		}
	}
	return 0;
}

