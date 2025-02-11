class Solution {
    public:
        bool check(stack<char> st,string part){
            int n=part.size()-1;
            while(n>=0 && !st.empty()){
                if(st.top()==part[n]){
                    st.pop();
                    n--;
                }else return false;
            }
            if(n==-1) return true;
            return false;
        }
        string removeOccurrences(string s, string part) {
            stack<char> st;
            int n=part.size();
            for(int i=0;i<s.size();i++){
                st.push(s[i]);
                if(st.top()==part[n-1]){
                    if(check(st,part)){
                        for(int i=0;i<n;i++){
                            st.pop();
                        }
                    }
                }
    
            }
            string ans="";
            while(!st.empty()){
                ans+=st.top();st.pop();
            }
            reverse(ans.begin(),ans.end());
            return ans;
        }
    };