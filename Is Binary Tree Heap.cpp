/*
class Node {
   public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    bool CBT(Node *root, int idx, int total_node){
        if(!root) return true;
        
        if(idx >= total_node) return false;
        
        return CBT(root->left, 2*idx +1, total_node) && 
        CBT(root->right, 2*idx +2, total_node);
    }
    bool maxHeap(Node* root){
        if(!root) return true;
        if(root->left && root->data < root->left->data)
        return false;
        
        if(!maxHeap(root->left)) return false; 
        // right mein bhi check karna hoga toh isliye if condition ka use karke 
        // function call kar rhe hai agar return ka use karege or left side maxheap
        // property fiollow kar rha hai but right side fail tb bhi yeh true return 
        // karega isliye return nhi kar rhe direct
        
        if(root->right && root->data < root->right->data)
        return false;
        
        return maxHeap(root->right);
    }
    int count(Node *root){
        if(!root) return 0;
        return 1 + count(root->left) + count(root->right);
    }
    bool isHeap(Node* tree) {
        // code here
        int cnt = count(tree);
        if(!CBT(tree, 0, cnt)) return false;
        
        if(!maxHeap(tree)) return false;
        
        return true;
    }
};



Question Link : https://www.geeksforgeeks.org/problems/is-binary-tree-heap/