#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

vector<int> ar[100001],prime;
vector<pair<int,int>> primefactors[1000001];
int block=1000,st[100001],et[100001],fl[200001],timer=1,cost[100001],fre[100001],vis[100001],lca[100001][20],maxN,level[100001],ans[100001];
bool isPrime[1000001];
lli inv[2000001];
struct query
{
	int i,l,r,type;
}Q[100001];

lli totalfactors;

//void sieve()
//{
//	int i,j;
//	for(i=2;i*i<=1000000;i++)
//		for(j=i*i;j<=1000000;j+=i)
//			isPrime[j]=true;
//	for(i=2;i<=1000000;i++)
//		if(!isPrime[i])
//			prime.push_back(i);
//	inv[0] = inv[1] = 1;
//	for(int i=2;i<=2000000;i++)
//	inv[i] = (mod - (((mod/i) * 1LL *inv[mod % i])  % mod)) % mod;
//}

bool comp(query a,query b)
{
	if(a.l/block!=b.l/block)
		return a.l/block < b.l/block;
	return a.r<b.r;
}

void sieve() 
{ 
	int i,j;
    prime[1]=1; 
    for(i=2;i<1000000;i++) 
        prime[i]=i; 
    for (i=4;i<1000000;i+=2) 
        prime[i]=2; 
    for (i=3;i*i<1000000;i++) 
    { 
        if(prime[i]==i) 
        { 
            for(j=i*i;j<1000000;j+=i) 
                if(prime[j]==j) 
                    prime[j]=i; 
        } 
    } 
	inv[0] = inv[1] = 1;
	for(int i=2;i<=2000000;i++)
	inv[i] = (mod - (((mod/i) * 1LL *inv[mod % i])  % mod)) % mod;
}

void primeFactorization()
{
	int i;
	for(i=1;i<=1000000;i++)
	{
		int j=0,x=i,fre;
		while(x>1)
		{
			fre=0;
			while(x%prime[j]==0)
			{
				fre++;
				x/=prime[j];
			}
			if(fre>0)
				primefactors[i].pb(mk(prime[j],fre));
			j++;
		}
	}
}

void DFS(int src,int par,int d)
{
	level[src]=d;
	lca[src][0]=par;
	st[src]=timer;
	fl[timer]=src;
	timer++;
	for(auto child : ar[src])
		if(child!=par)
			DFS(child,src,d+1);
	et[src]=timer;
	fl[timer]=src;
	timer++;
}

int findLCA(int a,int b)
{
	int i,d;
	if(level[a]>level[b])
		swap(a,b);
	d=level[b]-level[a];
	while(d>0)
	{
		i=log2(d);
		b=lca[b][i];
		d-=(1<<i);
	}
	if(a==b)
		return b;
	for(i=maxN;i>=0;i--)
	{
		if(lca[a][i]!=-1 && (lca[a][i]!=lca[b][i]))
		{
			a=lca[a][i];
			b=lca[b][i];
		}
	}
	return lca[a][0];
}

void add(int pos)
{
	vector<pair<int,int>> v=primefactors[cost[fl[pos]]]; 
	for(auto pair : v)
	{
		if(fre[pair.first]!=0)
		{
//			totalfactors/=(fre[pair.first]+1);
			totalfactors=(totalfactors*inv[(fre[pair.first]+1)])%mod;
			fre[pair.first]+=pair.second;
			totalfactors=(totalfactors*(fre[pair.first]+1))%mod;
		}
		else
		{
			fre[pair.first]+=pair.second;
			totalfactors=(totalfactors*(fre[pair.first]+1))%mod;
		}
	}
}

void remove(int pos)
{
	vector<pair<int,int>> v=primefactors[cost[fl[pos]]];
	for(auto pair : v)
	{
//		if(fre[pair.first]!=0)
//		{
//			totalfactors/=(fre[pair.first]+1);
//			fre[pair.first]+=pair.second;
//			totalfactors=(totalfactors*(fre[pair.first]+1));
//		}
//		else
//		{
			totalfactors=(totalfactors*inv[(fre[pair.first]+1)])%mod;
			fre[pair.first]-=pair.second;
			totalfactors=(totalfactors*(fre[pair.first]+1))%mod;
//		}
	}
}

