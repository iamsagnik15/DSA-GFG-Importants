class Solution {
  public:
    void segregate0and1(vector<int> &arr) {
        int n=arr.size();
        int i=0, j=0; 
        
        while(j < n){
            if(arr[j]==0){
                arr[i]=0;
                i++,j++;
            }
            else{
                j++;
            }
        }
        
        while(i < n) arr[i]=1, i++;
    }
};