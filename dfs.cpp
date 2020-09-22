#include<iostream>
#include<vector>
#include<math.h>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
using namespace std;
vector<lli> ar[100001];
lli vis[100001];

void DFS(lli s)
{
	vis[s]=1;
//	cout<<s<<" ";
	for(lli child : ar[s])
		if(vis[child]==0)
			DFS(child);
}
void BFS(lli s)
{
	queue<lli> q;
	q.push(s);
	vis[s]=1;
//	dist[s]=1;
	
	while(!q.empty())
	{
		lli cur=q.front();
		q.pop();
		for(lli child : ar[cur])
		{
			if(vis[child]==0)
			{
				q.push(child);
//				dist[child]=dist[cur]+1;
				vis[child]=1;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false); 
    cout.tie(NULL);
    lli n,m,s,i,a,b,cc=0;
    cin>>n>>m;
    for(i=0;i<m;i++)
    	cin>>a>>b , ar[a].pb(b), ar[b].pb(a);
    	
	for(i=1;i<=n;i++)
		if(vis[i]==0)
			DFS(i) , cc++;  // we can use both dfs and bfs to find number of connected components
			
	cout<<cc;
	return 0;
}
