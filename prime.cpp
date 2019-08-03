#include <bits/stdc++.h>
using namespace std;

int main(){
unsigned long long x,y,z,p,q,r,i;
string a,b,c,e;
cin>>x;
r=1;
for(i=2;i<=sqrt(x);i++){
    if(x%i==0){
        r=0;
        break;
    }
}
if(r==1){
    cout<<"PRIME"<<endl;
}else{
    cout<<"NOT PRIME"<<endl;
}
return 0;
}
