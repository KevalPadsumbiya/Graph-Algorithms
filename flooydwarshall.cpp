#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

int main ()
{
    lli n,m,a,b,w,i,j,k,negative_cycle=0;
	cin>>n>>m;
	lli dp[n+1][m+1];
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
		{	
			if(i!=j)
				dp[i][j]=mod;
			else
				dp[i][j]=0;
		}
		
	for(i=0;i<m;i++)
	{
		cin>>a>>b>>w;
		dp[a][b]=w;
	}
	for(k=1;k<=n;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
			}
		}
	}
	for(i=1;i<=n;i++)
		if(dp[i][i]<0)
			negative_cycle=1;
	cout<<negative_cycle;
	return 0;
}
