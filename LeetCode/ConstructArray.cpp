class Solution {
    public:
        bool backtrack(vector<int>& ans,vector<bool>& vis,int n,int ind){
            if(ind==((2*n)-1)){
                return true;
            }
            if(ans[ind]!=0) return backtrack(ans,vis,n,ind+1);
            for(int i=n;i>=1;i--){
                if(!vis[i]){
                    vis[i]=true;
                    if(i==1){
                        ans[ind]=1;
                        if(backtrack(ans,vis,n,ind+1)) return true;
                        ans[ind]=0;
                    }
                    if(ind+i<ans.size() && ans[ind+i]==0){
                        ans[ind]=i;
                        ans[ind+i]=i;
                        if(backtrack(ans,vis,n,ind+1)) return true;
                        ans[ind]=0;
                        ans[ind+i]=0;
                    }
                    vis[i]=false;
                }
            }
            return false;
            
        }
        vector<int> constructDistancedSequence(int n) {
            vector<int> ans(((2*n)-1),0);
            vector<bool> vis(n+1,false);
            vector<int> occur(n+1,-1);
            backtrack(ans,vis,n,0);
            return ans;
        }
    };