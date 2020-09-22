#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

char a[20][20];
int vis[20][20],n,m;

void DFS(int x,int y)
{
	if(vis[x][y]==0 && a[x][y]=='O')
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
		int i,j;
		cin>>n>>m;
		
		for(i=0;i<n;i++)
			for(j=0;j<m;j++)
				cin>>a[i][j] , vis[i][j]=0;
		
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(vis[i][j]==0 && a[i][j]=='O' && (i==0 || i==n-1 || j==0 || j==m-1))
					DFS(i,j);
			}
		}
	
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(a[i][j]=='X' || a[i][j]=='O')		
					cout<<"X ";
				else
					cout<<"O ";
			}
		}
		cout<<endl;
	}
	return 0;
}

