class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        vector<int> ans(arr.size(),-1);
        int n=arr.size();
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<=arr[i]) st.pop();
            if(!st.empty()) ans[i]=st.top();
            st.push(i);
        }
        for(int i=0;i<n;i++){
            if(ans[i]==-1) ans[i]=i+1;
            else ans[i]=i-ans[i];
        }
        return ans;
    }
};