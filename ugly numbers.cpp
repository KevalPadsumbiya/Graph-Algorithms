#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

int prime[1000001];
vector<int> v;
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
    v.pb(1);
	for(i=2;i<=1000000;i++) 
		if(prime[i]==2 || prime[i]==3 || prime[i]==5)
			v.pb(i);
}

int main()
{
	fastio;
	sieve();
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout<<v[n-1]<<"\n";
	}
	return 0;
}

