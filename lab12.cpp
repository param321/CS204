#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define st string
#define sexy ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mod 1000000007

vector<ll> parent;
vector<ll> size;

void make_set(int v) {
    parent[v] = v;
    size[v] = 0;
}

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        if (size[a] == size[b])
            size[a]++;
    }
}

struct Edge {
    ll u, v;
    ll weight;
    bool operator<(Edge const& other) {
        return weight > other.weight;
    }
};

int main(){
    sexy;
    ll x,y,p,q,r,n,m;
    ll z;
    cin>>n>>m;
    vector <Edge> edges;
    for(ll i=0;i<m;i++){
        cin>>x>>y>>z;
        Edge e;
        e.u=x;
        e.v=y;
        e.weight=z;
        edges.push_back(e);
    }
    int cost = 1;
    vector<Edge> result;
    parent.resize(n);
    size.resize(n);
    for (int i = 0; i < n; i++)
        make_set(i);

    sort(edges.begin(), edges.end());

    for (Edge e : edges) {
        if (find_set(e.u) != find_set(e.v)) {
            cost=(cost*((e.weight)%mod))%mod;
            result.push_back(e);
            union_sets(e.u, e.v);
        }
    }
    cout<<cost<<endl;
    return 0;
}
