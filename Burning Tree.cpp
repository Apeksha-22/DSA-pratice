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
    int burn(Node*root, int& timer, int target){
          if(!root) return 0;
          if(root->data == target)
          return -1;
          
          int left = burn(root->left, timer, target);
          int right = burn(root->right, timer, target);
          if(left<0){
              timer = max(timer, abs(left)+right);
              return left-1;
          }
          if(right<0){
              timer = max(timer, left+abs(right));
              return right-1;
          }
          return 1+max(abs(left),abs(right));
     }
    
    void find(Node*root, Node*&BurnNode, int& target){
        if(!root) return;
        if(root->data == target){
            BurnNode = root;
            return;
        }
        find(root->left,BurnNode, target);
        find(root->right, BurnNode, target);
    }
    
    int height(Node*root){
        if(!root)return 0;
        return 1 + max(height(root->left),height(root->right));
    }
    int minTime(Node* root, int target) {
        // code here
        int timer=0;
        burn(root,timer,target);
        
        Node* BurnNode = nullptr;
        find(root, BurnNode, target);
        int high = height(BurnNode);
        return max(timer,high-1);
    }
};




Question Link : https://www.geeksforgeeks.org/problems/burning-tree/1