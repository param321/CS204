#include <bits/stdc++.h>
using namespace std;

string add(string a,string b){
int x,y,z,p,q,r;
string c;
char d;
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
return c;
}

int main(){
int x,y,z,p,q,r=0;
string a,b,c,e,f;
char d;
cin>>a>>b;
reverse(a.begin(),a.end());
reverse(b.begin(),b.end());
x=max(a.length(),b.length());
y=min(a.length(),b.length());
if(b.length()==x){
	c=b;
	b=a;
	a=c;
}
int rem;
for(int i=0;i<y;i++){
	c="";
	p=b[i]-'0';
	rem=0;
	for(int j=0;j<x;j++){
		q=a[j]-'0';
		d='0'+(p*q+rem)%10;
		c=c+d;
		rem=(p*q+rem)/10;
	}
	d='0'+rem;
	c=c+d;
	reverse(c.begin(),c.end());
	for(int j=0;j<i;j++){
		c=c+'0';
	}
	e=add(e,c);
}
for(int i=0;i<e.length();i++){
	if(e[i]=='0'){
		r++;
	}else{
		break;
	}
}
for(int i=r;i<e.length();i++){
	f=f+e[i];
}
if(f.empty()){
	cout<<0<<endl;
}else{
	cout<<f<<endl;
}
return 0;
}
