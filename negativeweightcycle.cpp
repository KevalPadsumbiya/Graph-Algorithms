#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<chrono>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;
using namespace std::chrono; 

int main()
{
	fastio;
	lli n,m,i,a,b,x,y,w,f=0;
	cin>>n>>m;
	
	vector<pair<lli,lli>> ar[n+1];
	vector<lli> dist(n+1,mod);
	
	for(i=0;i<m;i++)
		cin>>a>>b>>w , ar[a].pb({b,w});			// directed graph
		
	priority_queue<pair<lli,lli>,vector<pair<lli,lli>>,greater<pair<lli,lli>>> p; // mean heap...smallest element stays in  top in pair
	
	for(i=1;i<=n;i++)
		if(ar[i].size()>0)
		{
			x=i;
			break;
		}
		
	p.push({0,x});	//due to sorting according to first value in pri.queue...we are storing pair like (dist,node) 
	dist[x]=0;
	
	auto start = high_resolution_clock::now(); 
	
	while(!p.empty())
	{
		b=p.top().second;
		w=p.top().first;
		p.pop();
		for(pair<lli,lli> edge : ar[b])		
		{
			if(w+edge.second < dist[edge.first])
			{
				dist[edge.first]=w+edge.second;
				p.push({dist[edge.first],edge.first});
			}
		}
		auto stop = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start); 
		if(duration.count()>1500000)
		{
			f=1;
			break;
		}
	}
	cout<<f;
	
	return 0;
}
