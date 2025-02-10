class Solution {
    public:
      void DFS(Node* root,int k,int& ans,int curr,unordered_map<int,int>& mp){
          if(root==NULL) return;
          curr+=root->data;
          ans+=mp[curr-k];
          mp[curr]++;
          DFS(root->left,k,ans,curr,mp);
          DFS(root->right,k,ans,curr,mp);
          mp[curr]--;
      }
      int sumK(Node *root, int k) {
          unordered_map<int,int> mp;
          mp[0]=1;
          int ans=0,curr=0;
          DFS(root,k,ans,0,mp);
          return ans;
      }
  };