#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

vector<vector<lli>> adj(10001, vector<lli>());
vector<vector<lli>> cost(10001, vector<lli>());
vector<lli> d(10001,mod);
lli n,m;

bool negative_cycle() 
{
	lli i,j,k,v,u;
  	d[0]=0;
	for(i=0;i<n;i++) 
	    for(u=0;u<n;u++)
			for(k=0;k<n;k++) 
			{
			    v=adj[u][k];
			    if(d[u]+cost[u][k]< d[v]) 
				{
				    d[v]=d[u]+cost[u][k];
					if(i==n-1) 
					  	return true;
				}
			}
 	return false;
}

int main() 
{	
  	cin>>n>>m;
  
	for (lli i = 0; i < m; i++) 
	{
		lli x, y, w;
	    cin>>x>>y>>w;
	    adj[x-1].pb(y - 1);
	    cost[x-1].pb(w);
	}
  
  	cout<<negative_cycle();
	return 0;
}
