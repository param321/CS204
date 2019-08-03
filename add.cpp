#include <bits/stdc++.h>
using namespace std;
int main(){
int x,y,z,p,q,r;
string a,b,c;
char d;
cin>>a>>b;
reverse(a.begin(),a.end());
reverse(b.begin(),b.end());
x=max(a.length(),b.length());
y=min(a.length(),b.length());
int rem=0;
for(int i=0;i<x;i++){
	if(i<y){
		p=a[i]-'0';
		q=b[i]-'0';
		d=('0'+((p+q+rem)%10));
		c=c+d;
		rem=(p+q+rem)/10;
	}else{
		if(a.length()==x){
			p=a[i]-'0';
		}else{
			p=b[i]-'0';
		}
		d=('0'+((p+rem)%10));
		c=c+d;
		rem=(p+rem)/10;
	}
}
if(rem==1){
	c=c+'1';
}
reverse(c.begin(),c.end());
cout<<c<<endl;
return 0;
}
