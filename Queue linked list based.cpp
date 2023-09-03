#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node * next;
    node(int d):data(d){}
    //~node();
};

class linked_list{
    node *head;
    node *tail;
    int length=0;
public:

    linked_list(){
        head=tail= nullptr;
    }
    linked_list(const linked_list&) = delete;
    linked_list &operator=(const linked_list &another) = delete;

    void insert_end(int n){
        node *new_node= new node(n);
        new_node->next= nullptr;
        if(head== nullptr){
            head=tail=new_node;
        }
        else{
            tail->next=new_node;
            tail=new_node;
        }
        length++;
    }


    void delete_front(){
        if(length==0)
            cout<<" The list is already empty"<<endl;
        else{
            node *temp = head;
            head= head->next;
            delete temp;
        }
        length--;
    }

    void print(){
        int n=length;
        node* new_node= head;
        while(n--){
            cout<<new_node->data<<" ";
            new_node=new_node->next;
        }
        cout<<"\n";
    }
    node* get_head(){
        return head;
    }

    node *get_tail(){
        return tail;
    }

    bool is_empty(){
        return length==0;
    }

};

class Queue{
    linked_list l;
public:
    void enqueue(int num){
        l.insert_end(num);
    }

    void dequeue(){
        l.delete_front();
    }

    bool is_empty(){
        return l.is_empty();
    }

    int get_front(){
        return l.get_head()->data;
    }

    void print(){
        l.print();
    }
};

int main() {
    
}
