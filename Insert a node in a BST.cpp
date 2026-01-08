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
    Node* insert(Node* root, int key) {
        //  code  here
        if(!root){
            Node*temp = new Node(key);
            return temp;
        }if(root->data > key){
            root->left = insert(root->left,key);
        }else
        root->right = insert(root->right, key);
        return root;
    }
};



Question Link : https://www.geeksforgeeks.org/problems/insert-a-node-in-a-bst/1