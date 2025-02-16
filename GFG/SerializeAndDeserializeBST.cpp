class Solution {
    public:
      // Function to serialize a tree and return a list containing nodes of tree.
      vector<int> serialize(Node *root) {
          vector<int> ans;
          ans.push_back(root->data);
          queue<Node*> q;
          q.push(root);
          while(!q.empty()){
              int n=q.size();
              for(int i=0;i<n;i++){
                  Node* temp=q.front();q.pop();
                  if(temp->left){
                      ans.push_back(temp->left->data);
                      q.push(temp->left);
                  }else{
                      ans.push_back(-1);
                  }
                  if(temp->right){
                      q.push(temp->right);
                      ans.push_back(temp->right->data); 
                  }else{
                     ans.push_back(-1);
                  }
              }
          }
          return ans;
      }
  
      Node *deSerialize(vector<int> &arr) {
          if(arr.empty() || arr[0]==-1) return NULL;
          Node* root=new Node(arr[0]);
          queue<Node*> q;
          q.push(root);
          int i=0,j=1,n=arr.size();
          while(!q.empty() && j<n){
              Node* temp=q.front();q.pop();
              if(arr[j]==-1){
                  temp->left=NULL;
              }else{
                  temp->left=new Node(arr[j]);
                  q.push(temp->left);
              }
              j++;
              if(j<n){
                  if(arr[j]==-1){
                      temp->right=NULL;
                  }else{
                      temp->right=new Node(arr[j]);
                      q.push(temp->right);
                  }
              }
              j++;
          }
          return root;
      }
  };