
//Correct logic but high time complexity
// class Solution
// {
// public:
//     vector<vector<string>> groupAnagrams(vector<string> &strs)
//     {
//         vector<vector<string>> result;
//         vector<string> v1 = {strs[0]};
//         result.push_back(v1);
//         for (int i = 1; i < strs.size(); i++)
//         {
//             string s = strs[i];
//             string s1 = s;
//             sort(s1.begin(), s1.end());
//             bool flag = false;
//             for (vector<string> &row : result)
//             {
//                 for (string &s2 : row)
//                 {
//                     string s3 = s2;
//                     sort(s3.begin(), s3.end());
//                     if (s3 == s1)
//                     {
//                         row.push_back(s);
//                         flag = true;
//                         break;
//                     }
//                 }
//             }
//             if (!flag)
//             {
//                 vector<string> v;
//                 v.push_back(s);
//                 result.push_back(v);
//             }
//         }
//         return result;
//     }
// };

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> result;
        unordered_map<string,vector<string>> temp;
        for(string s:strs){
            string s1 = s;
            sort(s1.begin(),s1.end());
            temp[s1].push_back(s);
        }
        for(auto&pair:temp){
            result.push_back(pair.second);
        }
        return result;
    }
};