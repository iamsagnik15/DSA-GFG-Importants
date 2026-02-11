class Solution {
  public:
    int stockBuySell(vector<int> &prices) {
        // code here
        int p=0;
        for(int i=1;i<prices.size();i++){
            if(prices[i]>prices[i-1]){
                p +=prices[i]-prices[i-1];
            }
        }
        return p;
        //p means profit
    }
};