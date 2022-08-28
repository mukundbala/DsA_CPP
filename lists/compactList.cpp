#include <iostream>
using namespace std;

template <typename T>
class CompactList{
private:
    int size;
    int capacity;
    T arr[]; //we create a default array of size 100
public:
    CompactList():size(0),capacity(100){arr[capacity];}
    CompactList(int i):size(0),capacity(i){}
    void add(T value);
    int getSize(){cout<<size<<endl;return size;}
    T get(int index);
    void insert(int index,T value);
    void remove(int index);
    bool search(T value);
    void print(){
        if (size==0){return;}
        for (int i=0;i<size;++i){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};


template<typename T> void CompactList<T>::add(T value){
    if (size==capacity){cout<<"Error!Out of Bounds"<<endl;return;}
    else{
        arr[size]=value;
        size++;
    }
}

template<typename T> T CompactList<T>::get(int index){
    if (index>=100){cout<<"Error! Out of Bounds"<<endl;return;}
    else{
        return arr[index];
    }
}

template<typename T> void CompactList<T>::insert(int index,T value){
    if (size>capacity){cout<<"Error! Out of Bounds"<<endl;return;}
    else if (index>size && index<100){add(value);}
    else{
        for (int i=size-1;i>=index;--i){
            arr[i+1]=arr[i]; //ON 
        }
        arr[index]=value;
        size++; 
    }
}

template<typename T> void CompactList<T>::remove(int index){
    if (size==0) {cout<<"Empty"<<endl;return;}
    for (int i=index+1;i<size;++i){
        arr[i-1]=arr[i]; //(ON)
    }
    size--;
}

template<typename T> bool CompactList<T>::search(T value){
    for (int i=0;i<size;++i){
        if(arr[i]==value){cout<<"Found"<<endl;return true;}
    }
    cout<<"Not Found"<<endl;
    return false;
}

int main(){
    CompactList<int> myarr(110);
    myarr.add(1);
    myarr.add(2);
    myarr.add(3);
    myarr.add(4);
    myarr.add(5);
    myarr.add(6);
    myarr.remove(0);
    myarr.print();

    myarr.add(1000);
    myarr.insert(3,69);

    myarr.print();

    myarr.remove(2);
    myarr.print();
    myarr.getSize();
    for (int i=0;i<100;++i){
        myarr.add(i*(i+1));
    }
    myarr.print();
    myarr.getSize();
    myarr.add(10);
    myarr.search(6006);
}