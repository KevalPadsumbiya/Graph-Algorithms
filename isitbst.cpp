#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

struct BST 
{
    int key,leftchild,rightchild;
    BST()
	{
		key=0;
		leftchild=-1;
		rightchild=-1;
	}
    BST(int key1,int leftchild1,int rightchild1)
	{
		key=key1;
		leftchild=leftchild1;
		rightchild=rightchild1; 
	}
};

vector<BST> bst;
vector<int> v;

void inOrder(int root) 
{
    if(root==-1) 
		return;
    inOrder(bst[root].leftchild);
    v.pb(bst[root].key);
    inOrder(bst[root].rightchild);
}

int main() 
{
	fastio;
    int n,i,key, leftchild, rightchild,f=0;

    cin>>n;

    for (i=0;i<n;i++) 
        cin>>key>>leftchild>>rightchild, bst.pb(BST(key, leftchild, rightchild));

    if(bst.size()>1)
	{
		inOrder(0);
        for (i=1;i<v.size();i++) 
            if(v[i]<=v[i-1]) 
            	f=1;
    }

    if(f) 
        cout<<"INCORRECT";
    else
        cout<<"CORRECT";
    return 0;
}
