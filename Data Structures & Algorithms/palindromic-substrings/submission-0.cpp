class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        int res = 0;

        for (int i = 0; i < n; i++) {
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                res++;
                l--;
                r++;
            }
        }

        for (int i = 1; i < n; i++) {
            int l = i - 1, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                res++;
                l--;
                r++;
            }
        }

        return res;
    }
};