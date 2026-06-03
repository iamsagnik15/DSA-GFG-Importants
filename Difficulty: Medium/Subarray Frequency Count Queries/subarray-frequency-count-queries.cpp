class Solution {
  public:
    virtual vector<int> freqInRange(vector<int>& arr, vector<vector<int>>& queries){
      int n=arr.size();
      
      unordered_map<int, vector<int>> um;
      for(int i=0; i<n; i++){
        um[arr[i]].push_back(i);  
      }
      
      vector<int> ans;
      
      for(auto z: queries){
        int l=z[0], r=z[1], x=z[2];
        
        if(um.find(x) == um.end()) { ans.push_back(0); continue; }
        
        auto &v=um[x];
        
        int cnt = upper_bound(v.begin(), v.end(), r) - lower_bound(v.begin(), v.end(), l);
        ans.push_back(cnt);
      }
      
      return ans;
    }
    
};