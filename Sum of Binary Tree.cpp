/* A binary tree node has data, pointer to left child
   and a pointer to right child
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
}; */

// Function to return a list containing the level order traversal in spiral form.

//1st Method

class Solution {
  public:
    void find(Node* root, int& sum){
        if(!root) return;
        
        sum += root->data;
        find(root->left, sum);
        find(root->right, sum);
    }
    int sumBT(Node* root) {
      int sum=0;
      find(root,sum);
      return sum;
        
    }
};



//2nd Method

class Solution {
  public:
    int sumBT(Node* root) {
        if(!root)return 0;
        return root->data + sumBT(root->left) + sumBT(root->right);
    }
};


Question Link: https://practice.geeksforgeeks.org/problems/sum-of-binary-tree/1