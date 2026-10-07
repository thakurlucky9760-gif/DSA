class Solution {
  public:

    bool solve(string& s, int low, int high) {

        if (low >= high) {
            return true;
        }

        if (s[low] != s[high]) {
            return false;
        }

        return solve(s, low + 1, high - 1);
    }

    bool isPalindrome(string& s) {

        int low = 0;
        int high = s.size() - 1;

        return solve(s, low, high);
    }
};