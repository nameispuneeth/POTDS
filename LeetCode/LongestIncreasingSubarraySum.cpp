//Date 04-02-25
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int temp=nums[0];
        int ans=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]<nums[i]){
                temp+=nums[i];
            }
            else{
                temp=nums[i];
            }
            ans=max(ans,temp);
        }
        return ans;
    }
};