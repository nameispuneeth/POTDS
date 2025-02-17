class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
       priority_queue<int,vector<int>,greater<int>> pq;
       for(auto it:arr){
           if(pq.size()<k) pq.push(it);
           else{
               if(pq.top()<it){
                   pq.pop();
                   pq.push(it);
               }
           }
       }
       int j=pq.size()-1;
       vector<int> ans(pq.size(),0);
       while(!pq.empty()){
           ans[j]=pq.top();
           pq.pop();
           j--;
       }
       return ans;
    }
};