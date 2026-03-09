class Solution {
public:
    string largestSwap(string &s) {
        int maxi = INT_MIN;
        int j = -1;
        int l = -1;
        bool bl = false;
        int kcnt = 0;
        for(int i = 0;i<s.length()-1;i++){
            if(bl){
                kcnt++;
                int k = maxi;
                maxi = max(maxi,s[i]-'0');
                if(maxi > k){
                    l = i;
                }
                if(maxi == s[i]-'0'){
                    l = i;
                }
                if(i == s.length()-2){
                    int m = maxi;
                    maxi = max(maxi,s[i+1]-'0');
                    if(maxi > m){
                        l = i+1;
                    }
                    if(maxi == s[i+1]-'0'){
                        l = i+1;
                    }
                }
                continue;
            }
            if(s[i]-'0' < s[i+1]-'0'){
                j = i;
                bl = true;
            }
        }
        if(!bl){
            return s;
        }
        if(bl && kcnt == 0){
            int a = s[s.length()-1]-'0';
            for(int i = 0;i<s.length()-1;i++){
                if(s[i]-'0' < a){
                    swap(s[i],s[s.length()-1]);
                    break;
                }
            }
            return s;
        }
        for(int i = 0;i<=j;i++){
             if(maxi > s[i]-'0'){
                 swap(s[i],s[l]);
                 break;
             }
        }
        return s;
    }
};