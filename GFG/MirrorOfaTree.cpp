//Date 05-02-25
/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void DFS(Node* root){
        if(!root) return;
        swap(root->left,root->right);
        DFS(root->left);
        DFS(root->right);
    }
    void mirror(Node* node) {
       DFS(node);
    }
};