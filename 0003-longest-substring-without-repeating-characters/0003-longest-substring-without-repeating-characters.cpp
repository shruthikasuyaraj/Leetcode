class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left=0, maxlen=0, n=s.length();
        unordered_set<char> dupfind;
        for(int right=0;right<n;right++){
            while(dupfind.find(s[right])!=dupfind.end()){
                dupfind.erase(s[left]);
                left++;
            }
            dupfind.insert(s[right]);
            maxlen=max(maxlen,right-left+1);
        }
        return maxlen;
    }
};