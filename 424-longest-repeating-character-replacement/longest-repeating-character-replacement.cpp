class Solution {
public:
    // Helper: find the maximum frequency in the current window
    int find(vector<int> &a) {
        int maxc = -1;
        for (int i = 0; i < 256; i++) {
            maxc = max(maxc, a[i]);
        }
        return maxc;
    }

    int characterReplacement(string s, int k) {
        vector<int> f(256, 0);
        int low = 0, res = INT_MIN;
        int n = s.size();

        for (int high = 0; high < n; high++) {
            f[s[high]]++;                // expand window
            int maxcurn = find(f);       // most frequent char count
            int len = high - low + 1;
            int def = len - maxcurn;     // replacements needed

            while (def > k) {            // shrink if too many replacements
                f[s[low]]--;
                low++;
                maxcurn = find(f);
                len = high - low + 1;
                def = len - maxcurn;
            }

            res = max(res, len);         // update result
        }

        return res;
    }
};
