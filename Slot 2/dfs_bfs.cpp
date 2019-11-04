#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define st string
#define sexy ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mod 1000000007
const ll N=1e6+5;
vector<vector<ll>> adj(N);  

queue<ll> q;
vector<bool> used(N);
vector<ll> d(N), p(N);

void bfs(ll s){
	q.push(s);
	used[s] = true;
	p[s] = -1;
	while (!q.empty()) {
    	ll v = q.front();
    	cout<<v<<" ";
    	q.pop();
    	for (ll u : adj[v]) {
        	if (!used[u]) {
            	used[u] = true;
            	q.push(u);
            	d[u] = d[v] + 1;
            	p[u] = v;
        	}
    	}
	}
	fill(used.begin(),used.end(),false);
}

void dfs(ll v) {
    used[v] = true;
    cout<<v<<" ";
    for(ll u : adj[v]){
        if(!used[u])
           dfs(u);
    }
}

int main(){
	ll x,y,z,x1,x2;
	cin>>x>>y;
	for(ll i=0;i<y;i++){
		cin>>x1>>x2;
		adj[x1].push_back(x2);
		adj[x2].push_back(x1);
	}
	bfs(0);
	return 0;
}




