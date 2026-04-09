class Solution {
public:
    vector<int> intersection(vector<int>& a, vector<int>& b) {
        if (a.size() > b.size()) swap(a, b);
        unordered_set<int> s(a.begin(), a.end());
        vector<int> r;
        for (int x : b) if (s.erase(x)) r.push_back(x);
        return r;
    }
};