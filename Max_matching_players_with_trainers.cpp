class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int i = 0;
        int j = 0;
        int m = players.size();
        int n = trainers.size();
        int k = 0;
        sort(players.begin(),players.end());
        sort(trainers.begin(),trainers.end());
        while(i<m && j<n){
            if(trainers[j]>=players[i]){
                i++;
                j++;
                k++;
            }
            else{
                j++;
            }
       }
       return k;
    }
};