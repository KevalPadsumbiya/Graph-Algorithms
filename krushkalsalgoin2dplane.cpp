#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

vector<int> par(100001,-1);

struct edge
{
	int a,b;
	double w;
}ar[100001];

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
	fastio;
	int n,i,j,a,b,c=0;
	double ans=0;
	
	cin>>n;
	int x[n],y[n];
	
	cout<<fixed<<setprecision(8);	
	
	for(i=0;i<n;i++)
		cin>>x[i]>>y[i];
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			ar[c].a=i+1;
			ar[c].b=j+1;
			ar[c].w=sqrt(pow(x[i]-x[j],2)+pow(y[i]-y[j],2));
			c++;
			ar[c].a=j+1;
			ar[c].b=i+1;
			ar[c].w=ar[c-1].w;
			c++;
		}
	}
	
	sort(ar,ar+c,comp);
	
//	for(i=0;i<c;i++)
//		cout<<ar[i].a<<" "<<ar[i].b<<" "<<ar[i].w<<endl;
		
	for(i=0;i<c;i++)
	{
		a=find(ar[i].a);
		b=find(ar[i].b);
		
		if(a!=b)
		{	
			ans+=ar[i].w;
			Union(a,b);
//			cout<<endl<<ar[i].a<<" "<<ar[i].b<<" "<<ar[i].w<<endl;
		}
	}

	cout<<ans;
		
	return 0;
}
