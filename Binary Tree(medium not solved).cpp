#include <bits/stdc++.h>
using namespace std;


class Binary_tree{
private:
    int data=0;
    Binary_tree*left= nullptr;
    Binary_tree*right= nullptr;
    void print2() {
        // in order LVR
        // post order LRV
        // pre order VLR
        if(left)
            left->print();
        cout<<data;
        if(right)
            right->print();
    }
public:
    // n=2^(h+1)-1
    // h=log(n+1)-1

    Binary_tree(int n):data(n){

    }

    void print (){
        this->print2();
        cout<<endl;
    }

    void add(vector<int>value, vector<char>direction){
        Binary_tree *cur= this;
        for(int index=0;index<direction.size();index++) {
            if (direction[index] == 'l') {
                if (cur->left){
                    if(cur->left->data!=value[index])
                        cout<<"Error"<<endl;
                }
                else
                    cur->left=new Binary_tree(value[index]);
                cur=cur->left;
            } else {
                if (cur->right){
                    if(cur->right->data!=value[index])
                        cout<<"Error"<<endl;
                }
                else
                    cur->right=new Binary_tree(value[index]);
                cur=cur->right;
            }
        }
    }

    int tree_max( ){
        int m=data;
        if(left)
            m=max(m,left->tree_max());
        if(right)
            m=max(m,right->tree_max());
        return m;
    }

    int tree_height(){
        int h=0;
        if(left)
            h+=1+left->tree_height();
        if(right)
            h=max(h,1+right->tree_height());
        return h;
    }

    int count_all(){
        int c=1;
        if(left)
            c+=left->count_all();
        if(right)
            c+=right->count_all();
        return c;
    }

    int count_leafs(){
        int c=!left&&!right;
        if(left)
            c+=left->count_leafs();
        if(right)
            c+=right->count_leafs();
        return c;
    }

    bool is_exists(int value){
        bool c= data==value;
        if(!c&&left)
            c=left->is_exists(value);
        if(!c&&right)
            c=right->is_exists(value);
        return c;
    }

    bool is_perfect(int h=-1){
        if(h==-1)
            h=tree_height();
        if(!left&&!right)
            return h==0;
        if(left&&!right||!left&&right)
            return false;

        return left->is_perfect(h-1)&& right->is_perfect(h-1);
    }

    bool is_perfect_formula(){
        return count_all()== pow(2,tree_height()+1)-1;
    }

    void level_order_traversal(){
        queue<Binary_tree*>q;
        q.push(this);
        int level=0;
        while(!q.empty()){
            cout<<"Level "<<level<<": ";
            int size=q.size();
            while(size--){
                Binary_tree*cur=q.front();
                if(cur->left)
                    q.push(cur->left);
                if(cur->right)
                    q.push(cur->right);
                cout<<cur->data<<" ";
                q.pop();
            }
            cout<<endl;
            level++;
        }
    }

// then ->serialization 

};





int main() {
  
}

