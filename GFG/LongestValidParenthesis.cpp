class Solution {
  public:
    int maxLength(string& s) {
        int n=s.size();
        int ans=0;
        int open=0,close=0;
        if(s[0]=='(') open++;
        for(int i=1;i<n;i++){
            if(s[i]=='(') open++;
            else close++;
            if(open==close) ans=max(ans,open+close);
            if(close>open){
                close=0;
                open=0;
            }
        }
        open=0,close=0;
        if(s[n-1]==')') close=1;
        for(int i=n-2;i>=0;i--){
            if(s[i]=='(') open++;
            else close++;
            if(open==close) ans=max(ans,open+close);
            if(open>close){
                open=0;
                close=0;
            }
        }
        return ans;
    }
};