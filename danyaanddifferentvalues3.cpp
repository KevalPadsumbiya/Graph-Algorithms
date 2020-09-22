#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

set<int>* seg_tree;  
int cost[200001];

int power(int n)
{
	int res=1,a=2;
	while(n)
	{
		if(n%2)
			res*=a;
		a*=a;
		n/=2;
	}
	return res;
}

set<int> give_cnt(int node, int l, int r, int a, int b) 
{ 
	set<int> leftchild,rightchild,ans; 
	if (b<l || a>r) 
		return ans;  
	if (a<=l && r<=b) 
		return seg_tree[node]; 
	leftchild = give_cnt(2 * node, l, (l + r) / 2, a, b); 
	ans.insert(leftchild.begin(), leftchild.end()); 
	rightchild = give_cnt(1 + 2 * node, 1 + (l + r) / 2, r, a, b); 
	ans.insert(rightchild.begin(), rightchild.end()); 
	return ans; 
} 

void make_seg_tree(int i, int s, int e, int a[]) 
{ 
	if(s==e) 
	{ 
		seg_tree[i].insert(a[s]); 
		return; 
	} 
	make_seg_tree(2 * i, s, (s + e) / 2, a); 
	make_seg_tree(1 + 2 * i, 1 + (s + e) / 2, e, a); 
	seg_tree[i].insert(seg_tree[2 * i].begin(),seg_tree[2 * i].end()); 
	seg_tree[i].insert(seg_tree[2 * i + 1].begin(),seg_tree[2 * i + 1].end()); 
}

int main() 
{ 
//	fastio;
	int t;
//	cin>>t;
	scanf("%d",&t);
	while(t--)
	{
		int n,a,x,d,X,D,i,j,height,cnt=0,q;
		
		scanf("%d",&n);
//		cin>>n;
		
		for(i=0;i<n-1;i++)
			scanf("%d",&a);
//			cin>>a;
		for(i=1;i<=n;i++)
			scanf("%d",&cost[i]);
//			cin>>cost[i];
		
		height=(int)ceil(log2(n)); 
		height=(2*(power(height)))-1;  
		
		seg_tree = new set<int>[height]; 
		make_seg_tree(1,1,n, cost);
		
//		cin>>q;
		scanf("%d",&q);
		while(q--)
		{
			scanf("%d %d",&x,&d);
//			cin>>x>>d;
			X=cnt^x;
			D=cnt^d;
			set<int> ans = give_cnt(1,1,n,X,X+D); 
			cnt=ans.size();
			printf("%d\n",cnt);
//			cout<<cnt<<endl;  
		}	
	}
	return 0; 
} 

