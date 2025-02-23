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
        TreeNode* dfs(vector<int>& preord,int pstart,int pend,vector<int>& postord,int ostart,int oend,unordered_map<int,int>& mp){
            if(pstart>pend || ostart>oend) return NULL;
            TreeNode* root=new TreeNode(preord[pstart]);
            pstart++;
            if(pstart>pend || ostart>oend) return root;
            int temp=mp[preord[pstart]];
            int len=temp-ostart;
            root->left=dfs(preord,pstart,pstart+len,postord,ostart,temp,mp);
            root->right=dfs(preord,pstart+len+1,pend,postord,temp+1,oend,mp);
            return root;
        }
        TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
            int n=preorder.size();
            unordered_map<int,int> mp;
            for(int i=0;i<n;i++) mp[postorder[i]]=i;
            return dfs(preorder,0,n-1,postorder,0,n-1,mp);
        }
    };