#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define ld long double
#define st string
#define sexy ios_base::sync_with_stdio(false); cin.tie(NULL)
#define mod 1000000007
vector<vector<ll>> v(1000005);
vector <ll> color(1000005,-1);
bool c=true;

void dfs(ll x,ll a){
    if(!c) return;
    else if(color[x]!=-1){
        if(a^color[x]==0){
            return;
        }else{
            c=false;
            return;
        }
    }else{
        color[x]=a;
        for(auto it:v[x]){
            dfs(it,a^1);
        }
        return;
    }
}

int main(){
    sexy;
    ll x,y,z,p,q,r,n,m;
    cin>>n>>m;
    for(ll i=0;i<m;i++){
        cin>>x>>y;
        v[x].push_back(y);
        v[y].push_back(x);
    }
    for(ll i=1;i<=n;i++){
        if(!c) break;
        else if(color[i]!=-1) continue;
        else dfs(i,1);
    }
    if(!c){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
    }
    return 0;
}
