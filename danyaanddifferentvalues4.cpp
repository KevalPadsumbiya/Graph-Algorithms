#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

int fre[200001],cost[200001],cnt;

void add(int pos)
{
	if(++fre[cost[pos]]==1)
		cnt++;
}
void remove(int pos)
{
	if(--fre[cost[pos]]==0)
		cnt--;
}

int main()
{
//	fastio;
	int t;
	scanf("%d",&t);
//	cin>>t;
	while(t--)
	{
		cnt=0;
		int n,i,j,a,b,l,r,ML,MR,q,x,d,X,D;
//		cin>>n;
		scanf("%d",&n);
		for(i=1;i<=n;i++)
			fre[i]=0;
		for(i=0;i<n-1;i++)
			scanf("%d",&a);
//			cin>>a;
		for(i=1;i<=n;i++)
			scanf("%d",&cost[i]);
//			cin>>cost[i];
//		cin>>q;
		scanf("%d",&q);
		ML=1,MR=0;
		for(i=0;i<q;i++)
		{
			scanf("%d %d",&x,&d);
//			cin>>x>>d;
			l=x^cnt;
			r=d^cnt;
			r+=l;
//			cout<<l<<" "<<r<<"\n";
			while(ML>l)
				ML-- , add(ML);
			while(MR<r)
				MR++ , add(MR);
			while(ML<l)
				remove(ML) , ML++;
			while(MR>r)
				remove(MR) , MR--;
			printf("%d\n",cnt);
//			cout<<cnt<<"\n";
		}
	}
	return 0;
}

