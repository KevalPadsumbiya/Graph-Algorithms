#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;
int c;
struct trie
{
	struct trie* child[26];
	bool isend;
	trie()
	{
		for(int i = 0; i < 26; i++)
			child[i] = NULL;
		isend=false;
	}
};
struct trie* root;

void insert(string s)
{
	struct trie* cur=root;
	for(auto c : s)
	{
		if(cur->child[c-'a']==NULL)
			cur->child[c-'a']=new trie;
		cur=cur->child[c-'a'];
	}
	cur->isend=true;
}

int count(trie* &cur)
{
	int i;
	for(i=0;i<26;i++)
	{
		if(cur->child[i]!=NULL)
		{
			cur=cur->child[i];
			count(cur->child[i]);
//			cout<<(cur->child[i])<<endl;	
		}
		else if(cur->isend==true)
			c++;
	}
	return c;		
}

int isPresent(string s)
{
	struct trie* cur=root;
	for(auto c : s)
	{
		if(cur->child[c-'a']==NULL)
			return
			 0;
		cur=cur->child[c-'a'];
	}
	if(cur->isend==false)
		return count(cur);
	else
		return 1;
}

int main()
{
	fastio;
	root=new trie;
	int n,i;
	string s,s1;
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>s>>s1;
		if(s=="add")
			insert(s1);
		else
			cout<<isPresent(s1)<<"\n";
	}
	return 0;
}

