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
	priority_queue<int,vector<int>,greater<int>> p;
	int i,frnt;
	for(i=1;i<=n;i++)
		if(in[i]==0)
			p.push(i);
	while(!p.empty())
	{
		frnt=p.top();
		p.pop();
		toposort.pb(frnt);
		for(auto child : ar[frnt])
		{
			in[child]--;
			if(in[child]==0)
				p.push(child);
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
	if(toposort.size()==n)
		for(auto el : toposort)
			cout<<el<<" ";
	else
		cout<<"Sandro fails."; 
	return 0;
} 
