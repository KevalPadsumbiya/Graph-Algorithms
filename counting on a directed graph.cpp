#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

vector<int> ar[500001],v;
vector<vector<int>> subtrees;
int vis[500001];

void DFS(int src)
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
	int n,m,j,a,b,i;
	lli pairs=0;
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>a>>b;
		ar[a].pb(b);
//		ar[b].pb(a);
	}
	for(auto child : ar[1])
	{
		DFS(child);
		subtrees.pb(v);
		v.clear();
	}
//	for(auto v : subtrees)
//	{
//		for(auto el : v)
//			cout<<el<<" ";
//		cout<<endl;
//	}
	for(auto v : subtrees)
		pairs+=v.size();
	for(i=0;i<subtrees.size()-1;i++)
	{
		for(j=i+1;j<subtrees.size();j++)
		{
			pairs+=(subtrees[i].size()*subtrees[j].size());
		}
	}
	cout<<pairs;
	return 0;
}

