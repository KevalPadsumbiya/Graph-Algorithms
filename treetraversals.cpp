#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

vector<int> key,leftchild,rightchild;

void inOrder(int root)
{
	if(root==-1)
		return;
	inOrder(leftchild[root]);
	cout<<key[root]<<" ";
	inOrder(rightchild[root]);
}

void preOrder(int root)
{
	if(root==-1)
		return;
	cout<<key[root]<<" ";
	preOrder(leftchild[root]);
	preOrder(rightchild[root]);
}

void postOrder(int root)
{
	if(root==-1)
		return;
	postOrder(leftchild[root]);
	postOrder(rightchild[root]);
	cout<<key[root]<<" ";
}

int main()
{
	fastio;
	int n,i;
	cin>>n;
	
	key.resize(n);
	leftchild.resize(n);
	rightchild.resize(n);
	
	for(i=0;i<n;i++)
		cin>>key[i]>>leftchild[i]>>rightchild[i];
	
	inOrder(0);		// left,right,root
	cout<<"\n";		
	preOrder(0);	// root,left,right
	cout<<"\n";	
	postOrder(0);	// left,right,root
}

