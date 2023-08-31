#include <bits/stdc++.h>
using namespace std;



class Stack{
private:
    int size;
    int top;
    int *arr{};
public:
    Stack(int size):size(size),top(-1){
        arr=new int[size];
    }

    bool is_full(){
        return top==size-1;
    }

    bool is_empty(){
        return top==-1;
    }

    void push(int num){
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

    int get_top(){
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


int main() {

}


