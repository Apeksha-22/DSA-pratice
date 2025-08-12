#include<iostream>
#include<vector>
using namespace std;
class Dequeue{
    int cap;
    vector<int> arr;
    int front,rear;
    public:
    Dequeue(int capacity){
        cap = capacity;
        arr.resize(cap);
        front=-1;
        rear=-1;

    }
    void push_front(int data){
        if((rear + 1)%cap == front){
            cout << "Deque is full" << endl;
            return;
        }
        if(front==-1){
            front++;
            rear= front;
            arr[rear] = data;
        }else{
            front = (front - 1 + cap) % cap;
            arr[front] = data;
        }
    }
    void push_back(int data){
        if((rear + 1)% cap == front){
            cout << "Deque is full" << endl;
            return;
        }if(rear == -1){
            rear++;
            arr[rear] = data;
        }
    }
    void pop_front(){
        if(front == -1){
            cout << "Deque is empty" << endl;
            return;
        }if(front == rear){
            front = rear = -1;
        }else{
            front = (front + 1)% cap;
        }
    }
    void pop_back(){
        if(rear == -1){
            cout << "Deque is empty" << endl;
            return;
        }if(front == rear){
            front = rear = -1;
        }else{
            rear = (rear - 1 + cap) % cap;
        }
    }
    int get_front(){
        if(front == -1){
            cout << "Deque is empty" << endl;
            return -1;
        }
        return arr[front];
    }
    int get_rear(){
        if(rear == -1){
            cout << "Deque is empty" << endl;
            return -1;
        }
        return arr[rear];
    }
};
int main(){
    Dequeue dq(5);
    dq.push_back(10);
    dq.push_back(20);
    dq.push_front(30);
    dq.push_front(40);
    cout << "Front element: " << dq.get_front() << endl;
    cout << "Rear element: " << dq.get_rear() << endl;
    dq.pop_front();
    dq.pop_back();
    int f = dq.get_front();
    if (f != -1) cout << "Front element after pop: " << f << endl;
    int r = dq.get_rear();
    if (r != -1) cout << "Rear element after pop: " << r << endl;
    return 0;
}