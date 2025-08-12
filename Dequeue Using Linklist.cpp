#include<iostream>
using namespace std;
struct Node{
    int data;
    Node *prev;
    Node *next;
    Node(int val) : data(val), prev(NULL), next(NULL) {}
};
class Solution{
    Node *front, *rear;
    public:
    Solution() {
        front = rear = NULL;
    }
    void Push_back(int val){
        if(!front){
            front = new Node(val);
            rear = front;
        }else{
            rear->next = new Node(val);
            rear->next->prev = rear;
            rear = rear->next;
        }
    }
    void push_front(int val){
        if(!front){
            front = new Node(val);
            rear = front;
        }else{
            front->prev = new Node(val);
            front->prev->next = front;
            front = front->prev;
        }
    }
    void pop_back(){
        if(!rear){
            return;
        }
        if(rear == front){
            Node *temp = rear;
            rear = front = NULL;
            delete temp;
        }else{
            Node *temp = rear;
            rear = rear->prev;
            rear->next = NULL;
            delete temp;
        }
        return;
    }
    void pop_front(){
        if(!front)return;
        if(rear == front){
            Node *temp = rear;
            rear = front = NULL;
            delete temp;
        }else{
            front = front->next;
            front->prev = NULL;
        }
        return;
    }
    int getFront() {
        if (!front) {
            cout << "Deque empty\n";
            return -1;
        }
        return front->data;
    }
    int getRear() {
        if (!rear) {
            cout << "Deque empty\n";
            return -1;
        }
        return rear->data;
}    
    void printDeque() {
        Node* temp = front;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }

};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution dq;

    cout << "Push_back 10\n";
    dq.Push_back(10);
    dq.printDeque();

    cout << "Push_front 5\n";
    dq.push_front(5);
    dq.printDeque();

    cout << "Push_back 20\n";
    dq.Push_back(20);
    dq.printDeque();

    cout << "Push_front 2\n";
    dq.push_front(2);
    dq.printDeque();

    cout << "Pop_back\n";
    dq.pop_back();
    dq.printDeque();

    cout << "Push_back 15\n";
    dq.Push_back(15);
    dq.printDeque();

    cout << "Pop_front\n";
    dq.pop_front();
    dq.printDeque();

    cout << "Pop_back\n";
    dq.pop_back();
    dq.printDeque();

    cout << "Front element: " << dq.getFront() << "\n";
    cout << "Rear element: " << dq.getRear() << "\n";
    return 0;
}
