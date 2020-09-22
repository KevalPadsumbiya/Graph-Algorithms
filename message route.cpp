#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

vector<int> ar[100001];
int n,timer=1,vis[100001],fl[200001],st[100001];
bool isItPossible=false;

void DFS(int src,int parent,int d)
{
	if(src==n)
		isItPossible=true;
	vis[src]=1;
	fl[timer]=src;
	st[src]=timer;
	timer++;
	for(auto child : ar[src])	
		if(vis[child]==0)
			DFS(child,src,d+1);
	fl[timer]=src;
	timer++;
}

int main()
{
	fastio;
	int m,a,b,i,ans=0;
	unordered_map<int,int> mp;
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>a>>b;
		ar[a].pb(b);
		ar[b].pb(a);
	}
	DFS(1,-1,0);
	if(isItPossible)
	{
		
	}
	else
		cout<<"IMPOSSIBLE";
	return 0;
}

