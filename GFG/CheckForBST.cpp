class Solution {
    public:
      // Function to check whether a Binary Tree is BST or not.
      bool DFS(Node* root,int left,int right){
          if(!root) return true;
          if(root->data<=left || root->data>=right) return false;
          return DFS(root->left,left,min(right,root->data)) && 
              DFS(root->right,max(left,root->data),right);
      }
      bool isBST(Node* root) {
          return DFS(root,INT_MIN,INT_MAX);
      }
  };
  