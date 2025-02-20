class Solution {
    public:
        int to_nums(string temp){
            int ans=0;
            for(int i=0;i<temp.size();i++){
                if(temp[i]=='1') ans+=(1<<i);
            }
            return ans;
        }
        string findDifferentBinaryString(vector<string>& nums) {
           priority_queue<int,vector<int>,greater<int>> pq;
           for(auto it:nums){
               int n=to_nums(it);
               pq.push(n);
           }
           int i=0;
           while(!pq.empty()){
            if(pq.top()==i) pq.pop();
            else break;
            i++;
           }
           bitset<64> bs(i);
            string result = bs.to_string().substr(64 - nums[0].size());
            reverse(result.begin(), result.end());
        
        return result;
        }
    };