int main()
{
	fastio;
	sieve();
	primeFactorization();
//	for(int i=1;i<=20;i++)
//	{
//		cout<<i<<" : ";
//		for(auto pair : primefactors[i])
//			cout<<"( "<<pair.first<<" , "<<pair.second<<" ) , ";
//		cout<<"\n";
//	}
//	vector<pair<int,int>> v=primefactors[20];
//	for(auto pair : v)
//		cout<<"( "<<pair.first<<" , "<<pair.second<<" ) , ";
//	cout<<"\n";
	int t;
	cin>>t;
	while(t--)
	{
		int n,i,a,b,j,q,LCA;
		cin>>n;
		if(n>1000)
			return 0;
		maxN=log2(n)+1;
		timer=totalfactors=1;
		for(i=1;i<=n;i++)
		{
			ar[i].clear();
			fre[i]=0;
			vis[i]=0;
		}
		for(j=1;j<=maxN;j++)
			for(i=1;i<=n;i++)
			{
					lca[i][j]=-1;
			}
		for(i=0;i<n-1;i++)
		{
			cin>>a>>b;
			ar[a].pb(b);
			ar[b].pb(a);
		}
		for(i=1;i<=n;i++)
			cin>>cost[i];
		DFS(1,-1,0);
		for(j=1;j<=maxN;j++)
			for(i=1;i<=n;i++)
			{
				if(lca[i][j-1]!=-1)
				{
					int par=lca[i][j-1];
					lca[i][j]=lca[par][j-1];
				}
			}
//		for(i=1;i<=n;i++)
//			cout<<st[i]<<" ";
//		cout<<"\n";
//		for(i=1;i<=n;i++)
//			cout<<et[i]<<" ";
//		cout<<"\n";
//		for(i=1;i<=n;i++)
//			cout<<lca[i][0]<<" ";
//		cout<<"\n";
//		for(i=1;i<=2*n;i++)
//			cout<<fl[i]<<' ';
//		cout<<"\n";
		cin>>q;
		for(i=0;i<q;i++)
		{
			cin>>a>>b;
//			cout<<findLCA(a,b);
			LCA=findLCA(a,b);
//			if(LCA==a || LCA==b)
//			{
//				Q[i].l=min(st[a],st[b]);
//				Q[i].r=max(st[a],st[b]);
//				Q[i].type=0;
//			}
//			else
//			{
//				Q[i].l=min(et[a],st[b]);
//				Q[i].r=max(et[a],st[b]);
//				Q[i].type=LCA;
//			}
			if(st[a]>st[b])
				swap(a,b);
			if(a==LCA || b==LCA)
			{
				Q[i].l=st[a];
				Q[i].r=st[b];
				Q[i].type=0;	
			}
			else
			{
				Q[i].l=et[a];
				Q[i].r=st[b];
				Q[i].type=LCA; 
			}
			Q[i].i=i;
		}
		sort(Q,Q+q,comp);
//		for(i=0;i<q;i++)
//			cout<<Q[i].l<<" "<<Q[i].r<<" "<<Q[i].type<<"\n";
		int l,r,ML=1,MR=0;
		for(i=0;i<q;i++)
		{
			l=Q[i].l;
			r=Q[i].r;
			while(ML>l)
			{
				ML--;
				if(ML>=l && ML<=r)
				{
					if(vis[fl[ML]]==1)
					{
						remove(ML);
					}
					else
					{
//						vis[ML]^=1;
						add(ML);
					}
//					vis[fl[ML]]^=1;
				}
				else
					add(ML);
				vis[fl[ML]]^=1;
			}
			while(MR<r)
			{
				MR++;
				if(MR>=l && MR<=r)
				{
					if(vis[fl[MR]]==1)
					{
						remove(MR);
					}
					else
					{
//						vis[fl[MR]]^=1;
						add(MR);
					}
//					vis[fl[MR]]^=1;
				}
				else
					add(MR);
				vis[fl[MR]]^=1;
			}
			while(ML<l)
			{
				if(ML>=l && ML<=r)
				{
					if(vis[fl[ML]]==1)
					{
						remove(ML);
					}
					else
					{
//						vis[fl[ML]]^=1;
						add(ML);
					}
//					vis[fl[ML]]^=1;
				}
				else
					remove(ML);
				vis[fl[ML]]^=1;
				ML++;
			}
			while(MR>r)
			{
				if(MR>=l && MR<=r)
				{
					if(vis[fl[MR]]==1)
					{
						remove(MR);
					}
					else
					{
//						vis[fl[MR]]^=1;
						add(MR);
					}
//					vis[fl[MR]]^=1;
				}
				else
					remove(MR);
				vis[fl[MR]]^=1;
				MR--;
			}
			if(Q[i].type!=0)
				add(Q[i].type);
			ans[Q[i].i]=totalfactors%mod;
		}
		for(i=0;i<q;i++)
			cout<<ans[i]<<"\n";
//		for(i=1;i<=n;i++)
//			cout<<level[i]<<" ";
//		cout<<"\n";
	}
	return 0;
}
/*
1
5
1 2
1 3
2 4
2 5
3 4 1 3 5
1
4 3
*/
