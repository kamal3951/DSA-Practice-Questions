#include<iostream>
using namespace std;
template <typename T>
class stackUsingDynamicArray{
    T *data;
    int nextIndex;
    int capacity;
    
    public:
    stackUsingDynamicArray(){
        data=new T[4];
        nextIndex=0;
        capacity=4;
    }
    int size(){
        return nextIndex;
    }
    bool isEmpty(){
        /*if(nextIndex==0){
            return true;
        }
        else return false;*/
        return nextIndex==0;
    }
    void DApush(T ele){                    // Dynamic Array push
        if(nextIndex==capacity){
            int* newData = new int[2*capacity];
            for(int i=0;i<capacity;i++){
                newData[i]=data[i];
            }
            delete [] data;
            data=newData;
        }
        data[nextIndex]=ele;
        nextIndex++;
    }
    int pop(){
        if(isEmpty()){
            cout<<"Stack is empty! nothing to pop."<<endl;
            return 0;
        }
        nextIndex--;
        return data[nextIndex];
    }
    int top(){
        if(isEmpty()){
            cout<<"Stack is empty! nothing in top."<<endl;
            return 0;
        }
        return data[nextIndex-1];
    }
};
int main(){
    stackUsingDynamicArray<int> s;
    s.DApush(10);
    s.DApush(20);
    s.DApush(30);
    s.DApush(40);
    s.DApush(50);
    cout<<s.top()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.pop()<<endl;
    cout<<s.size()<<endl;
    cout<<s.isEmpty()<<endl;
    return 0;
}