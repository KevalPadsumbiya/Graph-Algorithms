#include<iostream>
#include<vector>
#include<math.h>
#include<bits/stdc++.h>
#define lli long long int
#define mod 998244353
#define pb push_back
using namespace std;

vector<lli> ar[1000000];
lli vis[1000000],col[1000000],c[2];

//in bipartite graph every vertex(node) must lies in only on set and if there is edge between two nodes of different sets then there must be a edge joining them
// and there is no edge between two nodes of the same set

bool DFS(lli s,lli cl)
{
	vis[s]=1;
	col[s]=cl;
	c[cl]++;
	for(lli child : ar[s])
	{
		if((vis[child]==0 && DFS(child,cl^1)==false) || col[child]==col[s])
			return false;
	}
	return true;
}

lli power(lli a,lli n)
{
	lli p=1;
	while(n)
	{
		if(n&1)
			p=(p*a)%mod;
		a=(a*a)%mod;
		n>>=1;
	}
	return p;
}

int main()
{
	ios_base::sync_with_stdio(false); 
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
	    lli n,m,a,b,i,ans=1,f=0;
	    cin>>n>>m;
	    
	    for(i=1;i<=n;i++)
	    	ar[i].clear(), vis[i]=0;
	    
		for(i=0;i<m;i++)
	    	cin>>a>>b, ar[a].pb(b) , ar[b].pb(a);
	    
	    for(i=1;i<=n;i++)
	    {
	    	if(vis[i]==0)
	    	{
	    		c[0]=c[1]=0;
	    		if(DFS(i,0)==false)
	    		{
	    			f=1;
	    			break;
				}
				ans=(ans*(power(2,c[0])+power(2,c[1])))%mod ;
			}
		}
		if(f)
			cout<<0<<endl;
		else
			cout<<ans<<endl;
	}
	return 0;
}
