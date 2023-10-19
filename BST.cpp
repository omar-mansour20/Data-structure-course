#include <bits/stdc++.h>
using namespace std;


class bst{
        // in order LVR
        // post order LRV
        // pre order VLR

        // n=2^(h+1)-1
        // h=log(n+1)-1

private:
    int data=0;
    bst*left= nullptr;
    bst*right= nullptr;
public:
    void print() {
        if(left)
            left->print();
        cout<<data<<" ";
        if(right)
            right->print();
    }

    bst(int n,bst*l= nullptr,bst*r= nullptr):data(n),left(l),right(r){

    }


    bool search(int value){
        if(data==value)
            return true;

        if(value<data)
            return left&&left->search(value);

        return right&&right->search(value);
    }

    bool search_iterative(int value){
        bst*cur=this;
        while(cur){
            if(cur->data==value)
                return true;

            if(left&&value<cur->data)
                cur=cur->left;
            else
                cur=cur->right;
        }
        return false;
    }

    void insert(int target){
        if(target<data){
            if(left)
                left->insert(target);
            else
                left=new bst(target);
        }
        else if(target>data){
            if(right)
                right->insert(target);
            else
                right=new bst(target);
        }
    }

    int tree_min(){
        if(!left)
            return data;
        else
            left->tree_min();
    }

    int tree_max(){
        if(!right)
            return data;
        else
            right->tree_min();
    }

    bool find_chain(vector<bst*>&ancestors,int target){
        ancestors.push_back(this);

        if(data==target)
            return true;
        if(target<data)
            return left&&left->find_chain(ancestors,target);
        return right&&right->find_chain(ancestors,target);
    }

    bst* get_next(vector<bst*>&ancestors){
        if(ancestors.size()==0)
            return nullptr;
        bst*node=ancestors.back();
        ancestors.pop_back();
        return node;
    }

    pair<bool,int> tree_successor(int target){
        vector<bst*>ancestors;

        if(!find_chain(ancestors,target))
            return make_pair(false,-1);

        bst*child= get_next(ancestors);
        bst*parent= get_next(ancestors);
        if(child->right)
            return make_pair(true,child->right->tree_min());

        while(parent&&parent->right==child){
            child=parent,parent= get_next(ancestors);
        }

        if(parent)
            return make_pair(true,parent->data);
        return make_pair(false,-1);
    }

    bst*min_node(){
        bst*cur=this;
        while(cur&&cur->left)
            cur=cur->left;
        return cur;
    }

    bst*max_node(){
        bst*cur=this;
        while(cur&&cur->right)
            cur=cur->right;
        return cur;
    }

    void delete_value(int target){
        if(target==data&&!left&&!right)
            return;
        delete_node(target,this);
    }

    bst* delete_node(int value,bst*node){
        if(!node)
            return nullptr;

        if(value<node->data)
            node->left= delete_node(value,node->left);
        else if(value>node->data)
            node->right= delete_node(value,node->right);
        else{
            bst*temp= node;

            if(!node->left&&!node->right) //case1: no left or right --> delete and link with null
                return nullptr;
            else if(!node->left)          //case2: right only --> delete and link with the right
                node=node->right;
            else if(!node->right)         //case2: left only --> delete and link with the left
                node=node->left;
            else{                         //case3: left and right --> find successor, copy and delete
                bst* successor=node->right->min_node();
                node->data=successor->data;
                //node->right= delete_node(node->data,node->right); //delete successor recursevly
                //or
                if(node->right==successor)
                    node->right= nullptr;
                else {
                    bst *before_successor = node->right;
                    while (before_successor->left->left)
                        before_successor = before_successor->left;
                    before_successor->left = successor->right;
                }
                delete successor;
                temp= nullptr;
            }
            if(temp)
                delete temp;
        }
        return node;
    }

