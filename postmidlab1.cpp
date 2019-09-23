#include <bits/stdc++.h>
using namespace std;
#define mod 10000001
#define ll long long

ll partition(ll arr[], ll l, ll r, ll k); 

ll findMedian(ll arr[], ll n){ 
    sort(arr, arr+n);  
    return arr[n/2]; 
} 

ll kthSmallest(ll arr[], ll l, ll r, ll k){ 
    if (k > 0 && k <= r - l + 1){ 
        ll n = r-l+1; 
        ll i, median[(n+4)/5];
        for (i=0; i<n/5; i++) 
            median[i] = findMedian(arr+l+i*5, 5); 
        if (i*5 < n){ 
            median[i] = findMedian(arr+l+i*5, n%5);  
            i++; 
        }     
  
        ll medOfMed = (i == 1)? median[i-1]: 
                                 kthSmallest(median, 0, i-1, i/2); 
  
        ll pos = partition(arr, l, r, medOfMed); 
  
        if (pos-l == k-1) 
            return arr[pos]; 
        if (pos-l > k-1) 
            return kthSmallest(arr, l, pos-1, k); 
  
        return kthSmallest(arr, pos+1, r, k-pos+l-1); 
    } 
    return INT_MAX; 
} 

void swap(ll *a, ll *b) 
{ 
    ll temp = *a; 
    *a = *b; 
    *b = temp; 
} 

ll partition(ll arr[], ll l, ll r, ll x){ 
    ll i; 
    for (i=l; i<r; i++) 
        if (arr[i] == x) 
           break; 
    swap(&arr[i], &arr[r]);
    i = l; 
    for (ll j = l; j <= r - 1; j++) 
    { 
        if (arr[j] <= x) 
        { 
            swap(&arr[i], &arr[j]); 
            i++; 
        } 
    } 
    swap(&arr[i], &arr[r]); 
    return i; 
} 

int main(){
	ll x,y,z,p,q,r;
	double s;
	cin>>x;
	for(ll i=0;i<x;i++){
		cin>>y;
		ll arr[y];
		for(ll j=0;j<y;j++){
			cin>>p>>q;
			arr[j]=(p*p)+(q*q);
		}
		r= kthSmallest(arr, 0, y-1, (y+1)/2);
		s=sqrt(r);
		cout<<s<<endl;
	}
	return 0;
}
