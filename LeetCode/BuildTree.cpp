class Solution {
  public:
    Node* DFS(vector<int>& inorder,vector<int>& preorder,int istart,int iend,int pstart,int pend,unordered_map<int,int>& mp){
        if(pstart>pend || istart>iend ) return NULL;
        Node* root=new Node(preorder[pstart]);
        int x=mp[preorder[pstart]];
        int llen=x-istart;
        root->left=DFS(inorder,preorder,istart,x-1,pstart+1,pstart+llen,mp);
        root->right=DFS(inorder,preorder,x+1,iend,pstart+llen+1,pend,mp);
        return root;
    }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        unordered_map<int,int> mp;
        int n=inorder.size();
        for(int i=0;i<n;i++) mp[inorder[i]]=i;
        return DFS(inorder,preorder,0,n-1,0,n-1,mp);
    }
};