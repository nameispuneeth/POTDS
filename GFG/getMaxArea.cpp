class Solution {
  public:
    vector<int> nse_el(vector<int>& arr){
        vector<int> ans(arr.size(),arr.size());
        stack<int> st;
        for(int i=arr.size()-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            if(!st.empty()) ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> pse_el(vector<int>& arr){
        vector<int> ans(arr.size(),-1);
        stack<int> st;
        for(int i=0;i<arr.size();i++){
            while(!st.empty() && arr[st.top()]>=arr[i]) st.pop();
            if(!st.empty()) ans[i]=st.top();
            st.push(i);
        }
        return ans;
    }
    int getMaxArea(vector<int> &arr) {
        vector<int> nse=nse_el(arr);
        vector<int> pse=pse_el(arr);
        int ans=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            ans = max(ans, (nse[i]-pse[i]-1)*arr[i]);
        }
        return ans;
    }
};
