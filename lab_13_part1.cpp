#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define st string
#define sexy ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mod 1000000007

int main(){
	ll x,y,z,p,q,r;
	cin>>x;
	st a[x],b;
	set <st> s;
	for(ll i=0;i<x;i++){
		cin>>a[i];
		b=a[i];
		reverse(b.begin(),b.end());
		if(b!=a[i]){
			s.insert(a[i]);
		}
	}
	y=s.size();
	for(ll i=0;i<x;i++){
		b=a[i];
		reverse(a[i].begin(),a[i].end());
		if(b!=a[i]){
			s.insert(a[i]);
		}
	}
	z=s.size();
	if(z<(2*y)){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}
