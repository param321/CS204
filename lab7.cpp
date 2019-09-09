#include<bits/stdc++.h>
using namespace std;

bool compare(string a,string b){
	if((a+b)>(b+a)){
		return 1;
	}else{
		return 0;
	}
}

int main(){
	int x,y,z;
	string a,b,c;
	cin>>x;
	while(x--){
		cin>>y;
		string ar[y];
		for(int j=0;j<y;j++){
			cin>>ar[j];
		}
		sort(ar,ar+y,compare);
		for(int j=0;j<y;j++){
			cout<<ar[j];
		}
		cout<<endl;
	}
	return 0;
}
