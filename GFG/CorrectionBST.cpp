class Solution {
    public:
      void solve(Node* root, Node* &last, pair<Node*, Node*>&prev){
          if(!root)   return;
          
          solve(root->left, last, prev);
          if(root->data < last->data){
              if(prev.first == NULL){
                  prev.first = last;
                  prev.second = root;
              }
              else {
                  prev.second = root;
              }
          }
          last = root;
          solve(root->right, last, prev);
      }
      
      void correctBST(Node* root) {
          Node* last = new Node(0);
          pair<Node*, Node*>prev;
          prev.first = NULL;
          prev.second = NULL;
          solve(root, last, prev);
  
          swap(prev.first->data, prev.second->data);
      }
  };
  