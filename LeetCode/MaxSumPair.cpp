class Solution {
    public:
        int SumOfDigits(int n){
            int ans=0;
            while(n){
                ans+=(n%10);
                n/=10;
            }
            return ans;
        }
        int maximumSum(vector<int>& nums) {
            vector<int> mp(82,-1);
            int ans=-1;
            for(int i=0;i<nums.size();i++){
                int sum=SumOfDigits(nums[i]);
                if(mp[sum]==-1){
                    mp[sum]=nums[i];
                }else{
                    int temp=mp[sum];
                    ans=max(ans,temp+nums[i]);
                    mp[sum]=max(temp,nums[i]);
                }
            }
            return ans;
        }
    };