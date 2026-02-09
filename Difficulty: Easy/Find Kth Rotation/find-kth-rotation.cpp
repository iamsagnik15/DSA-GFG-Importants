class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int st = 0 , en = arr.size()-1; // logic is finding the index of smallest element, i.e. the no of right rotation done.
        while(st<en){
            if(arr[st]< arr[en])return st; // if the sub-array is already sorted
            int mid = (st + en)/2;
            if(arr[st] < arr[mid]){
                st = mid+1;
            }else if(arr[st] == arr[mid]){ // when  st+1 == en
                return st+1;
            }else en = mid;
        }
        return st; // final index will be the  minimum element
    }
};