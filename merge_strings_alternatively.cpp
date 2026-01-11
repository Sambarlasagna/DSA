class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string s;
        int i = 0;
        int j = 0;
        int m = word1.size();
        int n = word2.size();
        while(i<m &&j<n){
            s+=word1[i];
            s+=word2[j];
            i++;
            j++;
        }
        while(i<m){
            s+=word1[i];
            i++;
        }
        while(j<n){
            s+=word2[j];
            j++;
        }
        return s;
    }
};