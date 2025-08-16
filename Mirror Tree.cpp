/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/


//1st Method

class Solution {
  public:
    void mirror(Node* node) {
        // code here
        queue<Node*>q;
        Node*temp;
        q.push(node);
        
        while(!q.empty()){
            temp = q.front();
            q.pop();
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
            swap(temp->left, temp->right);
        }
    }
};


//2nd Method

class Solution {
  public:
    void mirror(Node* node) {
        if(!node)return;
        swap(node->left,node->right);
        mirror(node->left);
        mirror(node->right);
    }
};


Question Link: https://practice.geeksforgeeks.org/problems/mirror-tree/1