//Date 05-02-25
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int n=s1.size();
        int ind=-1;
        bool fin=false;
        for(int i=0;i<n;i++){
            if(s1[i]!=s2[i]){
                if(fin) return false;
                if(ind==-1) ind=i;
                else{
                    if(s2[ind]==s1[i] && s1[ind]==s2[i]){
                        fin=true;
                    }else return false;
                }
            }
        }
        if((ind==-1 && !fin) ||(ind!=-1 && fin)) return true;
        return false;
    }
};