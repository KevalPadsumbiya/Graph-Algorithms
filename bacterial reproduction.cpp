#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

vector<pair<lli,lli>> v;
lli dist[100001],vis[100001];
vector<lli> ar[100001];
lli cost[100001];

void DFS(lli src,lli d)
{
	vis[src]=1;
	dist[src]=d;
	if(ar[src].size()>1)
		v.pb({d,src});
	for(auto child : ar[src])
		if(vis[child]==0)
			DFS(child,d+1);
}

int main()
{
	fastio;
	lli n,q,i,a,b;
	cin>>n>>q;
	
	for(i=0;i<n-1;i++)
	{
		cin>>a>>b;
		ar[a].pb(b);
		ar[b].pb(a);
	}
	for(i=1;i<=n;i++)
		cin>>cost[i];
	DFS(1,0);

	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	
	char type;
	while(q--)
	{
		for(auto pair : v)
		{
			for(auto child : ar[pair.second])
			{
				if(dist[child]>dist[pair.second])
					cost[child]+=cost[pair.second];
			}
			cost[pair.second]-=cost[pair.second];
		}
		cin>>type;
		if(type=='+')
		{
			cin>>a>>b;
			cost[a]+=b;
		}
		else
		{
			cin>>a;
			cout<<cost[a]%mod<<"\n";	
		}
	}
	return 0;
}

