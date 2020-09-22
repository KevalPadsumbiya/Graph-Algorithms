#include<iostream>
#include<vector>
#include<math.h>

#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
using namespace std;

vector<lli> ar[100001];
lli vis[100001],dist[10001];
void bfs(lli src)
{
	queue<lli> q;
	q.push(src);
	vis[src]=1;
	dist[src]=1;
	
	while(!q.empty())
	{
		lli cur=q.front();
		q.pop();
		cout<<cur<<" ";
		for(lli child : ar[cur])
		{
			if(vis[child]==0)
			{
				q.push(child);
				dist[child]=dist[cur]+1;
				vis[child]=1;
			}
		}
	}
}
int main()
{
    lli i,n,a,b;
    cin>>n;
    for(i=0;i<n-1;i++)
    {
		cin>>a>>b;
		ar[a].push_back(b);
		ar[b].push_back(a);
	}
	cout<<"BFS order : ";
    bfs(1);
}
