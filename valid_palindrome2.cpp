//sol 1
class Solution {
public:
    bool check(string s){
        int i = 0;
        int j = s.size()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        while(i<j){
            if(s[i]!=s[j]){
                string s1 = s;
                s.erase(i,1);
                bool condn1 = check(s);
                if(condn1){
                    return true;
                }
                s1.erase(j,1);
                bool condn2=check(s1);
                if(condn2){
                    return true;
                }
                return false;

            }
            i++;
            j--;
        }
        return true;
    }
};

//sol 2(optimized)
class Solution {
public:
    bool check(string s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int i = 0;
        int j = s.size()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return (check(s,i+1,j))|| (check(s,i,j-1));
            }
            i++;
            j--;
        }
        return true;
    }
};