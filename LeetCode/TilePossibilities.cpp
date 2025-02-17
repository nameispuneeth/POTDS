class Solution {
public:
    void backtrack(string s,vector<int>& freq,unordered_set<string>& st){
        for(int i=0;i<26;i++){
            if(freq[i]){
                freq[i]--;
                char x=('A'+i);
                backtrack(s+x,freq,st);
                if(s!="") st.insert(s);
                freq[i]++;
            }
        }
        if(s!="") st.insert(s);

    }
    int numTilePossibilities(string tiles) {
        unordered_set<string> st;
        vector<int> freq(26,0);
        for(auto it:tiles) freq[it-'A']++;
        backtrack("",freq,st);
        return st.size();
    }
};