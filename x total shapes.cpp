#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

int vis[50][50],n,m;
char a[50][50];

void DFS(int x,int y)
{
	if(vis[x][y]==0 && a[x][y]=='X')
	{
//		cout<<x<<" "<<y<<"\n";
		vis[x][y]=1;
		a[x][y]='1';
		if(x-1>=0)
			DFS(x-1,y);
		if(x+1<n)
			DFS(x+1,y);
		if(y-1>=0)
			DFS(x,y-1);
		if(y+1<m)
			DFS(x,y+1);
	}
}

int main()
{
	fastio;
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		int i,j,cc=0;	
		cin>>n>>m;
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				vis[i][j]=0;
		for(i=0;i<n;i++)
		{
			cin>>s;
			for(j=0;j<m;j++)
			{
				if(s[j]=='O')
					a[i][j]='O';
				else
					a[i][j]='X';				
			}				
		}
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				if(vis[i][j]==0 && a[i][j]=='X')
					DFS(i,j) , cc++;
		cout<<cc<<"\n";
	}
	return 0;
}

