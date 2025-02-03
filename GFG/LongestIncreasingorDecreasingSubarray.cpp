//Date 03-02-25
//Author Puneeth
class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        int curr1=1;
        int curr2=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                curr1++;
                ans=max(ans,curr1);
                curr2=1;
            }else if(nums[i]<nums[i-1]){
                curr1=1;
                curr2++;
                ans=max(ans,curr2);
            }
            else{
                curr1=1;
                curr2=1;
            }
        }
        return ans;
    }
};