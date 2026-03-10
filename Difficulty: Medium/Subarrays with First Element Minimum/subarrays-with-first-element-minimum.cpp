class Solution {
  public:
    int countSubarrays(vector<int> &arr) {
        int n=arr.size();
        vector<int>nextSmaller(n,n);
        stack<int>st;
        st.push(n-1);
        for(int i=n-2;i>=0;i--){
            while(!st.empty()&&arr[st.top()]>=arr[i])st.pop();
            if(!st.empty())nextSmaller[i]=st.top();
            st.push(i);
        }
        // for(auto&idx:nextSmaller)cout<<idx<<" ";
        int result=0;
        for(int i=0;i<n;i++)result+=nextSmaller[i]-i;
        return result;
    }
};