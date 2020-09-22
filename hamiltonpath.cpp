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
	int a,b,i,n,m;
	cin>>n>>m;
	vector<int> ar[n+1];
	for(i=0;i<m;i++)
		cin>>a>>b , ar[a].pb(b) , ar[b].pb(a);
	for(i=1;i<=n;i++)
	{
		if(ar[i].size()<(n/2))
			break;
	}
	if(i<=n)
		cout<<"NO";
	else
		cout<<"YES";
	return 0;
}

