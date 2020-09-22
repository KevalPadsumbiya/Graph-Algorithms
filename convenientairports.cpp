#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

vector<lli> ar[200001];
lli vis[100001],degree[100001];
vector<pair<lli,lli>>pairs;
vector<lli> v;
vector<vector<lli>> con_comps;

void DFS(lli src)
{
	v.pb(src);
	vis[src]=1;
	for(auto child : ar[src])
		if(vis[child]==0)
			DFS(child);
}

int main()
{
	fastio;
	int t;
	cin>>t;
	while(t--)
	{
		lli n,m,a,b,i,cc=0;
		lli ans1=0;
		cin>>n>>m;
		for(i=1;i<=n;i++)
		{
			degree[i]=0;
			vis[i]=0;
			ar[i].clear();
		}
		pairs.clear();
		con_comps.clear();
		for(i=0;i<m;i++)
		{
			cin>>a>>b;
			degree[a]++;
			degree[b]++;
			pairs.pb(mk(a,b));
			ar[a].pb(b);
			ar[b].pb(a);
		}
		for(i=1;i<=n;i++)
		{
			if(vis[i]==0)
			{
				DFS(i);
				cc++;
				con_comps.pb(v);
				v.clear();
			}
		}
		if(cc>1)
			for(i=1;i<cc;i++)
				pairs.pb(mk(con_comps[i-1][con_comps[i-1].size()-1],con_comps[i][con_comps[i].size()-1]));
		for(i=1;i<=n;i++)
			ans1+=degree[i];
		
		if(cc==1)
		{
			cout<<0<<" "<<m<<"\n";
			for(auto pair : pairs)
				cout<<pair.first<<" "<<pair.second<<"\n";
		}
		else if(ans1<=(pairs.size()-m)*2)
			cout<<ans1<<" "<<0<<"\n";
		else if(ans1>(pairs.size()-m)*2)
		{
			cout<<(pairs.size()-m)*2<<" "<<pairs.size()<<"\n";
			for(auto pair : pairs)
				cout<<pair.first<<" "<<pair.second<<"\n";
		}
//		cout<<ans1<<" "<<(cc-1)*2<<"\n";
	}
	return 0;
}

