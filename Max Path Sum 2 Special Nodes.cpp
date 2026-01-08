/*
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

class Solution {
  public:
    int func(Node*root, int&sum){
        if(!root)
        return 0;
        if(!root->left && !root->right)
        return root->data;
        int left = func(root->left, sum);
        int right = func(root->right, sum);
        if(!root->left){
            return root->data + right;
        }if(!root->right){
            return root->data + left;
        }if(root->left && root->right){
            sum = max(sum, root->data + left + right);
            return root->data + max(left, right);
        }
    }
    int maxPathSum(Node* root) {
        // code here
        int sum=INT_MIN;
        int val = func(root,sum);
        if(root->left && root->right)
        return sum;
        return max(sum,val);
        
    }
};





Question Link : https://www.geeksforgeeks.org/problems/maximum-path-sum/1