class Solution{
public:
    int missingInteger(vector<int>& nums){
        int sum=nums[0];
        bitset<52> seen;
        bool seq=true;
        seen.set(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(seq&&nums[i]==nums[i-1]+1)
                sum+=nums[i];
            else{
                seq=false;
                if(sum>50)
                    return sum;
            }
            seen.set(nums[i]);
        }
        for(int i=sum;i<52;i++)
            if(!seen.test(i))
                return i;
        return sum;
    }
};