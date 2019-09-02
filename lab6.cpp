#include<bits/stdc++.h>
using namespace std;

int main(){
	int x,y,z,p,q,r,s,x2;
	string x1;
	cin>>x1;
	vector <int> v1;
	vector <int> v2;
	cin>>x2;
	for(int i=0;i<x2;i++){
		cin>>q;
		if(q==1){
			cin>>y>>z;
			auto it=find(v1.begin(),v1.end(),y);
			if(it==v1.end()){
				v1.push_back(y);
				v2.push_back(z);
			}else{
				auto it=find(v1.begin(),v1.end(),y);
				s=it-v1.begin();
				v2[s]=v2[s]+z;
			}
		}else{
			if(v1.empty()){
				cout<<"No data available."<<endl;
			}else{
				p=v1.size();
				r=0;
				s=0;
				for(int j=0;j<p;j++){
					if(v2.at(j)>r){
						r=v2.at(j);
						s=j;
					}
				}
				cout<<v1.at(s)<<endl;
			}
		}
	}
	return 0;
}
