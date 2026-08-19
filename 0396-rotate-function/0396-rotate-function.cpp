class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        long long sum=0,F=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            F+=1LL*i*nums[i];
        }
        long long maxi=F;
        for(int i=1;i<n;i++){
            F+=sum-(1LL*n*nums[n-i]);
            maxi=max(maxi,F);
        }
        return maxi;
    }
};