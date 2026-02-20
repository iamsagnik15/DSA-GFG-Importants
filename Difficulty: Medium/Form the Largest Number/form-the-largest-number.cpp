class Solution {
  public:
  
    static bool comp(string a, string b) {
        return a + b > b + a;
    }
  
    string findLargest(vector<int> &arr) {
        
        int n = arr.size();
        vector<string> nums;
        
        // Convert integers to strings
        for(int i = 0; i < n; i++) {
            nums.push_back(to_string(arr[i]));
        }
        
        // Sort using custom comparator
        sort(nums.begin(), nums.end(), comp);
        
        // Edge case: if highest is "0"
        if(nums[0] == "0")
            return "0";
        
        // Concatenate result
        string ans = "";
        for(int i = 0; i < n; i++) {
            ans += nums[i];
        }
        
        return ans;
    }
};