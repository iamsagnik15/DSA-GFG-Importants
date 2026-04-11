class Solution {
  public:
    virtual int countIncreasing(vector<int>& arr){
      int contribut=0;
      long long ans=0;
      
      int n=arr.size();
      
      for(int i=1; i<n; i++){
        if(arr[i] > arr[i-1]){
          contribut++;
          ans+=(1LL*contribut);
        }else{
          contribut=0;    
        }    
      }
      
      return (int)(ans);
    }
};