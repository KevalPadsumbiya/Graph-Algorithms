#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

int main()
{
	fastio;
	int t;
	cin>>t;
	while(t--)
	{
		lli n,m,i,a,b,w;
		cin>>n>>m;
		
		vector<pair<lli,lli>> ar[n+1];
		vector<lli> dist(n+1,mod);
		
		for(i=0;i<m;i++)
			cin>>a>>b>>w , ar[a].pb({b,w}) , ar[b].pb({a,w});
			
		priority_queue<pair<lli,lli>,vector<pair<lli,lli>>,greater<pair<lli,lli>>> p; // mean heap...smallest element stays in  top in pair
		
//		priority_queue< T , vector<T> , Compare = std::less<typename Container::value_type> >

//		template of priority_queue
//		
//		template<
//				    class T,
//				    class Container = std::vector<T>, 
//				    class Compare = std::less<typename Container::value_type>
//				> class priority_queue;
		
		cin>>a; 	// source node
		
		p.push({0,a});	//due to sorting according to first value in pri.queue...we are storing pair like (dist,node) 
		dist[a]=0;
		
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
		}
		
		for(i=1;i<=n;i++)
			if(i!=a)
			{
				if(dist[i]==mod)
					cout<<-1<<" ";
				else
					cout<<dist[i]<<" ";
			}
		cout<<"\n";
	}
	return 0;
}
/*
1
6 9
1 2 4
1 6 2
2 3 5
2 6 1
6 3 8
6 5 10
3 4 6
3 5 3
5 4 5
1
ans : 0 3 8 14 11 2
*/
