#include <bits/stdc++.h>
using namespace std;

struct tree{
	string x;
	tree *left;
	tree *right;
};

bool isOperator(char c){ 
    if(c=='+'||c=='-'||c=='*'||c=='/'||c=='^'){
        return true; 
    }else{
    	return false;
    } 
} 

tree *newNode(int v){ 
    tree *temp = new tree; 
    temp->left = temp->right = NULL; 
    temp->x = v; 
    return temp; 
}; 

int pr(char c){
	if(c=='^'){
		return 5;
	}else if(c=='/'){
		return 4;
	}else if(c=='*'){
		return 3;
	}else if(c=='+'){
		return 2;
	}else if(c=='-'){
		return 1;
	}else{
		return -1;
	}
}

string postfi(string a){
	stack <char> st; 
    st.push('N'); 
    int l = a.length(); 
    string ns; 
    for(int i = 0; i < l; i++){
    	//if(a[i]<'0'||a[i]>'9'){
    		//ns=ns+" ";
    	//}
        // If the scanned character is an operand, add it to output string. 
        if((a[i]>='0'&&a[i]<='9')){
        	ns+=a[i];
        // If the scanned character is an ‘(‘, push it to the stack. 
        }else if(a[i]=='('){
        	st.push('('); 
        // If the scanned character is an ‘)’, pop and to output string from the stack 
        // until an ‘(‘ is encountered. 
        }else if(a[i] == ')'){
            while(st.top() != 'N' && st.top() != '('){ 
                char c = st.top(); 
                st.pop(); 
               	ns += c; 
            } 
            if(st.top() == '('){ 
                char c = st.top(); 
                st.pop(); 
            } 
        }else{ 
            while(st.top() != 'N' && pr(a[i]) <= pr(st.top())) 
            { 
                char c = st.top(); 
                st.pop(); 
                ns += c; 
            } 
            st.push(a[i]); 
        } 
  
    } 
    //Pop all the remaining elements from the stack 
    while(st.top() != 'N') 
    { 
        char c = st.top(); 
        st.pop(); 
        ns += c; 
    }
	return ns;
}

tree* constructTree(string postfix){ 
    stack<tree *> st; 
    tree *t, *t1, *t2; 
    // Traverse through every character of 
    // input expression 
    for (int i=0; i<postfix.length(); i++){ 
        // If operand, simply push into stack 
        if (!isOperator(postfix[i])){ 
            t = newNode(postfix[i]); 
            st.push(t); 
        }else{ 
            t = newNode(postfix[i]);
            // Pop two top nodes 
            t1 = st.top(); // Store top 
            st.pop();      // Remove top 
            t2 = st.top(); 
            st.pop();
            //  make them children 
            t->right = t1; 
            t->left = t2;
            // Add this subexpression to stack 
            st.push(t); 
        } 
    } 
    //  only element will be root of expression 
    // tree 
    t = st.top(); 
    st.pop(); 
    return t; 
}

void inorder(tree *t) { 
    if(t){ 
        inorder(t->left); 
        cout<<(t->x)<<" ";
        inorder(t->right); 
    } 
} 

int toInt(string s)  {  
    int num = 0; 
    // Check if the integral value is  
    // negative or not 
    // If it is not negative, generate the number  
    // normally 
    if(s[0]!='-') 
        for (int i=0; i<s.length(); i++)  
            num = num*10 + (int(s[i])-48);  
    // If it is negative, calculate the +ve number 
    // first ignoring the sign and invert the  
    // sign at the end 
    else
        for(int i=1;i<s.length();i++){ 
            num = num*10 + (int(s[i])-48);  
            num = num*-1; 
        } 
    return num;  
}  

int eval(struct tree* root){  
    // empty tree  
    if (!root)  
        return 0;  
    // leaf node i.e, an integer  
    if (!root->left && !root->right)  
        return toInt(root->x);  
    // Evaluate left subtree  
    int l_val = eval(root->left);  
    // Evaluate right subtree  
    int r_val = eval(root->right);  
    // Check which operator to apply  
    if (root->x=="+")  
        return l_val+r_val; 
    if (root->x=="^")  
        return pow(r_val,l_val); 
    if (root->x=="-")  
        return l_val-r_val;  
    if (root->x=="*")  
        return l_val*r_val;  
    return l_val/r_val;  
}  

int main(){
	string a,b,c;
	int x,y,z,p,q;
	cin>>x;
	for(int i=0;i<x;i++){
		cin>>y;
		for(int j=0;j<y;j++){
			cin>>a;
			b=postfi(a);
			cout<<b<<endl;
			tree* r = constructTree(b);
			inorder(r);
			cout<<endl;
			cout << eval(r)<<endl;
		}
	}
	return 0;
}
