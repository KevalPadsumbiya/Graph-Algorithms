#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

char a[1001][1001];
pair<int,int> src,dest;
int n,m,i,j,vis[1001][1001],steps;
vector<pair<int,int>> back_up;
int x[4]={1,-1,0,0};
int y[4]={0,0,1,-1};

bool isValid(int x,int y)
{
	if(x<0 || y<0 || x>=n || y>=m)
		return false;
	if(vis[x][y]==1 || a[x][y]=='#')
		return false;
	return true;	
}

int zeroOneBFS()
{
	queue<pair<int,int>> q;	
	q.push(src);
	vis[src.first][src.second]=1;
	while(!q.empty())
	{
		while(!q.empty())
		{
			pair<int,int> cur=q.front();
			q.pop();
			back_up.pb(cur);
			for(i=0;i<4;i++)
			{
				if(isValid(cur.first+x[i],cur.second+y[i]))
				{
					q.push({cur.first+x[i],cur.second+y[i]});
					vis[cur.first+x[i]][cur.second+y[i]]=1;
					if(cur.first+x[i]==dest.first && cur.second+y[i]==dest.second)
						return steps;	
				}
			}
		}
		for(auto p : back_up)
		{
			for(i=-2;i<=2;i++)
			{
				for(j=-2;j<=2;j++)
				{
					if(isValid(p.first+i,p.second+j))
					{
						q.push({p.first+i,p.second+j});
						vis[p.first+i][p.second+j]=1;
						if(p.first+i==dest.first && p.second+j==dest.second)
							return ++steps;
					}
				}
			}
		}
		steps++;
		back_up.clear();
	}
	return -1;
}

int main()
{
	fastio;
	int x1,y1;
	cin>>n>>m;
	cin>>x1>>y1;
	src={x1-1,y1-1};	
	cin>>x1>>y1;
	dest={x1-1,y1-1};
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			cin>>a[i][j];
	cout<<zeroOneBFS();
	return 0;
}

