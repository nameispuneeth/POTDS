//Date 03-02-25
//Author Puneeth

class Solution {
  public:
    // Function to find the height of a binary tree.
    int height(Node* node) {
        queue<Node*> q;
        q.push(node);
        int ans=0;
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                Node* sameLvl=q.front();q.pop();
                if(sameLvl->left) q.push(sameLvl->left);
                if(sameLvl->right) q.push(sameLvl->right);
            }
            if(!q.empty()) ans++;
        }
        return ans;
    }
};