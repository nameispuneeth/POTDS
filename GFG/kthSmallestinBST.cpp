class Solution {
    public:
      void DFS(Node* root,vector<int>& vec){
        if(!root) return;
        DFS(root->left,vec);
        vec.push_back(root->data);
        DFS(root->right,vec);
    }
      int kthSmallest(Node *root, int k) {
          vector<int> vec;
          DFS(root,vec);
          if(k>vec.size()) return -1;
          return vec[k-1];
      }
  };