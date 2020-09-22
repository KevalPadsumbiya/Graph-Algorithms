#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

vector<int> ar[2001];
int vis[2001],matching[2001];
int matched;

bool DFS(int src)
{
//	cout<<src<<" ";
	vis[src]=1;
	for(auto child : ar[src])
	{
		if(vis[child]==0)
		{
			if(matching[child]==0)
			{
				matching[child]=src;
				matching[src]=child;
				matched=1;
				return true;
			}
			else if(vis[matching[child]]==0 && DFS(matching[child])==true)
			{
				matching[child]=src;
				matching[src]=child;
				matched=1;
				return true;
			}
		}
	}
	return false;
}

int main()
{
	fastio;
	int n,m,k,a,b,i,j,max_matching=0;
	cin>>n>>m>>k;
	for(i=0;i<m;i++)
	{
		cin>>a>>b;
		ar[a].pb(b);
		ar[b].pb(a);
	}
	for(i=1;i<=n;i++)
	{
		if(matching[i]==0)
		{
			matched=0;
			memset(vis,0,sizeof(vis));
			DFS(i);
			max_matching+=matched;
		}
	}
	cout<<max_matching;
	return 0;
}
/*
8 9 1
1 2
1 8 
2 3
3 7
3 4
4 5
5 6
6 7
7 8
ans : 4
*/
