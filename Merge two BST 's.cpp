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
    Node* getNext(Node* &curr) {
        while (curr) {
            if (!curr->left) {
                Node* res = curr;
                curr = curr->right;
                return res;
            } else {
                Node* pred = curr->left;
                while (pred->right && pred->right != curr)
                    pred = pred->right;

                if (!pred->right) {
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    pred->right = NULL;
                    Node* res = curr;
                    curr = curr->right;
                    return res;
                }
            }
        }
        return NULL;
    }
public:
    vector<int> merge(Node *root1, Node *root2) {
        vector<int> res;

        Node *curr1 = root1, *curr2 = root2;
        Node *n1 = NULL, *n2 = NULL;

        while (true) {
            if (!n1) n1 = getNext(curr1);
            if (!n2) n2 = getNext(curr2);

            if (!n1 && !n2) break;

            if (!n2 || (n1 && n1->data <= n2->data)) {
                res.push_back(n1->data);
                n1 = NULL;
            } else {
                res.push_back(n2->data);
                n2 = NULL;
            }
        }

        return res;
    }
};




Question Link : https://www.geeksforgeeks.org/merge-two-bsts-with-limited-extra-space/