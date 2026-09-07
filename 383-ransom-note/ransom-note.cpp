class Solution {
public:

    bool fun(unordered_map<char, int> have,
             unordered_map<char, int> need) {

        for (auto i : need) {
            char c = i.first;
            int fneed = i.second;
            int fhave = have[c];

            if (fhave < fneed) {
                return false;
            }
        }

        return true;
    }

    bool canConstruct(string ransomNote, string magazine) {

        int n = magazine.size();
        int m = ransomNote.size();

        unordered_map<char, int> have;
        unordered_map<char, int> need;

        for (int i = 0; i < n; i++) {
            have[magazine[i]]++;
        }

        for (int i = 0; i < m; i++) {
            need[ransomNote[i]]++;
        }

        return fun(have, need);
    }
};