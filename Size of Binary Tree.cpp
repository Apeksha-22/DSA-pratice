/*

Definition for Binary Tree Node
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/


//1st method

class Solution {
  public:
    void preorder(Node *node , int& cnt){
        if(!node) return;
        
        cnt++;
        preorder(node->left,cnt);
        preorder(node->right,cnt);
    }
    int getSize(Node* node) {
        int cnt = 0;
        preorder(node,cnt);
        return cnt;
    }
};


//2nd Method

class Solution {
  public:
    int getSize(Node* node) {
        if(!node)return 0;
        return 1 + getSize(node->left) + getSize(node->right);
    }
};



Question Link: https://practice.geeksforgeeks.org/problems/size-of-binary-tree/1