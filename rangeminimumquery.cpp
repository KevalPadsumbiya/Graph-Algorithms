	#include<iostream>
	#include<vector>
	#include<bits/stdc++.h>
	#define lli long long int
	#define mod 1000000007
	#define pb push_back
	#define mk make_pair
	#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
	using namespace std;
	int a[500001],fre[500001],mn=-1,block,cnt,h[50001];
	unordered_map<int,int> mp;
	
	inline bool cmp(const pair< pair<int,int>,int> &a,const pair< pair<int,int>,int> &b)
	{
	    int l1 = a.first.first/block;
	    int l2 = b.first.first/block;
	    if(l1 != l2)
	        return (l1<l2);
	    return l1%2 ? (a.first.second < b.first.second) : (a.first.second > b.first.second);
	}
	inline void add(lli pos)
	{
		fre[a[pos]]++;
		if(fre[a[pos]]==1)
			mp[a[pos]]=1;
	}
	
	inline void remove(lli pos)
	{
		fre[a[pos]]--;
		if(fre[a[pos]]==0)
			mp[a[pos]]=0;
	}
	
	int main()
	{
		fastio;
		vector< pair< pair<int,int>,int> > qry;
		int n,q,m,ML=0,MR=-1,L,R,i,f=0,j;
		
		cin>>n>>m;
		
		int ans[n+1];
		
		block=800;
		
		for(i=1;i<=n;i++)
			cin>>a[i];
		
		for(i=1;i<=m;i++)
			cin>>h[i];
			
		cin>>q;
		
		for(i=0;i<q;i++)
		{
			cin>>L>>R;
			qry.push_back(make_pair(make_pair(L,R),i));
		}
		
		sort(qry.begin(),qry.end(),cmp);
		
		for(i=0;i<q;i++)
		{
			f=0;
			L=qry[i].first.first;
			R=qry[i].first.second;
			while(ML>L)
				ML-- , add(ML);
			
			while(MR<R)
				MR++ , add(MR);
				
			while(ML<L)
				remove(ML) , ML++;
				
			while(MR>R)
				remove(MR) , MR--;
			
			for(auto it : mp)
			{
				if(it.second==1)
				{
	//				cout<<it.first<<endl;
					if(h[it.first]!=fre[it.first])
					{
						f=1;
						break;
					}
				}
			}
			if(f==1)
				ans[qry[i].second]=0;
			else
				ans[qry[i].second]=1;
		}
		
		for(i=0;i<q;i++)
			cout<<ans[i]<<"\n";
		
		return 0;
	}

