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

struct Edge
{
    ll u, v, weight;
    bool operator<(Edge const &other)
    {
        return weight < other.weight;
    }
};

int main(){
    ll n,m;
    vector<Edge> edges;
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        ll p,q,w;
        cin>>p>>q>>w;
        Edge e;
        e.u=p;
        e.v=q;
        e.weight=w;
        edges.push_back(e);
    }
    ll cost = 0;
    vector<Edge> result;
    parent.resize(n);
    size.resize(n);
    for (ll i = 0; i < n; i++)
        make_set(i);

    sort(edges.begin(), edges.end());

    for (Edge e : edges) {
        if (find_set(e.u) != find_set(e.v)) {
            cost += e.weight;
            result.push_back(e);
            union_sets(e.u, e.v);
        }
    }
}
