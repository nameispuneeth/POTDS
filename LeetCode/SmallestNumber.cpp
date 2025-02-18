class Solution {
public:
    bool backtrack(string& ans,string& pattern,vector<bool>& freq,int ind){
        if((ans.size()-1)==pattern.size()) return true;
        for(int i=1;i<=9;i++){
            char x=ans.back();
            char y=i+'0';
            if(!freq[i]){
                if(pattern[ind]=='I'){
                    if(y>x){
                        freq[i]=true;
                        ans.push_back(y);
                        if(backtrack(ans,pattern,freq,ind+1)) return true;
                        freq[i]=false;
                        ans.pop_back();
                    }
                }else{
                    if(y<x){
                        freq[i]=true;
                        ans.push_back(y);
                        if(backtrack(ans,pattern,freq,ind+1)) return true;
                        ans.pop_back();
                        freq[i]=false;
                    }
                }
            }
        }
        return false;
    }
    string smallestNumber(string pattern) {
        vector<bool> freq(10,false);
        freq[0]=true;
        for(int i=1;i<=9;i++){
            string ans="";
            ans+=(i+'0');
            freq[i]=true;
            backtrack(ans,pattern,freq,0);
            freq[i]=false;
            if((ans.size()-1)==pattern.size()) return ans;
        }
        return "";
    }
};