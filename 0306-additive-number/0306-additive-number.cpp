#define ll long long int
class Solution {
public:
    bool isAdditiveNumber(string num) {
        int N = num.size();
        for (int flen = 1; flen <= N / 2; flen++) {
            // Leading zeros are not allowed for numbers with length > 1
            if (num[0] == '0' && flen > 1) break; 
            
            for (int slen = 1; N - flen - slen >= max(flen, slen); slen++) {
                // Leading zeros are not allowed for the second number either
                if (num[flen] == '0' && slen > 1) break; 
                
                ll fnum = stoll(num.substr(0, flen));
                ll snum = stoll(num.substr(flen, slen));
                string bal = num.substr(flen + slen);
                
                bool isValid = true;
                while (bal.size() > 0) {
                    ll tnum = fnum + snum;
                    string tnumstr = to_string(tnum);
                    
                    if (bal.find(tnumstr) == 0) {
                        fnum = snum;
                        snum = tnum;
                        bal = bal.substr(tnumstr.size()); // Update the remaining string
                    } else {
                        isValid = false;
                        break; // Sequence broken
                    }
                }
                
                if (isValid) return true; // Found a valid sequence
            }
        }
        return false;
    }
};
