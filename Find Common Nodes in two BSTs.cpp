class Solution {
  public:
    // Function to find the nodes that are common in both BST.
    vector<int> findCommon(Node *r1, Node *r2) {
        // Your code here
        stack<Node*>st1, st2;
        vector<int>res;
        while(r1){
            st1.push(r1);
            r1 = r1->left;
        }while(r2){
            st2.push(r2);
            r2 = r2->left;
        }
        
        while(!st1.empty() && !st2.empty()){
            // Node* curr1, *curr2;
            if(st1.top()->data < st2.top()->data){
                r1 = st1.top();
                st1.pop();
                r1 = r1->right;
                while(r1){
                    st1.push(r1);
                    r1 = r1->left;
                }
            }else if(st1.top()->data > st2.top()->data){
                r2 = st2.top();
                st2.pop();
                r2 = r2->right;
                while(r2){
                    st2.push(r2);
                    r2 = r2->left;
                }
            }else{
                res.push_back(st1.top()->data);
                r1 = st1.top();
                st1.pop();
                r2 = st2.top();
                st2.pop();
                r1 = r1->right;
                r2 = r2->right;
                while(r1){
                    st1.push(r1);
                    r1 = r1->left;
                }while(r2){
                    st2.push(r2);
                    r2 = r2->left;
                }
            }
        }
        return res;
    }
};


Question Link : https://practice.geeksforgeeks.org/problems/find-common-nodes-in-two-bsts/1