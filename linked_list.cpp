#include <bits/stdc++.h>
using namespace std;

struct Node{
    int p;
    int q;
    struct Node *ptr;
};

struct Node *lis=NULL;

void ad(int x,int y){
    struct Node *new_node;
    new_node = new Node;
    new_node->ptr=lis;
    new_node->p=x;
    new_node->q=y;
    lis=new_node;
}

void del(){
    struct Node *new_node;
    new_node=lis;
    if(lis!=NULL){
        if(lis!=NULL){
            lis=(lis->ptr);
        }
        free(new_node);
    }else{
        cout<<-1<<endl;
    }
}

void length(){
    int x=0;
    struct Node *new_node=lis;
    while(new_node!=NULL){
        x++;
        new_node=new_node->ptr;
    }
    cout<<x<<endl;
}

void delxy(int x,int y){
    struct Node *new_node=lis;
    struct Node *back_node=NULL;
    if(new_node==NULL){
        cout<<-1<<endl;
        return;
    }
    if(new_node->p==x&&new_node->q==y){
        lis=new_node->ptr;
        free(new_node);
        return;
    }
    while(new_node->p!=x||new_node->q!=y){
        back_node=new_node;
        new_node=new_node->ptr;
        if(new_node==NULL){
            cout<<-1<<endl;
            return;
        }
    }
    if(new_node->ptr!=NULL){
        back_node->ptr=new_node->ptr;
    }else{
       back_node->ptr=NULL;
    }
    delete(new_node);
}

void searchxy(int x,int y){
    struct Node *new_node;
    new_node=lis;
    while(new_node->p!=x||new_node->q!=y){
        new_node=new_node->ptr;
        if(new_node==NULL){
            cout<<"False"<<endl;
            break;
        }
    }
    if(new_node!=NULL){
        cout<<"True"<<endl;
    }
}

void search(float y){
    struct Node *new_node;
    new_node=lis;
    float j,k;
    int p=0;
    while(new_node!=NULL){
        j=new_node->p;
        k=new_node->q;
        if(((j*j)+(k*k))<=y*y){
            p++;
        }
        new_node=new_node->ptr;
    }
    if(p==0){
        cout<<-1;
    }else{
        cout<<p;
    }
    cout<<endl;
}

int main(){
    int x,y,z,p,q,r;
    cin>>r;
    for(int i=0;i<r;i++){
        cin>>x;
        if(x==1){
            cin>>y>>z;
            ad(y,z);
        }else if(x==2){
            del();
        }else if(x==3){
            cin>>y>>z;
            delxy(y,z);
        }else if(x==4){
            float n;
            cin>>n;
            search(n);
        }else if(x==5){
            cin>>y>>z;
            searchxy(y,z);
        }else if(x==6){
            length();
        }
    }
    return 0;
}
