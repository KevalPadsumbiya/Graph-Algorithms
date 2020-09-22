#include<iostream>
#include<vector>
#include<math.h>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

vector<int> ar[100001];
int vis[100001],col[100001];

//in bipartite graph every vertex(node) must lies in only on set and if there is edge between two nodes of different sets then there must be a edge joining them
// and there is no edge between two nodes of the same set

bool DFS(int s,int c)
{
	vis[s]=1;
	col[s]=c;
	
	for(int child : ar[s])
	{
		if((vis[child]==0 && DFS(child,c^1)==false) || col[child]==col[s])
				return false;
	}
	return true;
}

int main()
{
	fastio;
	int n,m,a,b,i;
    
	cin>>n>>m;
    
	for(i=0;i<m;i++)
    	cin>>a>>b, ar[a].pb(b) , ar[b].pb(a);
    
//	cout<<DFS(1,1);		// true(1) means graph is bi-partite , false (0) means not
	DFS(1,1);	
	for(i=1;i<=n;i++)
		cout<<col[i]+1<<" ";	
	
	return 0;
}
