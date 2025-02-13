class Solution {
    public:
        int minOperations(vector<int>& nums, int k) {
            priority_queue<int,vector<int>,greater<int>> pq;
            for(int i=0;i<nums.size();i++) pq.push(nums[i]);
            int ans=0;
            while(pq.size()>=2 && pq.top()<k){
                int mini=pq.top();pq.pop();
                int maxi=pq.top();pq.pop();
                long long temp=(mini*2);
                if(temp>=INT_MAX) pq.push(INT_MAX);
                else{
                    temp+=maxi;
                    if(temp>=INT_MAX) pq.push(INT_MAX);
                    else pq.push(temp);
                }
                ans++;
            }
            return ans;
        }
    };