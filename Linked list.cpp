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

//    ~linked_list(){
//        while(head){
//            node *current= head->next;
//            delete head;
//            head= current;
//        }
//    }

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

    void insert_front(int n){
        node *new_node= new node(n);
        new_node->next= nullptr;
        if(head== nullptr)
            head=tail=new_node;
        else{
            new_node->next=head;
            head=new_node;
        }
        length++;
    }

    void insert_nth(int index, int n){
        if(index==1)
            insert_front(n);
        else if(index==length)
            insert_end(n);
        else {
            node *new_node= new node(n);
            node *previous= head;
            index-=2;
            while (index--){
                previous=previous->next;
            }
            new_node->next=previous->next;
            previous->next=new_node;
            length++;
        }
    }

    void insert_sorted(int n){
        if(length==0||head->data>=n)
            insert_front(n);
        else if(tail->data<=n)
            insert_end(n);
        else {
            node *Node = head;
            for (int x = 1; x <= length; x++) {
                if (Node->data >=n) {
                        insert_nth(x - 1, n);
                    break;
                }
                Node=Node->next;
            }

        }
    }

    void delete_end(){
        if(length==0)
            cout<<"error: The list is alrready empty"<<endl;
        else {
           node *temp = get_nth(length-1);
           delete tail;
           tail= temp;
           tail->next= nullptr;
           length--;
        }
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

    void delete_nth(int n){
        if(length==0)
            cout<<" The list is already empty"<<endl;
        else if (n>length||n<1)
            cout<<" invalid index entered"<<endl;
        else if(n==1) delete_front();
        else if(n==length) delete_end();
        else {
            node*previous= get_nth(n-1);
            node *current = previous->next;
            previous->next=current->next;
            delete current;
            length--;
        }
    }

    void delete_key(int n){
        if(length==0)
            cout<<" The list is already empty"<<endl;
        else {
            node *temp = head;
            for (int x = 1; x <= length; x++) {
                if (temp->data == n) {
                    delete_nth(x);
                    break;
                }
                temp = temp->next;
            }
        }
    }

    void delete_even_positions(){
        if(length<=1)
            return;
        int x=2;
        while(x<=length) {
            delete_nth(x);
            x+=1;
        }
    }

    void delete_next_node(node *Node){
        node *n=head;
        for(int x=1;x<length;x++){
            if(n==Node) {
                delete_nth(x+1);
                break;
            }
            n=n->next;
        }
    }

    void swap_pairs(){
        for(node*Node= head; Node ;Node=Node->next){
            if(Node->next) {
                swap(Node->data, Node->next->data);
                Node=Node->next;
            }
        }
    }

    void reverse(){
        if(length<=1)
            return;
        if(length==2){
            swap(head->data,tail->data);
            return;
        }
        node *previous=head;
        node *current=head->next;
        node *post=head->next->next;
        tail=head;
        int x=length;
        while(x>=2){
            current->next=previous;
            x--;
            previous=current;
            current=post;
            if(post->next)
                post=post->next;
        }
        head=previous;
        tail->next= nullptr;
    }

    void swap_head_tail(){
        tail->next=head->next;
        get_nth(length-1)->next=head;
        head->next= nullptr;
        swap(head,tail);
    }

    void left_rotate(int n){
        n%=length;
        while(n--){
            node *new_tail= get_nth(length-1);
            tail->next=head;
            head=tail;
            tail=new_tail;
            tail->next= nullptr;
        }
    }

    void remove_duplicates(){
        if(length<=1)
            return;
        for(node*x=head; x ;x=x->next){
            for(node*y=x->next,*previous=x; y ;){
                if(y->data==x->data) {
                    delete_next_node(previous);
                    y=previous->next;
                }
                else {
                    previous=y;
                    y=y->next;
                }
            }
        }

    }

    void remove_last_occurance(int n){
        node *Node=head;
        int index=0;int x;
        for( x=1;x<=length;x++){
            if(Node->data==n)
                index=x;
            Node=Node->next;
        }
        if(index>=1)
            delete_nth(index);
    }

    void move_to_back(int n){
        vector<int>v;
        int counter=0;
        node *Node=head;
        for(int x=1;x<=length;x++){
            if(Node->data==n){
                counter++;
                v.push_back(x);
            }
            Node=Node->next;
        }
        while (counter--){
            insert_end(n);
            delete_nth(v.back());
            v.pop_back();
        }
    }

    int Max(node *Node= nullptr,bool first_call= true){
        if(first_call)
            return Max(head,false);

        if(Node== nullptr)
            return INT_MIN;
        else return max(Node->data, Max(Node->next, false));

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


    node* get_nth(int n){
        if(n>length)
            return nullptr;
        n--;
        node *new_node = head;
        while(n--){
            new_node=new_node->next;
        }
        return new_node;
    }

    node* get_nth_back(int n){
        n=length-n+1;
        if(n>length)
            return nullptr;
        get_nth(n);
    }

    bool is_same (linked_list &ls2){
        if(length!=ls2.length)
            return false;
        node *temp1=head;
        node *temp2=ls2.head;
        for(int x=0;x<length;x++){
            if(temp1->data!=temp2->data)
                return false;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return true;
    }

    bool is_same_no_length (linked_list &ls2){
        node *temp1=head;
        node *temp2=ls2.head;
        while(temp1||temp2){
            if(temp1== nullptr||temp2== nullptr)
                return false;
            if(temp1->data!=temp2->data)
                return false;
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return true;
    }

    int search(int n){
        node*new_node = head;
        for(int x=0;x<length;x++){
            if(new_node->data==n)
                return x+1;
            new_node=new_node->next;
        }
        return -1;
    }

    int search_improved(int n){
        if(head->data==n)
            return 1;
        node *previous =head;
        node *current = previous->next;
        for(int x=1;x<length;x++){
            if(current->data==n) {
                swap(current->data,previous->data);
                return x+1;
            }
            current=current->next;
            previous=previous->next;
        }
        return -1;
    }

    void verify(){
        if(length==0) {
            assert(head == nullptr);
            assert(tail== nullptr);
        }
        else if(length==1)
            assert(head==tail);
        else
            assert(head!=tail);
        int c=0;
        for(node *Node=head;Node!=NULL;Node=Node->next){
            c++;
            assert(c<1e5);
        }
        assert(length==c);
    }

};



int main() {
 
}



