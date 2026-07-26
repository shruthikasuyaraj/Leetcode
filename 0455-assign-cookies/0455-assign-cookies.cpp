class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int cs = s.size();
        if (cs == 0) return 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0;
        int ci = cs - 1;
        int gi = g.size() - 1;
        while (ci >= 0 && gi >= 0) {
            if (s[ci] >= g[gi]) {
                ans++;
                ci--;
                gi--;
            } else {
                gi--;
            }
        }
        return ans;
    }
};