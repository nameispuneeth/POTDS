
class Solution {
  public:
    void findLeaves(Node* root,vector<int>& ans){
        if(!root->right && !root->left){
            ans.push_back(root->data);
            return;
        }
        if(root->left) findLeaves(root->left,ans);
        if(root->right) findLeaves(root->right,ans);
    }
    vector<int> boundaryTraversal(Node *root) {
        if(root->left==NULL && root->right==NULL) return {root->data};
        vector<int> left,right,leaves;
        left.push_back(root->data);
        Node* temp=root->left;
        while(temp!=NULL){
            left.push_back(temp->data);
            if(temp->left) temp=temp->left;
            else temp=temp->right;
        }
        temp=root->right;
        while(temp!=NULL){
            right.push_back(temp->data);
            if(temp->right) temp=temp->right;
            else temp=temp->left;
        }
        temp=root;
        findLeaves(temp,leaves);
        if(temp->left) left.insert(left.end(),leaves.begin()+1,leaves.end());
        else left.insert(left.end(),leaves.begin(),leaves.end());
        for(int i=right.size()-2;i>=0;i--) left.push_back(right[i]);

        return left;
    }
};