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

//1st Method

class Solution {
  public:
    void func(Node* node, int cnt, int& ans){
        if(!node)return;
        if(!node->left && !node->right){
            ans = max(ans,cnt);
            return;
        }
        func(node->left,cnt + 1,ans);
        func(node->right,cnt + 1,ans);
    }
    int height(Node* node) {
        int ans=0, cnt=0;
        func(node,cnt,ans);
        return ans;
    }
};

//2nd Method


class Solution {
  public:
    int height(Node* node) {
        if(!node) return 0;
        if(!node->left && !node->right) return 0;
        
        return 1 + max(height(node->left), height(node->right));
    }
};


Question Link: https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1