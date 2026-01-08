/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/



class Solution {
  public:
    Node* LCA(Node* root, Node* n1, Node* n2) {
        if(!root) return NULL;
        
        if(root->data > n1->data && root->data > n2->data)
        return LCA(root->left, n1, n2);
        
        if(root->data < n1->data && root->data < n2->data)
        return LCA(root->right, n1, n2);
        
        return root;
    }
};




//Another Approach
class Solution {
  public:
    Node* LCA(Node* root, Node* m1, Node* m2) {
        // code here
        Node* curr = root;
        int n1 = m1->data, n2 = m2->data;
        while(curr && curr->left && curr->right){
            if(curr->data > n1 && curr->data > n2)
                curr = curr->left;
            else if(curr->data < n1 && curr->data < n2)
            curr = curr->right;
            else return curr;
        }
    }
};




Question Link : https://www.geeksforgeeks.org/problems/lowest-common-ancestor-in-a-bst/