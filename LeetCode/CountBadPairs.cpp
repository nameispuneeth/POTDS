class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        long long ans=0;
        int n=nums.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++) mp[i-nums[i]]++;
        for(int i=0;i<n;i++){
            ans+=(n-i-mp[i-nums[i]]);
            mp[i-nums[i]]--;
        }
        return ans;
    }
};