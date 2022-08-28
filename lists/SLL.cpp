#include <iostream>
#include <cstdlib>
using namespace std;


struct Node{
    Node* next;
    int data;
};

class SLL{
private:
    Node* head;
    Node* tail;
    int size; //size of the SLL
public:
    SLL():head(nullptr), tail(nullptr),size(0){}
    Node* get(int idx);
    void insert(int idx,int val);
    void remove(int idx);
    int search(int val);
    void print(){
        Node* temp=head;
        for (int i=0 ; i<size;++i){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    int getSize(){cout<<"Size is "<<size<<endl;return size;}
};

Node* SLL::get(int idx){
    if (head==nullptr || idx>=size){
            cout<<"Cant be gotten due to empty list or large index"<<endl;
            return nullptr;
        }
    else{
        Node* temp=head;
        for (int i=0 ; i<idx;++i){
            temp=temp->next;
        }
        cout<<"The value is : "<<temp->data<<endl;
        return temp;
    }
}

void SLL::insert(int idx, int val){
    Node* newnode=new Node;
    newnode->data=val;
    if (head==nullptr){
        //case where we have an empty list
        newnode->next=head;
        head=newnode;
        tail=head;
        cout<<val<<" added into empty list"<<endl;
    }
    else{
        if (idx==0){//case of inserting at head
            newnode->next=head;
            head=newnode;
            cout<<val<<" added at head"<<endl;
        }
        else if (idx>=size){ //case of inserting at tail
            tail->next=newnode;
            tail=newnode;
            cout<<val<<" added at tail"<<endl;
        }
        else { //case of inserting anywhere else
            Node* prev=get(idx-1); //get the prev node
            Node* aft=prev->next; //get the next node
            newnode->next=aft; //connect
            prev->next=newnode; //connect
            cout<<val<<"added at index "<<idx<<endl;
        }
    }
    size++;
}

void SLL::remove(int idx){
    //first check to see if we are trying to remove from empty list
    int removed_val;
    if (size==0){cout<<"List is empty."<<endl;return;}
    if (idx>=size){cout<<"Out of Bounds!"<<endl;return;} //out of bounds check
    //head removal
    if (idx==0){
        Node* temp=head;
        removed_val=temp->data;
        head=head->next;
        delete temp;
        cout<<removed_val<<" removed at head"<<endl;
    }
    //tail removal
    else if (idx==size-1){
        Node* pre=get(size-2); //second to last node/node before tail
        pre->next=nullptr; //point to nothing
        removed_val=tail->data;
        delete tail; //delete the current tail
        tail=pre;
        cout<<removed_val<<" removed at tail"<<endl;
    }
    //middle removal
    else{
        Node* prev;
        Node* del;
        Node* aft;
        prev=get(idx-1);
        del=get(idx);
        aft=get(idx+1);
        prev->next=aft;
        removed_val=del->data;
        delete del;
        cout<<removed_val<<" removed from index "<<idx<<endl;
    }
    size--;
}

int SLL::search(int val){
    Node* iter=head;
    int cnt=0;
    if (iter->data==val){cout<<"Found!"<<endl;return cnt;}
    while(iter->next !=nullptr){
        iter=iter->next;
        cnt++;
        if (iter->data==val){cout<<"Found!"<<endl;return cnt;}
    }
    cout<<"Not found."<<endl;
    return -1;
}


int main(){
    SLL list;
    // list.insert(0,10); //Insert into empty list test; --> OK
    
    // list.getSize(); //get size test --> OK

    // list.insert(0,50);//Insert at head test

    // list.print(); //Print test -->OK

    // list.insert(2,500); //Insert at tail test with idx==size --> OK
    // list.print();
    // list.getSize();

    // list.insert(10,650); //Insert at tail with idx>size --> OK
    // list.print();
    
    //INSERT, PRINT, GETSIZE fully tested
    list.getSize();
    list.remove(0); //test for empty list removal

    for (int i=0; i<20;++i){
        int randval=rand() % 100;
        list.insert(i,randval);
    }
    list.print();
    list.remove(0); //head removal
    list.print();
    list.remove(list.getSize()-1); //tail removal
    list.print();
    list.remove(4); //middle removal
    list.print();
    
    list.insert(100,101);
    list.print();
    cout<<list.search(67)<<endl; //head search
    cout<<list.search(34)<<endl;// one after head search
    cout<<list.search(42)<<endl;//One before tail search
    cout<<list.search(101)<<endl;//tail search
}   