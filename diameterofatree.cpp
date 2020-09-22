#include<iostream>
#include<vector>
#include<math.h>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
using namespace std;

vector<lli> ar[200001];
lli vis[200001],maxdist,maxnode;

void DFS(lli s,lli d)
{
	vis[s]=1;
	if(d>maxdist)
		maxdist=d , maxnode=s;
	
	for(lli child : ar[s])
		if(vis[child]==0)
			DFS(child,d+1);
}
int main()
{
	ios_base::sync_with_stdio(false); 
    cout.tie(NULL);
    
	lli n,m,a,b,i;
    
    cin>>n;
    
    for(i=0;i<n-1;i++)
    	cin>>a>>b , ar[a].pb(b) , ar[b].pb(a);
    	
    maxdist=-1;
    DFS(1,0);
    				
    // first make dfs call to an arbitrary node which is present in tree and then make a dfs call to that node which is at max dist from first dfs call...
	//and tha will give you deepest node from that node which is diameter if tree
	
    for(i=1;i<=n;i++)
    	vis[i]=0;
    	
    DFS(maxnode,0);
    
    cout<<maxdist;
	return 0;
}
