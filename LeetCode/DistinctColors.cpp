class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> mp,balls;
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            if(balls.find(queries[i][0])==balls.end()){
                balls[queries[i][0]]=queries[i][1];
                mp[queries[i][1]]++;
            }else{
                mp[balls[queries[i][0]]]--;
                if(mp[balls[queries[i][0]]]==0) mp.erase(balls[queries[i][0]]);
                balls[queries[i][0]]=queries[i][1];
                mp[queries[i][1]]++;
            }
            ans.push_back(mp.size());
        }
        return ans;
    }
};