class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n=nums.size();
        if(n<4) return 0;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int temp=nums[i]*nums[j];
                mp[temp]++;
            }
        }
        int ans=0;
        for(auto it:mp){
            int x=it.second;
            ans+=(x*(x-1)*4);
        }
        return ans;
    }
};