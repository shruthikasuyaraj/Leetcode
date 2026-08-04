class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int rem = 0;
        vector<bool> ans;
        for(auto& x : nums) {
            rem = ((rem << 1) + x) % 5;
            ans.push_back(rem == 0);
        }
        return ans;
    }
};