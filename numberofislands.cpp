#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

lli vis[1000][1000],c=0,a[1000][1000],n,m;

void DFS(lli x,lli y)
{
	if(x>=0 && y>=0 && x<n && y<m && vis[x][y]==0 && a[x][y]==1)
	{
		vis[x][y]=1;
		
		DFS(x-1,y);
		DFS(x+1,y);
		DFS(x,y-1);
		DFS(x,y+1);
		
		DFS(x-1,y-1);
		DFS(x+1,y-1);
		DFS(x-1,y+1);
		DFS(x+1,y+1);
		c++;
	}
}
int main()
{
	fastio;
		lli i,j,islands=0,mx=0;
		cin>>n>>m;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				cin>>a[i][j];
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				if(vis[i][j]==0 && a[i][j]==1)
				{
//					mx=0;
//					islands++;
					DFS(i,j);
					if(c>mx)
						mx=c;
				}
		cout<<mx<<endl;
	return 0;
}
