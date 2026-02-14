
class Solution {
  public:
    int minTime(vector<int>& arr, int k) {
        int h = accumulate(arr.begin(),arr.end(),0);
        int l = max(h/k,*max_element(arr.begin(),arr.end()));
        int ans = 0;
        while(l<=h){
            int mid = l + (h-l)/2;
            // cout<<h<<"-"<<l<<endl;
            int count = 1;
            int curSum = 0;
            for(int i = 0; i< arr.size();i++){
                if(curSum+arr[i]>mid){
                    curSum = arr[i];
                    count++;
                    if(count>k)break;
                }else{
                    curSum+=arr[i];
                }
            }
            if(count<=k){
                ans = mid;
                h = mid-1;
            }else{
                l = mid+1;
            }
        }
        return ans;
    }
};