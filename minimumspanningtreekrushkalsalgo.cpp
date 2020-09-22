#include<iostream>
#include<vector>
#include<math.h>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
using namespace std;
struct edge
{
	int a,b,w;
};
edge ar[100001];
int par[10001];
bool comp(edge a,edge b)
{
	if(a.w<b.w)
		return true;
	return false;
}
int find(int a)
{
	if(par[a]<0)
		return a;
	return par[a]=find(par[a]);
}
void Union(int a,int b)
{
	par[b]=a;
}
int main()
{
	ios_base::sync_with_stdio(false); 
    cout.tie(NULL);
	int i,n,m,ans=0;
	cin>>n>>m;
	for(i=1;i<=n;i++)
		par[i]=-1;
		
	for(i=0;i<m;i++)
		cin>>ar[i].a>>ar[i].b>>ar[i].w;
	
	sort(ar,ar+m,comp);
	
	for(i=0;i<m;i++)
	{
		int a,b;
		a=find(ar[i].a);
		b=find(ar[i].b);
		
		if(a!=b)
		{
			ans+=ar[i].w;
			Union(a,b);
			cout<<endl<<ar[i].a<<" "<<ar[i].b<<endl;
		}
	}
	cout<<ans;
	return 0;
}

