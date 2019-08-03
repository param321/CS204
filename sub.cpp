#include <bits/stdc++.h>
using namespace std;

int gre(string a,string b){
	int x,y,z,p,q,r;
	x=a.length();
	if(a.length()>b.length()){
		return 1;
	}else if(a.length()<b.length()){
		return 0;
	}else{
		for(int i=0;i<x;i++){
			if((a[i]-'0')>(b[i]-'0')){
				return 1;
			}else if((a[i]-'0')<b[i]-'0'){
				return 0;
			}
		}
	}
	return 1;
}

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
int x,y,z,p,q,r;
string a,b,c,e;
char d;
cin>>a>>b;
if(gre(a,b)==1){
	r=1;
}else{
	swap(a,b);
	r=0;
}
x=max(a.length(),b.length());
y=min(a.length(),b.length());
for(int i=0;i<x;i++){
	d='0'+'9'-a[i];
	c=c+(d);
}
e=add(b,c);
reverse(e.begin(),e.end());
y=e.length();
for(int i=0;i<x;i++){
	if(i<y){
		d='9'-e[i]+'0';
		e[i]=d;
	}else{
		e=e+'9';
	}
}
int i=e.length();
while(e[i-1]=='0'){
	e.pop_back();
	i--;
}
reverse(e.begin(),e.end());
if(e.empty()){
	cout<<0<<endl;
}else{
	if(r==0){
		cout<<'-';
	}
	cout<<e<<endl;
}	
return 0;
}