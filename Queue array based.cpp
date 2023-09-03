#include <bits/stdc++.h>
using namespace std;


class Queue{
private:
    int front,rear,size,added_elements;
    int *arr{};
public:
    Queue(int size):size(size),front(0),rear(0),added_elements(0){
        arr=new int[size];
    }

    void enqueue(int num){
        if(is_full()) {
            cout << "The queue is already full" << endl;
            return;
        }
        arr[rear]=num;
        rear=(rear+1)%size;
        added_elements++;
    }

    void dequeue(){
        if(is_empty()) {
            cout << "The queue is already empty" << endl;
            return;
        }
        front=(front+1)%size;
        added_elements--;
    }

    bool is_empty(){
        return added_elements==0;
    }

    bool is_full(){
        return added_elements==size;
    }

    void print(){
        if(is_empty()) {
            cout << "The queue is already empty" << endl;
            return;
        }
        for(int x=front,step=0;step<added_elements;step++,x=(x+1)%size){
            cout<<arr[x]<<" ";
        }
        cout<<endl;
    }

};

int main() {
}


