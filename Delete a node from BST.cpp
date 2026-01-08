/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    Node*findMax(Node*root){
        while(root && root->right){
            root=root->right;
        }
        return root;
    }
    Node* delNode(Node* root, int x) {
        // code here
        if(!root)return NULL;
        if(root->data > x)
        root->left = delNode(root->left, x);
        else if(root->data < x)
        root->right = delNode(root->right, x);
        else{
            if(!root->left && !root->right){
                delete root;
                return NULL;
            }else if(!root->left){
                Node* temp = root->right;
                delete root;
                return temp;
            }else if(!root->right){
                Node* temp = root->left;
                delete root;
                return temp;
            }else{
                Node*child = findMax(root->left);
                root->data = child->data;
                root->left = delNode(root->left,child->data);
            }
        }
        
        return root;
    }
};



Question Link : https://www.geeksforgeeks.org/problems/delete-a-node-from-bst/1