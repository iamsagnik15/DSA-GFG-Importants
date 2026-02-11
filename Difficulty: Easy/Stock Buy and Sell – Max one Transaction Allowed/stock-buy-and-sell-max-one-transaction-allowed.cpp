class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int maxProf = 0, mini = INT_MIN;
        for(int i=0; i<prices.size(); i++) {
            if(prices[i]-mini > 0) maxProf = max(maxProf, prices[i]-mini);
            else mini = prices[i];
        } return maxProf;
    }
};