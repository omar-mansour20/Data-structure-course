#include <bits/stdc++.h>
using namespace std;

template<class t>
class Stack{
private:
    int size;
    int top;
    t *arr{};
public:
    Stack(int size):size(size),top(-1){
        arr=new t [size];
    }

    bool is_full(){
        return top==size-1;
    }

    bool is_empty(){
        return top==-1;
    }

    void push(t num){
        if(is_full())
            cout<<"The stack is already full"<<endl;
        else{
            arr[++top]=num;
        }
    }

    void pop(){
        if(is_empty())
            cout<<"The stack is already empty"<<endl;
        else {
            top--;
        }
    }

    t get_top(){
        if(is_empty())
            cout<<"The stack is already empty"<<endl;
        else {
            return arr[top];
        }
    }

    void print(){
        for (int x = top; x >=0 ; --x)
            cout<<arr[x]<<" ";
        cout<<endl;
    }



};

string reverse_subwords(string s){
    Stack<char> st(s.length());
    string s2="";
    for (int x = 0; x < s.length(); ++x) {
        if(s[x]==' '){
            while(!st.is_empty()){
                s2.push_back(st.get_top());
                st.pop();
            }
            s2.push_back(' ');
        }
        else
            st.push(s[x]);
    }
    while(!st.is_empty()){
        s2.push_back(st.get_top());
        st.pop();
    }
    return s2;
}

int reverse_num(int num){
    Stack<int>st(100);int c=0,num2=0;
    while(num){
        st.push(num%10);
        num/=10;
    }
    while (!st.is_empty()){
        num2+=st.get_top()*pow(10,c++);
        st.pop();
    }
    return num2;
}

bool is_valid(string s){
    Stack<char>st(100);
    for (int x = 0; x < s.length(); ++x) {
        if(s[x]=='('||s[x]=='{'||s[x]=='[')
            st.push(s[x]);
        else if(s[x]==']'&&st.get_top()=='[')
            st.pop();
        else if(s[x]=='}'&&st.get_top()=='{')
            st.pop();
        else if(s[x]==')'&&st.get_top()=='(')
            st.pop();
    }
    if(st.is_empty())
        return true;
    return false;
}

string remove_duplicates(string s){
    Stack<char>st(100);
    for (int x = 0; x < s.length(); ++x) {
        if(!st.is_empty()&&st.get_top()==s[x])
            st.pop();
        else
            st.push(s[x]);
    }
    string s2="";
    while(!st.is_empty()) {
        s2.push_back(st.get_top());
        st.pop();
    }
   reverse(s2.begin(), s2.end());
    return s2;
}


class Stack2{
private:
    int size;
    int added_elements;
    int *arr{};
public:
    Stack2(int size):size(size),added_elements(0){
        arr=new int[size];
    }

    bool is_full(){
        return added_elements==size;
    }

    bool is_empty(){
        return added_elements==0;
    }

    bool push(int num){
        if(is_full())
        return false;

        added_elements++;
        for (int x = added_elements-1; x >0 ; --x) {
            arr[x]=arr[x-1];
        }
        arr[0]=num;
    return true;

    }

    bool pop(){
        if(is_empty())
        return false;
        added_elements--;
        for (int x = 0; x < added_elements; ++x) {
            arr[x]=arr[x+1];
        }
         return true;
    }

    int get_top(){
        if(is_empty())
            return -1;
        else {
            return arr[0];
        }
    }

    void print(){
        for (int x = 0; x<added_elements ; x++)
            cout<<arr[x]<<" ";
        cout<<endl;
    }


};


class stack_of_2stacks{
private:
    int size;
    int index1,index2,added_elements;
    int*arr{};
public:
    stack_of_2stacks(int size):size(size){
        index1=-1;
        index2=size;
        added_elements=0;
        arr=new int [size];
    }

    bool is_full(){
        return added_elements==size;
    }

    bool is_empty(){
        return added_elements==0;
    }

    void push(int id,int num){
        if(is_full())
            cout<<"The stack is already full"<<endl;
        else{
            if(id==1)
                arr[++index1]=num;
            else
                arr[--index2]=num;
            added_elements++;
        }
    }

    void pop(int id){
        if(id==1){
            if(index1==-1)
                cout<<"first stack is already empty";
            else
                index1--;
        }
        else{
            if(index2==size)
                cout<<"second stack is already empty";
            else
                index1++;
        }
        added_elements--;
    }

    int get_top(int id){
        if(is_empty())
            cout<<"The stack is already empty"<<endl;
        else {
            if(id==1)
                return arr[index1];
            else
                return arr[index2];
        }
    }

    void print(){
        for (int x = 0; x <=index1 ; ++x) {
            cout<<arr[x]<<" ";
        }
        cout<<endl;
        for (int x = index2; x <=size-1 ; ++x) {
            cout<<arr[x]<<" ";
        }
    }
};

int main() {
 

}

