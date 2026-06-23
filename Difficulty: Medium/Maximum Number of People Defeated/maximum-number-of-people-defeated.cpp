class Solution {
  public:
    int maxPeopleDefeated(int p) {
        // Code Here
         int ans=0;
        int i=1;
       while(i*i<=p){
                p=p-(i*i);
                ans++;
                i++;
        }
        return ans;
        
    }
};
