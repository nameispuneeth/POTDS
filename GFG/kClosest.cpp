class Solution {
  public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<points.size();i++){
            int val=(points[i][0])*(points[i][0]);
            val+=((points[i][1]*points[i][1]));
            pq.push({val,i});
        }
        vector<vector<int>> ans;
        while(k>0){
            auto it=pq.top();pq.pop();
            ans.push_back(points[it.second]);
            k--;
        }
        return ans;
    }
};