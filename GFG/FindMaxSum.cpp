class Solution {
  public:
    int DFS(Node* root){
        if(root==NULL) return 0;
        if(root->data<0){
            int left=DFS(root->left);
            int right=DFS(root->right);
            return max(0,(max(left,right)+root->data));
        }
        int left=DFS(root->left);
        int right=DFS(root->right);
        return max(left,right)+root->data;
    }
    int findMaxSum(Node *root) {
        int ans=INT_MIN;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            Node* curr=q.front();q.pop();
            Node* temp=curr;
            int leftSum=DFS(temp->left);
            int rightSum=DFS(temp->right);
            ans=max(ans,leftSum+rightSum+temp->data);
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
        return ans;
    }
};