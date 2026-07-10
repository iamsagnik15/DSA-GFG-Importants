class Solution {
    public int getCount(int n) {
        // code here
        int cnt = 0, sm = 0, i=0;
        for(i=2;i*i<=2*n; i++){
            int val = n -(i*(i-1))/2;
            if(val%i == 0)cnt++;
        }
        return cnt;
    }
};