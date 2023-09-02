#include <bits/stdc++.h>
using namespace std;


struct node{
    int data;
    node * next;
    node(int d):data(d){}
    //~node();
};

template<class t>
class Stack{
private:
    node*head= nullptr;
public:
    void push(int num){
        node*new_node=new node(num);
        new_node->next=head;
        head=new_node;
    }

    void pop(){
        if(isempty())
            cout<<"The stack is already empty\n";
        else{
            node*temp=head;
            head=head->next;
            delete temp;
        }
    }

    int get_head(){
        if(isempty())
            cout<<"The stack is already empty\n";
        else {
            return head->data;
        }
    }

    bool isempty(){
        return !head;
    }
    void print(){
        for(node*cur=head;cur;cur= cur->next){
            cout<<cur->data<<" ";
        }
        cout<<endl;
    }



};

bool comp(char c1,char c2){
    if(((c1=='*'||c1=='/')&&(c2=='-'||c2=='+'))||(c2=='('))
        return true;
    return false;
}


string infixtopostfix(string infix){
    string s="";
    stack<char>operators;
    for(int x=0;x<infix.length();x++){
        if(isdigit(infix[x])){
            s+=infix[x];
        }

        else if(operators.empty()||infix[x]=='(')
            operators.push(infix[x]);
        else if(infix[x]==')'){
            while(operators.top()!='('){
                s+=operators.top();
                operators.pop();
            }
            operators.pop();
        }
        else {
            if (comp(infix[x], operators.top()))
                operators.push(infix[x]);
            else {
                while (!operators.empty()) {
                    s+=operators.top();
                    operators.pop();
                }
                operators.push(infix[x]);
            }
        }
    }
    while (!operators.empty()) {
        s+=operators.top();
        operators.pop();
    }
    return s;
}






int main() {
 
}


