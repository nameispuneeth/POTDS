/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class FindElements {
public:
    unordered_set<int> st;
    FindElements(TreeNode* root) {
        st.clear();
        if(root==NULL) return;
        st.insert(0);
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            auto temp=q.front();q.pop();
            int x=temp.second*2;
            if(temp.first->left){
                st.insert(x+1);
                q.push({temp.first->left,x+1});
            }
            if(temp.first->right){
                st.insert(x+2);
                q.push({temp.first->right,x+2});
            }
        }
    }
    
    bool find(int target) {
        if(st.find(target)==st.end()) return false;
        return true;
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */