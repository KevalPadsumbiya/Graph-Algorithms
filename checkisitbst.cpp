#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

vector<lli> leftchild,rightchild;
vector<lli> key,v;

void inOrder(lli root)
{
	if(root==-1)
		return;
	inOrder(leftchild[root]);
	if(root!=-1)
		v.pb(key[root]);
	inOrder(rightchild[root]);
}

int main()
{
	fastio;
	lli n,i,f=0;
	cin>>n;
	
	key.resize(n);
	leftchild.resize(n,-1);
	rightchild.resize(n,-1);
	
	for(i=0;i<n;i++)
		cin>>key[i]>>leftchild[i]>>rightchild[i];
	
	if(n>1)
	{
		inOrder(0);		// left,right,root
		for(i=1;i<v.size();i++)
			if(v[i]<v[i-1])	
				f=1;
	}
	
	if(f)
		cout<<"INCORRECT";
	else
		cout<<"CORRECT";
}

