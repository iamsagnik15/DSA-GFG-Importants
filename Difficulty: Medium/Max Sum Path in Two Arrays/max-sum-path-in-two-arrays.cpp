class Solution {
  public:
    int maxPathSum(vector<int> &a, vector<int> &b) {
        // Code here
      
        int i = 0 ;
        int j = 0 ; 
        int sum1 = 0 ; 
        int sum2 = 0 ;
        int ans = 0 ;
        
        while(i < a.size() && j < b.size() ){
            
            if(a[i] > b[j]){
                
                sum2 += b[j] ;
                  j++ ;
            }
            
            else if( a[i] < b[j] ){
                
                sum1 += a[i] ;
                   i++ ;
            }
            else { //a[i] == b[j]
            
                ans += max(sum1 , sum2) + a[i] ;
                i++ ;
                j++ ;
                sum1 = 0 ;
                sum2 = 0 ;
                 
            }
            
        }
        
        while(i < a.size()){
            sum1 += a[i] ;
            i++ ;
        }
        
        while(j < b.size()){
            sum2+= b[j] ;
            j++ ;
            
        }
        
        ans += max(sum1 , sum2 ) ;
        
        return ans ;
        
        
        
    }
};

