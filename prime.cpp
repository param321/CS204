#include <bits/stdc++.h>
using namespace std;

int main(){
unsigned long long x,y,z,p,q,r,i,l;
string a,b,c,e;
cin>>l;
while(l--){
    cin>>x;
    r=1;
    for(i=2;i<=sqrt(x);i++){
        if(x%i==0){
            r=0;
            break;
        }
    }
    if(r==1){
        cout<<"Prime"<<endl;
    }else{
        cout<<"Not a Prime"<<endl;
    }
}
return 0;
}
