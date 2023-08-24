#include <bits/stdc++.h>
using namespace std;

struct node{
    int data;
    node * next= nullptr;
    node * previous= nullptr;
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

//    ~linked_list(){
//        while(head){
//            node *current= head->next;
//            delete head;
//            head= current;
//        }
//    }

    void insert_front(int n){
        node*new_node=new node(n);
        if(!head)
            head=tail=new_node;
        else{
            new_node->next=head;
            head->previous=new_node;
            head=new_node;
        }
        length++;
    }

    void insert_end(int n){
        node*new_node=new node(n);
        if(!head)
            head=tail=new_node;
        else{
            tail->next=new_node;
            new_node->previous=tail;
            tail=new_node;
        }
        length++;
    }

    void insert_nth(node*Node,int n){
        node*new_node=new node(n);
        new_node->next=Node->next;
        new_node->previous=Node;
        new_node->next->previous=new_node;
        new_node->previous->next=new_node;
        length++;

    }

    void insert_sorted(int n){
        if(!head||n<=head->data)
            insert_front(n);
        else if(n>=tail->data)
            insert_end(n);
        else{
            for(node*temp=head;temp;temp=temp->next){
                if(temp->data>=n){
                    insert_nth(temp->previous,n);
                    break;
                }
            }

        }
    }

    void delete_front(){
        if(!head)
            cout<<"The list is already empty"<<endl;
        else if(length==1){
            delete head;
            head=tail= nullptr;
        }
        else {
            node*temp=head;
            head=head->next;
            delete temp;
            head->previous= nullptr;
        }
        length--;
    }

    void delete_end(){
        if(!head)
            cout<<"The list is already empty"<<endl;
        else if(length==1){
            delete head;
            head=tail= nullptr;
        }
        else {
            node*temp=tail;
            tail=tail->previous;
            delete temp;
            tail->next= nullptr;
        }
        length--;

    }
    void delete_nth(int index){
        if(index<1||length<1||index>length)
            return;
        else{
            int x=1;
            for(node*cur=head;cur;cur=cur->next){
                if(x==index){
                    delete_and_link(cur);
                    break;
                }
                x++;
            }
        }
    }

    void delete_and_link(node*Node){
        // لما تحل الهارد ابق عدلها و خليها ترجع النود الي عليها الدور زي م الدكتور عامل
        if(Node==head)
            delete_front();
        else if(Node==tail)
            delete_end();
        else{
            Node->next->previous = Node->previous;
            Node->previous->next=Node->next;
            delete Node;
        }
    }

    void delete_with_key(int n){
        if(!head)
            cout<<"The list is already empty"<<endl;
        else if(head->data==n)
            delete_front();
        else if(tail->data==n)
            delete_end();
        else {
            for (node *temp = head; temp; temp = temp->next) {
                if (temp->data == n) {
                    delete_and_link(temp);
                    break;
                }
            }
        }
    }

    void delete_all_nodes_with_key(int n){
        if(!head)
            cout<<"The list is already empty"<<endl;
        else{
            for(node*cur=head;cur;){
                if(cur->data==n){
                    node*next=cur->next;
                    if(cur==head){
                        delete_front();
                        cur=next;
                    }
                    else if(cur==tail){
                        delete_end();
                        break;
                    }
                    else{
                        delete_and_link(cur);
                        cur=next;
                    }
                }
                else
                    cur=cur->next;
            }
        }
    }

    void delete_even_positions(){
        if(length<=1)
            return;
        else{
            int x=1;
            for(node*cur=head;cur;){
                if(x%2==0){
                    node*next=cur->next;
                    delete_and_link(cur);
                    cur=next;
                }
                else
                    cur=cur->next;
                x++;
            }
        }
    }

    void delete_odd_positions(){
        insert_front(-1);
        delete_even_positions();
        delete_front();
    }

    bool is_palindrome(){
        if(length<=1)
            return true;
        pair<int,node*>first={1,head};
        pair<int,node*>second={length,tail};
        while(first.first<=second.first){
            if(first.second->data!=second.second->data)
                return false;
            first.second=first.second->next;
            second.second=second.second->previous;
            first.first++;
            second.first--;
        }
        return true;
    }


    void print(){
        for(node*temp=head;temp;temp=temp->next){
            cout<<temp->data<<" ";
        }
        cout<<endl;
    }

};

void solve(){


}
int main() {
     // delete and link function
     // لما تحل الهارد ابق عدلها و خليها ترجع النود الي عليها الدور زي م الدكتور عامل
  
}

