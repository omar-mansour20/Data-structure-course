#include <bits/stdc++.h>
using namespace std;


class Vector{
    int *arr= nullptr;
    int size=0;
    int capacity =0;
public:

    Vector(int s):size(s){
        if(size<0)
            size=0;
        capacity=size*2;
        arr=new int [capacity]{};
    }

    ~Vector(){
        delete []arr;
        arr= nullptr;
    }

    void set(int index,int n){
        if(index<0)
            cout<<"invalid index entered"<<endl;
        else
            arr[index]=n;
    }

    int get(int index){
        if(index<0)
            return -1;

        else
            return arr[index];
    }

    void print(){
        for(int x=0;x<size;x++)
            cout<<arr[x]<<" ";
        cout<<endl;
    }

    int find(int n){
        for(int x=0;x<size;x++){
            if(arr[x]==n)
                return x;
        }
        return -1;
    }

    int get_front(){
        return arr[0];
    }

    int get_back(){
        return arr[size-1];
    }

    void expand_capacity(){
        capacity*=2;
        int *arr2=new int[capacity];
        for(int x=0;x<size;x++){
            arr2[x]=arr[x];
        }
        swap(arr2,arr);
        delete arr2;
        arr2= nullptr;
    }

    void push_back(int n){
        if(size==capacity)
            expand_capacity();
        arr[size++]=n;

    }

    void insert(int index, int n){
        if(size==capacity)
            expand_capacity();
        size++;
        for(int x=size-1;x>index-1;x--){
            arr[x]=arr[x-1];
        }
        arr[index-1]=n;
    }

    int get_capacity(){
        return capacity;
    }

    int get_size(){
        return size;
    }

    void right_rotate(int times){
        times=times%size;
        while(times--) {
            int num = arr[size - 1];
            for (int x = size - 1; x >= 1; x--) {
                arr[x] = arr[x - 1];
            }
            arr[0] = num;
        }
    }

    void left_rotate(){
        int num=arr[0];
        for(int x=0;x<size-1;x++){
            arr[x]=arr[x+1];
        }
        arr[size-1]=num;
    }

    void pop(int index){
        for(int x=index-1;x<size-1;x++){
            arr[x]=arr[x+1];
        }
        size--;
    }

    int find_transposition(int num){
        for(int x=0;x<size;x++){
            if(arr[x]==num){
                if(x!=0)
                    swap(arr[x],arr[x-1]);
                return x;
            }
        }
        return -1;
    }


};





int main() {
   
}





