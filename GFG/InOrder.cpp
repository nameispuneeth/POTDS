class Solution {
  public:
    // Function to return a list containing the inorder traversal of the tree.
    void DFS(Node* root,vector<int>& ans){
        if(!root) return;
        DFS(root->left,ans);
        ans.push_back(root->data);
        DFS(root->right,ans);
    }
    vector<int> inOrder(Node* root) {
        vector<int> ans;
        DFS(root,ans);
        return ans;
    }
};