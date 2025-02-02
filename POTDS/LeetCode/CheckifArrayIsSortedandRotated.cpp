//Date 02-02-25 Sunday

class Solution {
public:
    bool check(vector<int>& nums) {
        int i=1,n=nums.size();
        while(i<n && nums[i-1]<=nums[i]) i++;
        if(i==n) return true;
        if(i==n-1) return nums[i]<=nums[0];
        for(i;i<n-1;i++){
            if(nums[i]<=nums[0] && nums[i+1]>=nums[i] && nums[i+1]<=nums[0]) continue;
            else return false;
        }
        return true;
    }
};