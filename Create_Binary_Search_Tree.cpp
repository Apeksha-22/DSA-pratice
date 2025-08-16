#include<iostream>
#include<queue>
using namespace std;
class Node{
    public:
    int data;
    Node *left, *right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

void Print(Node *root){
    if(!root) return;
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout << temp->data << " ";
        if(temp->left) q.push(temp->left);
        if(temp->right) q.push(temp->right);
    }
    cout << endl;
}

int main(){
    queue<Node *>q;
    int x,first,second;
    cout<<"Enter Root value : "<<endl;
    cin>>x;
    Node *root = new Node(x);
    q.push(root);
    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        cout<<"Enter left child value of "<<temp->data<<endl;
        cin>>first;
        if(first != -1){
            temp->left = new Node(first);
            q.push(temp->left);
        }
        
        cout<<"Enter right child value of "<<temp->data<<endl;
        cin>>second;
        if(second != -1){
            temp->right = new Node(second);
            q.push(temp->right);
        }
    }
    Print(root);
    return 0;
}