class Solution {
    public:
        int maxAbsoluteSum(vector<int>& nums) {
            int  curr=0;
            int ans=0;
            int low=0,high=0;
            for(auto it:nums){
                curr+=it;
                if(curr>0){
                    ans=max(ans,curr-low);
                    high=max(high,curr);
                }else{
                    ans=max(ans,abs(curr-high));
                    low=min(low,curr);
                }
            }
            return ans;
        }
    };