class Solution {
  public:
    long long sumXOR(vector<int> &arr) {
        // code here
        int n=arr.size();
long long result=0;
for(int bit=0;bit<32;bit++){
long long count1=0;
for(int x:arr){
if(x&(1<<bit)){
count1++;
}
}
long long count0=n-count1;
result+=count0*count1*(1LL<<bit);
}
return result;
        
    }
};