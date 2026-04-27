class Solution {
    public int smallestSubstring(String s) {
        // code here
        int n =  s.length();
         int i = 0;
         int j = 0;
          int c1 =0,c2 =0,c0=0;
          int distinct = 0;
           int ans =  Integer.MAX_VALUE;
           while(j<n){
               char ch  = s.charAt(j);
               if(ch=='0'){
                   if(c0==0)distinct++;
                       c0++;
                   
               }
              else if(ch=='1'){
                   if(c1==0)distinct++;
                       c1++;
                   
               }
              else if(ch=='2'){
                   if(c2==0)distinct++;
                       c2++;
                   
               }
               while(distinct==3){
                   ans = Math.min(ans,j-i+1);
                   char remove = s.charAt(i);
                   if(remove=='0'){
                       c0--;
                       if(c0==0)distinct--;
                   }  else if(remove=='1'){
                       c1--;
                       if(c1==0)distinct--;
                   } else{
                       c2--;
                       if(c2==0) distinct--;
                   }
                   i++;
               }
               j++;
           }
           return ans==Integer.MAX_VALUE ? -1 : ans;
    }
};