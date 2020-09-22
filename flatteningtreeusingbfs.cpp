#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

int timer=1,vis[100],level[100],st[100],et[100],fl[200];
vector<int> ar[100];

void BFS(int src)
{
	queue<int> q;
	q.push(src);
	vis[src]=1;
	level[src]=1;
	st[1]=1;
	timer++;
	while(!q.empty())
	{
		int cur=q.front();
		q.pop();
//		st[cur]=timer;
//		fl[timer]=cur;
//		timer++;
		for(auto child : ar[cur])
		{
			if(vis[child]==0)
			{
				q.push(child);
				level[child]=level[cur]+1;
				vis[child]=1;
				st[child]=timer;
//				fl[timer]=child;
				timer++;
				cout<<child<<" "<<st[child]<<"\n";
			}
		}
	}
}

int main()
{
	fastio;
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,i,a,b;
		cin>>n>>m;
		for(i=0;i<m;i++)
		{
			cin>>a>>b;
			ar[a].pb(b);
			ar[b].pb(a);
		}
		BFS(1);
		for(i=1;i<=n;i++)
			cout<<st[i]<<" ";
		cout<<endl;
//		for(i=1;i<=n;i++)
//			cout<<et[i]<<" ";
//		cout<<endl;
//		for(i=1;i<=2*n;i++)
//			cout<<fl[i]<<" ";
//		cout<<endl;
		for(i=1;i<=n;i++)
			cout<<level[i]<<" ";
		cout<<endl;
	}
	return 0;
}

