#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

vector<int> ar[1000001],toposort;
int in[10001],n;

void Kahn()
{
	int i,frnt;
	queue<int> q;
	for(i=1;i<=n;i++)
		if(in[i]==0)
			q.push(i);
	while(!q.empty())
	{
		frnt=q.front();
		q.pop();
		toposort.pb(frnt);
		for(auto child : ar[frnt])
		{
			in[child]--;
			if(in[child]==0)
				q.push(child);
		}
	}	
}

int main()
{
	fastio;
	int m,i,x,y;
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>x>>y;
		ar[x].pb(y);
		in[y]++;
	}
	Kahn();
	for(auto el : toposort)
		cout<<el<<" "; 
	return 0;
}
/*
9 10
1 2
3 4
1 8
2 9
2 5
4 5
4 8
5 9
5 7
6 7

o/p:1 3 6 2 4 5 8 9 7
*/
