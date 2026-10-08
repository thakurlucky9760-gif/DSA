
class Solution {
  public:

    void solve(string &s, char c, int i, int &j) {

        if (i == s.size()) {
            return;
        }

        if (s[i] != c) {
            s[j] = s[i];
            j++;
        }

        solve(s, c, i + 1, j);
    }

    void removeCharacter(string &s, char c) {
        int j = 0;

        solve(s, c, 0, j);

        s.resize(j);
    }
};

