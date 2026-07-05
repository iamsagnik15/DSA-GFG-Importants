class Solution {
  public:
    int maxCharGap(string &s) {
        // code here
        vector<char> arr(26,0);
        for(int i=0;i<s.length();i++){
            arr[s[i]-'a']++;
        }
        string f;
        
        for(int i=0;i<26;i++){
            if(arr[i]>1){
                char d= 'a'+i;
                f+=d;
            }
           
        }
        int ans=0;
        for(int i=0;i<f.length();i++){
            int c=0;
            int m=0;
            int n=0;
            for(int j=0;j<s.length();j++){
                
                if((s[j]==f[i])&&c==0){
                    c++;
                    m=j;
                }
                else if((s[j]==f[i])&&c!=0){
                    n=j;
                }
            }
            ans = max(ans,n-m);
        }
        return ans-1;
    }
};