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

    int get_front(){
        return arr[front];
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



class Deque{
private:
    int front,rear,size,added_elements;
    int *arr{};
public:
    Deque(int size):size(size),front(-1),rear(0),added_elements(0){
        arr=new int[size];
    }

    void enqueue_rear(int num){
        if(is_full()) {
            cout << "The queue is already full" << endl;
            return;
        }
        arr[rear]=num;
        rear=(rear+1)%size;
        added_elements++;
    }

    void enqueue_front(int num){
        if(is_full()) {
            cout << "The queue is already full" << endl;
            return;
        }
        if(front<=0)
            front=size-1;
        else
            front=front-1;
        arr[front]=num;
        added_elements++;
    }

    void dequeue_rear(){
        if(is_empty()) {
            cout << "The queue is already empty" << endl;
            return;
        }
        if(rear==0)
            rear=size-1;
        else
            rear=rear-1;
        added_elements--;
    }

    void dequeue_front(){
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


class Stack{
private:
    Queue q;
    int added_elements=0;
public:
    Stack(int size):q(size){}
    void push(int num){
        int size=added_elements;
        q.enqueue(num);
        while (size--){
            q.enqueue(q.get_front());
            q.dequeue();
        }
        added_elements++;
    }

    void pop(){
        if(is_empty()){
            cout<<"The stack is already empty"<<endl;
            return;
        }
        q.dequeue();
        added_elements--;
    }

    int get_head(){
        return q.get_front();
    }

    bool is_empty(){
        return added_elements==0;
    }
};

void move(Stack&s1,Stack&s2){
    while (!s1.is_empty()){
        s2.push(s1.get_head());
        s1.pop();
    }
}


class queue_2stacks{
    int size;
    int added_elements=0;
    Stack s1;
    Stack s2;
public:
    queue_2stacks(int size):size(size),s1(size),s2(size){}

    void enqueue(int num){
        if(is_full()) {
            cout << "The queue is already full" << endl;
            return;
        }
        move(s1,s2);
        s1.push(num);
        move(s2,s1);
        added_elements++;
    }

    void dequeue(){
        if(is_empty()) {
            cout << "The queue is already empty" << endl;
            return;
        }
        s1.pop();
        added_elements--;
    }

    bool is_empty(){
        return added_elements==0;
    }

    bool is_full(){
        return added_elements==size;
    }

    int get_front(){
        return s1.get_head();
    }
    void print(){
        if(is_empty()) {
            cout << "The queue is already empty" << endl;
            return;
        }
        while(!s1.is_empty()) {
            cout << s1.get_head() << " ";
            s1.pop();
        }
    }


};





int main() {
  
}

