#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

int vis[1000],mx;
vector<int> ar[1000];

int DFS(int src)
{
	vis[src]=1;
	int n=0;
	for(int child : ar[src])
	{
		if(vis[child]==0)
		{
			int n1=DFS(child);
			if(n1%2==0)
				mx++;
			else
				n+=n1;
		}	
	}
	return n+1;	
}

int main()
{
	fastio;
	int n,m,i,a,b;
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>a>>b;
		ar[a].pb(b);
		ar[b].pb(a);
	}
	DFS(1);
	cout<<mx;
	return 0;
}

