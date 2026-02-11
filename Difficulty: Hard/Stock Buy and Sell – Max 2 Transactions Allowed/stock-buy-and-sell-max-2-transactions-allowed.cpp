class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int b1=-prices[0];
        int s1=0;
        int b2=-prices[0];
        int s2=0;
        for(int i=1;i<prices.size();i++){
            int price=prices[i];
            b1=max(b1, -price);
            s1=max(s1,b1+price);
            b2=max(b2,s1-price);
            s2=max(s2,b2+price);
        }
        return s2;
    }
};