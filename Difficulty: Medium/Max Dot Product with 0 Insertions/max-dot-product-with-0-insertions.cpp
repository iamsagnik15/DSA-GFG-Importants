class Solution {
  public:
    int helper(int i, int j, vector<int>&a, vector<int>&b, vector<vector<int>>&dp){
        if(i>=a.size() || j>=b.size())return 0;
        if((a.size()-i) < (b.size()-j))return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        int take = a[i]*b[j] + helper(i+1, j+1, a, b, dp);
        int not_take = helper(i+1, j, a, b, dp);
        return dp[i][j] = fmax(take, not_take);
    }
    int maxDotProduct(vector<int>& a, vector<int>& b) {
        // code here
        vector<vector<int>>dp(a.size(), vector<int>(b.size(), -1));
        return helper(0, 0, a, b, dp);
    }
};