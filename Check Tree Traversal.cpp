//Back-end complete function Template for C++

class Solution {
  public:
    bool chck(vector<int>&pre, vector<int>&in, vector<int>&post, int preidx, int inidx, int postidx, int n){
        if(n==0)return true;
        if(n==1)
        return (pre[preidx] == in[inidx] && in[inidx] == post[postidx]);
        
        int root = pre[preidx];
        if(root != post[postidx+n-1])return false;
        
        int rootidx = -1;
        for(int i=inidx; i<inidx+n; i++){
            if(in[i] == root){
            rootidx = i;
            break;
            }
        }
        if(rootidx == -1)return false;
        
        int left = rootidx - inidx;
        int right = n-left-1;
        
        return chck(pre, in, post, preidx+1, inidx, postidx, left) &&
        chck(pre, in, post, preidx+left+1, rootidx+1, postidx+left, right);
    }
    bool checktree(int preorder[], int inorder[], int postorder[], int N) {
        // Your code goes here
        vector<int>pre(preorder, preorder+N);
        vector<int>in(inorder, inorder+N);
        vector<int>post(postorder, postorder+N);
        
        return chck(pre,in,post,0,0,0,N);
    }
};


Question Link : https://www.geeksforgeeks.org/problems/check-tree-traversal--141628/1
