/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void small(TreeNode*root, int& k, int& lar){
    if(!root) return;
    small(root->left, k, lar);
    k--;
    if(k==0){
        lar = root->val;
        return;
    }
    small(root->right, k, lar);
}
int Solution::kthsmallest(TreeNode* A, int B) {
    int smal = 0;
    small(A, B, smal);
    return smal;
}




Question Link : https://www.interviewbit.com/problems/kth-smallest-element-in-tree/