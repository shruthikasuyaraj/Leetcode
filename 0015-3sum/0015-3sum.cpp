class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        map<int,vector<int>> m;
        int N=nums.size();
        for(int i=0;i<N;i++){
            int v=nums[i];
            m[v].push_back(i);
        }
        set<string> used;
           for(int lt=0;lt<N;lt++){
            for(int rt=lt+1;rt<N;rt++){
                int sum=nums[lt]+nums[rt];
                if(m.find(-sum)!=m.end()){
                    
                    for(int idx:m[-sum]){
                        
                        if(idx==lt || idx==rt) continue;

                            vector<int> t={nums[lt],nums[rt],-sum};
                            
                            sort(t.begin(),t.end());
                            string iden="";
                            for(int v:t) iden+=to_string(v)+"_";
                            
                            if(!used.contains(iden)){
                                used.insert(iden);
                                ans.push_back(t);
                            }
                            while(rt+1<N && nums[rt]==nums[rt+1]){
                                rt++;
                            }
                            break;
                        
                    }
                    
                }
            }         
            }
        
       
        return ans;
    }
};