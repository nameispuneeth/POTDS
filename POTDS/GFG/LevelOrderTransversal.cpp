//Date 02-02-25 Sunday
//Author Puneeth
class Solution {
  public:
    vector<vector<int>> levelOrder(Node *root) {
       vector<vector<int>> levels;
       queue<Node*> q;
       q.push(root);
       while(!q.empty()){
            vector<int> temp;
            int n=q.size();
            for(int i=0;i<n;i++){
                Node* prev=q.front();q.pop();
                temp.push_back(prev->data);
                if(prev->left) q.push(prev->left);
                if(prev->right) q.push(prev->right);
            }
            levels.push_back(temp);
       }
       return levels;
    }
};