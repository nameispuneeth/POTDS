class Solution {
    public:
      bool findTarget(Node *root, int target) {
          queue<Node*> q;
          q.push(root);
          unordered_map<int,bool> mp;
          while(!q.empty()){
              int n=q.size();
              for(int i=0;i<n;i++){
                  auto it=q.front();q.pop();
                  if(mp.find(target-it->data)!=mp.end()) return true;
                  mp[it->data]=true;
                  if(it->left) q.push(it->left);
                  if(it->right) q.push(it->right);
  
              }
          }
          return false;
      }
  };