    bst* delete_node_p(int value,bst*node){
        if(!node)
            return nullptr;

        if(value<node->data)
            node->left= delete_node(value,node->left);
        else if(value>node->data)
            node->right= delete_node(value,node->right);
        else{
            bst*temp= node;

            if(!node->left&&!node->right) //case1: no left or right --> delete and link with null
                return nullptr;
            else if(!node->left)          //case2: right only --> delete and link with the right
                node=node->right;
            else if(!node->right)         //case2: left only --> delete and link with the left
                node=node->left;
            else{                         //case3: left and right --> find successor, copy and delete
                bst* mx=node->left->max_node();
                node->data=mx->data;
                node->left= delete_node(node->data,node->left);
                temp= nullptr;
            }
            if(temp)
                delete temp;
        }
        return node;
    }
    

    vector<int> get_inorder(){

    }



    bool is_bst(int mn= INT_MIN, int mx=INT_MAX){
        bool check = data>mn && data<mx;
        if(!check)
            return false;

        bool left_is_bst= !left || left->is_bst(mn,data) ;
        bool right_is_bst=!right|| right->is_bst(data,mx);
        return left_is_bst&&right_is_bst;
        // another way-> get the inorder traversal and check if it is sorted
    }

    bst* build_bst(vector<int>&values,int start=0,int end=-10){
        if(end==-10)
            end=(int)values.size()-1;

        if(start>end)
            return nullptr;

        int mid=(start+end)/2;
        bst* left_bst= build_bst(values,start,mid-1);
        bst* right_bst= build_bst(values,mid+1,end);
        bst* root = new bst(values[mid],left_bst,right_bst);
        return root;
    }

    int kth_smallest(int &k){
        if(k==0)
            return -1234;

        if(left) {
            int res = left->kth_smallest(k);
            if(k==0)
                return res;
        }

        --k; // it decreases every time when call returns to the current node or the right if found
        if(k==0)
            return data; // will return the value to be stored at variable res ln138
        if(right)
            return right->kth_smallest(k);

        return -1234;
    }

    int lca(int x,int y){

        if(x<data&&y<data)
            left->lca(x,y);
        if(x>data&&y>data)
            right->lca(x,y);

        return data;
        // important tip: to find the path between 2 nodes a,b
        // first find the lca and the path will be (lca+a)+(lca+b)
    }


//    int tree_height(){
//        int h=0;
//        if(left)
//            h+=1+left->tree_height();
//        if(right)
//            h=max(h,1+right->tree_height());
//        return h;
//    }
//
//    int count_all(){
//        int c=1;
//        if(left)
//            c+=left->count_all();
//        if(right)
//            c+=right->count_all();
//        return c;
//    }
//
//    int count_leafs(){
//        int c=!left&&!right;
//        if(left)
//            c+=left->count_leafs();
//        if(right)
//            c+=right->count_leafs();
//        return c;
//    }
//
//
//
//    bool is_perfect(int h=-1){
//        if(h==-1)
//            h=tree_height();
//        if(!left&&!right)
//            return h==0;
//        if(left&&!right||!left&&right)
//            return false;
//
//        return left->is_perfect(h-1)&& right->is_perfect(h-1);
//    }
//
//    bool is_perfect_formula(){
//        return count_all()== pow(2,tree_height()+1)-1;
//    }
//
//    void level_order_traversal(){
//        queue<Binary_tree*>q;
//        q.push(this);
//        int level=0;
//        while(!q.empty()){
//            cout<<"Level "<<level<<": ";
//            int size=q.size();
//            while(size--){
//                Binary_tree*cur=q.front();
//                if(cur->left)
//                    q.push(cur->left);
//                if(cur->right)
//                    q.push(cur->right);
//                cout<<cur->data<<" ";
//                q.pop();
//            }
//            cout<<endl;
//            level++;
//        }
//    }

};





int main() {
    bst t(1);
    vector<int>v={1,2,3,4,5,6,7,8,9,10};
    bst*t2=t.build_bst(v);
    t2->print();
    cout<<endl<<t2->tree_min();

}


