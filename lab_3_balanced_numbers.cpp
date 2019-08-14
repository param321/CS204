#include <bits/stdc++.h>
using namespace std;

int main(){
	string a,b,c;
	int x,y,z,p,q;
	cin>>x;
	for(int i=0;i<x;i++){
		stack <char> s;
		cin>>a;
		y=a.length();
		z=0;
		for(int j=0;j<y;j++){
			if(a[j]=='|'){
				z++;
			}
		}
		if(z%2==1){
			cout<<"NO"<<endl;
		}else{
			p=1;
			z=z/2;
			q=0;
			for(int j=0;j<y;j++){
				if(a[j]=='('||a[j]=='['||a[j]=='{'||a[j]=='<'){
					s.push(a[j]);
				}else if(a[j]=='|'){
					if(q<=(z-1)){
						s.push('|');
					}else{
						if(s.top()=='|'){
							s.pop();
						}else{
							p=0;
							break;
						}
					}
					q++;
				}else{
					if(!s.empty()){
					if((a[j]==')'&&s.top()=='(')||(a[j]==']'&&s.top()=='[')||(a[j]=='}'&&s.top()=='{')||(a[j]=='>'&&s.top()=='<')){
						s.pop();
					}else{
						p=0;
						break;
					}
					}else{
						p=0;
						break;
					}
				}
			}
			if(!s.empty()){
				p=0;
			}
			if(p==1){
				cout<<"YES"<<endl;
			}else{
				cout<<"NO"<<endl;
			}
		}
	}
	return 0;
}
