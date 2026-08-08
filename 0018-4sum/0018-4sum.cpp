class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, long long target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int l = j + 1, r = n - 1;
                long long goal = target - nums[i] - nums[j];
                while (l < r) {
                    if (1LL * nums[l] + nums[r] == goal) {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        ++l; --r;
                        while (l < r && nums[l-1] == nums[l]) ++l;
                    } else if (1LL * nums[l] + nums[r] > goal) {
                        --r;
                    } else {
                        ++l;
                    }
                }
                while (j+1 < n && nums[j] == nums[j+1]) ++j; 
            }
            while (i+1 < n && nums[i] == nums[i+1]) ++i; 
        }
        return ans;
    }
};