//Date 04-02-25
class Solution {
  public:
    int dia=0;
    int helper(Node* root){
        if(!root) return 0;
        int l=helper(root->left);
        int r=helper(root->right);
        dia=max(dia,l+r);
        return max(l,r)+1;
        
    }
    int diameter(Node* root) {
        helper(root);
        return dia;
    }
};