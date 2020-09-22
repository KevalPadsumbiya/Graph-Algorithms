#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

vector<int> ar[100001],v;
int vis[100001];

void DFS(int src)
{
	vis[src]=1;
	for(auto child : ar[src])
		if(vis[child]==0)
			DFS(child);	
}

int main()
{
	fastio;
	int n,m,a,b,i;
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>a>>b;
		ar[a].pb(b);
		ar[b].pb(a);
	}
	for(i=1;i<=n;i++)
	{
		if(vis[i]==0)
		{
			DFS(i);
			v.pb(i);
		}
	}
	cout<<v.size()-1<<"\n";
	for(i=1;i<v.size();i++)
		cout<<v[0]<<" "<<v[i]<<"\n";
	return 0;
}

