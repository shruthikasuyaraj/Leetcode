class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lastInd;

        for (int currInd = 0; currInd < nums.size(); currInd++) {
            if (lastInd.contains(nums[currInd])) {
                if (currInd - lastInd[nums[currInd]] <= k) {
                    return true;
                }
            }

            lastInd[nums[currInd]] = currInd;
        }

        return false;
    }
};