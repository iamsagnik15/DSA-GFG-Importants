class Solution {
  public:
    int solve(int idx, string &s, int prevSum,vector<vector<int>> &dp){
        if(idx>=s.size()){
            return 1;
        }
        if(dp[idx][prevSum] !=-1){
            return dp[idx][prevSum];
        }
        int cnt = 0, sum = 0;
        for(int i = idx;i<s.size();i++){
            sum += int(s[i]-'0');
            if(sum>=prevSum){
                cnt += solve(i+1, s, sum, dp);
            }
        }
        return dp[idx][prevSum] = cnt;
    }
    int validGroups(string &s) {
        int mxSum = 0;
        for(char c: s){
            mxSum += int(c - '0');
        }
        vector<vector<int>> dp(s.size(), vector<int>(mxSum+1, -1));
        return solve(0, s, 0, dp);
    }
};