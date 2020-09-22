#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

vector<int> ar[100001],con_comp;
int cc,vis[100001];

void DFS(int src)
{
	vis[src]=1;
	for(auto el : ar[src])
	{
		if(vis[el]==0)
		{
			con_comp.pb(el);
			cc++;
			DFS(el);
		}
	}	
}

int main()
{
	fastio;
	int n,m,a,b,i,ans=0;
	cin>>n>>m;
	for(i=0;i<m;i++)
		cin>>a>>b , ar[a].pb(b) , ar[b].pb(a);
	for(i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			cc=1;
			con_comp.pb(i);
			DFS(i);	
			int total_edges=0;
			for(auto el : con_comp)
				total_edges+=ar[el].size();
			con_comp.clear();
			ans+=max(0,(total_edges/2)-(cc-1));
		}	
	}	
	cout<<ans;
	return 0;
}

