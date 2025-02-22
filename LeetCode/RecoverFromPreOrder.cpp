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
 class Solution {
    public:
        int find_Dashes(string s,int i){
            int ans=0;
            while(i<s.size() && s[i]=='-'){
                ans++;
                i++;
            }
            return ans;
        }
        string findStr(string s,int i){
            string ans="";
            while(i<s.size() && s[i]!='-'){
                ans+=s[i];
                i++;
            }
            return ans;
        }
        void backtrack(TreeNode* temp,int curr_lvl,string& s,int& ind){
            if(ind>=s.size()) return;
            int lvl=find_Dashes(s,ind);
            if(lvl!=curr_lvl) return;
            ind+=lvl;
            string ans=findStr(s,ind);
            temp->left=new TreeNode(stoi(ans));
            ind+=ans.size();
            backtrack(temp->left,curr_lvl+1,s,ind);
    
            if(ind>=s.size()) return;
            lvl=find_Dashes(s,ind);
            if(lvl!=curr_lvl) return;
            ind+=lvl;
            ans=findStr(s,ind);
            temp->right=new TreeNode(stoi(ans));
            ind+=ans.size();
            backtrack(temp->right,curr_lvl+1,s,ind);
            
        }
        TreeNode* recoverFromPreorder(string traversal) {
            if(traversal=="") return NULL;
            string ans=findStr(traversal,0);
            TreeNode* root=new TreeNode(stoi(ans));
            TreeNode* temp=root;
            int ind=ans.size();
            backtrack(temp,1,traversal,ind);
            return root;
        }
    };